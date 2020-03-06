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
    cout << oraciones << endl; 
}

int main(int argc, char const *argv[])
{
    fstream inputFile;
    string nombreArchivo, oraciones;
    
    if (argv == 0)
    {
        printf("No se insertó un valor después del '-i'\n");
    }
    
    nombreArchivo = argv[2]; 
     
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