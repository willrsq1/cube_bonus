#!/bin/bash

# Liste des fichiers à tester
files=(
    "empty_map.cub"
    "invalid_chr.cub"
    "invalid_extra_line.cub"
    "invalid_format.ber"
    "invalid_map.cub"
    "invalid_rgb.cub"
    "invalid_rgb_overflow.cub"
    "invalid_texture_path.cub"
    "invalid_texture_path_2.cub"
    "tab_by_the_right.cub"
)

# Boucle pour tester chaque fichier
for file in "${files[@]}"; do
    full_path="maps/$file"  # Ajoute le préfixe "maps/" au nom de fichier
    echo "Testing $full_path..."
    valgrind ./cube "$full_path"
    echo "============================================="
done
