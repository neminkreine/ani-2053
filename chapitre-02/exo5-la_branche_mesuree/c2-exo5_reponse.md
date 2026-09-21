on verifie la taille du dossier .git avant les modifications:
C:\Users\ASUS\OneDrive\Desktop\git\depot>dir /s .git | find "fichier(s)"
le nombre de fichiers et leur nombre:  146 fichier(s)          132 864 octets

Creation de la branche
C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch -c br
Switched to a new branch 'br'

verification


Les trois commits:
C:\Users\ASUS\OneDrive\Desktop\git\depot>echo "Premiere modification" > test_poids.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git add test_poids.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "feat(test): premier commit"
[br 042b62b] feat(test): premier commit
 1 file changed, 2 deletions(-)

C:\Users\ASUS\OneDrive\Desktop\git\depot>
C:\Users\ASUS\OneDrive\Desktop\git\depot>echo "Deuxieme modification" >> test_poids.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -am "feat(test): deuxieme commit"
[br 63bc282] feat(test): deuxieme commit
 1 file changed, 1 insertion(+)

C:\Users\ASUS\OneDrive\Desktop\git\depot>
C:\Users\ASUS\OneDrive\Desktop\git\depot>echo "Troisieme modification" >> test_poids.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -am "feat(test): troisieme commit"
[br 6940c15] feat(test): troisieme commit
 1 file changed, 1 insertion(+)

 on verifie la taille apres:
 151 fichier(s)          134 754 octets

 la difference est de 1 890 octets