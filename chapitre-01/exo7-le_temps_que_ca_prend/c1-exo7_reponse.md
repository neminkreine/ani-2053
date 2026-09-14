La commande tapee a chaque fois est: jenga build --project MonEssai
Le temps de la premiere construction est: 1m5.9s
preuve:
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED
════════════════════════════════════════════════════════════════════════════════
Projects Built:  18/18
Time:           1m5.9s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

le temps de la deuxieme construction est: 8.24s
preuve:
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED
════════════════════════════════════════════════════════════════════════════════
Projects Built:  18/18
Time:           8.24s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

L'ecart entre les deux peut etre du au fait que aucun fichier source n'a été modifié entre les deux commandes, le système détecte que les fichiers objets sont toujours à jour et saute l'etape de compilation.
