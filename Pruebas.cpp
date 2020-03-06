#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    string op[]={"+","-","=","[", "<", ">", "*"};
    vector<string>vectorOP(op,op + sizeof(op)/sizeof(*op));
    string funcFor[]={"for","while"};
    vector<string>vectorFN(funcFor,funcFor + sizeof(funcFor)/sizeof(*funcFor));
    string funcIf[]={"if"};
    vector<string>vectorFUN(funcIf,funcIf + sizeof(funcIf)/sizeof(*funcIf));

    queue<string> lineasComp;
    //lineasComp.push("void oddEvenSort(int* a, int n){");
    //lineasComp.push("for(int i=(n-1); i>=0; i--){");
    //lineasComp.push("for(int j=(n-1); j>0; j--){");
    /*lineasComp.push("if(a[j]<a[j-1]){");
    lineasComp.push("int temp = a[j];");
    lineasComp.push("a[j]=a[j-1];");
    lineasComp.push("a[j-1]=temp;");
    lineasComp.push("}");
    lineasComp.push("}");
    lineasComp.push("}");
    lineasComp.push("}");*/
    lineasComp.push("cout << endl");
    lineasComp.push("int i=2+3;");

    int cont = lineasComp.size();
    int cont1 = 0;
    vector <string> oes;

    for(int i=0; i < cont; i++){
        string analize = lineasComp.front();
        for(int i=0; i<vectorOP.size(); i++){
            int found = analize.find(vectorOP.at(i));
            int find = analize.find("<<");
            if(find >= 0){
                break;
            }
            else if(found >= 0){
                cont1++;
            }
        }
        cout << cont1;
        cout << endl;


        /*for(int i=0; i < vectorFN.size(); i++){
            int found = analize.find(vectorFN.at(i));
            if(found >= 0){ //si es mayor a 0 está en la línea
                oes.push_back(vectorFN.at(i));
                for(int i=0; i < vectorOP.size(); i++){
                    int found = analize.find(vectorOP.at(i));
                    if(found >= 0){

                    }
                }
                cout << vectorFN.at(i);
                cout << endl;
            }
        }*/
        lineasComp.pop();
    }

    return 0;
}