on modifie notre fichier texte.txt dans une autre branche:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch master
Already on 'master'

C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch -c test-rebase
fatal: a branch named 'test-rebase' already exists

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo "Modif sur branche" >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git add texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Commit sur test-rebase"
[master 0ad2fc6] Commit sur test-rebase
 1 file changed, 1 insertion(+)



 on reprend la meme operation mais en utilisant la fusion:
 C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch master
Already on 'master'

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo "Modif sur master" >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git add texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Commit sur master"
[master acd460d] Commit sur master
 1 file changed, 1 insertion(+)

C:\Users\ASUS\OneDrive\Desktop\git\depot>git merge test-rebase -m "Fusion classique"
Already up to date.

son graphe:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git log --oneline --graph --all
* acd460d (HEAD -> master) Commit sur master
* 0ad2fc6 Commit sur test-rebase
*   7122aca Commit sur test-rebase-2
|\
| * cb4688c (test-rebase) Commit sur test-rebase
* | 441d4b9 Commit sur master
* | 81e4adf Commit sur test-rebase
|/
* 9744d03 Modifier uniquement le second sujet
* e8ddedb Modifier uniquement le premier sujet
*   4ed7535 Tentative de fusion automatique
|\
| * 0b24ba1 (branche-loin) Modification de la ligne 3
* | 7451843 Modification de la ligne 1
|/
* 873146b Fichier initial a 3 lignes
*   20ed4f7 Resoudre le conflit sur config.txt
|\
| * b007d61 (branche-A) Modifier config sur branche-A
* | 52a2c0a Modifier config sur master
* | 67fb4d1 Fusion de branche-A
|\|
| * ec28c94 Mets la vitesse a 180
| * 391c0d1 Mets la vitesse a 250 sur branche-A
| * 5cfc274 (branche) Ajout test 3
| * b9b2ed7 Ajout test 2
| * c322807 Ajout test 1
* | ec9ac2b Mettre la vitesse à 180 sur main
|/
* 5821490 Modifier fichier1
* bc5a8d6 Ajout du fichier 3
* 33a5d98 Ajout du fichier 2
* 629ebf3 Ajout du fichier 1


maintenant on procede en rejouant:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch -c test-rebase-2 master
Switched to a new branch 'test-rebase-2'

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo "Modif autre" >> texte.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -am "Commit sur test-rebase-2"
[test-rebase-2 2bb4d98] Commit sur test-rebase-2
 1 file changed, 1 insertion(+)


 son graphe:
 C:\Users\ASUS\OneDrive\Desktop\git\depot>git log --oneline --graph --all
* 2bb4d98 (HEAD -> test-rebase-2) Commit sur test-rebase-2
* acd460d (master) Commit sur master
* 0ad2fc6 Commit sur test-rebase
*   7122aca Commit sur test-rebase-2
|\
| * cb4688c (test-rebase) Commit sur test-rebase
* | 441d4b9 Commit sur master
* | 81e4adf Commit sur test-rebase
|/
* 9744d03 Modifier uniquement le second sujet
* e8ddedb Modifier uniquement le premier sujet
*   4ed7535 Tentative de fusion automatique
|\
| * 0b24ba1 (branche-loin) Modification de la ligne 3
* | 7451843 Modification de la ligne 1
|/
* 873146b Fichier initial a 3 lignes
*   20ed4f7 Resoudre le conflit sur config.txt
|\
| * b007d61 (branche-A) Modifier config sur branche-A
* | 52a2c0a Modifier config sur master
* | 67fb4d1 Fusion de branche-A
|\|
| * ec28c94 Mets la vitesse a 180
| * 391c0d1 Mets la vitesse a 250 sur branche-A
| * 5cfc274 (branche) Ajout test 3
| * b9b2ed7 Ajout test 2
| * c322807 Ajout test 1
* | ec9ac2b Mettre la vitesse à 180 sur main
|/
* 5821490 Modifier fichier1
* bc5a8d6 Ajout du fichier 3
* 33a5d98 Ajout du fichier 2
* 629ebf3 Ajout du fichier 1

les deux me donnent le meme graphe>