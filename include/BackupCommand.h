#include "pch.h"
#include "Backup.h"
#include "ConfigFile.h"
#include "Message.h"

namespace Command{
    extern std::vector<std::string> backupList;
}

void CmdReloadConfig(Player *p);

void CmdBackup(Player* p);

void CmdCancel(Player* p);

void BackWorld();

void listAllBackups(Player *player, int limit);