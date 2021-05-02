#include <iostream>
#include <time.h>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/PQueue_Class/pqueue_class.h"
/*
 * Name: Jason Pambuena
 * Project: PriorityQueue
 * Purpose: Uses the heap class to create a priority queue, meaning with an integer priority it sorts data according to
 * that priority.
 * Notes: Just a matter of calling heap and creating a struct called info holding an item of type T and priority.
 */
using namespace std;

void Heap_main();
void Heap_menu();

int main()
{
    srand(time(NULL));
    PQueue<int> pq;
    for (int i = 0; i < 100; i++){
        pq.insert(rand() % 1000 + 1, rand() % 10 + 1);
    }
    cout<<pq;
    for (int i = 0; i < 100; i++){
        cout<<pq.Pop()<<" ";
    }
    cout<<endl;
    return 0;
}
