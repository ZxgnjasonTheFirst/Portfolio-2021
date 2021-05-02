#ifndef STACK_H
#define STACK_H
#include <iomanip>
#include <iostream>
#include "list.h"

using namespace std;

template<class T>
class Stack
{
public:
//    Stack():_stack(), _top(NULL){}

//    ~Stack(){
//        _stack.~List<T>();
//    }
//    Stack(const List<T>& other){
//        List<T>::List(other);
//    }
//    Stack<T>& operator=(const List<T>& rhs){
//        *this = rhs;
//        return *this;
//    }

    void push(T item){
        _stack.insert(item);
    }
    T pop(){
        _top = _stack.erase();
        return _top;
    }
    T top(){
        _top = _stack.getheadval();
        return _top;
    }
    bool empty(){
        return _stack.empty();
    }
    friend ostream& operator<<(ostream& outs, const Stack& s){
        outs<<s._stack;
        return outs;
    }
//    friend ostream& operator<<(ostream& outs, const T& t){
//        if(t == NULL){
//            outs<<"Stack is empty"<<endl;
//        }
//        else
//            outs<<t;
//        return outs;
//    }
//    T test_NULL(){ //Just testing
//        _top = nullptr;
//    }

private:
    List<T> _stack;
    T _top;
};

#endif // STACK_H
