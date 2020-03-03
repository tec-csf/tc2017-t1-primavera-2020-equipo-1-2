#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    string op[]={"+","-","++","--","=","[]"};
    vector<string>vectorOP(op,op + sizeof(op)/sizeof(*op));
    string func[]={"for","if","while"};
    vector<string>vectorFN(func,func + sizeof(func)/sizeof(*func));

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

    for(int i=0; i < 2; i++){
        string analize = lineasComp.front();
        cout << "Fuera del primer for" << endl;
        for(int i=0; i < vectorFN.size(); i++){
            cout << "Dentro del for" << endl;
            bool found = analize.find(vectorFN.at(i));
            cout << "Fuera del if" << endl;
            if(found != false){
                cout << "yay";
                cout << endl;
            }
            cout << "Después del if" << endl;
        }
        lineasComp.pop();
    }

    return 0;
}