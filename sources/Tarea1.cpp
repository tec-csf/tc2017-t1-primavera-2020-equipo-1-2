/*
 *  Tarea 1 - Análisis y diseño de algoritmos
 * 
 *  
 * 
 */
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void AnalisisOracion(string oraciones)
{
    char cOraciones[oraciones.size() + 1]; //cOraciones = oraciones en char
    cout << oraciones << endl;
}

int main(int argc, char const *argv[])
{
    stack<string> lineasComp;
    fstream inputFile;                  //file to read
    string nombreArchivo, oraciones;    //strings meant to initialize the document and it's content

    nombreArchivo = argv[2];

    cout << "\nSe ingresó el documento con nombre " << nombreArchivo << "\n"    //clarifies the document that's been inserted
         << endl;

    inputFile.open(nombreArchivo.c_str());

    if (inputFile.is_open())
    {

        while (getline(inputFile, oraciones))
        {
            AnalisisOracion(oraciones);
            lineasComp.push(oraciones);
        }
        cout<<lineasComp.size()<<endl;
    }
    else
    {
        cout << "No existe el documento" << endl;
    }

    inputFile.close();

    return 0;
}