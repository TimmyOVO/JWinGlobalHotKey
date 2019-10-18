package com.github.timmyovo.winglobalhotkey;

public class Test {
    public static void main(String[] args) {
        new Thread(() -> {
            System.loadLibrary("WinGlobalHotkey");
            WinGlobalHotkeyAPI.registerHotkey(0x77, () -> {
                System.out.println("F8 Pressed");
            });
            System.out.println("Done");
        }).start();
        while (true) {
            //app logical
        }
    }
}
