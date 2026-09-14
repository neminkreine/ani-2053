Le nombre de fichiers source est: 4796
preuve: PS C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu> @(Get-ChildItem -Recurse -Include *.cpp, *.c, *.hpp, *.h -File).Count
4796
le chapitre indique 2 641

Le nombre de de lignes du depot est: 2600167
preuve: PS C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu> (Get-ChildItem -Recurse -Include *.cpp, *.c, *.hpp, *.h -File | Get-Content | Measure-Object -Line).Lines
2600167
le chapitre indique: 1 193 385
La difference peut etre due au fait que la version du depot actuelle possede plus de fichiers et de lignes que celle consideree dans la lecon.