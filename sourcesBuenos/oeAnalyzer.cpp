#include "oeAnalyzer.h"
#include "printers.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int findChar(string s, char x)
{
    int count = 0;

    //iterates through each char of line
    for (int i = 0; i < s.size(); i++)
    {
        //compares char with operator
        if (s[i] == x) 
        {
            if (!(s[i] == '+' || s[i] == '-') && s[i+1] == s[i])
            {
                //checks if duplicate sign. Ignores if it is << or >>
            }

            else if (s[i-1] == x )
            {
                //checks if duplicate sign. Ignores if it is.
            }
            else if (s[i-1] == 't')
            {
                //checks if '*' is multiplication or pointer
            }
            else
            {
                //if not any of the above, adds to the elemental operation counter
                count++;
            }
        }
    }
    return count;
}

void analisisPrueba(queue<string> lineasComp){

    char op[]={'+', '-', '*', '/', '=', '[', '<', '>'};  //check cout and return
    vector<char> vectorOP(op, op + sizeof(op) / sizeof(*op));                   
    string funcFor[] = {"for", "while"};
    string funcIf[] = {"if"};

    vector<string> vecComp; // se almacena los valores de la cola
    vector<int> contOE;//usado para almacenar Operaciones Elementales

    int cont = lineasComp.size(); 
    int cont1 , mayor = 0;

    for (int i = 0; i < cont; i++) //recorre por todas las filas
    {
        cont1 = 0;
        string analize = lineasComp.front();
        for (int j = 0; j < vectorOP.size(); j++) //recorre y compara las operaciones
        {
            cont1 += findChar(analize, vectorOP.at(j));
            //checks if said operator is in line            
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