#include "oeAnalyzer.h"
#include "printers.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void printArray(vector<int> a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << endl;
    }
}

int findChar(string s, char x)
{
    int count = 0;

    //iterates through each char of line
    for (int i = 0; i < s.size(); i++)
    {
        //compares char with operator
        if (s[i] == x) 
        {
            if (!(s[i] == '+' || s[i] == '-') && s[i+1] == s[i])
            {
                //checks if duplicate sign. Ignores if it is << or >>
            }

            else if (s[i-1] == x )
            {
                //checks if duplicate sign. Ignores if it is.
            }
            else if (s[i-1] == 't')
            {
                //checks if '*' is multiplication or pointer
            }
            else
            {
                //if not any of the above, adds to the elemental operation counter
                count++;
                cout << x;
            }
        }
    }
    return count;
}

int analyzer(queue<string> lineasComp)
{
    //vector that stores all operators that do an elemental operation
    char op[]={'+', '-', '*', '/', '=', '[', '<', '>'};
    vector<char>vectorOP(op,op + sizeof(op)/sizeof(*op));
    string funcFor[]={"for","while"};
    vector<string>vectorFN(funcFor,funcFor + sizeof(funcFor)/sizeof(*funcFor));
    string funcIf[]={"if"};
    vector<string>vectorFUN(funcIf,funcIf + sizeof(funcIf)/sizeof(*funcIf));

    vector<string> vecComp;

    // //que that stores each line of the analized file
    // queue<string> lineasComp;

    // //just for testing
    // lineasComp.push("void oddEvenSort(int* a, int n){");
    // lineasComp.push("int i=2+3;");
    // lineasComp.push("for(int i=(n-1); i>=0; i--){");
    // //lineasComp.push("for(int j=(n-1); j>0; j--){");
    // //lineasComp.push("if(a[j]<a[j-1]){");
    // lineasComp.push("int temp = a[j];");
    // lineasComp.push("a[j]=a[j-1];");
    // //lineasComp.push("a[j-1]=temp;");
    // lineasComp.push("}");
    // lineasComp.push("}");
    // //lineasComp.push("}");
    // //lineasComp.push("}");
    // lineasComp.push("cout << endl");

    //
    int cont = lineasComp.size();

    //elemental operation counter
    vector<int> opCounter;
    int cont1;

    //iterates thtough each line of file
    for(int i=0; i < cont; i++)
    {
        //saves line as string for practicality
        string analize = lineasComp.front();
        vecComp.push_back(lineasComp.front()); 
        cont1 = 0;

        //iterates through operator vector
        for(int i=0; i<vectorOP.size(); i++)
        {
            cont1 += findChar(analize, vectorOP.at(i));
            //checks if said operator is in line
        }

        opCounter.push_back(cont1);
        // cout << cont1;
        // cout << endl;
        int mayor = analize.size();
        PrintTable(vecComp, opCounter, mayor);
        lineasComp.pop();
    }

    printArray(opCounter);


    

    return 0;
}