Creation du depot vide:
C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu>mkdir depot

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu>cd depot

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\depot>git init
Initialized empty Git repository in C:/Users/ASUS/OneDrive/Desktop/code/Nkentseu/depot/.git/

Ajout de trois fichiers en trois commits:
C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>echo fichier 1 > fichier1.txt

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>git add fichier1.txt

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>git commit -m "Ajout du premier fichier"
[master (root-commit) aba716f] Ajout du premier fichier
 1 file changed, 1 insertion(+)
 create mode 100644 fichier1.txt

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>echo fichier 2 > fichier2.txt

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>git add fichier2.txt

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>git commit -m "Ajout du deuxième fichier"
[master d591293] Ajout du deuxième fichier
 1 file changed, 1 insertion(+)
 create mode 100644 fichier2.txt

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>echo fichier 3 > fichier3.txt

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>git add fichier3.txt

C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>git commit -m "Ajout du troisième fichier"
[master 49dcd63] Ajout du troisième fichier
 1 file changed, 1 insertion(+)
 create mode 100644 fichier3.txt

 Affichage de l'historique en une ligne:
 C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>git log --oneline
49dcd63 (HEAD -> master) Ajout du troisième fichier
d591293 Ajout du deuxième fichier
aba716f Ajout du premier fichier

Affichage du graphe:
C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu\mon-projet>git log --oneline --graph
* 49dcd63 (HEAD -> master) Ajout du troisième fichier
* d591293 Ajout du deuxième fichier
* aba716f Ajout du premier fichier