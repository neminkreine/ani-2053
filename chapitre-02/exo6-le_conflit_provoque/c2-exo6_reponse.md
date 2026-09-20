on cree d'abord une nouvelle branche avant de basculer et faire la modification dessus, et on ajoute un message qui explique ce que fait la modification:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git switch -c branche-A
Switched to a new branch 'branche-A'
C:\Users\ASUS\OneDrive\Desktop\git\depot>echo valeur_branche = 100 > config.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git add config.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Modifier config sur branche-A"
[branche-A b007d61] Modifier config sur branche-A
 1 file changed, 1 insertion(+), 1 deletion(-)

 puis on repasse a la branche principale et on modifie differemment:
  C:\Users\ASUS\OneDrive\Desktop\git\depot>echo valeur_master = 50 > config.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git add config.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Modifier config sur master"
[master 52a2c0a] Modifier config sur master
 1 file changed, 1 insertion(+), 1 deletion(-)

 pour provoquer le conflit on fusionne les deux branches:

C:\Users\ASUS\OneDrive\Desktop\git\depot>git merge branche-A
Auto-merging config.txt
CONFLICT (content): Merge conflict in config.txt
Automatic merge failed; fix conflicts and then commit the result.


pour regler le conflit on modifie le ficheir config.txt. il se presente comme suit:

<<<<<<< HEAD
valeur_master = 50 
=======
valeur_branche = 100 
>>>>>>> branche-A

apres modification on ne garde que la valeur desiree:
valeur_branche = 100 


puis on le reactualise:
C:\Users\ASUS\OneDrive\Desktop\git\depot>git add config.txt

C:\Users\ASUS\OneDrive\Desktop\git\depot>git commit -m "Resoudre le conflit sur config.txt"
[master 20ed4f7] Resoudre le conflit sur config.txt


nous no9us sommes heurter a des problemes tels que l'entree dans l'invite Vim par exemple quand on committe sans ajouter de message. il ne s'agit que d'une observation, sans en connaitre la raison.



