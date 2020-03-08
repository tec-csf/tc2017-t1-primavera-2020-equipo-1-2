#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    string op[] = {"+", "-", "++", "--", "=", "[]"};
    vector<string> vectorOP(op, op + sizeof(op) / sizeof(*op));
    string func[] = {"for", "if", "while"};
    vector<string> vectorFN(func, func + sizeof(func) / sizeof(*func));

    queue<string> lineasComp;
    lineasComp.push("void oddEvenSort(int* a, int n){");
    lineasComp.push("for(int i=(n-1); i>=0; i--){");
    lineasComp.push("for(int j=(n-1); j>0; j--){");
    lineasComp.push("if(a[j]<a[j-1]){");
    lineasComp.push("int temp = a[j];");
    lineasComp.push("a[j]=a[j-1];");
    lineasComp.push("a[j-1]=temp;");
    lineasComp.push("}");
    lineasComp.push("}");
    lineasComp.push("}");
    lineasComp.push("}");

    int cont = lineasComp.size();
    //bool found = false;

    for (int i = 0; i < cont; i++)
    {
        string analize = lineasComp.front();
        for (int i = 0; i < vectorFN.size(); i++)
        {
            int found = analize.find(vectorFN.at(i));
            if (found >= 0)
            {
                cout << vectorFN.at(i);
                cout << endl;
            }
        }
        lineasComp.pop();
    }

    return 0;
}