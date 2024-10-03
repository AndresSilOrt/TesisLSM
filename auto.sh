#!/bin/bash
>orden.txt
>salida.txt
# Paso 1: Recorrer cada archivo 1.txt a 5.txt
for i in {1..5}
do
    # Paso 2: Copiar el contenido de cada archivo a datos.txt
    cp "$i.txt" datos.txt

    # Paso 3: Ejecutar el programa a.out que genera el archivo salida.txt
    ./a.out

    # Paso 4: Crear el archivo correspondiente M*.txt
    next_file="M$i.txt"

    # Paso 5: Copiar el contenido de salida.txt al archivo M*.txt
    cp salida.txt "$next_file"

    # Mensaje opcional de éxito
    echo "Archivo $i.txt procesado y guardado como $next_file"
done

