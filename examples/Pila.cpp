//Last in first out
#include <iostream>
using namespace std;

template <class T>
class Nodo{
    public: 
        Nodo<T> *next;
        Nodo<T> *before;
        T value;
        Nodo()
        {
            next = NULL;
            before = NULL;
            value = NULL;
        }
        Nodo(T val)
        {
            next = NULL;
            before =  NULL;
            value = val;
        }

};

template <class T>
class Pila{
    public:
        Nodo <T> *top;
        Pila ()
        {
            top = NULL;
        }
        void push(Nodo <T> * nuevo)
        {
            if(top == NULL)
            {
                top= nuevo;
            }
            else
            {
                top->next=nuevo; //guardas en next el nuevo valor
                nuevo->before= top;// conviertes el valor anterior de nuevo en top
                top= nuevo;//top ahora pasa a ser nuevo
            }
            
        }
        void push (T value)
        {
            Nodo<T> * nuevo= new Nodo <T>(value);
            push(nuevo);
        }
        T pop()
        {
           if(top== NULL)
           {
               return NULL;
           }  
           else
           {
               T val = top->value;
               if(top->before == NULL) //si el anterior a top es null entonces
               {
                   delete(top); //eliminas top
                   return val;//regresas el valor que tenía top
               }
               else //si no...
               {
                   top=top->before; //top se va convirtiendo en tus valores anteriores
                    delete(top->next);//se elimina lo que va después de top
                    top-> next= NULL; // lo que apunta despues de top pasa a ser null
                    return val;//Se regresa el valor de top    
               }              
            }
           
        }
};
int main()
{
    Pila<int> p;
    p.push(5);
    p.push(7);
    p.push(9);
    cout<<p.pop()<<endl;
    cout<<p.pop()<<endl;
    cout<<p.pop()<<endl;
}