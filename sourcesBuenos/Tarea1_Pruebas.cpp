/*
 *  Tarea 1 - Análisis y diseño de algoritmos
 * 
 *  
 * 
 */
#include "oeAnalyzer.h"
#include "printers.h"
#include <stdio.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

//template <class T>

/*Prueba*/

int main(int argc, char const *argv[])
{
    string op[] = {"+", "-", "++", "--", "=", "[]"};
    string func[] = {"for", "if", "while"};

    queue<string> lineasComp;
    fstream inputFile;               //file to read
    string nombreArchivo, oraciones; //strings meant to initialize the document and it's content

    nombreArchivo = argv[2];

    cout << "\nSe ingresó el documento con nombre " << nombreArchivo << "\n" //clarifies the document that's been inserted
         << endl;

    inputFile.open(nombreArchivo.c_str());

    if (inputFile.is_open())
    {

        while (getline(inputFile, oraciones))
        {
            lineasComp.push(oraciones); // once the line is adding it to a queue
        }
        analisisPrueba(lineasComp);
    }
    else
    {
        cout << "No existe el documento" << endl;
    }

    inputFile.close();

    return 0;
}