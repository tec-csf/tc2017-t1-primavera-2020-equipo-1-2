/*
 *  Tarea 1 - Análisis y diseño de algoritmos
 * 
 *  
 * 
 */
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
template <class T>

void PrintTable(queue<T> lineasComp)
{
    int cont = lineasComp.size();

    cout << "No. de linea\t | \t\t\t\t\t\t\tCódigo\t\t\t\t\t\t\t\t | OE\t | Polinomio\t |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 1; i <= cont; i++)
    {
        cout << i << "            \t |" << lineasComp.front() <<endl;
        lineasComp.pop();
    }
    
}

int main(int argc, char const *argv[])
{
    string op[]={"+","-","++","--","=","[]"};
    vector<string>vectorOP(op,op + sizeof(op)/sizeof(*op));
    string func[]={"for","if","while"};
    vector<string>vectorFN(func,func + sizeof(func)/sizeof(*func));

    queue<string> lineasComp;
    fstream inputFile;                  //file to read
    string nombreArchivo, oraciones;    //strings meant to initialize the document and it's content

    nombreArchivo = argv[2];

    cout << "\nSe ingresó el documento con nombre " << nombreArchivo << "\n"    //clarifies the document that's been inserted
         << endl;

    inputFile.open(nombreArchivo.c_str());

    if (inputFile.is_open())
    {

        while (getline(inputFile, oraciones))
        {
            lineasComp.push(oraciones); // once the line is adding it to a queue
        }
            PrintTable(lineasComp);
        //cout<<lineasComp.size()<<endl;
    }
    else
    {
        cout << "No existe el documento" << endl;
    }

    inputFile.close();

    return 0;
}