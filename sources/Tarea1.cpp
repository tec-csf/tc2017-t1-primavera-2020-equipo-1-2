/*
 *  Tarea 1 - Análisis y diseño de algoritmos
 * 
 *  
 * 
 */
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream archivoPrueba;
    string nombreArchivo, demo;

    cout << "A continuación ingrese el nombre del documento\nDebe de tener la terminación .txt" << endl;

    cin >> nombreArchivo;

    cout << "\nSe ingresó el documento con nombre " << nombreArchivo << "\n" << endl;

    archivoPrueba.open(nombreArchivo.c_str());

    while (archivoPrueba >> demo)
    {
        cout << demo << endl;
    }
    

    return 0;
}