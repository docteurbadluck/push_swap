# push_swap

Projet de l'école 42 — trier une pile de nombres entiers en utilisant un ensemble d'opérations limité, avec le minimum de mouvements possible.

**Score obtenu : 100/100**

---

## Principe

Le programme reçoit une liste d'entiers en argument et affiche sur la sortie standard la séquence d'opérations permettant de trier la pile `a` dans l'ordre croissant, en se servant d'une pile auxiliaire `b`.

## Opérations disponibles

| Opération | Description |
|-----------|-------------|
| `sa` | Échange les 2 premiers éléments de la pile `a` |
| `sb` | Échange les 2 premiers éléments de la pile `b` |
| `ss` | `sa` et `sb` simultanément |
| `pa` | Prend le premier élément de `b` et le pousse sur `a` |
| `pb` | Prend le premier élément de `a` et le pousse sur `b` |
| `ra` | Fait tourner la pile `a` vers le haut (le premier devient le dernier) |
| `rb` | Fait tourner la pile `b` vers le haut |
| `rr` | `ra` et `rb` simultanément |
| `rra` | Fait tourner la pile `a` vers le bas (le dernier devient le premier) |
| `rrb` | Fait tourner la pile `b` vers le bas |
| `rrr` | `rra` et `rrb` simultanément |

## Algorithme

Le programme adapte la stratégie de tri selon la taille de l'entrée :

- **2 éléments** : un seul `sa` si nécessaire
- **3 éléments** : résolution par cas (au plus 2 opérations)
- **4 éléments** : pousse le plus petit sur `b`, trie les 3 restants, puis `pa`
- **5 éléments** : même principe, pousse les 2 plus petits sur `b`
- **> 5 éléments** : algorithme glouton par coût minimal
  1. Pousse 3 éléments sur `b` et les trie en ordre décroissant
  2. Pour chaque élément restant dans `a`, calcule le coût d'insertion optimal dans `b` (en tenant compte du sens de rotation — `ra`/`rra` et `rb`/`rrb` — et des rotations simultanées `rr`/`rrr`)
  3. Envoie l'élément au coût le moins élevé
  4. Répète jusqu'à ce qu'il reste 5 éléments dans `a`
  5. Trie ces 5 éléments avec la stratégie dédiée, puis repousse tout `b` vers `a`

## Compilation

```bash
make        # compile push_swap
make clean  # supprime les fichiers objets
make fclean # supprime les objets et l'exécutable
make re     # recompile depuis zéro
```

## Utilisation

```bash
./push_swap 5 2 8 1 3
```

```bash
# Vérifier le nombre d'opérations
./push_swap 5 2 8 1 3 | wc -l
```

```bash
# Avec des arguments entre guillemets
./push_swap "5 2 8 1 3"
```

