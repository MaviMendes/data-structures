// Maria Vitoria Ribeiro Mendes - 2021

#include <bits/stdc++.h>

#ifndef STACKDYNAMIC_H
#define STACKDYNAMIC_H

typedef int Data;

class Stack
{
     public:
         // methods
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
        // forward declaration of StackNode

        struct StackNode;

        // pointer of type StackNode
        typedef StackNode (*Pointer);

        // definition of StackNode
        struct StackNode
        {
             Data data;
             Pointer next;
        };

        // a stack must have a pointer to its top
        Pointer top;

        int sizeOfStack; // stores how many elements there are in the stack
};

#endif