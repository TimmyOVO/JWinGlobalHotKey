package com.github.timmyovo.winglobalhotkey;

public class WinGlobalHotkeyAPI {
    public native static void registerHotkey(int vk, Runnable callback);
}
