#include "printers.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "simplificacion.h"

/* printTable: this method prints the lines of code
number of elemental operations and number of lines in the specified format
* @param VecComp containes the code analyzed, contOE has the number of elemental operations in each line
and maxLinea is the size of the longest line 
* @return void (prints table)
*/
void PrintTable(vector<string> vecComp, vector<int> contOE, int maxLinea, vector<string> poli)
{
    int cont = vecComp.size();
    int bigO;

    //table formatting
    cout <<setfill(' ') << setw(0) << "No. de linea|" << setfill(' ') << setw((maxLinea+6)/2) << "Código";
    cout<< setfill(' ') << setw(maxLinea/2+10)<<"|"<<setfill(' ')<< setw(4);
    cout<< "OE" <<setfill(' ') << setw(2)  <<"|"<< setfill(' ') << setw(20) <<"Polinomio|"<< endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;

    //iterates over queue containing file lines. Prints number of line and how many elemental operations are detected in each line
    for (int i = 0; i < cont; i++)
    {
        cout <<setfill(' ') << setw(6) << i + 1 <<setfill(' ') << setw(7)<< "|" 
        << setfill(' ') << setw(maxLinea+10) << vecComp.at(i) <<"|"<< setfill(' ') << setw(4) << contOE.at(i);
        cout<< setfill(' ') << setw(2) <<"|"<< setfill(' ') << setw(20)<< poli.at(i) <<endl;
    }

    cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
    string poliSt = " ";

    //iterates and sums all polynomials
    for(int i=0; i<poli.size()-1; ++i){
        poliSt += "("+poli.at(i)+")+";
        
    }
    poliSt += "("+poli.at(poli.size()-1)+")";
    cout << "Polinimio: T(n)= ";

    //simplifies resulting polynomial
    simplificar(poliSt, &bigO);
    cout <<endl;
    cout << "Complejidad: O(n^"<<bigO<<")"<<endl;
}


