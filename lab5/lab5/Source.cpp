#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define SIZE 1

using namespace std;

template <typename T>
class Stack
{
    T* arr;
    int top;
    int _size;
public:
    Stack(int size = SIZE);
    ~Stack();
    void push(T);
    T pop();
    T back();
    void append(int);

    int size();
    bool isEmpty();
    bool isFull();
    friend string push(string example, string postfix, Stack* operationsStack, int index);
};


template <typename T>
Stack<T>::Stack(int size)
{
    arr = new T[size];
    _size = size;
    top = -1;
}


template <typename T>
void Stack<T>::append(int size)
{
    T* Arr = new T[size + _size];
    for (int i = 0; i < _size; i++)
        Arr[i] = arr[i];
    _size += size;
    arr = Arr;
}


template <typename T>
Stack<T>::~Stack()
{
    delete[] arr;
}


template <typename T>
void Stack<T>::push(T x)
{
    if (isFull())
    {
        if (!isEmpty())append(2);
        else append(_size);
    }
    arr[++top] = x;
}



template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw out_of_range("Error: stack is empty");
    }
    return arr[top--];
}


template <typename T>
T Stack<T>::back()
{
    if (!isEmpty())
    {
        return arr[top];
    }
    else {
        throw out_of_range("Error: stack is empty");
    }
}


template <typename T>
int Stack<T>::size()
{
    return top + 1;
}


template <typename T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}


template <typename T>
bool Stack<T>::isFull()
{
    return top == _size - 1;
}


