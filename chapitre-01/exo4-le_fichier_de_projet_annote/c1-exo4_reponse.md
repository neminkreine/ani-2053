Le fichier .jenga choisi est NKAssimp.jenga

L'annotation est la suivante':
#!/usr/bin/env python3
# -*- coding: utf-8 -*- #permet l'utilisation des caracteres accentues
"""
NKAssimp — Open Asset Import Library (Assimp, BSD-3) pour Nkentseu/Jenga.

!!! SCAFFOLD A VALIDER !!!
Assimp est un gros projet CMake : il requiert normalement un 'config.h'/'revision.h'
generes, zlib, et la selection des importeurs/exporteurs via defines ASSIMP_BUILD_NO_*.
Ce .jenga est un point de depart : ajuster les globs, defines et contrib selon les
formats reellement necessaires (souvent : OBJ, FBX, glTF). Voir CMakeLists amont.

Usage :
    dependson(["NKAssimp"]); includedirs(["%{NKAssimp.location}/include"]); links(["NKAssimp"])
"""
from Jenga import * #sert a charger l'emvironnement jenga dans le script Pyhton

with project("NKAssimp"): #definit NKAssimp
    staticlib() #specifie que le resultat sera une une bibliotheque statique
    language("C++") #le langage du projet est le c++
    cppdialect("C++17") #?
    location(".")#?

    includedirs([ #les dossiers contenant les fichiers d'en-tete
        "include",
        ".",
        "code",
        "contrib",
        "contrib/unzip",
        "contrib/zlib",
        "contrib/rapidjson/include",
        "contrib/utf8cpp/source",
    ])

    defines([
        "ASSIMP_BUILD_NO_C4D_IMPORTER",#?
        "ASSIMP_BUILD_NO_OWN_ZLIB=0",#?
        "RAPIDJSON_HAS_STDSTRING=1",#?
    ])

    # A AFFINER : globs larges (peut inclure des importeurs non desires -> ajouter
    # des ASSIMP_BUILD_NO_<FORMAT>_IMPORTER pour reduire / corriger la compilation).
    files([
        "code/Common/**.cpp",
        "code/PostProcessing/**.cpp",
        "code/Material/**.cpp",
        "code/CApi/**.cpp",
    ])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")#?
    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")#?

    with filter("system:Windows && !options:windows-runtime=uwp"):
        usetoolchain("nk-windows-clang-mingw") #le compilateur utilise
    with filter("system:Android"):
        usetoolchain("android-ndk"); buildoptions(["-fPIC"]) #adapte pour les architectures mobiles
    with filter("config:Debug"):
        defines(["_DEBUG"]); optimize("Off"); symbols(True) #?
    with filter("config:Release"):
        defines(["NDEBUG"]); optimize("Speed"); symbols(False) #?

