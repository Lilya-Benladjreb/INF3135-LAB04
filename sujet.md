# Labo 4: Pointeurs

## 1 - Pointeurs, structures et tableaux (60 minutes)

Récupérez le fichier [`chess.c`](chess.c) disponible dans ce répertoire.
Complétez les fonctions suivantes:

* `ajouter_piece`: ajoute une pièce à un échiquier
* `initialiser_echiquier`: initialise un échiquier
* `afficher_type_piece`: affiche un type de pièce (`P` pour pion, `T` pour
  tour, `C` pour cavalier, `F` pour fou, `D` pour dame et `R` pour roi)
* `afficher_couleur`: affiche une couleur (`B` ou `N`)
* `afficher_piece`: affiche une pièce
* `afficher_echiquier`: affiche un échiquier

À la fin, on souhaite avoir le comportement suivant:

```sh
$ gcc chess.c -o chess
$ ./chess
+--+--+--+--+--+--+--+--+
|TN|CN|FN|DN|RN|FN|CN|TN|
+--+--+--+--+--+--+--+--+
|PN|PN|PN|PN|PN|PN|PN|PN|
+--+--+--+--+--+--+--+--+
|  |  |  |  |  |  |  |  |
+--+--+--+--+--+--+--+--+
|  |  |  |  |  |  |  |  |
+--+--+--+--+--+--+--+--+
|  |  |  |  |  |  |  |  |
+--+--+--+--+--+--+--+--+
|  |  |  |  |  |  |  |  |
+--+--+--+--+--+--+--+--+
|PB|PB|PB|PB|PB|PB|PB|PB|
+--+--+--+--+--+--+--+--+
|TB|CB|FB|DB|RB|FB|CB|TB|
+--+--+--+--+--+--+--+--+
Le trait aux blancs
```

## 2 - Chaînes de caractères (30 minutes)

* Récupérez le fichier [`string.c`](string.c) disponible dans ce répertoire.
* Complétez la fonction `first_repeated` de telle sorte qu'on ait le
  comportement suivant:

```sh
$ gcc string.c -o string
$ ./string fr
The first repeated character in "abracadabra" is 'a'
The first repeated character in "Linux Mint" is 'i'
The first repeated character in "Ubuntu" is 'u'
```

* Complétez la fonction `num_occurrences` de telle sorte qu'on ait le
  comportement suivant:

```sh
$ gcc string.c -o string
$ ./string no
"abr" occurs 2 times in "abracadabra"
"a" occurs 5 times in "abracadabra"
"ana" occurs 2 times in "ananas"
```

## 3 - La fonction `qsort` (30 minutes)

Dans cette question, on s'intéresse à l'utilisation de la fonction `qsort` de
la bibliothèque `stdlib.h` pour trier des chaînes de caractères. Voir `man
qsort` pour plus d'informations.

* Récupérez le fichier [`sort.c`](sort.c) disponible dans ce répertoire
* Complétez la fonction `lex_compare` qui compare deux chaînes de caractères
  selon l'ordre lexicographique.
* Vérifiez que votre programme fonctionne en le testant sur le fichier
  [`fruits`](fruits)

```sh
$ ./sort -l < fruits
ananas
banane
bleuet
fraise
framboise
kiwi
mangue
melon
nectarine
noix de coco
orange
pastèque
poire
pomme
```

* Complétez la fonction `radix_compare` qui compare deux chaînes de caractères
  selon l'ordre radix. L'ordre *radix* est obtenu en comparant d'abord les
  longueurs des chaînes de caractères. Dans le cas où il y a égalité, on
  utilise l'ordre lexicographique pour trancher.
* Vérifiez que votre programme fonctionne en le testant sur le fichier
  [`fruits`](fruits)

```sh
$ ./sort -r < fruits
kiwi
melon
poire
pomme
ananas
banane
bleuet
fraise
mangue
orange
framboise
nectarine
pastèque
noix de coco
```

* D'après vous, pourquoi le mot *pastèque* apparaît après *nectarine* lorsqu'on
  utilise l'option `-r`? S'agit-il d'un bogue du programme?

**Remarques**:

* La fonction `strcmp` de la bibliothèque `string.h` vous sera utile
* Bien que les paramètres des fonctions de comparaison doivent être de type
  `const void *` pour compiler, dans la situation présente, les arguments
  passés sont de type `char**`.
