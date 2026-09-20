Creation de la branche
C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch -c branche
Switched to a new branch 'branche'

verification
C:\Users\ASUS\OneDrive\Desktop\git\depot>git branch
* branche
  master

Les trois commits:
C:\Users\ASUS\OneDrive\Desktop\git\depot>echo test1 > test1.txt & git add test1.txt & git commit -m "Ajout test 1"
[branche c322807] Ajout test 1
 1 file changed, 1 insertion(+)
 create mode 100644 test1.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo test2 > test2.txt & git add test2.txt & git commit -m "Ajout test 2"
[branche b9b2ed7] Ajout test 2
 1 file changed, 1 insertion(+)
 create mode 100644 test2.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>echo test3 > test3.txt & git add test3.txt & git commit -m "Ajout test 3"
[branche 5cfc274] Ajout test 3
 1 file changed, 1 insertion(+)
 create mode 100644 test3.txt

Pour verifier la taille, j'ai utilise la commande dir /s .git trouvee suite a des recherches:
la verification n'a pas ete proprement faite, suite au volume de d'informations recues en retour, mais en se tenant au cours le depot ne doit pas avoir gangne beaucoup 