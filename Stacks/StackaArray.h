// Maria Vitoria Ribeiro Mendes - 2021
#include <bits/stdc++.h>

#ifndef STACKARRAY_H
#define STACKARRAY_H

// stack implementation using array (static)
typedef int Data;

class Stack{

    public:
        Stack();
        ~Stack();
        void push(Data x);
        void pop(Data &x);
        bool empty();
        bool full();
        void clear();
        void stackTop(Data &x);
        int size();
        void reverse();
        void toString(); 
        
    private:
        static const int MaxSize = 100;
        int top; // contains the index of the stack's top
        Data data[MaxSize]; // array containing the stack elements

};

#endif