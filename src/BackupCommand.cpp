#include "BackupCommand.h"

using namespace std;

std::vector<std::string> Command::backupList = {};

void CmdReloadConfig(Player *p)
{
    ini.Reset();
    auto res = ini.LoadFile(_CONFIG_FILE);
    if (res < 0)
    {
        Message::info(p, "Failed to open Config File!");
    }
    else
    {
        Message::info(p, "Config File reloaded.");
    }
}

void CmdBackup(Player* p)
{
    if (p) {
        if((int)p->getCommandPermissionLevel()==0){
            Message::error(p,"你没有权限使用这个指令");
            return;
        }
    }
    Player* oldp = nowPlayer;
    nowPlayer = p;
    if (isWorking) {
        Message::info(p, "An existing backup is working now...Please Wait!");
        nowPlayer = oldp;
    } else {
        StartBackup();
    }
}

void CmdCancel(Player* p)
{
    if (isWorking)
    {
        isWorking = false;
        nowPlayer = nullptr;
        Message::info(p, "Backup Canceled.");
    }
    else
    {
        Message::info(p, "No backup is working now.");
    }
}
//重启时调用
void BackWorld()
{
    bool isBack = ini.GetBoolValue("BackFile", "isBack", false);
    if (isBack) {
        Message::info(nullptr, "正在回档......");
        std::string worldName = ini.GetValue("BackFile", "worldName", "Bedrock level");
        if (!BackFile(worldName)) {
            ini.SetBoolValue("BackFile", "isBack", false);
            ini.SaveFile(_CONFIG_FILE);
            Message::error(nullptr, "回档失败！");
            return;
        }
        ini.SetBoolValue("BackFile", "isBack", false);
        ini.SaveFile(_CONFIG_FILE);
        Message::info(nullptr, "回档成功");
    }
}

void listAllBackups(Player *player, int limit) {
    Command::backupList = getAllBackup();
    if (Command::backupList.empty()) {
        Message::error(player, "No Backup Files");
        return;
    }
    int totalSize = Command::backupList.size();
    int maxNum = totalSize < limit ? totalSize : limit;
    Message::info(player,"使用存档文件前的数字选择回档文件");
    for (int i = 0; i < maxNum; i++) {
        Message::info(player,"[%d]%s",i+1,Command::backupList[i].c_str());
    }
}