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
#include <vector>

using namespace std;

void AnalisisOracion(string oraciones)
{
    char cOraciones[oraciones.size() + 1];  //cOraciones = oraciones en char
    //cout << oraciones << endl; 
}

int main()
{
    fstream inputFile;
    string nombreArchivo, oraciones;
    
    cout << "Ingresa el nombre del documento a continuación:";
    cin >> nombreArchivo;           
    cout << "\nSe ingresó el documento con nombre " << nombreArchivo << "\n" << endl;

    inputFile.open(nombreArchivo.c_str());

    if(inputFile.is_open()){
        
        while (getline(inputFile, oraciones))
        {
            AnalisisOracion(oraciones);
        }
        
    }else
    {
        cout << "File not found!" << endl;
    }
    
    
    inputFile.close();

    return 0;
}