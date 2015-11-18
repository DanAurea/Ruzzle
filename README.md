# Ruzzle


Le Ruzzle est un jeu originaire du monde mobile, ce jeu consiste à former le plus de mots en un temps imparti à partir
d'une grille de lettres générée aléatoirement.
Le but étant de marquer le plus de points possible pour celà des bonus lettre et mot double/triple sont répartis sur la grille
mais il n'est pas permis de réutiliser deux fois la même case.

## Sommaire
   **Ruzzle**
   1. **[Changelog](#changelog)**
     - **[Version 1.0](#version-10)**
     - **[Version 1.01](#version-101)**
     - **[Version 1.08](#version-108)**
   2. **[A faire](#a-faire)**
   3. **[Optimisation](#optimisation)**
   3. **[Instructions de compilation](#instructions-de-compilation)**
   4. **[Utilisation](#utilisation)**
   5. **[Documentation](#documentation)**

## A faire
 
 - [x] Documentation
 - [ ] CUnit
 - [ ] Compte rendu
 - [x] Optimisation

## Changelog

### Version 1.0
 - Solver complet permettant la résolution d'une grille saisie ou générée aléatoirement
 - Documentation complète
 - Instructions utilisateur

### Version 1.01
 - Optimisations diverses sur le traitement

### Version 1.08
 - Comptage points
 - Tests unitaires

## Optimisation

Le solver résouds la grille en l'espace de ~100 ms actuellement, le seul moyen d'optimiser le traitement encore plus est de faire un arbre de recherche mais ce serait plus coûteux en mémoire, tout en sachant qu'avec la taille importante du dictionnaire l'arbre de recherche pourrait prendre plus de temps à être simplement conçu qu'ici à résoudre la grille.

## Instructions de compilation


>  $ **make**

Permet de compiler l'ensemble des sources, l'exécutable généré peut être retrouvé dans **./bin** .

>  $ **make clean**

Permet de supprimer les fichiers objets.

>  $ **make mrproper**

Permet de nettoyer le dossier de tout ce qui peut être régénéré.

## Utilisation

>  $ **./bin/ruzzleSolver**

Permet d'exécuter le programme en générant une grille aléatoire, les lettres sont tirées au hasard en prenant compte de leurs fréquences d'apparition dans la langue française.

On peut prédéfinir une grille à l'aide d'une chaine de 16 caractères.

Par exemple:

>  $ **./bin/ruzzleSolver adcksxirmdesuckh**

Génèrera la grille : 

>	A&nbsp;&nbsp;&nbsp;&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;C&nbsp;&nbsp;&nbsp;&nbsp;K
> 
>	S&nbsp;&nbsp;&nbsp;&nbsp;X&nbsp;&nbsp;&nbsp;&nbsp;I&nbsp;&nbsp;&nbsp;&nbsp;R
> 
>	M&nbsp;&nbsp;&nbsp;&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;E&nbsp;&nbsp;&nbsp;&nbsp;S
> 
>	U&nbsp;&nbsp;&nbsp;&nbsp;C&nbsp;&nbsp;&nbsp;&nbsp;K&nbsp;&nbsp;&nbsp;&nbsp;H 
> 

Dans le cas d'une chaîne trop petite un message d'erreur apparaîtra, si la chaîne est trop grande,
la grille sera composée des 16 premiers caractères.

Les bonus lettres et mots sont tirés aléatoirement de manière à ce qu'il n'y ait pas trop de bonus.

Le résultat du solver se retrouve dans :

> **assets/listWords.txt**

## Documentation

Il est possible de se documenter sur la structure du solver grâce à une documentation générée par doxygen.
Le fichier de configuration pour la documentation est fournie et permet donc de régénérer la documentation en cas de soucis, une page html sera crée reprenant toute la documentation :

> **doc/html/index.html**

Permet de recréer la documentation:

> $ **make doc**
