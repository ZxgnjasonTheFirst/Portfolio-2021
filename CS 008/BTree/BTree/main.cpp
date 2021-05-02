#include <iostream>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/BTree_Class/btree_funcs.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Array_Funcs/array_funcs.h"

/*
 * Name: Jason Pambuena
 * Project: Btree
 * Purpose: To create a type of tree that is needed for maps and multimaps.
 * Notes: NEEDS TO HAVE WORKING ARRAY FUNCS, OR IT DOESN'T WORK AT ALL.
 */
using namespace std;

void test_split();
void test_insertitem();
void test_copy_array();
void test_merge();
void test_deleteitem();

int main()
{
    BTree<int> root;
    BTree<int> copy;
//    root.make_tree();
    root.insert(100);
    root.insert(200);
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.insert(400);
    copy.copy_tree(root);
    cout<<"COPY: "<<endl;
    cout<<copy;
    cout<<"**********************"<<endl;
    copy.insert(110);
    cout<<"**********************"<<endl;
    cout<<"COPY INSERTED 110: "<<endl;
    cout<<copy;
    cout<<"**********************"<<endl;
    copy.~BTree();
    cout<<"**********************"<<endl;
    cout<<"COPY DESTUCTOR: "<<endl;
    cout<<copy;
    cout<<"**********************"<<endl;
    cout<<"ORIGINAL: "<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.insert(110);
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.insert(120);
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.insert(130);
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.insert(105);
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.insert(450);
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.insert(125);
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.remove(125);
    cout<<"removed 125: "<<endl;
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.remove(130);
    cout<<"removed 130: "<<endl;
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.remove(200);
    cout<<"removed 200: "<<endl;
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    root.remove(110);
    cout<<"removed 110: "<<endl;
    cout<<"**********************"<<endl;
    cout<<root;
    cout<<"**********************"<<endl;
    if(root.is_valid()){
        cout<<"tree is valid:"<<endl;
    }
    else{
        cout<<"tree is not valid!"<<endl;
    }

//    test_split();
//    test_insertitem();
//    test_copy_array();
//    test_merge();
//    test_deleteitem();
    return 0;
}
void test_split(){
    int n1 = 3;
    int n2 = 0;
    int array[4] = {0, 1, 2, 3};
    int array1[4];

    split(array, n1, array1, n2);

    for(int i = 0; i < n1; ++i){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n2; ++i){
        cout<<array1[i]<<" ";
    }
    cout<<endl;

    cout<<"n1 and n2: "<<n1<<" "<<n2<<endl;
}

void test_insertitem(){
    int n1 = 4;
    int array[5] = {0, 1, 2, 3};
    insert_item(array,2,n1,4);
    for(int i = 0; i < n1; ++i){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<n1<<endl;
}
void test_copy_array(){
    int n1 = 4;
    int n2 = 0;
    int array[4] = {0, 1, 2, 3};
    int array1[4];

    copy_array(array1,array,n2, n1);
    for(int i = 0; i < n2; ++i){
        cout<<array1[i]<<" ";
    }
    cout<<endl;
}

void test_merge(){
    int n1 = 4;
    int n2 = 4;
    int array[8] = {0, 1, 2, 3};
    int array1[4] = {0, 1, 2, 3};

    merge(array, n1, array1, n2);
    for(int i = 0; i < n1; ++i){
        cout<<array1[i]<<" ";
    }
    cout<<endl;
}
void test_deleteitem(){
    int n1 = 4;
    int array[5] = {0, 1, 2, 3};
    int extracted;
    delete_item(array,1, n1, extracted);
    for(int i = 0; i < n1; ++i){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<n1<<endl;
    cout<<extracted<<endl;
}

