on commence par verifier la taille du dossier .git avant les modifications:
C:\Users\ASUS\OneDrive\Desktop\git\depot>powershell -Command "(Get-ChildItem .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1MB"
0.121649742126465

puis on cree un fichier. on peut le generer grace a fsutil file createnew gros_fichier.bin 10485760:

C:\Users\ASUS\OneDrive\Desktop\git\depot>fsutil file createnew gros_fichier.bin 10485760
Le fichier C:\Users\ASUS\OneDrive\Desktop\git\depot\gros_fichier.bin est créér. 

puis on le committe:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git add gros_fichier.bin

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Ajout d'un gros fichier de 10 Mo"
[master 29ae2f7] Ajout d'un gros fichier de 10 Mo
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 gros_fichier.bin

 puis on le retire:
 C:\Users\ASUS\OneDrive\Desktop\git\depot>git rm gros_fichier.bin
rm 'gros_fichier.bin'

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Suppression du gros fichier"
[master 4f5f45a] Suppression du gros fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 gros_fichier.bin


puis on mesure la taille apres:
C:\Users\ASUS\OneDrive\Desktop\git\depot>powershell -Command "(Get-ChildItem .git -Recurse | Measure-Object -Property Length -Sum).Sum / 1MB"
0.122637748718262

la taille initiale est de 0.121649742126465MB et la taille finale est de 0.122637748718262MB. la difference est de quelques kilobits.