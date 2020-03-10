#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


void instalar()
{
    system("sudo apt-get update");
    system("sudo apt install python3-pip3");
    system("pip install --user sympy");

}
string busqueda(string s)
{
    for (int i = 0; i< s.size(); i++)
    {
        if(s.at(i) == '*')
        {
            if (s.at(i+1)== '*')
            {
                s.replace(i,2,"^");
            }
        }
    }
    return s;
}
int main()
{
    string line; //lineas que va jalando del archivo
    ofstream myOfile;
    ifstream myfile; //input file 
    myOfile.open ("polinomio.txt"); // hace el archivo y lo abre de python
    myOfile<<"(3*n-1)*(3*n +1)"<<endl; // escribe esto 
    myOfile.close(); // cierra el documento 
    instalar();

    system("python simply.py");
 
    myfile.open ("listo.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            cout << line << '\n';
            busqueda(line);
            
        }
        myfile.close();
    }
    myfile.close();
}
