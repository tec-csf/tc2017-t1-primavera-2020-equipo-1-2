#include "printers.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

void PrintTable(vector<string> vecComp, vector<int> contOE, int maxLinea)
{
    int cont = vecComp.size();

    cout <<setfill(' ') << setw(0) << "No. de linea|" << setfill(' ') << setw(maxLinea/2) << "Código";
    cout<< setfill(' ') << setw(maxLinea/2)<<"|" << "OE|" << setfill(' ') << setw(50) <<"Polinomio|"<< endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < cont; i++)
    {
        cout <<setfill(' ') << setw(6) << i + 1 <<setfill(' ') << setw(7)<< "|" 
        << setfill(' ') << setw(maxLinea) << vecComp.at(i) <<"|"<< contOE.at(i) << endl;
    }

    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void impresionMetodos(vector<int> contOE){

    int count = contOE.size();

    cout << count<< "\t"; 
    cout << contOE[count-1] << endl; //imprime last en el vector

}



