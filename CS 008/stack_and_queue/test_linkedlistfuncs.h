#ifndef TEST_LINKEDLISTFUNCS_H
#define TEST_LINKEDLISTFUNCS_H
#include <iomanip>
#include <iostream>
#include "linkedlistfuncs.h"


//TESTING INIT HEAD:
void test_init_head(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing initialize head:"<<endl;
    cout<<"----------------------------------"<<endl;
    //init the head.
    node<int>* head;
    init_head(head);
    //print.
    print_list(head);    
    cout<<"----------------------------------"<<endl;

}
//TESTING INSERT HEAD:
void test_insert_head(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing insert head:"<<endl;
    cout<<"----------------------------------"<<endl;
    //init the head.
    node<int>* head;

    init_head(head);
    //use a for loop and insert numbers from 1 to 10 into a linked list.
    for(int i = 0; i < 10 ; ++i){//<-- The last of the numbers inserted in go first on list (next to head).
        insert_head(head, i);
    }
    print_list(head);

    //print the list
    //results should be 9,8,7,....1,0
    cout<<"----------------------------------"<<endl;

}
//TESTING DELETE ALL:
void test_delete_all(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing delete all:"<<endl;
    cout<<"----------------------------------"<<endl;
    //init. head
    node<int>* head;
    init_head(head);
    //make a for loop inserting at the head 10 times.
    for(int i = 0; i < 10 ; ++i){//Take off list to test delete all for an empty list
        insert_head(head, i);
    }
    //Print
    print_list(head);
    //delete all
    delete_all(head);
    //Print
    print_list(head);
    cout<<"----------------------------------"<<endl;

}

//TESTING INSERT AFTER:
void test_insert_after(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing insert after:"<<endl;
    cout<<"----------------------------------"<<endl;
    node<int> *head;
    init_head(head);
    for(int i = 0; i < 10 ; ++i){ //Take both loops off to test empty list
        insert_head(head, i);
    }
    node<int> *here = head;
    print_list(head);
    while(here->_item != 1){
//        cout<<"here: "<<*here<<endl; //Testing where here is.
        here = here->_next;
    }
    here = insert_after(head, here, 3);
    here = insert_after(head, here, 2);
    here = insert_after(head, here, 1);
    print_list(head);
    cout<<"----------------------------------"<<endl;

}
//TESTING DELETE HEAD:
void test_delete_head(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing delete head:"<<endl;
    cout<<"----------------------------------"<<endl;
    node<int>* head;
    init_head(head);
    for(int i = 0; i < 10 ; ++i){
        insert_head(head, i);
    }
    print_list(head);
    delete_head(head);
    print_list(head);
    delete_head(head);
    print_list(head);
//    delete_head(head);
//    delete_head(head);
//    print_list(head);
    cout<<"----------------------------------"<<endl;

}
//TESTING COPY LIST:
void test_copy_list(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing copy list:"<<endl;
    cout<<"----------------------------------"<<endl;
    //Init. head
    node<int> *head, *copy;
    init_head(head);
    //Create list 10 to 0
//    for(int i = 0; i < 10 ; ++i){ //Take loop off to test copying empty list
//        insert_head(head, i);
//    }
    cout<<"Orig:"<<endl;
    print_list(head);
    //Copy list
    copy_list(head, copy);
    //Print
    cout<<"COPY:"<<endl;
    print_list(copy);
    cout<<"----------------------------------"<<endl;

}
//Testing empty
void test_linkedempty(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing if linked list is empty:"<<endl;
    cout<<"----------------------------------"<<endl;
    //declare nodes head and here
    node<int>* head, *here;
    //init head
    init_head(head);
    //print
    print_list(head);

    //insert (comment out to test empty)
    //point here to first insert
//    here = insert_head(head, 1);
    //insert after
//    insert_after(head, here, 2);

    //print
    print_list(head);

    //delete
    delete_all(head);
    delete_head(head);
    delete_head(head);

    //check if empty
    if(isempty(head)){
        cout<<"head is empty!"<<endl;
    }
    else
        cout<<"head is not empty!"<<endl;

    cout<<"----------------------------------"<<endl;


}
//------------------------------------------------------------
//Testing NULL to see why it does test_top() in stack.h
void test_NULL(){
    node<int>* test;
    init_head(test);
    cout<<"Hello World!";
    cout<<test->_item; //FOUND for some reason when test points to NULL and test->item is couted it doesn't print "H.W!"

}

#endif // TEST_LINKEDLISTFUNCS_H
