#include "printers.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

void PrintTable(vector<string> vecComp, vector<int> contOE, int maxLinea)
{
    int cont = vecComp.size();

    cout <<setfill(' ') << setw(0) << "No. de linea|" << setfill(' ') << setw((maxLinea+6)/2) << "Código";
    cout<< setfill(' ') << setw(maxLinea/2+10)<<"|"<<setfill(' ') << setw(10)<< "OE" <<setfill(' ') << setw(10)  <<"|"<< setfill(' ') << setw(20) <<"Polinomio|"<< endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < cont; i++)
    {
        cout <<setfill(' ') << setw(6) << i + 1 <<setfill(' ') << setw(7)<< "|" 
        << setfill(' ') << setw(maxLinea+10) << vecComp.at(i) <<"|"<< setfill(' ') << setw(10) << contOE.at(i)<< setfill(' ') << setw(10) <<"|"<< endl;
    }

    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void impresionMetodos(vector<int> contOE){

    int count = contOE.size();

    cout << count<< "\t"; 
    cout << contOE[count-1] << endl; //imprime last en el vector

}



