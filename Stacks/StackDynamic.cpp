// Maria Vitoria Ribeiro Mendes - 2021

#include <bits/stdc++.h>
#include "StackDynamic.h"
using namespace std;

typedef int Data;

Stack::Stack()
{
    top = NULL;
    sizeOfStack = 0;
}

Stack::~Stack()
{
    cout<<"Stack destructed"<<endl;
    clear();
}

void Stack::push(Data x)
{
    Pointer p = new StackNode;
    if(p==NULL)
    {
        cout<<"No memory!"<<endl;
        abort();
    }
    p->data = x;
    p->next = top;
    top = p;

    sizeOfStack++;
}
void Stack::pop(Data &x)
{
    Pointer p;

    if(empty())
    {
        cout<<"Empty stack!"<<endl;
    } 
    else 
    {
        x = top->data;
        p = top;
        top = top->next;
        delete p;

        sizeOfStack--;
    }
}
bool Stack::empty()
{
    return(top==NULL);
}
bool Stack::full()
{
    return false; // there is no size limit
}
void Stack::clear()
{
    Data x;

    while(!empty())
    {
        pop(x);
    }
}
void Stack::stackTop(Data &x)
{
    x = top->data;
}
int Stack::size()
{
    return sizeOfStack;
}

void Stack::reverse()
{
    // pre: stack is not empty 
    // pos: reversed stack (new head is the previous last node
    Pointer p = top, aux = NULL;

    while(p!=NULL)
    {
        top = p;
        p=p->next;
        top->next = aux;
        aux = top;
    }
}

std::string Stack::toString()
{
    std::stringstream ss;

    Pointer p;
    p = top;

    ss<<"[ ";
    while(p!=NULL)
    {
        ss<<to_string(p->data);
        p = p->next;
        if(p!=NULL)
            ss<<" , ";
    }
    ss<<" ] "<<endl;

    return ss.str();
}




