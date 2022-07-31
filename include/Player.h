//
// Created by Qiuzhizhe on 2022/7/28.
//

#ifndef BACKUPHELPER_PLAYER_H
#define BACKUPHELPER_PLAYER_H

#include <vector>
#include <string>

struct NetworkIdentifier {
    uint64_t getHash();
};
enum CommandPermissionLevel : char {
    Any = 0,
    GameMasters = 1,
    Admin = 2,
    HostPlayer = 3,
    Console = 4,
    Internal = 5,
};

class Player {
public:
    std::string getNameTag();
    NetworkIdentifier *getClientID();
    enum CommandPermissionLevel getCommandPermissionLevel();

};

#endif //BACKUPHELPER_PLAYER_H
