#ifndef TEST_STACK_H
#define TEST_STACK_H
#include <iomanip>
#include <iostream>
#include "stack.h"


//Testing Push
void test_push(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing stack push and constructor:"<<endl;
    cout<<"----------------------------------"<<endl;
    //declare stack
    Stack<int> test;

    //push
    test.push(1);
    cout<<"test"<<test;
    test.push(2);
    cout<<"test"<<test;
    test.push(3);

    cout<<"test"<<test;
    cout<<"----------------------------------"<<endl;

}
//Testing pop
void test_stackpop(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing stack pop:"<<endl;
    cout<<"----------------------------------"<<endl;
    //declare stack
    Stack<int> test;

    //push
    test.push(1);
    test.push(2);
    test.push(3);

    cout<<"test"<<test;

    //pop
    test.pop();
    cout<<"pop1"<<test;
    test.pop();
    cout<<"pop2"<<test;
    test.pop();
    cout<<"pop3"<<test;

    //popping from an empty list
    test.pop();
    cout<<"pop4"<<test;
    cout<<"----------------------------------"<<endl;


}
//Testing top
void test_top(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing stack top:"<<endl;
    cout<<"----------------------------------"<<endl;
    //Declare stack
    Stack<int> test;
    //Push, top, push, top, push, top
    test.push(1);
    cout<<"Test:"<<test;
    cout<<"Top1: "<<test.top()<<endl;
    test.push(2);
    cout<<"Test:"<<test;
    cout<<"Top2: "<<test.top()<<endl;
    test.push(3);
    cout<<"Test:"<<test;
    cout<<"Top3: "<<test.top()<<endl;
    //Pop, top, pop, top, pop, top
    test.pop();
    cout<<"Test:"<<test;
    cout<<"Top4: "<<test.top()<<endl;
    test.pop();
    cout<<"Test:"<<test;
    cout<<"Top5: "<<test.top()<<endl;
    test.pop();
    cout<<"Test:"<<test; //putting this after line below (vvvv) doesn't print.
    cout<<"Top6: "<<test.top()<<endl; //test.top() returns NULL and ends program when there are no endl?
    cout<<"----------------------------------"<<endl;


}
//Testing empty
void test_stackempty(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing if stack is empty and destructor:"<<endl;
    cout<<"----------------------------------"<<endl;
    //declare list and node "here"
    Stack<int> test;

    //insert (comment out to test empty)
    test.push(1);
    test.push(2);

    //print
    cout<<test;

    //pop/destructor
//    test.~Stack();
    test.pop();
//    cout<<test;
//    test.pop(); //comment out test for empty
    cout<<test;

    //check if empty
    if(test.empty()){
        cout<<"list is empty!"<<endl;
    }
    else
        cout<<"list is not empty!"<<endl;

    cout<<"----------------------------------"<<endl;

}


#endif // TEST_STACK_H
