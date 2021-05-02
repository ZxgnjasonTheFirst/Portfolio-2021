#ifndef TEST_LIST_H
#define TEST_LIST_H
#include <iomanip>
#include <iostream>
#include "list.h"

//Testing copy CTOR and Insert
void test_listcopyconstructor(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing list copy constructor and insert (1 argument):"<<endl;
    cout<<"----------------------------------"<<endl;

    //ALSO TESTS INSERT
    //declare list
    List<int> test;

    //insert
    test.insert(1);
    test.insert(2);
    test.insert(3);


    //cout
    cout<<"test"<<test<<endl;

    //CTOR
    List<int> yes(test);

    cout<<"yes"<<yes<<endl;
    cout<<"----------------------------------"<<endl;

}

void test_insert_here(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing insert (two arguments):"<<endl;
    cout<<"----------------------------------"<<endl;

    List<int> test;
    node<int>* here;

    test.insert(1);
    here = test.insert(2); //insert returns the head from insert_head (specifically temp_head)
    test.insert(3);

    test.insert(here, 5);

    cout<<"test"<<test;
    cout<<"----------------------------------"<<endl;

}

//Testing destructor
void test_listdestructor(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing list destructor:"<<endl;
    cout<<"----------------------------------"<<endl;

    //declare list
    List<int> test;

    //insert (comment out to test destructor of empty list)
//    test.insert(1);
//    test.insert(2);

    //cout
    cout<<test<<endl;

    //destructor
    test.~List();

    cout<<"this is test after destructor"<<test<<endl;
    cout<<"----------------------------------"<<endl;



}


//Testing equals operator
void test_listequals_operator(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing list equals operator:"<<endl;
    cout<<"----------------------------------"<<endl;

    //declare test and yes
    List<int> test, yes;

    //insert (comment either to test equals op)
    test.insert(1);
    test.insert(2);

    //cout test
    cout<<"test"<<test;

    //assignment operator
    yes = test;

    //cout yes
    cout<<"yes"<<yes;
    cout<<"----------------------------------"<<endl;

}

//Testing erase(from head)
void test_erase(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing erase (deleting head of list):"<<endl;
    cout<<"----------------------------------"<<endl;

    //declare test
    List<int> test;

    //insert into test
    test.insert(1);
    test.insert(2);
    test.insert(3);

    //cout test
    cout<<"test"<<test;

    //erase
    test.erase();
    cout<<"test"<<test;
    test.erase();
    cout<<"test"<<test;
    test.erase();
    cout<<"test"<<test;
    test.erase();

    //cout test
    cout<<"test"<<test;
    cout<<"----------------------------------"<<endl;

}

void test_head_val(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing getting head value:"<<endl;
    cout<<"----------------------------------"<<endl;

    List<int> test;

    //insert (comment out any/ switch for head value)
    test.insert(1);
    test.insert(2);
    test.insert(3);

    cout<<"Test: "<<test;
    cout<<"Head value is: "<<test.getheadval()<<endl;
    cout<<"----------------------------------"<<endl;

}
//Testing empty
void test_listempty(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing if list is empty:"<<endl;
    cout<<"----------------------------------"<<endl;

    //declare list and node "here"
    List<int> test;
    node<int>* here;

    //insert (comment out to test empty)
    here = test.insert(1);
    test.insert(here,2);

    //print
    cout<<test;

    //erase/destructor

    test.~List();
    test.erase();
//    test.erase(); //comment out to test for empty
    cout<<test;

    //check if empty
    if(test.empty()){
        cout<<"list is empty!"<<endl;
    }
    else
        cout<<"list is not empty!"<<endl;

    cout<<"----------------------------------"<<endl;

}
#endif // TEST_LIST_H
