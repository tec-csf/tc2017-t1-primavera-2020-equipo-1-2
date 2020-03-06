#include "printers.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>

void impresionMetodos(vector<int> contOE){

    int count = contOE.size();

    cout << count<< "\t"; 
    cout << contOE[count-1] << endl; //imprime last en el vector

}

void PrintTable(vector<string> vecComp, vector<int> contOE)
{
    int cont = vecComp.size();

    cout <<setfill(' ') << setw(0) << "No. de linea|" << setfill(' ') << setw(50) << "Código|"<< setfill(' ') << setw(10) << "OE|" << setfill(' ') << setw(50) <<"Polinomio|"<< endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < cont; i++)
    {
        cout <<setfill(' ') << setw(6) << i + 1 <<setfill(' ') << setw(7)<< "|" << setfill(' ') << setw(50) << vecComp.at(i) << setfill(' ') << setw(50) << contOE.at(i) << endl;
    }

    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

