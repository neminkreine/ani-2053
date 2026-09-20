modification du fichier:
C:\Users\ASUS\OneDrive\Desktop\git\depot>echo modification de test >> fichier1.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   fichier1.txt

no changes added to commit (use "git add" and/or "git commit -a")

add:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git add fichier1.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   fichier1.txt

commit:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Modifier fichier1"
[master 5821490] Modifier fichier1
 1 file changed, 1 insertion(+)

C:\Users\ASUS\OneDrive\Desktop\git\depot>git status
On branch master
nothing to commit, working tree clean


les differences que j'ai note sont:
- dans la modification le nom du fichier est en rouge tandis que dans le git add le nom du fichier est en vert. d'apres mes recherches cela est du au fait que git ait remarque que le fichier est different mais n'a pas encore ete mis a jour.
-