#ifndef TEST_MAIN_STACK_AND_QUEUE_H
#define TEST_MAIN_STACK_AND_QUEUE_H
#include <iomanip>
#include <iostream>
#include "stack.h"
#include "queue.h"

void main_test_stack(){
    cout<<"----------------------------------"<<endl;
    cout<<"MAIN STACK TEST:"<<endl;
    cout<<"----------------------------------"<<endl;

    Stack<int> s;

    for(int i = 0; i < 10; ++i){
        s.push(i);
    }

    Stack<int> s2(s);

    cout<<"s: "<<s<<endl;
    cout<<"s2: "<<s2<<endl;
    for(int i = 10; i > 0; --i){
        cout<<"{"<<s2.pop()<<"} "<<s2<<endl;
    }

    s2 = s;
    cout<<"assigning s back to s2: s: "<<s<<endl;
    cout<<"s2: "<<s2<<endl;
    cout<<"----------------------------------"<<endl;

}

void main_test_queue(){
    cout<<"----------------------------------"<<endl;
    cout<<"MAIN QUEUE TEST:"<<endl;
    cout<<"----------------------------------"<<endl;

    Queue<int> q;

    for(int i = 0; i < 10; ++i){
        q.push(i);
    }

    Queue<int> q2(q);

    cout<<"q: "<<q<<endl;
    cout<<"q2: "<<q2<<endl;
    for(int i = 10; i > 0; --i){
        cout<<"{"<<q2.pop()<<"} "<<q2<<endl;
    }

    q2 = q;
    cout<<"assigning q back to q2: q: "<<q<<endl;
    cout<<"q2: "<<q2<<endl;

    cout<<"----------------------------------"<<endl;

}
#endif // TEST_MAIN_STACK_AND_QUEUE_H
