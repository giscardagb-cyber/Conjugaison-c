# Conjugaison en C

Programme en ligne de commande qui conjugue un verbe français du **1er ou du 2ᵉ groupe**
à plusieurs temps et enregistre le résultat dans un fichier texte.

## Fonctionnalités

- Détection du groupe du verbe (`-er` → 1er groupe, `-ir` → 2ᵉ groupe)
- 8 temps : présent, passé simple, imparfait, futur simple, passé composé,
  passé antérieur, plus-que-parfait, futur antérieur
- Cas particuliers du 1er groupe : `manger` → *nous mangeons*, `commencer` → *nous commençons*,
  `payer` → *je paie*, `appeler` / `jeter` → *j'appelle* / *je jette*
- Élision (*j'aime*) et verbes pronominaux (*se laver* → *je me lave*)
- Les conjugaisons sont enregistrées dans `resultats.txt` ; un verbe déjà conjugué n'est pas ajouté deux fois

Un exemple de sortie est fourni dans [`exemple_resultats.txt`](exemple_resultats.txt).

## Compiler et lancer

```bash
make
./conjugaison
```

Sans `make` :

```bash
gcc -Wall -Wextra -o conjugaison main.c recherche.c conjugaison_1er_groupe.c conjugaison_2eme_groupe.c
```

## Structure

| Fichier | Rôle |
|---|---|
| `main.c` | Saisie, validation, choix du groupe |
| `conjugaison.h` | Prototypes et constantes partagés |
| `conjugaison_1er_groupe.c` | Conjugaison des verbes en `-er` |
| `conjugaison_2eme_groupe.c` | Conjugaison des verbes en `-ir` (type *finir*) |
| `recherche.c` | Vérifie si un verbe est déjà dans le fichier de résultats |

## Limites connues

- `aller` et les verbes irréguliers ne sont pas gérés.
- Tous les verbes en `-ir` sont traités comme des verbes du 2ᵉ groupe (*finir* ✔, *partir* ✘).
- Les temps composés utilisent toujours l'auxiliaire *avoir* (pas de *je suis allé*, ni pour les verbes pronominaux).
- Pas d'accents circonflexes au passé simple (*nous parlames*).
- Le fichier de sortie est en UTF-8.

## Pistes d'amélioration

- Ajouter une liste de verbes irréguliers (*être*, *avoir*, *aller*, *partir*…)
- Gérer l'auxiliaire *être*
- Factoriser les quatre boucles de temps du 1er groupe avec une seule fonction
- Ajouter des tests automatisés
