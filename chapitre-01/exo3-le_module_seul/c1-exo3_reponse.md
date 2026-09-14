la commande entree est: jenga build --project NKMath --config Debug
L'ordre de construction affiche est:
Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] →
  2. NKCore [STATIC_LIB] (depends: NKPlatform) →
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) →
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) →
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)

  arbre du releve de construction de NKMath: 
                                                                   |NKMath|
                                                                       |
                                                                       |
                                                                       |
  ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        |                                 |                                                      |                                                        |
    |NKPlatform|                   |NKCore|                                                 |NKMemory|                                             |NKContainers|
        |                               |                                                         |                                                      |
                              --------------------                            ----------------------------------              ------------------------------------------
                                        |                                      |                                |             |                     |                  |
                                    |NKPlatform|                         |NKCore|                          |NKPlatform|  |NKCore|             |NKMemory|     |NKPlatform
                                                                             |                                                |                    |
                                                                        ----------                                        ---------            ----------
                                                                             |                                                |                |        |
                                                                        |NKPlatform|                                     |NKPlatform|      |NKCore|   |NKPlatform|
                                                                                                                                               |
                                                                                                                                            -------
                                                                                                                                                |
                                                                                                                                            |NKPlatform|     