/*
 *  Tarea 1 - Análisis y diseño de algoritmos
 * 
 *  
 * 
 */
#include "oeAnalyzer.h"
#include <stdio.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

vector<int> contOE;

//template <class T>
// documentacion

/*Prueba*/
void analisisPrueba(queue<string> lineasComp){

    string op[] = {"+", "-", "=", "[", " < ", " > ", " * " , " / ","cout","return"};
    vector<string> vectorOP(op, op + sizeof(op) / sizeof(*op));                   
    string funcFor[] = {"for", "while"};
    string funcIf[] = {"if"};
    queue<int> contadorOE;

    vector<string> vecComp; // se almacena los valores de la cola
    vector<int> contOE;//usado para almacenar Operaciones Elementales

    int cont = lineasComp.size(); 
    int cont1 , mayor = 0;

    for (int i = 0; i < cont; i++) //recorre por todas las filas
    {
        cont1 = 0;
        string analize = lineasComp.front();
        for (int i = 0; i < vectorOP.size(); i++) //recorre y compara las operaciones
        {
            int found = analize.find(vectorOP.at(i));
            if (found >= 0)
            {
                cont1++;
            }
            
        }
        if(analize.size()> mayor)
        {
            mayor = analize.size();
        }
    
        contOE.push_back(cont1);
        
        vecComp.push_back(lineasComp.front()); //usado para insertar los valores de la cola en el vector
        lineasComp.pop(); //saca los valores de la cola, COMO POR??? :D 
    }


    PrintTable(vecComp, contOE, mayor);

}

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
        analyzer(lineasComp);
    }
    else
    {
        cout << "No existe el documento" << endl;
    }

    inputFile.close();

    return 0;
}