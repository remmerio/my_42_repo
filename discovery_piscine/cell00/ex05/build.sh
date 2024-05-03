#!/bin/bash

# Controllo se sono stati passati argomenti
if [ $# -eq 0 ]; then
        echo "Errore: Nessun argomento passato."
        exit 1
fi

# Ciclo per ogni argomento
for arg in "$@"; do
        # creo l'argomento corrente
        mkdir   ex$arg
       #count=$((count + 1))
done

exit 0

               
