// Maria Vitoria Ribeiro Mendes - 2021

#include <bits/stdc++.h>
#include "StackaArray.h"
using namespace std;

int main()
{
    Stack firstStack;
    cout<<"Initialy:"<<endl;
    firstStack.toString();
    firstStack.push(10);
    firstStack.push(22);
    firstStack.push(340);
    firstStack.push(-5);
    cout<<"Added some numbers:"<<endl;
    firstStack.toString();
    cout<<firstStack.empty()<<endl;
    cout<<firstStack.full()<<endl;
    int y;
    firstStack.stackTop(y);
    cout<<to_string(y)<<endl;
    cout<<firstStack.size()<<endl;
    int popped;
    firstStack.pop(popped);
    cout<<to_string(popped);
    cout<<"After pop:"<<endl;
    firstStack.toString();
    firstStack.push(popped);
     cout<<"After pushing the popped:"<<endl;
    firstStack.toString();
    firstStack.reverse();
    cout<<"After reversing:"<<endl;
    firstStack.toString();
    firstStack.reverse();
    cout<<"Reverse back to the original:"<<endl;
    firstStack.toString();
    firstStack.clear();
    cout<<"Cleared"<<endl;
    cout<<firstStack.empty()<<endl;
    
    return 0;
}