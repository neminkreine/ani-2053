nous realiserons cet exercice sur deux branches:

on commence avec la bramche principale:
C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 1 > texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 2 >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 3 >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git add texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Fichier initial a 3 lignes"
[master 873146b] Fichier initial a 3 lignes
 1 file changed, 3 insertions(+)
 create mode 100644 texte.txt

 puis on cree une branche secondaire:
 C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch -c branche-loin
Switched to a new branch 'branche-loin'

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 1 > texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 2 >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 3 modifiee sur la branche >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git add texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Modification de la ligne 3"
[branche-loin 0b24ba1] Modification de la ligne 3
 1 file changed, 1 insertion(+), 1 deletion(-)

 puis on modifie la premiere ligne sur la branche principale:
 C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch master
Switched to branch 'master'

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 1 modifiee sur master > texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 2 >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo Ligne 3 >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git add texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Modification de la ligne 1"
[master 7451843] Modification de la ligne 1
 1 file changed, 1 insertion(+), 1 deletion(-)


 puis on fusionne les deux branches:
 C:\Users\ASUS\OneDrive\Desktop\git\depot>git merge branche-loin -m "Tentative de fusion automatique"
Auto-merging texte.txt
Merge made by the 'ort' strategy.
 texte.txt | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

 la fusion a bel et bien eu lieu. donc git assemble bien les deux.