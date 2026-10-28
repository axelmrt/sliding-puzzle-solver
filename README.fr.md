[🇬🇧 English](README.md) | [🇫🇷 Français](README.fr.md)

# Sliding Puzzle Solver 🧩

Projet pédagogique en C++ consacré au développement d'un jeu de taquin et à la recherche d'une solution optimale à l'aide de l'algorithme A*.

## 📌 Présentation

Le taquin est un jeu de réflexion composé d'une grille contenant des tuiles numérotées et une case vide. Le but est de déplacer les tuiles une par une afin de retrouver leur ordre croissant, en laissant la case vide en bas à droite.

Ce projet a pour objectif de développer une application permettant de jouer au taquin, de calculer une solution optimale et de comparer le nombre de coups effectués par le joueur avec le minimum théorique.

Le développement est réalisé en C++, avec Qt pour l'interface graphique et la STL pour les structures de données.

## 🎯 Fonctionnalités prévues

### Jeu de taquin
- [x] Représentation de la grille en C++.
- [x] Déplacements légaux des tuiles.
- [x] Mélange de la grille par déplacements successifs.
- [x] Vérification de la résolubilité.
- [x] Calcul de l'heuristique de Manhattan.
- [ ] Prise en charge complète des grilles 3×3 et 4×4.
- [ ] Interface graphique interactive avec Qt.
- [ ] Compteur de coups et détection de la victoire.

### Résolution automatique
- [ ] Implémentation complète de l'algorithme A*.
- [ ] Calcul du nombre minimal de déplacements.
- [ ] Affichage d'une solution optimale.
- [ ] Mode d'aide avec exécution de la solution coup par coup.
- [ ] Recalcul de la solution à partir de la configuration courante.

### Chargement de fichiers et performances
- [ ] Chargement d'une grille depuis un fichier texte.
- [ ] Vérification du format et de la validité de la grille.
- [ ] Détection des configurations insolubles.
- [ ] Mesure du temps nécessaire au calcul d'une solution.

*Les cases cochées correspondent aux éléments déjà présents dans le code à ce stade du développement. Elles ne garantissent pas encore que tous les cas limites sont traités.*

## 🧠 Algorithme A*

La résolution automatique reposera sur l'algorithme de recherche A*, qui explore les configurations possibles afin de trouver une solution optimale.

La fonction d'évaluation utilisée est :

**f(n) = g(n) + h(n)**

- `g(n)` : nombre de déplacements effectués depuis la configuration initiale.
- `h(n)` : estimation du nombre de déplacements restants, calculée à l'aide de la distance de Manhattan.

La distance de Manhattan correspond à la somme des distances horizontales et verticales entre chaque tuile et sa position finale. La case vide n'est pas prise en compte.

Cette heuristique permet de guider la recherche vers la solution tout en conservant l'optimalité de A* dans les conditions prévues par l'algorithme.

## 🛠️ Technologies utilisées

- **C++** — logique du jeu et algorithme de résolution.
- **Qt** — interface graphique prévue.
- **STL** — structures de données et conteneurs, notamment `std::vector` et `std::priority_queue`.
- **Git / GitHub** — gestion des versions et du développement.

## 📂 Organisation du projet

L'organisation actuelle comprend notamment les fichiers suivants :

```text
sliding-puzzle-solver/
├── jeu.cpp
├── jeu.h
├── main.cpp
├── grille/
└── exe/
```

- `jeu.h` : déclaration de la classe `Jeu`.
- `jeu.cpp` : implémentation de la logique du jeu, des déplacements, du mélange, de la vérification de résolubilité et de l'heuristique.
- `main.cpp` : point d'entrée du programme et premiers essais.
- `grille/` : fichiers de grilles utilisés pour les tests.
- `exe/` : dossier présent dans le dépôt, destiné aux éléments liés à l'exécution.

L'architecture pourra évoluer afin de séparer clairement la logique du jeu, l'algorithme de résolution, la gestion des fichiers et l'interface graphique.

## 🚀 Compilation et exécution

### Prérequis

- Un compilateur compatible C++.
- Git.
- Qt sera nécessaire pour la future version graphique.

### Récupérer le projet

```bash
git clone https://github.com/axelmrt/sliding-puzzle-solver.git
cd sliding-puzzle-solver
```

### Compilation du prototype en console

Si un compilateur `g++` est disponible, la compilation des sources actuelles peut être tentée avec :

```bash
g++ -std=c++17 main.cpp jeu.cpp -o sliding-puzzle-solver
```

Puis, sous Linux ou macOS :

```bash
./sliding-puzzle-solver
```

Sous Windows, exécuter `sliding-puzzle-solver.exe`.

Cette commande correspond au prototype console actuel. Elle devra être adaptée si d'autres fichiers sources ou des dépendances Qt sont ajoutés. La compilation et l'exécution devront être vérifiées dans l'environnement utilisé pour le projet.

## 🌿 Organisation du développement

Le développement peut être organisé autour de plusieurs branches Git :

- `main` : version stable du projet.
- `feature/qt-interface` : développement de l'interface graphique.
- `feature/astar-solver` : développement et tests de l'algorithme A*.
- `integration` : intégration et validation des différentes fonctionnalités avant leur fusion dans `main`.

L'objectif est de permettre le développement indépendant des différentes parties tout en conservant une interface commune entre le plateau de jeu et le solveur.

## 📚 Objectifs pédagogiques

Ce projet permet de mettre en pratique :

- La programmation orientée objet en C++.
- L'utilisation des conteneurs de la STL.
- Les algorithmes de recherche dans un espace d'états.
- Les heuristiques et la recherche de solutions optimales.
- La conception d'une interface graphique avec Qt.
- La modularité du code, les tests et la gestion de versions avec Git.

## 📄 Contexte

Projet pédagogique réalisé dans le cadre d'un travail de développement logiciel en C++.

Le projet est en cours de développement. Les fonctionnalités annoncées comme prévues seront intégrées progressivement.
