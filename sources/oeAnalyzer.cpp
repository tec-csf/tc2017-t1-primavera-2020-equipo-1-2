#include "oeAnalyzer.h"
#include "printers.h"
#include "simplificacion.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
int vr, flag; //saves first line of while, for and if 
int lineaF; //saves last line of while, for and if
string Pf[]={"for", "while", "if"};  //TODO: check cout and return Possible Functions
vector<string> functions(Pf, Pf + sizeof(Pf) / sizeof(*Pf)); //turns Pf into vector
size_t foundW , foundF, foundI;

/* findKey: this method finds the kewords of each line 
* Note: It won't count the keywords specified in the vector keywords
* @param string contains the line of the anlyzed code
* @return pos it returns the position of the keyword
*/
int findKey(string str, int* add)
{
    string kw[]={"int", "char", "string", "double", "bool", "long", "float", "class"}; //keywords that won't be counted
    vector<string> keywords(kw, kw + sizeof(kw) / sizeof(*kw)); 
    size_t found;
    int pos;
    for (int i = 0; i < keywords.size(); ++i)
    {
        found = str.find(keywords[i]);
        if (found != string::npos)
        {
            pos = static_cast<int>(found);
            return pos;
        }
    }
    return -1;
}
/* findSequence: this method gets the times a function is repeated
* @param string contains the line of the anlyzed code
* @return polinomio it returns the polinomial string of the function
*/
string findSequence(string s, int cont1)
{
    string polinomio = " ";
    polinomio = "*n";
    return polinomio;
}
/* findChar: this method finds the elemental Operations in each line
* Note: It won't count the keywords specified
* @param string contains the line of the anlyzed code
* @return int which contains the number of elemental operations 
*/
int findChar(string s)
{
    int count = 0;
    int add;
    bool ignore = false;
    bool quotes = false;

    //iterates through each char of line
    for (int i = 0; i < s.size(); i++)
    {
        //checks if quotes
        if (s[i] == '"')
        {
            //if quote found, check if it opens or closes string
            quotes = !quotes;
        }
        //if start of quotes, ignore chars. If end of quotes, start analyzing chars again
        if(!quotes)
        {  
            switch(s[i])
            {
                case '#':
                    ignore = true;
                    break;
                case '/':
                    if (s[i+1] == '/')
                    {
                        ignore = true;
                    }
                    break;
                case '+':
                    if (!(s[i-1] == '+'))
                    {
                        count++;
                    }
                    break;
                case '-':
                    if (!(s[i-1] == '-' || s[i+1] == '>'))
                    {
                        count++;
                    }
                    break;
                case '*':
                    if (s[i-1] == '*' || s[i+1] == '*')
                    {
                        //pointer case. ignore
                    }
                    else if(s[i-1] == '>' || s[i-2] == '>')
                    {
                        //pointer case. ignore
                    }
                    else if (findKey(s, &add) > (i-5))
                    {
                        //pointer case. ignore
                    }
                    else
                    {
                        count++;
                    }
                    
                    
                    break;
                case '=':
                    if (!(s[i-1] == '>' || s[i-1] == '<' || s[i-1] == '='))
                    {
                        count++;
                    }
                    break;
                case '[':
                    count++;
                    break;
                case '<':
                    if (s[i-1] == '<' || s[i+1] == '<' || (s[i+1] == 'T' || s[i+2] == '>'))
                    {
                        //if it is part of an input stream, references object or is part of template, ignore
                    }
                    else if (findKey(s, &add) < (i+2) && findKey(s, &add) >= i)
                    {
                        //template case. ignore
                        cout << findKey(s, &add) << endl;
                    }
                    else
                    {
                        count++;
                    }
                    break;
                case '>':
                    if (s[i-1] == '>' || s[i+1] == '>' || s[i-1] == '-' || (s[i-1] == 'T' || s[i-2] == '<'))
                    {
                        //if it is part of an input stream, or is part of template, ignore
                    }
                    else if (findKey(s, &add) > (i-5) && findKey(s, &add) <= i)
                    {
                        //template case. ignore
                    }
                    else
                    {
                        count ++;
                    }

                    break;
                case '%':
                    count++;
                    break;
            }   
        }

        if (ignore)
        {
            //stops analyzing line if any of the cases stated above is true
            break;
        }
    }
    return count;
}
/* findChar: this method finds how many lines are between a while, if or for method
* Note: It starts reading on the line with the function
* @param int gives us the first line to analize
* @return int which contains the number of the last line inside the function
*/
int analisisCorchetes(int lineaI, vector<string> vecComp){
    int corch=0;
    int cont = vecComp.size(); 
    int cont1;
    for(int i=lineaI; i<cont; i++){
        cont1 = 0;

        //nos da la linea a prtir de la primera posición
        string read = vecComp.at(i);

        //empieza a sumar corchetes
        if(read.find("{") != string::npos){
            corch++;
        }
        else if(read.find("}") != string::npos){
            corch--;
        }
        if(corch==0 && i!=lineaI){
            return i;
        }
    }
    return -1;
}
/* findPoli: this method checks if a function exists in the file
* Note: Gives us different values of flag for the different functions
* @param string contains the line of the analyzed code, int gives us the line to analyze
* @return void
*/
void findPoli(string s, int linea, vector<string> vecComp, int cont1)
{
    for (int i = 1; i <= functions.size(); ++i)
    {
        foundF = s.find(functions[0]);
        foundW = s.find(functions[1]);
        foundI = s.find(functions[2]);
        //in case there is a while flag will be 1
        if (foundW != string::npos) 
        {
            vr = linea; //guarda la linea en una variable universal
            lineaF = analisisCorchetes(linea, vecComp);
            flag = 1;
            break;
        }
        //in case there is a For flag will be 2
        else if (foundF != string::npos)
        {
            vr = linea; //guarda la linea en una variable universal
            lineaF = analisisCorchetes(linea, vecComp);
            flag = 2;
            break;
        }
        //in case there is an "if" flag will be set 3
        else if (foundI != string::npos)
        {
            vr = linea; //guarda la linea en una variable universal
            lineaF = analisisCorchetes(linea, vecComp);
            flag = 3;
            break;
        }
        flag = -1;
    }
}
/* analisisPrueba: this method iterates over the lines of code 
* @param queue that containes the file to be analyze 
* @return void
*/
void analisisPrueba(queue<string> lineasComp){

    char op[]={'#', '/', '+', '-', '*', '=', '[', '<', '>'};  //TODO: check cout and return
    vector<char> vectorOP(op, op + sizeof(op) / sizeof(*op));    
    /*string funcFor[]={"for","while"};
    vector<string>vectorFN(funcFor,funcFor + sizeof(funcFor)/sizeof(*funcFor));
    string funcIf[]={"if"};
    vector<string>vectorFUN(funcIf,funcIf + sizeof(funcIf)/sizeof(*funcIf));*/
                

    vector<string> vecComp; // for saving queue elements in a vector
    vector<int> contOE;//for saving elemental operations in each line
    vector<string> poli;

    int cont = lineasComp.size(); 
    int cont1 , mayor = 0;
    string hilo = " ";

    for(int i=0; i<cont; i++){
        vecComp.push_back(lineasComp.front()); //saves line in queue before being deleted
        lineasComp.pop(); //removes line from queue
    }

    for (int i = 0; i < cont; i++) //iterates over each line
    {
        cont1 = 0;

        //saves line as string
        string analize = vecComp.at(i);

        //checks if said operator is in line    
        cont1 += findChar(analize);
        
        //tries to make the polynomial
        findPoli(analize, i, vecComp, cont1); //tengo que poner un int para igualarlo, y al final sumarlo
        for(int i=vr; i<lineaF; i++){ //lee de la primera linea que tiene una función a la última
            hilo = findSequence(analize, cont1);
        }
        if(lineaF == -1){
            hilo = " ";
        }

        //checks thre length of the largest line        
        if(analize.size()> mayor)
        {
            mayor = analize.size();
        }
    
        contOE.push_back(cont1); //saves elemental operation count in the line
        poli.push_back(to_string(cont1)+hilo);
    }

    PrintTable(vecComp, contOE, mayor, poli);
    
}