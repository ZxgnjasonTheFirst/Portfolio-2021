#ifndef QUEUE_H
#define QUEUE_H
#include <iomanip>
#include <iostream>
#include "linkedlistfuncs.h"

using namespace std;

template<class T>
class Queue
{
public:
    Queue():_front(NULL), _tail(NULL),_count(0){
//        cout<<"default constructor fired"<<endl;
    }

    ~Queue(){
//        cout<<"destructor fired"<<endl;
        delete_all(_front);
        _tail = nullptr;
        _count = 0;
    }
    Queue(const Queue<T>& other){
//        cout<<"copy constructor fired"<<endl;
        init_head(_front);
        _tail = copy_list(other._front, _front);

    }
    Queue<T> & operator=(const Queue<T>& rhs){
//        cout<<"=operator fired"<<endl;
        if(this != &rhs){
            delete_all(_front);
            _tail = copy_list(rhs._front, _front);
        }
        return *this;
    }

    node<T>* push(T item){
        _tail = _front;
        if(!isempty(_front)){
            while(_tail->_next != nullptr){
                _tail = _tail->_next;
            }
            _tail = insert_after(_front, _tail, item);
            ++_count;
        }
        else if(isempty(_front)){
            _tail = insert_head(_front, item);
            ++_count;
        }


        return _tail;
    }
    T pop(){
        T popped = delete_head(_front);
        if(_front == nullptr)
            init_head(_tail);
        --_count;
        return popped;
    }
    bool empty(){
        return isempty(_front);
    }
    T front(){
        assert(_front != nullptr);
        return _front->_item;
    }
    T back(){
//        cout<<"_Tail: "<<_tail<<endl;
        assert(_front != nullptr);
        return _tail->_item;

    }

    int count(){
        if(_count > 0)
            return _count;
        else
            return _count = 0;
    }

    friend ostream& operator<<(ostream& outs, const Queue& q){
        return print_list(q._front, outs);
    }



private:
    node<T>* _front;
    node<T>* _tail;
    int _count;
};

#endif // QUEUE_H
