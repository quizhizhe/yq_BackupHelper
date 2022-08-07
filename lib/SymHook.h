#pragma  once
namespace SymHook{
    // [原型] void __cdecl CommandUtils::displayLocalizableMessage(bool,class Player & __ptr64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & __ptr64,class std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > > > const & __ptr64)
    // [符号] ?displayLocalizableMessage@CommandUtils@@YAX_NAEAVPlayer@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
    constexpr RVA MSSYM_MD5_24be62e9330073695808606844de0d99 = 0x00445CB0;

    // [原型] public: virtual void __cdecl ServerNetworkHandler::handle(class NetworkIdentifier const & __ptr64,class CommandRequestPacket const & __ptr64) __ptr64
    // [符号] ?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVCommandRequestPacket@@@Z
    constexpr RVA MSSYM_B1QA6handleB1AE20ServerNetworkHandlerB2AAE26UEAAXAEBVNetworkIdentifierB2AAE24AEBVCommandRequestPacketB3AAAA1Z = 0x003A03A0;

    // [原型] private: bool __cdecl SPSCQueue<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,512>::inner_enqueue<0,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & __ptr64>(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & __ptr64) __ptr64
    // [符号] ??$inner_enqueue@$0A@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@AEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
    constexpr RVA MSSYM_MD5_b5c9e566146b3136e6fb37f0c080d91e = 0x000AC4A0;

    // [ԭ��] public: unsigned __int64 __cdecl NetworkIdentifier::getHash(void)const __ptr64
    // [����] ?getHash@NetworkIdentifier@@QEBA_KXZ
    constexpr RVA MSSYM_B1QA7getHashB1AE17NetworkIdentifierB2AAA4QEBAB1UA3KXZ = 0x00339FB0;

    // [ԭ��] public: virtual void __cdecl ServerLevel::tick(void) __ptr64
    // [����] ?tick@ServerLevel@@UEAAXXZ
    constexpr RVA MSSYM_B1QA4tickB1AE11ServerLevelB2AAA7UEAAXXZ = 0x004EA570;


    // [原型] public: __cdecl SPSCQueue<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,512>::SPSCQueue<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,512>(unsigned __int64) __ptr64
    // [符号] ??0?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@QEAA@_K@Z
    constexpr RVA MSSYM_MD5_3b8fb7204bf8294ee636ba7272eec000 = 0x000AC140;

    // [原型] public: virtual class std::vector<struct SnapshotFilenameAndLength,class std::allocator<struct SnapshotFilenameAndLength> > __cdecl DBStorage::createSnapshot(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & __ptr64) __ptr64
    // [符号] ?createSnapshot@DBStorage@@UEAA?AV?$vector@USnapshotFilenameAndLength@@V?$allocator@USnapshotFilenameAndLength@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z
    constexpr RVA MSSYM_MD5_adbca8b72d73db7bcce47c9a31411881 = 0x00B4C1E0;

    // [原型] public: virtual void __cdecl DBStorage::releaseSnapshot(void) __ptr64
    // [符号] ?releaseSnapshot@DBStorage@@UEAAXXZ
    constexpr RVA MSSYM_B1QE15releaseSnapshotB1AA9DBStorageB2AAA7UEAAXXZ = 0x00B4C9B0;

    // [原型] public: virtual enum CommandPermissionLevel __cdecl Player::getCommandPermissionLevel(void)const __ptr64
    // [符号] ?getCommandPermissionLevel@Player@@UEBA?AW4CommandPermissionLevel@@XZ
    constexpr RVA MSSYM_B1QE25getCommandPermissionLevelB1AA6PlayerB2AAA4UEBAB1QE25AW4CommandPermissionLevelB2AAA2XZ = 0x00718760;

    // [ԭ��] public: virtual class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & __ptr64 __cdecl Actor::getNameTag(void)const __ptr64
    // [����] ?getNameTag@Actor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
    constexpr RVA MSSYM_B1QE10getNameTagB1AA5ActorB2AAA8UEBAAEBVB2QDA5basicB1UA6stringB1AA2DUB2QDA4charB1UA6traitsB1AA1DB1AA3stdB2AAA1VB2QDA9allocatorB1AA1DB1AA12B2AAA3stdB2AAA2XZ = 0x00562BC0;

    // [原型] public: __cdecl PropertiesSettings::PropertiesSettings(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & __ptr64) __ptr64
    // [符号] ??0PropertiesSettings@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
    constexpr RVA MSSYM_MD5_a398f6a5fd39181326a27812ad91ddbb = 0x000B7180;

    // [原型] public: static unsigned int __cdecl LevelSettings::parseSeedString(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & __ptr64,unsigned int)
    // [符号] ?parseSeedString@LevelSettings@@SAIAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@I@Z
    constexpr RVA MSSYM_MD5_d2496e689e9641a96868df357e31ad87 = 0x00B1CA30;
}