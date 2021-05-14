// Maria Vitoria Ribeiro Mendes - 2021

#include <bits/stdc++.h>
#include "StackaArray.h"
using namespace std;

Stack::Stack() // initialize empty stack
{
    top = 0; 
}

Stack::~Stack() // destructor
{
    cout<<"Stack destructed"<<endl;
}

void Stack::push(Data x)
{
   // pre condition: stack not full
   // pos condition: add element to the stack, top++
   if(full())
   {
       cout<<"Stack is full!"<<endl;
       abort(); // abort execution and generate a core-dump
   }
   // suppose there is no element, therefore top = 0. x will be added at index 0, then top will be increased(top =1, there is 1 element). the next element will be added at index 1, top will be increased(top = 2, there are 2 elements), and so on. 
   // the number of elements in the array is top+1 if top!= 0
   data[top] = x; // supose there is 1 element, therefore top = 1, but the element is at index top-1, which is zero. So we always add the new element at the index with the same value as top
   top++; // then we increase top. suppose there are 3 elements after we increase top. top = 3. the fourth element will be added at data[3] = data[top], which is the fourth position, since the array starts at zero
}

void Stack::pop(Data &x)
{
    // pre condition: there is at least one element in the stack
    // pos condition: designated element deleted from the stack, top--
    if(empty())
    {
        cout<<"Stack is empty!"<<endl;
        abort();
    }

    x = data[top-1]; // top stores the number of elements and the index of the next element to be added. if there are 3 elements, top = 3 and the stack is like [1,2,3], index from 0 to 2. the top is element of value 3, which is at index 2, which corresponds to top-1
    top--; // [1,2,3] -> [1,2] index from 0 to 1, top = 2, next element will be added at index 2
}

bool Stack::empty()
{
    // pre condition: 
    // pos condition: true if stack is empty, false otherwise

    return (top == 0); // everytime a new element is added, top value is increased. if top = o, which is the default value, it means it has never been increased or that all elements were deleted, meaning that the stack is empty
}

bool Stack::full()
{
    // pre condition: 
    // pos condition: true if stack is full, false otherwise

    return (top == (MaxSize-1)); // everytime a new element is added, top value is increased. if top = MaxSize-1, the Stack is full (the array starts at 0, so 0...99 there are 100 elements)
}

/*void Stack::clear()
{
    int x;

    while(!empty()) // if empty = true, !empty = false, stops
    {
       pop(x); 
    }
    cout<<"Finished clearing stack."<<endl;
    // O(n) -> stack size
}*/

void Stack::clear()
{
    top = 0;
    // O(1) -> 1 operation and done
}

/*void Stack::stackTop(Data &x)
{
    if(empty())
    {
        cout<<"Stack is empty, there is no top."<<endl;
        abort();
    }
    // x receives a copy of the top value
    pop(x); // O(1)
    // puts the value in the list again
    push(x); // O(1)
}*/

void Stack::stackTop(Data &x)
{
    if(top==0)
    {
        cout<<"Stack is empty, there is no top."<<endl;
        abort();
    }
    // x receives a copy of the top value
    x = data[top-1]; //O(1)
}

// stackTop: the two implementations are equivalent, the operations are O(1)

int Stack::size()
{
    return top;
}

void Stack::reverse()
{
    // do an example by hand and you will get it
    for(int i = 0; i<=(top-1)/2;i++)
    {
        int aux = data[i];
        data[i] = data[top-1-i];
        data[top-1-i] = aux;
    }
}

void Stack::toString()
{
    string theStack;
    for(int i = 0;i<top;i++)
    {
        cout<<to_string(data[i]);
        cout<<" ";
    }

    cout<<endl;
}
