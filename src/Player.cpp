//
// Created by Qiuzhizhe on 2022/7/28.
//
#include "Player.h"
#include "mod.h"
#include "SymHook.h"

uint64_t NetworkIdentifier::getHash() {
    return SYM_CALL(
            uint64_t(*)(NetworkIdentifier * ),
            SymHook::MSSYM_B1QA7getHashB1AE17NetworkIdentifierB2AAA4QEBAB1UA3KXZ,
            this
    );
}

std::string Player::getNameTag() {
    return *SYM_CALL(std::string * (*)(Player * ),
                     SymHook::MSSYM_B1QE10getNameTagB1AA5ActorB2AAA8UEBAAEBVB2QDA5basicB1UA6stringB1AA2DUB2QDA4charB1UA6traitsB1AA1DB1AA3stdB2AAA1VB2QDA9allocatorB1AA1DB1AA12B2AAA3stdB2AAA2XZ,
                     this
    );
}

enum CommandPermissionLevel Player::getCommandPermissionLevel() {
    return *reinterpret_cast<CommandPermissionLevel *>(this+2112);
}

NetworkIdentifier *Player::getClientID() {
    //! from  ServerPlayer::isHostingPlayer
    return reinterpret_cast<NetworkIdentifier *>(this+0x980);
}
