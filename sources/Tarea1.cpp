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

void PrintTable(stack<string> lineasComp)
{
    cout << lineasComp.size()<<endl;
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
<<<<<<< HEAD
            //AnalisisOracion(oraciones);
            lineasComp.push(oraciones);
            PrintTable(lineasComp);
=======
            AnalisisOracion(oraciones);
            lineasComp.push(oraciones); // once the line is adding it to a stack
>>>>>>> 088d000d47b6e0ea7ffec9de6955f11d2729bd82
        }
        //cout<<lineasComp.size()<<endl;
    }
    else
    {
        cout << "No existe el documento" << endl;
    }

    inputFile.close();

    return 0;
}