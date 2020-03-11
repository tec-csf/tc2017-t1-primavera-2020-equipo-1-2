#include "simplificacion.h"
using namespace std;

/*
* Instalar before doing anything, it will install python in order to use sympy
* @param none
* @return void 
*/
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
        if(s.at(i) == '*' && s.at(i+1)== '*')
        {
            s.replace(i,2,"^");
        }
    }
    return s;
}
void simplificar(string escPoli, int* cota)
{
    string line, lineSimp; //lineas que va jalando del archivo
    ofstream myOfile;
    ifstream myfile; //input file 
    myOfile.open ("polinomio.txt"); // hace el archivo y lo abre de python
    myOfile<< escPoli <<endl; // escribe esto 
    myOfile.close(); // cierra el documento 
    system("python simply.py");
 
    myfile.open ("listo.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            //cout << line << '\n';
            lineSimp = busqueda(line);
            cout<< lineSimp <<endl;
            *cota = bigO(lineSimp);
            line = busqueda(line);
        }
        myfile.close();
    }
    myfile.close();

}

int bigO(string line)
{
    int max = 1;
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] == '^')
        {
            if (line[i+1] >= max)
            {
                max = line[i+1];
            }
        }
    }
    cout << max;
    return max;
}

void simplificacion()
{
    instalar();
       
}
