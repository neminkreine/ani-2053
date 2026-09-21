on commence par modifier un fichier:
C:\Users\ASUS\OneDrive\Desktop\git\depot>echo "Travail important à ne pas perdre" >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -am "Commit important que je vais détruire"
[master 7adef58] Commit important que je vais détruire
 1 file changed, 1 insertion(+)

 puis on revient en arriere:
 C:\Users\ASUS\OneDrive\Desktop\git\depot>git reset --hard HEAD~1
HEAD is now at 611024d Suppression du gros fichier

puis on verifie que le fichier n'est plus:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git log --oneline
611024d (HEAD -> master) Suppression du gros fichier
9eefd77 Ajout d'un gros fichier de 10 Mo
4f5f45a Suppression du gros fichier
29ae2f7 Ajout d'un gros fichier de 10 Mo

il n'apparait pas dans l'historique donc le fichier est bien perdu.
pusi on retrouve sa trace avec reflog:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git reflog
611024d (HEAD -> master) HEAD@{0}: reset: moving to HEAD~1
7adef58 HEAD@{1}: commit: Commit important que je vais détruire
611024d (HEAD -> master) HEAD@{2}: commit: Suppression du gros fichier
9eefd77 HEAD@{3}: commit: Ajout d'un gros fichier de 10 Mo
il apparait bel et bien>