#pragma once
#include "Player.h"


extern bool isWorking;
extern Player* nowPlayer;
bool UnzipFiles(const std::string &fileName);
bool StartBackup();
bool BackFile(const std::string &worldName);
std::vector<std::string> getAllBackup();


