#!/bin/bash

# Vérifiez que le script Perl est disponible
if ! command -v perl &> /dev/null
then
    echo "Perl n'est pas installé. Veuillez installer Perl pour utiliser ce script."
    exit 1
fi

# Vérifiez que le nombre d'arguments est correct
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <nombre_de_cartes>"
    exit 1
fi

# Nombre de cartes à générer
NUM_MAPS=$1

# Variables pour les limites des dimensions et densité
MIN_WIDTH=10
MAX_WIDTH=250
MIN_HEIGHT=10
MAX_HEIGHT=250
MIN_DENSITY=1
MAX_DENSITY=35

# Listes pour les caractères
CHARS1=('.' ',' '-' '_')
CHARS2=('0' 'p' 'o' '#')
CHARS3=('%' '*' '@' '$')
# Obtenir le chemin absolu du dossier où se trouve le script
SCRIPT_DIR=$(cd "$(dirname "$0")"; pwd)

# Déterminer le prochain numéro de génération
GEN_NUM=1
SRC_DIR="$SCRIPT_DIR/src"
while [ -d "$SRC_DIR/gen${GEN_NUM}" ]; do
    GEN_NUM=$((GEN_NUM + 1))
done

# Créer le dossier de génération
GEN_DIR="$SRC_DIR/gen${GEN_NUM}"
mkdir -p "$GEN_DIR"

# Fonction pour générer une carte
generate_map() {
    local map_num=$1

    # Générer des dimensions et une densité aléatoires
    local width=$((RANDOM % (MAX_WIDTH - MIN_WIDTH + 1) + MIN_WIDTH))
    local height=$((RANDOM % (MAX_HEIGHT - MIN_HEIGHT + 1) + MIN_HEIGHT))
    local density=$((RANDOM % (MAX_DENSITY - MIN_DENSITY + 1) + MIN_DENSITY))

    # Sélectionner des caractères aléatoires à partir des listes
    local char1=${CHARS1[$((RANDOM % ${#CHARS1[@]}))]}
    local char2=${CHARS2[$((RANDOM % ${#CHARS2[@]}))]}
    local char3=${CHARS3[$((RANDOM % ${#CHARS3[@]}))]}

    # Créer le nom du fichier de sortie
    local output_file="$GEN_DIR/map_${map_num}_${width}x${height}_${density}.txt"

    # Supprimer le fichier existant s'il existe
    if [ -f "$output_file" ]; then
        rm "$output_file"
    fi

    # Script Perl pour générer la carte
    PERL_SCRIPT=$(cat << 'EOF'
#!/usr/bin/perl
use warnings;
use strict;
die "program x y density char1 char2 char3" unless (scalar(@ARGV) == 6);
my ($x, $y, $density, $char1, $char2, $char3) = @ARGV;
print "$y$char1$char2$char3\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print "$char2";
        }
        else {
            print "$char1";
        }
    }
    print "\n";
}
EOF
    )

    # Enregistrer le script Perl temporairement
    PERL_SCRIPT_FILE=$(mktemp)
    echo "$PERL_SCRIPT" > "$PERL_SCRIPT_FILE"
    chmod +x "$PERL_SCRIPT_FILE"

    # Générer la carte et la sauvegarder dans le fichier de sortie
    perl "$PERL_SCRIPT_FILE" "$width" "$height" "$density" "$char1" "$char2" "$char3" > "$output_file"

    # Supprimer le script Perl temporaire
    rm "$PERL_SCRIPT_FILE"

    echo "Carte $map_num générée et sauvegardée dans $output_file"
    
    # Lancer le script bsq avec la carte en argument
    ./bsq "$output_file"
}

# Boucle pour générer le nombre de cartes demandé
for ((i=1; i<=NUM_MAPS; i++))
do
    generate_map $i
done