project(WinGlobalHotkey)

set (CMAKE_CXX_STANDARD 14)
cmake_minimum_required (VERSION 3.8)

if(NOT DEFINED ENV{JAVA_HOME})
    message(FATAL_ERROR "JAVA_HOME not found exiting.")  
endif()
set(JNI_INCLUDE "$ENV{JAVA_HOME}/include")
set(JNI_INCLUDE_WIN32 "$ENV{JAVA_HOME}/include/win32")
include_directories(${JNI_INCLUDE})
include_directories(${JNI_INCLUDE_WIN32})

add_library(WinGlobalHotkey SHARED "WinGlobalHotkeyAPI.cpp" "include/WinGlobalHotkeyAPI.h" "jni/com_github_timmyovo_winglobalhotkey_WinGlobalHotkeyAPI.h")

