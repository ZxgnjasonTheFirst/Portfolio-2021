#include <iostream>
#include <time.h>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/BST_Class/tree_funcs.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/BST_Class/bst.h"
#include "test_tree_funcs.h"
#include "test_bst.h"
/*
 * Name: Jason Pambuena
 * Project: BST_Functions
 * Purpose: Creates a tree-like list using binary search.
 * Notes: Doesn't have initialize root so set root to NULL when you declare it.
 */
using namespace std;

void BST_main();
void BST_menu();

int main()
{
    srand(time(NULL));
    BST_main();
    return 0;
}

void BST_main(){
    int num, rnd;
    char menu;
    bool done = false;
    BST<int> bst;
    tree_node<int>* ptr;
    do{
        BST_menu();
        cin>>menu;
        switch(toupper(menu)){
        case 'R':
            rnd = rand() % 100 + 1;
            cout<<"-- Inserting "<<rnd<<endl;
            bst.insert(rnd);
            cout<<bst;
            break;
        case 'I':
            cout<<"? ";
            cin>>num;
            cout<<"-- Inserting "<<num<<endl;
            bst.insert(num);
            cout<<bst;
            break;
        case 'C':
            bst.~BST();
            cout<<bst;
            break;
        case 'S':
            cout<<"? ";
            cin>>num;
            if(bst.search(num, ptr))
                cout<<"item is found. "<<*ptr<<endl;
            else
                cout<<"item not found."<<endl;
            cout<<bst;
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

void BST_menu(){
    cout<<"[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: ";
}
