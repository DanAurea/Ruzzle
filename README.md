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

>	A	D	C	K
> 
>	S	X	I	R
> 
>	M	D	E	S
> 
>	U	C	K	H 
> 

Pour la génération de la grille de façon aléatoire, les lettres sont tirées au hasard en prenant en compte de leurs fréquences d'apparition.




