Nombre de projets par type:
-StaticLib: 60
preuve: PS C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu> (jenga info | Select-String "StaticLib").Count
60

-TestSuite: 68
preuve: PS C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu> (jenga info | Select-String "TestSuite").Count
68

-ConsoleApp: 112
preuve: PS C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu> (jenga info | Select-String "ConsoleApp").Count
112

-WindowedApp: 55
preuve: PS C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu> (jenga info | Select-String "WindowedApp").Count
55

le nombre de chaines de compilation est:5
preuve:  Available Toolchains
------------------------------------------------------------
Name                Family   Target OS   Arch     Env
=======================================================
host-clang          clang    Windows     x86_64   mingw
host-gcc            gcc      Windows     x86_64   mingw
clang-mingw         clang    Windows     x86_64   mingw
mingw               gcc      Windows     x86_64   mingw
clang-cross-linux   clang    Linux       x86_64   gnu

Le projet de demarrage est: Sandbox
preuve: Start project: Sandbox

le fichier qui sert de racine au workspace est Nkentseu.jenga
preuve: Entry file: C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\Nkentseu.jenga
