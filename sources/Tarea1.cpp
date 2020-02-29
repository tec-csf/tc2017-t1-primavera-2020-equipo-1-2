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

void AnalisisOracion(string oraciones)
{
    char cOraciones[oraciones.size() + 1];
    cout << oraciones << endl; 
}

int main()
{
    fstream inputFile;
    string nombreArchivo, outputFile;
    string oraciones;
    
    cout << "Ingresa el nombre del documento a continuación:" << endl;
    cin >> nombreArchivo;           
    cout << "\nSe ingresó el documento con nombre " << nombreArchivo << "\n" << endl;

    ofstream newFile;

    inputFile.open(nombreArchivo.c_str());
    int i = 0;

    if(inputFile.is_open()){
        
        while (getline(inputFile, oraciones))
        {
            AnalisisOracion(oraciones);
            i++;
            cout << i << endl;
        }
        
    }else
    {
        cout << "File not found!" << endl;
    }
    
    
    inputFile.close();

    return 0;
}