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
using namespace std;
using namespace SymHook;

CSimpleIniA ini;
std::string ver = "v0.1";

// ===== onConsoleCmd =====
THook(bool,
      MSSYM_MD5_b5c9e566146b3136e6fb37f0c080d91e,
      void* _this,
      string& cmd)
{
    if (cmd == "backup") {
        CmdBackup(nullptr);
        return false;
    }
    if (cmd.front() == '/')
        cmd = cmd.substr(1);
    if (cmd == "stop" && isWorking)
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
    Message::logger("OP/后台命令： backup 开始备份");
    //Message::logger("OP/后台命令： backup reload 重新加载配置文件");

    //Cleanup Old
//    if (filesystem::exists("plugins/BackupHelper.lxl.js"))
//        filesystem::remove("plugins/BackupHelper.lxl.js");
//    if (filesystem::exists("plugins/BackupHelper/BackupRunner.exe"))
//        filesystem::remove("plugins/BackupHelper/BackupRunner.exe");
}