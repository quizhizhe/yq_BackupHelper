cmake_minimum_required(VERSION 3.17)
project(BackupHelper)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE}  /DEBUG /OPT:REF /OPT:ICF")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE}  /DEBUG /OPT:REF /OPT:ICF")
        #因为ABI原因这个项目只能msvc编译
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_compile_options(/wd4828 /wd4819 /EHsc /utf-8)
else ()
    message(this project don't support GNU Gcc or clang, please use MSVC instead)
endif ()
set(CMAKE_BUILD_TYPE release)


####################这里是具体功能##########################
#设置插版本
set(BACKUPHELPER_VERSION 0.2)
#设置游戏版本
set(MCBE_VERSION 1.16.40.2)
#是否是测试版
set(BETA OFF)

add_definitions(-DTD_VERSION="${BACKUPHELPER_VERSION}")
add_definitions(-DMC_VERSION="${MCBE_VERSION}")
if (${BETA} STREQUAL "ON")
    add_definitions(-DBETA)
    set(MOD_NAME BackupHelper-${BACKUPHELPER_VERSION}-${MCBE_VERSION}-test)
else ()
    set(MOD_NAME BackupHelper-${BACKUPHELPER_VERSION}-${MCBE_VERSION})
endif ()

add_library(${MOD_NAME}
        SHARED
        src/dllmain.cpp
        src/pch.cpp
        src/Backup.cpp
        src/BackupCommand.cpp
        src/Command.cpp
        src/Message.cpp
        src/Player.cpp
        Plugin.cpp
        )

target_include_directories(
        ${MOD_NAME}
        PUBLIC
        lib
        include
)
target_link_libraries(${MOD_NAME} ${PROJECT_SOURCE_DIR}/lib/detours.lib)