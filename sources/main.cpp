#include <stdlib.h>
#include <string>
#include <fstream>
#include<iostream>
using namespace std;

int main()
{
    string line;
    ifstream myfile;

    ofstream myOfile;
    myOfile.open ("polinomio.txt");
    myOfile << "(3*n-1)*(3*n +1)";
    myOfile.close();

    string cadena = "python hello.py ";

    system("pip install sympy");
    system("python hello.py");
 
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