#ifndef TEST_BST_H
#define TEST_BST_H
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/BST_Class/bst.h"

void test_BST_CTOR(){
    BST<int> bst;
    cout<<"================================"<<endl;
    cout<<bst;
    cout<<"================================"<<endl;

}

void test_BST_COPY_CTOR(){
    BST<int> bst;

    bst.insert(46);
    bst.insert(22);
    bst.insert(41);
    bst.insert(4);
    bst.insert(8);
    bst.insert(84);
    bst.insert(96);
    bst.insert(64);
    bst.insert(57);
    bst.insert(56);
    bst.insert(50);


    BST<int> cpy(bst);

    cout<<"================================"<<endl;
    cout<<"Original"<<endl;
    cout<<bst;
    cout<<"Copy"<<endl;
    cout<<cpy;
    cout<<"================================"<<endl;



}

void test_BST_ASSIGNMENT(){
    BST<int> bst, cpy;

    bst.insert(46);
    bst.insert(22);
    bst.insert(41);
    bst.insert(4);
    bst.insert(8);
    bst.insert(84);
    bst.insert(96);
    bst.insert(64);
    bst.insert(57);
    bst.insert(56);
    bst.insert(50);

    cpy = bst;

    cout<<"================================"<<endl;
    cout<<"Original"<<endl;
    cout<<bst;
    cout<<"Copy"<<endl;
    cout<<cpy;
    cout<<"================================"<<endl;

}

void test_BST_DTOR(){
    BST<int> bst, cpy;

    bst.insert(46);
    bst.insert(22);
    bst.insert(41);
    bst.insert(4);
    bst.insert(8);
    bst.insert(84);
    bst.insert(96);
    bst.insert(64);
    bst.insert(57);
    bst.insert(56);
    bst.insert(50);

    cout<<"================================"<<endl;
    cout<<"Original"<<endl;
    cout<<bst;
    bst.~BST();
    cout<<"Destructed"<<endl;
    cout<<bst;
    cout<<"================================"<<endl;

}

void test_BST_erase(){
    BST<int> bst;
    bst.insert(46);
    bst.insert(22);
    bst.insert(41);
    bst.insert(4);
    bst.insert(8);
    bst.insert(84);
    bst.insert(96);
    bst.insert(64);
    bst.insert(57);
    bst.insert(56);
    bst.insert(50);

    cout<<"================================"<<endl;
    cout<<"Original"<<endl;
    cout<<bst;
    bst.erase(84);
    bst.erase(8);
    cout<<"Erased 8 and 84"<<endl;
    cout<<bst;
    cout<<"================================"<<endl;

}

void test_BST_search(){
    BST<int> bst;
    tree_node<int> *ptr;
    bst.insert(46);
    bst.insert(22);
    bst.insert(41);
    bst.insert(4);
    bst.insert(8);
    bst.insert(84);
    bst.insert(96);
    bst.insert(64);
    bst.insert(57);
    bst.insert(56);
    bst.insert(50);

    cout<<"================================"<<endl;
    cout<<bst;
    if(bst.search(4,ptr))
        cout<<"4 was found!"<<endl;
    else
        cout<<"4 wasn't found!"<<endl;
    if(bst.search(99, ptr))
        cout<<"99 was found!"<<endl;
    else
        cout<<"99 wasn't found!"<<endl;
    cout<<"================================"<<endl;

}

void test_BST_add(){
    BST<int> bst, add;

    bst.insert(46);
    bst.insert(22);
    bst.insert(41);
    bst.insert(4);
    bst.insert(8);
    add.insert(84);
    add.insert(96);
    add.insert(64);
    add.insert(57);
    add.insert(56);
    add.insert(50);

    cout<<"================================"<<endl;
    cout<<"Original"<<endl;
    cout<<add;
    cout<<"Adding this"<<endl;
    cout<<bst;
    add += bst;
    cout<<"Added"<<endl;
    cout<<add;
    cout<<"================================"<<endl;

}
#endif // TEST_BST_H
