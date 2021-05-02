#ifndef LIST_H
#define LIST_H
#include <iomanip>
#include <iostream>
#include <fstream>
#include <assert.h>
#include "linkedlistfuncs.h"

using namespace std;

template<class T>
class List
{
public:
    List():_head(NULL){
//        cout<<"default constructor fired"<<endl;
    }
    ~List(){
//        cout<<"destructor fired"<<endl;
        delete_all(_head);

    }
    List(const List<T>& other){
//        cout<<"copy constructor fired"<<endl;
        init_head(_head);
        copy_list(other._head, _head);

    }
    List<T> & operator=(const List<T>& rhs){
        if(this != &rhs){
            delete_all(_head);
            copy_list(rhs._head, _head);
        }
        return *this;
    }

    node<T>* insert(T item){
        return insert_head(_head, item);
    }
    void insert(node<T>* here, T item){
        insert_after(_head, here, item);
    }
    void clear(){
       ~List();
    }
    T erase(){
        return delete_head(_head);
    }
    bool empty(){
        return isempty(_head);
    }
    T getheadval(){
        assert(!isempty(_head));
        return _head->_item;
    }

    friend ostream& operator<<(ostream& outs, const List& l){
        return print_list(l._head, outs);
    }


private:
    node<T>* _head;


};

#endif // LIST_H
