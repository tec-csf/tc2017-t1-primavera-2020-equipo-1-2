#include "oeAnalyzer.h"
#include "printers.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int findKey(string str, int* add)
{
    vector<string> keywords = {"int", "char", "string", "double", "bool", "long", "float", "class"};
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

}

//Checks if char x is in string s and how many times
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




//analyzes file lines for elemental operations and certain keywords
void analisisPrueba(queue<string> lineasComp){

    char op[]={'#', '/', '+', '-', '*', '=', '[', '<', '>'};  //TODO: check cout and return
    vector<char> vectorOP(op, op + sizeof(op) / sizeof(*op));    
    string funcFor[]={"for","while"};
    vector<string>vectorFN(funcFor,funcFor + sizeof(funcFor)/sizeof(*funcFor));
    string funcIf[]={"if"};
                

    vector<string> vecComp; // for saving queue elements in a vector
    vector<int> contOE;//for saving elemental operations in each line
    bool ignore;

    int cont = lineasComp.size(); 
    int cont1 , mayor = 0;

    for (int i = 0; i < cont; i++) //iterates over each line
    {
        ignore = false;
        cont1 = 0;

        //saves line as string
        string analize = lineasComp.front();

        //checks if said operator is in line    
        cont1 += findChar(analize);
        
        //checks thre length of the largest line        
        if(analize.size()> mayor)
        {
            mayor = analize.size();
        }
    
        contOE.push_back(cont1); //saves elemental operation count in the line
        
        vecComp.push_back(lineasComp.front()); //saves line in queue before being deleted
        lineasComp.pop(); //removes line from queue
    }


    PrintTable(vecComp, contOE, mayor);

}