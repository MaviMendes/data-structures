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
    
    Pointer newTop, front, back;    
    
    newTop = top; 
    back = NULL;
    front = NULL;
    if(top==NULL)
    {
        cout<<"Empty stack!"<<endl;
        abort();
    }
    cout<<"\nINSIDE THE FUNCTION TO REVERSE\n\n";
    while(newTop!=NULL)
    {
        front = newTop->next; // store the next node befere reversing the current node pointer
        cout<<"front = newTop->next\nfront = "<<to_string(front->data)<<endl;
        newTop->next = back; // reverse the current node pointer
        cout<<"newTop->next = back"<<endl;
        // after storing the next node to be reversed and reversing the current node pointer, go to the next position
        cout<<"\nupdate pointers:\n";
        back = newTop;
        cout<<"back = newTop\nback = "<<to_string(back->data)<<endl;
        newTop = front;
        cout<<"newTop = front\nnewTop = "<<to_string(newTop->data)<<endl;
    }
    top = back;
    cout<<"\n-----------------------------------------------\n";
}
void Stack::toString()
{
    Pointer p;
    p = top;

    cout<<"Stack: "<<endl;
    while(p!=NULL)
    {
        cout<<to_string(p->data)<<" ";
        p = p->next;
    }
    cout<<endl;
}
