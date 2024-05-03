#!/bin/bash

# Controllo se sono stati passati argomenti
if [ $# -eq 0 ]; then
	echo "Errore: Nessun argomento passato."
	exit 1
fi

# Controllo se sono stati passati piu' di 3 argomenti
if [ $# -ge 4 ]; then
        echo "Errore: Troppi argomenti passati."
        exit 1
fi


# Ciclo per ogni argomento
for arg in "$@"; do
	# Stampo l'argomento corrente
	echo "Argomento  $((count + 1)): $arg"
	# Incremento il contatore
	count=$((count + 1))
done

exit 0
