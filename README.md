# Gestionnaire de dictionnaire
Ceci est un petit programme en C fait dans le cadre d'un exercice pour l'ESGI.

## Organisation Git
Chaque partie de l'exercice correspondront à une branche dédiées.
Une branche de développement pour chacune d'elle sera disponible en remote.

## Structure
Dans sa version la plus simple, le programme comprend une partie qui gère le menu interactif, et 
Le dictionnaire est un fichier comportant tout les mots de la langues anglaises présent par défaut sur la
plupart des distribution Linux.

Ce projet applique les conventions de codage de l'ESGI.

## Compilation
Pour compiler le programme, il suffit de faire un:
```Bash
$ make build
# si un test.c existe à la racine:
$ make test
```
Le dictionnaire utilisé doit être précisé comme argument lors du lancement du programme.
