#!/bin/bash

# Vérifiez que le script Perl est disponible
if ! command -v perl &> /dev/null
then
    echo "Perl n'est pas installé. Veuillez installer Perl pour utiliser ce script."
    exit 1
fi

# Vérifiez que le nombre d'arguments est correct
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <largeur> <hauteur> <densité>"
    exit 1
fi

# Arguments
WIDTH=$1
HEIGHT=$2
DENSITY=$3

# Variables pour les caractères
CHAR1='.'
CHAR2='0'
CHAR3='%'

# Créer le nom du fichier de sortie
OUTPUT_FILE="src/${HEIGHT}${CHAR1}${CHAR2}${CHAR3}"

# Créer le dossier maps s'il n'existe pas
mkdir -p maps

# Supprimer le fichier existant s'il existe
if [ -f "$OUTPUT_FILE" ]; then
    rm "$OUTPUT_FILE"
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
perl "$PERL_SCRIPT_FILE" "$WIDTH" "$HEIGHT" "$DENSITY" "$CHAR1" "$CHAR2" "$CHAR3" > "$OUTPUT_FILE"

# Supprimer le script Perl temporaire
rm "$PERL_SCRIPT_FILE"

echo "Carte générée et sauvegardée dans $OUTPUT_FILE"