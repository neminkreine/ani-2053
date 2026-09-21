Pour cet exercice, nous allons modifier un fichier text.txt qui se presente initialement ainsi:
Ligne 1 modifiee sur l'heure
Ligne 2 
Ligne 3 modifiee sur le jour 


apres avoir modifie la ligne 1 et la ligne 3 on a:
Ligne 1 modifiee sur l'instant
Ligne 2 
Ligne 3 modifiee apres


on lance ensuite le git add -p, on valide la premiere moodification et on laisse l'autre de cote pour l'instant:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git add -p texte.txt
diff --git a/texte.txt b/texte.txt
index 0fd3dfc..21784ae 100644
--- a/texte.txt
+++ b/texte.txt
@@ -1,3 +1,3 @@
-Ligne 1 modifiee sur l'heure
+Ligne 1 modifiee sur l'instant
 Ligne 2
-Ligne 3 modifiee sur le jour
+Ligne 3 modifiee apres
(1/1) Stage this hunk [y,n,q,a,d,s,e,p,P,?]? s
Split into 2 hunks.
@@ -1,2 +1,2 @@
-Ligne 1 modifiee sur l'heure
+Ligne 1 modifiee sur l'instant
 Ligne 2
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]? y
@@ -2,2 +2,2 @@
 Ligne 2
-Ligne 3 modifiee sur le jour
+Ligne 3 modifiee apres
(2/2) Stage this hunk [y,n,q,a,d,K,J,g,/,e,p,P,?]? n

on committe ensuite la premiere partie:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Modifier uniquement le premier sujet"
[master e8ddedb] Modifier uniquement le premier sujet
 1 file changed, 2 insertions(+), 2 deletions(-)


quand on verifie grace a git status, le fichier apparait encore comme modifie:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   texte.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        git

no changes added to commit (use "git add" and/or "git commit -a")


on valide ensuite la seconde modification:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git add -p texte.txt
diff --git a/texte.txt b/texte.txt
index 6a3955e..21784ae 100644
--- a/texte.txt
+++ b/texte.txt
@@ -1,3 +1,3 @@
 Ligne 1 modifiee sur l'instant
 Ligne 2
-Ligne 3 modifiee sur le jour
+Ligne 3 modifiee apres
(1/1) Stage this hunk [y,n,q,a,d,e,p,P,?]? y

et on le committe:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Modifier uniquement le second sujet"
[master 9744d03] Modifier uniquement le second sujet
 1 file changed, 1 insertion(+), 1 deletion(-)

 on verifie l'historique:
 C:\Users\ASUS\OneDrive\Desktop\git\depot>git log -p -n 2
commit 9744d03d2d292f810e0cb6c658b03fa890eb41af (HEAD -> master)
Author: unknown <reineminkiede@gmail.com>
Date:   Mon Sep 21 18:01:07 2026 +0100

    Modifier uniquement le second sujet

diff --git a/texte.txt b/texte.txt
index 6a3955e..21784ae 100644
--- a/texte.txt
+++ b/texte.txt
@@ -1,3 +1,3 @@
 Ligne 1 modifiee sur l'instant
 Ligne 2
-Ligne 3 modifiee sur le jour
+Ligne 3 modifiee apres

commit e8ddedbd53704127785d3c50bdf69ff8ff631fad
Author: unknown <reineminkiede@gmail.com>
Date:   Mon Sep 21 17:57:40 2026 +0100

    Modifier uniquement le premier sujet

diff --git a/texte.txt b/texte.txt
index c581904..6a3955e 100644
--- a/texte.txt
+++ b/texte.txt
@@ -1,3 +1,3 @@
-Ligne 1 modifiee sur master
+Ligne 1 modifiee sur l'instant
 Ligne 2
-Ligne 3 modifiee sur la branche
+Ligne 3 modifiee sur le jour

