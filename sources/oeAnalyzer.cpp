#include "oeAnalyzer.h"
#include "printers.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


//Checks if char x is in string s and how many times
int findChar(string s, vector<char> op)
{
    int count = 0;
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
            //iterates through each operator in vector
            for(int j = 0; j < op.size(); j++)
            {
                //compares char with operator
                if (s[i] == op[j]) 
                {   
                    //ignores line if it starts with "#"
                    if (s[i] == '#')
                    {
                        ignore = true;
                        break;
                    }
                    else if (!(s[i] == '+' || s[i] == '-') && s[i+1] == s[i])
                    {
                        //checks if duplicate sign. Ignores char if it is << or >>
                        if (s[i] == '/')
                        {
                            ignore = true;
                            break;
                            //if duplicate is "//"", ignores rest of line to treat it as comment
                        }
                    }
        
                    else if (s[i-1] == op[j] )
                    {
                        //checks if duplicate sign. Ignores char if it is.
                    }
                    else if (s[i-1] == 't')
                    {
                        //checks if '*' is pointer. WORKAROUND
                    }

                    else if ((s[i] == '<' || '>') && s[i+1] == '=')
                    {
                        //if sign is >= or <=, ignores the first char so it only counts as one operation
                    }
                    else
                    {
                        //if not any of the above, adds to the elemental operation counter
                        count++;
                    }
                }
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
    vector<string>vectorFUN(funcIf,funcIf + sizeof(funcIf)/sizeof(*funcIf));               

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
        cont1 += findChar(analize, vectorOP);
        
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