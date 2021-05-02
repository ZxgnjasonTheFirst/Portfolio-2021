#ifndef LINKEDLISTFUNCS_H
#define LINKEDLISTFUNCS_H
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node(const T& item = T(), node<T>* next = NULL):_item(item), _next(next){}
    friend ostream& operator << (ostream& outs, const node<T>& print_me){
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

//initializes head to NULL
template <class T>
node<T>* init_head(node<T>* &head){
    //store the value NULL in head.
    //set head to NULL
    //point head to NULL
    head = NULL;
};

//deletes all the nodes in the list *That does NOT include the NULL.
template<class T>
void delete_all(node<T>*&head){
    node<T>* discard;
//    cout<<"Discard Next: "<<discard->_next<<endl;
    while(head != nullptr){
        discard = head; //Changes placement of walker(discard) after deletion.
        head = discard->_next;
        delete discard;
    }
};

//true if head is NULL, false otherwise.
template <class T>
bool isempty(const node<T>* head){
    if(head == nullptr){
        return true;
    }
    else{
        return false;
    }
};

//makes a copy of the list, returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>*& cpy){
    //Init cpy;
    init_head(cpy);
    const node<T>* walker1 = head;
//    cout<<*walker1<<endl;

    //Copy head
//    insert_head(cpy, walker1->_item);
    if(isempty(head)){
        node<T>* walker2 = cpy;
        return walker2;
    }
    else{
        node<T>* walker2 = cpy;
        walker2 = insert_after(cpy, walker2, walker1->_item);
        walker1 = walker1->_next;
        //Copy list after head (Use insert after).
        while(walker1 != NULL){
            walker2 = insert_after(cpy, walker2, walker1->_item);
            walker1 = walker1->_next;

//            cout<<"Walker2: "<<*walker2<<endl;
        }
        return walker2;
    }

//    cout<<"Walker2: "<<*walker2<<endl;
};

//insert at the beginning of the list:
template <class T>
node<T>* insert_head(node<T>* &head, T item){
    node<T>* temp_head;
    temp_head = new node<T>;
    temp_head->_item = item;
    temp_head->_next = head;
    head = temp_head;
    return temp_head;


};

//insert_after: if after is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item){

    if(head != NULL){
        //1. Create node and item
//        cout<<"inserting after "<<after->_item<<endl;
        node<T>* temp_head;
        temp_head = new node<T>;
        temp_head->_item = item;
//        cout<<"Doing this now"<<endl;
        //2.
        temp_head->_next = after->_next;
        //3.
        after->_next = temp_head;
        after = temp_head;
    }
    else if (head == NULL){
//        cout<<"Doing this"<<endl;
        insert_head(head, item);
        after = head;
    }
    return after;
//    cout<<"THIS IS AFTER: "<<*after<<endl;
//    cout<<"THIS IS head: "<<*head<<endl;


};

//delete the node at the head of the list, reuturn the item:
template <class T>
T delete_head(node<T>*& head){
    if(!isempty(head)){
        node<T>* discard;
        T discarded;
        discard = head; //Points discard to head
        head = discard->_next;
        discarded = discard->_item;
        delete discard;
        return discarded;
    }
    else
        head = nullptr;

};


//print the list and return outs
template<class T>
ostream& print_list(const node<T>* head, ostream& outs=cout){
    outs<<"->";
    while(head != NULL){
        outs<<*head;
        head = head->_next;
    }
    outs<<"|||"<<endl;
    return outs;
};

#endif // LINKEDLISTFUNCS_H
