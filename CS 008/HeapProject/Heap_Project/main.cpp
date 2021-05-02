#include <iostream>
#include <time.h>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Heap_Class/heap_class.h"
/*
 * Name: Jason Pambuena
 * Project: Heap_Project
 * Purpose: Uses an array to create a tree like data-structure.
 * Notes: Does not use tree_node or avl/bst. Pop works from the top-down while insert works from the bottom-up.
 * as a result, the next item to check so that it doesn't go over the vector's limits for insert() is the index itself
 * (since i becomes the parent()) and for pop() -- is_leaf() because it checks whether or not there is something below
 * the current node to swap with.
 */
using namespace std;

void Heap_main();
void Heap_menu();
void test_Heap();
int main()
{
//    srand(time(NULL));
//    Heap_main();
    test_Heap();
    return 0;
}

void test_Heap(){ //7, 11, 0, 8, 1, 10, 4, 9, 6, 3, 2, 5, 12, 14, 19, 18, 17, 13, 15, 16

    int a[] = {7, 11, 0, 8, 1, 10, 4, 9, 6, 3, 2, 5, 12, 14, 19, 18, 17, 13, 15, 16};
    Heap<int> heap;
    int size = 20;
    for (int i = 0; i< size; i++){
        heap.insert(a[i]);
    }
    for (int i= 0; i<size; i++){
        cout<<heap<<endl<<endl;
        cout<<"++++++++++ popping: "<<heap.Pop()<<endl;
        cout<<"-------------"<<endl;
    }
    cout<<"--- done ---- "<<endl;
    cout<<heap<<endl;
//    heap.insert(7);
//    heap.insert(11);
//    heap.insert(0);
//    heap.insert(8);
//    heap.insert(1);
//    heap.insert(10);
//    heap.insert(4);
//    heap.insert(9);
//    heap.insert(6);
//    heap.insert(3);
//    heap.insert(2);
//    heap.insert(5);
//    heap.insert(12);
//    heap.insert(14);
//    heap.insert(19);
//    heap.insert(18);
//    heap.insert(17);
//    heap.insert(13);
//    heap.insert(15);
//    heap.insert(16);

//    cout<<heap;
//    for(int i = 0; i < 7; ++i){
//        cout<<heap.Pop()<<endl;
//        cout<<heap;


}

void Heap_main(){
    int num, rnd;
    char menu;
    bool done = false;
    Heap<int> heap;
    do{
        Heap_menu();
        cin>>menu;
        switch(toupper(menu)){
        case 'R':
            rnd = rand() % 100 + 1;
            cout<<"-- Inserting "<<rnd<<endl;
            heap.insert(rnd);
            cout<<heap;
            break;
        case 'I':
            cout<<"? ";
            cin>>num;
            cout<<"-- Inserting "<<num<<endl;
            heap.insert(num);
            cout<<heap;
            break;
        case 'P':
            cout<<"-- Popping "<<heap.Pop()<<endl;
            cout<<heap;
            break;
        case 'X':
            done = true;
            break;
        default:
            cout<<"Please enter a valid key."<<endl;

        }

        cout<<"========================="<<endl;
    }while(!done);

    cout<<"================================"<<endl;

}

void Heap_menu(){
    cout<<"[R]andom  [I]nsert  [P]op  e[X]it: ";
}
