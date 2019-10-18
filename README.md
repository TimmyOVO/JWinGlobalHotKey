# WinGlobalHotKey
---
Set windows global hotkey via java
---
### Build
1.Camke(version>=3.8)   
2.Visual Studio (2015 or higher)    
3.Java and jdk installed    
4.%JAVA_HOME% environment variable    
5.Put the dll into your application   
---
### Examples
```
        new Thread(() -> {
            System.loadLibrary("WinGlobalHotkey");
            WinGlobalHotkeyAPI.registerHotkey(0x77, () -> {
                System.out.println("F8 Pressed");
            });
            System.out.println("Done");
        }).start();
        while (true) {
            //your code here
        }
```
