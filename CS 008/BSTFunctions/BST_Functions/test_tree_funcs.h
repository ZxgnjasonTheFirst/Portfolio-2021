#ifndef TEST_TREE_FUNCS_H
#define TEST_TREE_FUNCS_H
#include "tree_funcs.h"

void test_tree_insert(){
    tree_node<int>* root = NULL;
    tree_insert(root, 50);
    tree_insert(root, 20);
    tree_insert(root, 70);
    tree_insert(root, 12);
    tree_insert(root, 35);
    tree_insert(root, 100);
    tree_insert(root, 6);
    tree_insert(root, 30);
    tree_insert(root, 40);
    tree_insert(root, 80);
    tree_insert(root, 110);
    tree_insert(root, 75);
    tree_insert(root, 90);

    tree_print_debug(root);

}

void test_tree_clear(){
    tree_node<int>* root = NULL;
    tree_insert(root, 50);
    tree_insert(root, 20);
    tree_insert(root, 70);
    tree_insert(root, 12);
    tree_insert(root, 35);
    tree_insert(root, 100);
    tree_insert(root, 6);
    tree_insert(root, 30);
    tree_insert(root, 40);
    tree_insert(root, 80);
    tree_insert(root, 110);
    tree_insert(root, 75);
    tree_insert(root, 90);

    tree_print_debug(root);

    tree_clear(root);
    tree_print_debug(root);
}

void test_tree_erase(){
    tree_node<int>* root = NULL;
    tree_insert(root, 50);
    tree_insert(root, 20);
    tree_insert(root, 70);
    tree_insert(root, 12);
    tree_insert(root, 35);
    tree_insert(root, 100);
    tree_insert(root, 6);
    tree_insert(root, 30);
    tree_insert(root, 40);
    tree_insert(root, 80);
    tree_insert(root, 110);
    tree_insert(root, 75);
    tree_insert(root, 90);

    tree_print_debug(root);

    tree_erase(root, 20);
    tree_print_debug(root);
}

void test_tree_remove_max(){
    tree_node<int>* root = NULL;
    int max;
    tree_insert(root, 50);
    tree_insert(root, 20);
    tree_insert(root, 70);
    tree_insert(root, 12);
    tree_insert(root, 35);
    tree_insert(root, 100);
    tree_insert(root, 6);
    tree_insert(root, 30);
    tree_insert(root, 40);
    tree_insert(root, 80);
    tree_insert(root, 110);
    tree_insert(root, 75);
    tree_insert(root, 90);

    tree_print_debug(root);

    tree_remove_max(root, max);
    tree_print_debug(root);
}

void test_tree_print_debug(){
    tree_node<int>* root = NULL;
    tree_insert(root, 50);
    tree_insert(root, 20);
    tree_insert(root, 70);
    tree_insert(root, 12);
    tree_insert(root, 35);
    tree_insert(root, 100);
    tree_insert(root, 6);
    tree_insert(root, 30);
    tree_insert(root, 40);
    tree_insert(root, 80);
    tree_insert(root, 110);
    tree_insert(root, 75);
    tree_insert(root, 90);

    tree_print_debug(root);
}

void test_tree_copy(){
    tree_node<int>* root = NULL, *cpy = NULL;

    tree_insert(root, 50);
    tree_insert(root, 20);
    tree_insert(root, 70);
    tree_insert(root, 12);
    tree_insert(root, 35);
    tree_insert(root, 100);
    tree_insert(root, 6);
    tree_insert(root, 30);
    tree_insert(root, 40);
    tree_insert(root, 80);
    tree_insert(root, 110);
    tree_insert(root, 75);
    tree_insert(root, 90);

    cout<<"Original"<<endl;
    tree_print_debug(root);

    cpy = tree_copy(root);

    cout<<"Copy"<<endl;
    tree_print_debug(cpy);
}

void test_tree_add(){
    tree_node<int>* root = NULL, *cpy = NULL;

    tree_insert(root, 50);
    tree_insert(root, 20);
    tree_insert(root, 70);
    tree_insert(root, 12);
    tree_insert(root, 35);
    tree_insert(root, 100);
    tree_insert(root, 6);
    tree_insert(root, 30);
    tree_insert(root, 40);
    tree_insert(root, 80);
    tree_insert(root, 110);
    tree_insert(root, 75);
    tree_insert(root, 90);

    tree_insert(cpy, 42);
    tree_insert(cpy, 35);
    tree_insert(cpy, 75);


    cout<<"Original"<<endl;
    tree_print_debug(root);

    tree_add(root, cpy);
    cout<<"Added"<<endl;
    tree_print_debug(root);
}

void test_tree_frm_srted_lst(){
    int size = 7;
    int value = 1;
    tree_node<int>* root;
    int *list;
    list = new int[size];
    for(int i = 0; i < size; ++i){
        list[i] = value;
        ++value;
        cout<<list[i]<<" ";
    }
    cout<<endl;
    root = tree_from_sorted_list(list, size);

    cout<<"Tree w/ srted list"<<endl;
    tree_print_debug(root);
}

#endif // TEST_TREE_FUNCS_H
