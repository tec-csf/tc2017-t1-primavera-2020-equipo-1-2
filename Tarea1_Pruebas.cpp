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

vector<int> contOE;

//template <class T>
// documentacion

void PrintTable(vector<string> lineasComp, vector<int> contadorOE);

void impresionMetodos(vector<int> contOE){

    int count = contOE.size();

    cout << count<< "\t"; 
    cout << contOE[count-1] << endl; //imprime last en el vector

}

/*Prueba*/
void analisisPrueba(queue<string> lineasComp){

    string op[] = {"+", "-", "=", "[", " < ", " > ", " * " , " / "};
    vector<string> vectorOP(op, op + sizeof(op) / sizeof(*op));                   
    string funcFor[] = {"for", "while"};
    vector<string> vectorFN(funcFor, funcFor + sizeof(funcFor) / sizeof(*funcFor));
    string funcIf[] = {"if"};
    vector<string> vectorFUN(funcIf, funcIf + sizeof(funcIf) / sizeof(*funcIf));
    queue<int> contadorOE;

    vector<string> vecComp; // se almacena los valores de la cola
    vector<int> contOE;//usado para almacenar Operaciones Elementales

    int cont = lineasComp.size(); 
    int cont1 = 0;

    for (int i = 0; i < cont; i++) //recorre por todas las filas
    {
        cont1 = 0;
        string analize = lineasComp.front();
        for (int i = 0; i < vectorOP.size(); i++) //recorre y compara las operaciones
        {
            int found = analize.find(vectorOP.at(i));
            if (found >= 0)
            {
                cont1++;
            }
        }
        //cout << "Si esta fuera del for" << endl;
        //cout << contOE.size() << endl;
    
        contOE.push_back(cont1);
        
        vecComp.push_back(lineasComp.front()); //usado para insertar los valores de la cola en el vector
        lineasComp.pop(); //saca los valores de la cola, COMO POR??? :D 
    }


    impresionMetodos(contOE);
    //cout << vecComp << endl;

}

void PrintTable(vector<string> lineasComp, vector<int> contadorOE)
{
    int cont = lineasComp.size();

    cout << "No. de linea\t | \t\t\t\t\t\t\tCódigo\t\t\t\t\t\t\t\t | OE\t | Polinomio |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 1; i <= cont; i++)
    {
        cout << i << "            \t |" << lineasComp.front() << endl;
        lineasComp.pop_back();

        cout << i << "             \t" << contadorOE.front() << endl;
        contadorOE.pop_back();
    }

    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

int main(int argc, char const *argv[])
{
    string op[] = {"+", "-", "++", "--", "=", "[]"};
    vector<string> vectorOP(op, op + sizeof(op) / sizeof(*op));
    string func[] = {"for", "if", "while"};
    vector<string> vectorFN(func, func + sizeof(func) / sizeof(*func));

    queue<string> lineasComp;
    fstream inputFile;               //file to read
    string nombreArchivo, oraciones; //strings meant to initialize the document and it's content

    nombreArchivo = argv[2];

    cout << "\nSe ingresó el documento con nombre " << nombreArchivo << "\n" //clarifies the document that's been inserted
         << endl;

    inputFile.open(nombreArchivo.c_str());

    if (inputFile.is_open())
    {

        while (getline(inputFile, oraciones))
        {
            lineasComp.push(oraciones); // once the line is adding it to a queue
            analisisPrueba(lineasComp);
        }
        
        //analisisPrueba(lineasComp);
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