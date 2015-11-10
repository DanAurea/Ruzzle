# Ruzzle

Le Ruzzle est un jeu originaire du monde mobile, ce jeu consiste à former le plus de mots en un temps imparti à partir
d'une grille de lettres générée aléatoirement.
Le but étant de marquer le plus de points possible pour celà des bonus lettre et mot double/triple sont répartis sur la grille
mais il n'est pas permis de réutiliser deux fois la même case.

# Instructions de compilation


>  $ make

Permet de compiler l'ensemble des sources, l'exécutable généré peut être retrouvé dans **./bin** .

>  $ make mrproper

Permet de nettoyer le dossier.

# Utilisation

>  $ ./bin/ruzzleSolver

Permet d'exécuter le programme.

On peut prédéfinir une grille à l'aide d'une chaine de caractère ou générer un grille de façon aléatoire.

Par exemple:

La chaine de caractère "adcksxirmdesuckh" génèrera la grille : 

>	A&nbsp;&nbsp;&nbsp;&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;C&nbsp;&nbsp;&nbsp;&nbsp;K
> 
>	S&nbsp;&nbsp;&nbsp;&nbsp;X&nbsp;&nbsp;&nbsp;&nbsp;I&nbsp;&nbsp;&nbsp;&nbsp;R
> 
>	M&nbsp;&nbsp;&nbsp;&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;E&nbsp;&nbsp;&nbsp;&nbsp;S
> 
>	U&nbsp;&nbsp;&nbsp;&nbsp;C&nbsp;&nbsp;&nbsp;&nbsp;K&nbsp;&nbsp;&nbsp;&nbsp;H 
> 

Pour la génération de la grille de façon aléatoire, les lettres sont tirées au hasard en prenant compte de leurs fréquences d'apparition dans la langue française.

Les bonus lettres et mots sont tirés aléatoirement de manière à ce qu'il n'y ait pas trop de bonus.




