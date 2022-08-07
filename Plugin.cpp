#include "pch.h"
#include <filesystem>
#include "ConfigFile.h"
#include "BackupCommand.h"
#include "Backup.h"
#include "mod.h"
#include "SymHook.h"
#include "Message.h"
#include "seh_exception.hpp"
#include "Plugin.h"
#include <fstream>
#include <sstream>
using namespace std;
using namespace SymHook;

CSimpleIniA ini;
std::string ver = "v0.2";

// ===== onConsoleCmd =====
THook(bool,
      MSSYM_MD5_b5c9e566146b3136e6fb37f0c080d91e,
      void* _this,
      string& cmd)
{
    //以空格分离出子参数
    std::string cmdsub[2];
    istringstream is(cmd);
    is>>cmdsub[0]>>cmdsub[1];

    if (cmdsub[0] == "backup") {
        CmdBackup(nullptr);
        return false;
    }
    if(cmdsub[0] =="back"){
        if( Command::backupList.empty()) Message::info(nullptr,"禁止不查看存档文件列表回档");
        if(cmdsub[1] != "list") {
            int i = std::stoi(cmdsub[1]);
            if(i> Command::backupList.size()) {
                Message::error(nullptr,"存档选择参数错误");
                return false;
            }
            Message::info(nowPlayer, "正在进行回档文件解压复制\n回档会在重启后生效\n使用backCancel指令可取消回档");
            UnzipFiles(Command::backupList[i]);
            Message::info(nowPlayer, "回档文件准备完成\n即将进行回档前备份");
            StartBackup();
            Command::backupList.clear();
        }
        if (cmdsub[1] == "list"){
            listAllBackups(nullptr,1000);
        }
        return false;
    }
    if(cmdsub[0] == "backCancel"){
        ini.SetBoolValue("BackFile","isBack",false);
        ini.SaveFile(_CONFIG_FILE);
        std::filesystem::remove_all("./plugins/BackupHelper/temp1/");
        Message::info(nullptr,"回档已取消");
        return false;
    }
//    if (cmd.front() == '/')
//        cmd = cmd.substr(1);
    if (cmdsub[0] == "stop" && isWorking)
    {
        Message::error(nullptr,"在备份过程中请不要stop！");
        return false;
    }
    return original(_this, cmd);
}

bool Raw_IniOpen(const string& path, const std::string& defContent)
{
    if (!filesystem::exists(path))
    {
        //创建新的
        filesystem::create_directories(filesystem::path(path).remove_filename().u8string());

        ofstream iniFile(path);
        if (iniFile.is_open() && defContent != "")
            iniFile << defContent;
        iniFile.close();
    }

    //已存在
    ini.SetUnicode(true);
    auto res = ini.LoadFile(path.c_str());
    if (res < 0)
    {
        Message::error(nullptr,"Failed to open Config File!");
        return false;
    }
    else
    {
        return true;
    }
}

void entry()
{
    _set_se_translator(seh_exception::TranslateSEHtoCE);


    Raw_IniOpen(_CONFIG_FILE,"");
    //Translation::load(string("plugins/BackupHelper/LangPack/") + ini.GetValue("Main", "Language", "en_US") + ".json");

    
	Message::logger("BackupHelper存档备份助手-已装载  当前版本：%s", ver.c_str());
    Message::logger("OP/后台命令： {backup} 开始备份");
    Message::logger("使用 {back list} 列出存在的存档");
    Message::logger("使用 {back 存档序号} 指令回档");
    Message::logger("使用回档指令后，重启前，使用{backCancel}指令可以取消回档");
    //Message::logger("OP/后台命令： backup reload 重新加载配置文件");

    //Cleanup Old
//    if (filesystem::exists("plugins/BackupHelper.lxl.js"))
//        filesystem::remove("plugins/BackupHelper.lxl.js");
//    if (filesystem::exists("plugins/BackupHelper/BackupRunner.exe"))
//        filesystem::remove("plugins/BackupHelper/BackupRunner.exe");
}