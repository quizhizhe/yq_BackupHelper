#include "BackupCommand.h"

using namespace std;

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
        if(p->getCommandPermissionLevel()==0){
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