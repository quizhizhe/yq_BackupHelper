//
// Created by Qiuzhizhe on 2022/7/29.
//

#ifndef BACKUPHELPER_COMMAND_H
#define BACKUPHELPER_COMMAND_H

#include <vector>
#include <cstdio>
#include <functional>
#include "Player.h"
#include "mod.h"
#include "SymHook.h"


class Level {
public:
    Level() = delete;

    void forEachPlayer(const std::function<void(Player *)> &todo);

};

static Level *serverLevel;

void setLevel(Level *level);

bool runcmd(const std::string &command);

#endif //BACKUPHELPER_COMMAND_H