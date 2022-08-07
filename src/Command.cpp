//
// Created by Qiuzhizhe on 2022/7/29.
//
#include "Command.h"
#include "mod.h"
#include "SymHook.h"
#include "Player.h"
#include "BackupCommand.h"
#include <sstream>
#include <filesystem>

void Level::forEachPlayer(const std::function<void(Player *)> &todo) {
    //!硬编码
    auto begin = (uint64_t *) *((uint64_t *)
                                        this + 0xB);
    auto end = (uint64_t *) *((uint64_t *)
                                      this + 0xc);
    while (begin != end) {
        auto *player = (Player *) (*begin);
        if (player)todo(player);
        ++begin;
    }
}

using namespace SymHook;
static VA cmdQueue = 0;

THook(VA,
      MSSYM_MD5_3b8fb7204bf8294ee636ba7272eec000,
      VA _this
) {
    cmdQueue = original(_this);
    return cmdQueue;
}

//执行原版指令
bool runcmd(const std::string &command) {
    if (cmdQueue != 0) {
        SYM_CALL(bool(*) (VA, std::string),
                 MSSYM_MD5_b5c9e566146b3136e6fb37f0c080d91e,
                 cmdQueue,
                 command
        );
        return true;
    }
    return false;
}

void setLevel(Level *level){
    serverLevel = level;
}

using namespace SymHook;

THook(
        void,
        MSSYM_B1QA6handleB1AE20ServerNetworkHandlerB2AAE26UEAAXAEBVNetworkIdentifierB2AAE24AEBVCommandRequestPacketB3AAAA1Z,
        void *handler,
        NetworkIdentifier *id,
        void * commandPacket
) {
    //找到发送命令的玩家
    Player *source = nullptr;
    serverLevel->forEachPlayer([&id, &source](Player *player) {
        if (player->getClientID()->getHash() == id->getHash()) {

            source = player;
            return;
        }
    });
    //找不到就直接返回
    if (!source) {
        original(handler, id, commandPacket);
        return;
    }

    //! 这是一处强制转换
    auto commandString = *reinterpret_cast<std::string *>((char *) commandPacket + 40);
    //L_DEBUG("player %s execute command %s", source->getNameTag().c_str(), commandString->c_str());
    //截获命令数据包，获取命令字符串，如果是插件自定义的命令就直接处理，屏蔽原版，如果不是自定义命令就转发给原版去处理
    //以空格分离出子参数
    std::string cmdsub[2];
    std::istringstream is(commandString);
    is>>cmdsub[0]>>cmdsub[1];
    if((int)source->getCommandPermissionLevel() >= 1) {
        if (cmdsub[0] == "/back") {
            if (Command::backupList.empty()) Message::info(source, "禁止不查看存档文件列表回档");
            if (cmdsub[1] != "list") {
                int i = std::stoi(cmdsub[1]);
                if (i > Command::backupList.size()) {
                    Message::error(source, "存档选择参数错误");
                    return;
                }
                Message::info(source, "正在进行回档文件解压复制\n回档会在重启后生效\n使用backCancel指令可取消回档");
                UnzipFiles(Command::backupList[i]);
                Message::info(source, "回档文件准备完成\n即将进行回档前备份");
                CmdBackup(source);
                Command::backupList.clear();
                return;
            }
            if (cmdsub[1] == "list") {
                listAllBackups(source, 1000);
                return;
            }
        }else if(cmdsub[0] == "/backCancel"){
            if(ini.GetBoolValue("BackFile","isBack",false)) {
                ini.SetBoolValue("BackFile", "isBack", false);
                ini.SaveFile(_CONFIG_FILE);
                std::filesystem::remove_all("./plugins/BackupHelper/temp1/");
                Message::info(source, "回档已取消");
                return;
            }
        }
    }
    if ( commandString == "/backup") {
        CmdBackup(source);
    } else {
        //不是trapdoor的命令，转发给原版
        original(handler, id, commandPacket);
    }
}

THook(
        void *,
        MSSYM_MD5_a398f6a5fd39181326a27812ad91ddbb,
        void *_this,
        void *a2
){
    BackWorld();
    return original(_this,a2);
}