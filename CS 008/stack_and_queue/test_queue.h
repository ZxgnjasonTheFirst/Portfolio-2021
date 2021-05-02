#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H
#include <iomanip>
#include <iostream>
#include "queue.h"
//Testing copy CTOR and push
void test_queuecopyconstructor(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing queue copy constructor and push:"<<endl;
    cout<<"----------------------------------"<<endl;
    //ALSO TESTS PUSH
    //declare list
    Queue<int> test;

    //push
    test.push(1);
    cout<<"Count: "<<test.count()<<endl;
    test.push(2);
    cout<<"Count: "<<test.count()<<endl;
    test.push(3);
    cout<<"Count: "<<test.count()<<endl;
    test.push(4);
    cout<<"Count: "<<test.count()<<endl;


//    cout<<"BACK"<<test.back()<<endl;
    //cout
    cout<<"test"<<test<<endl;

    //CTOR
    Queue<int> yes(test);

    cout<<"yes"<<yes<<endl;
    cout<<"----------------------------------"<<endl;
}
//Testing destructor
void test_queuedestructor(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing queue destructor:"<<endl;
    cout<<"----------------------------------"<<endl;
    //declare list
    Queue<int> test;

    //push
//    test.push(1);
//    test.push(2);

    //cout
    cout<<test<<endl;

    //destructor
    test.~Queue();

    cout<<"this is test after destructor"<<test<<endl;

    cout<<"----------------------------------"<<endl;
}

//Testing equals operator
void test_queueequals_operator(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing queue equals operator:"<<endl;
    cout<<"----------------------------------"<<endl;
    //declare test and yes
    Queue<int> test, yes;

    //push (comment out/switch to test equals op)
    test.push(1);
    test.push(2);

    //cout test
    cout<<"test"<<test;

    //assignment operator
    yes = test;

    //cout yes
    cout<<"yes"<<yes;
    cout<<"----------------------------------"<<endl;
}
//Testing pop
void test_queuepop(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing queue pop:"<<endl;
    cout<<"----------------------------------"<<endl;
    //declare stack
    Queue<int> test;

    //push
    test.push(1);
    test.push(2);
    test.push(3);

    cout<<"Count: "<<test.count()<<endl;
    cout<<"test"<<test;

    //pop
    test.pop();
    cout<<"pop1"<<test;
    cout<<"Count: "<<test.count()<<endl;
    test.pop();
    cout<<"pop2"<<test;
    cout<<"Count: "<<test.count()<<endl;
    test.pop();
    cout<<"pop3"<<test;
    cout<<"Count: "<<test.count()<<endl;
    test.pop();
    cout<<"pop4"<<test;
    cout<<"Count: "<<test.count()<<endl;


    cout<<"----------------------------------"<<endl;

}

//Testing front
void test_front(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing front:"<<endl;
    cout<<"----------------------------------"<<endl;
    //Declare stack
    Queue<int> test;
    //Push, top, push, top, push, top
    test.push(1);
    cout<<"Test:"<<test;
    cout<<"Front1: "<<test.front()<<endl;
    test.push(2);
    cout<<"Test:"<<test;
    cout<<"Front2: "<<test.front()<<endl;
    test.push(3);
    cout<<"Test:"<<test;
    cout<<"Front3: "<<test.front()<<endl;
    //Pop, top, pop, top, pop, top
    test.pop();
    cout<<"Test:"<<test;
    cout<<"Front4: "<<test.front()<<endl;
    test.pop();
    cout<<"Test:"<<test;
    cout<<"Front5: "<<test.front()<<endl;
    test.pop();
    cout<<"Test:"<<test;//putting this after line below (vvvv) doesn't print.
    cout<<"Front6: "<<test.front()<<endl; //test.top() returns NULL and ends program when there are no endl?
    cout<<"----------------------------------"<<endl;



}

//Testing back
void test_back(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing back:"<<endl;
    cout<<"----------------------------------"<<endl;
    //Declare stack
    Queue<int> test;
    //Push, top, push, top, push, top
    test.push(1);
    cout<<"Test:"<<test;
    cout<<"Back1: "<<test.back()<<endl;
    test.push(2);
    cout<<"Test:"<<test;
    cout<<"Back2: "<<test.back()<<endl;
    test.push(3);
    cout<<"Test:"<<test;
    cout<<"Back3: "<<test.back()<<endl;
    //Pop, top, pop, top, pop, top
    test.pop();
    cout<<"Test:"<<test;
    cout<<"Back4: "<<test.back()<<endl;
    test.pop();
    cout<<"Test:"<<test;
    cout<<"Back5: "<<test.back()<<endl;
    test.pop();
    cout<<"Test:"<<test;//putting this after line below (vvvv) doesn't print.
    cout<<"Back6: "<<test.back()<<endl; //test.top() returns NULL and ends program when there are no endl?

    cout<<"----------------------------------"<<endl;



}

//Testing empty
void test_queueempty(){
    cout<<"----------------------------------"<<endl;
    cout<<"Testing if queue is empty:"<<endl;
    cout<<"----------------------------------"<<endl;
    //declare list and node "here"
    Queue<int> test;

    //insert (comment out to test empty)
    test.push(1);
    test.push(2);

    //print
    cout<<test;

    //pop/destructor
    test.~Queue();
    test.pop();
    test.pop(); //comment out test for empty
    cout<<test;

    //check if empty
    if(test.empty()){
        cout<<"list is empty!"<<endl;
    }
    else
        cout<<"list is not empty!"<<endl;

    cout<<"----------------------------------"<<endl;
}

#endif // TEST_QUEUE_H
