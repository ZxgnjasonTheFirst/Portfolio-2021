#include <iostream>
#include <time.h>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/AVL_Class/tree_funcs.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/AVL_Class/avl.h"
#include "test_tree_funcs.h"
/*
 * Name: Jason Pambuena
 * Project: AVL_Functions
 * Purpose: Creates a tree-like list using binary search. Automatically adjusts the tree
 * so that it becomes balanced or doesn't become a linked list.
 * Notes: Doesn't have initialize root so set root to NULL when you declare it. You need to
 * update height after changing the root.
 */
using namespace std;

void AVL_main();
void AVL_menu();

int main()
{
    srand(time(NULL));
    AVL_main();
    return 0;
}

void AVL_main(){
    int num, rnd;
    char menu;
    bool done = false;
    AVL<int> avl;
    tree_node<int>* ptr;
    do{
        AVL_menu();
        cin>>menu;
        switch(toupper(menu)){
        case 'R':
            rnd = rand() % 100 + 1;
            cout<<"-- Inserting "<<rnd<<endl;
            avl.insert(rnd);
            cout<<avl;
            break;
        case 'I':
            cout<<"? ";
            cin>>num;
            cout<<"-- Inserting "<<num<<endl;
            avl.insert(num);
            cout<<avl;
            break;
        case 'D':
            cout<<"? ";
            cin>>num;
            cout<<"-- Deleting "<<num<<endl;
            avl.erase(num);
            cout<<avl;
            break;
        case 'C':
            avl.~AVL();
            cout<<avl;
            break;
        case 'S':
            cout<<"? ";
            cin>>num;
            if(avl.search(num, ptr))
                cout<<"item is found. "<<*ptr<<endl;
            else
                cout<<"item not found."<<endl;
            cout<<avl;
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

void AVL_menu(){
    cout<<"[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: ";
}
