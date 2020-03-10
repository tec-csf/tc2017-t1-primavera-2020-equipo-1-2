#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;



int main()
{
    string line; //lineas que va jalando del archivo
    ofstream myOfile;
    ifstream myfile; //input file 
    myOfile.open ("polinomio.txt"); // hace el archivo y lo abre
    myOfile<<"(3*n-1)*(3*n +1)"<<endl; // escribe esto 
    myOfile.close(); // cierra el documento 

    system("sudo apt-get update");
    system("sudo apt install python3-pip3");
    system("pipinstall --user sympy"); // instalación py
 
    myfile.open ("file.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
        cout << line << '\n';
        }
        myfile.close();
    }
    myfile.close();
}