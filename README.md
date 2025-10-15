# README – Projet de gestion d’accès (tGestion)

## Description

Ce programme implémente un système de **gestion d’accès** sur Raspberry Pi.  
Il utilise un lecteur de carte connecté en RS232, un clavier ou pavé numérique, et des sorties GPIO pour piloter :

- une porte (verrou électronique),  
- une LED,  
- une lumière d’accès.

Le système fonctionne en **boucle continue** et contrôle les entrées à partir d’un fichier de comptes membres.

---

## Fonctionnement général

1. Le système attend qu’une carte soit passée devant le lecteur.  
2. Le numéro de carte est lu via la classe `tLecteur`.  
3. L’utilisateur saisit son code secret au clavier.  
4. La vérification est effectuée par `tComptesMembres::verifier()`.  
5. Si le couple (numéro, code) est valide :  
   - La porte est déverrouillée (`tMateriel::DebloquerPorte()`),  
   - La lumière s’allume pendant 1 seconde,  
   - L’accès est enregistré dans l’historique (`THistorique::Ajouter()`).  
6. En cas d’erreur, la LED s’allume brièvement.  
7. Le système revient ensuite en attente d’une nouvelle carte.

---

## Structure du projet

```
├── main.cpp
├── tgestion.h
├── tgestion.cpp
├── tcomptesmembres.h
├── tcomptesmembres.cpp
├── thistorique.h
├── thistorique.cpp
├── tlecteur.h
├── tlecteur.cpp
├── tmateriel.h
├── tmateriel.cpp
├── trs232.h
├── trs232.cpp
├── rpi2_exp500_gpio.h
├── rpi2_exp500_gpio.cpp
└── README.md
```

---

## Classes principales

| Classe | Rôle |
|---------|------|
| **tGestion** | Point d’entrée du programme, coordination des composants |
| **tLecteur** | Lecture du numéro de carte via port série |
| **tComptesMembres** | Vérifie si une carte et un code sont valides |
| **THistorique** | Gère l’enregistrement des accès dans un fichier |
| **tMateriel** | Pilote les GPIO (porte, LED, lumière) |
| **tRs232** | Communication série bas-niveau avec le lecteur |

---

## Compilation

Sur Raspberry Pi ou Linux :

```bash
g++ *.cpp -o gestion -std=c++11
```

---

## Exécution

Le programme accède aux GPIO et au port série, donc il doit être lancé avec les droits administrateur :

```bash
sudo ./gestion
```

---

## Fichiers utilisés

| Fichier | Description |
|----------|-------------|
| `comptes.txt` | Contient les informations des membres autorisés |
| `historique.txt` | Journal des accès (date, heure, numéro de carte) |

Ces fichiers doivent être dans le même répertoire que l’exécutable.

---

## Exemple d’exécution

```
Démarrage du système de gestion d’accès
Initialisation du système...
Composants initialisés.
Système prêt. En attente de carte...
Carte détectée : 12345678
Entrez le code : 4321
Accès autorisé.
En attente d’un nouveau passage...
```

---

## Arrêt du système

Le programme tourne en boucle continue.  
Pour l’arrêter, utiliser :  
**Ctrl + C**

---

## Auteur et objectif

Travail réalisé dans le cadre d’un **projet C++ embarqué**.  
Objectif : mise en œuvre d’une architecture orientée objet pour un contrôle d’accès utilisant un lecteur de carte et les GPIO du Raspberry Pi.
