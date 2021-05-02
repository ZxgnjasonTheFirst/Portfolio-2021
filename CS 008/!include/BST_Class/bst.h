#ifndef BST_H
#define BST_H
#include "tree_funcs.h"

using namespace std;
template <typename T>
class BST{
public:
    BST():root(NULL){
//        cout<<"CTOR fired"<<endl;
    }
    BST(const T* sorted_list, int size=-1){
        tree_from_sorted_list(sorted_list, size);
    }

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    BST(const BST<T>& copy_me){
        root = tree_copy(copy_me.root);
    }
    BST<T>& operator =(const BST<T>& rhs){
        if(this != &rhs){
            tree_clear(root);
            root = tree_copy(rhs.root);
        }
        return *this;
    }
    ~BST(){
        tree_clear(root);
    }

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me){
        tree_insert(root, insert_me);
    }
    void erase(const T& target){
        tree_erase(root, target);
    }
    bool search(const T& target, tree_node<T>* & found_ptr){
        return tree_search(root, target, found_ptr);
    }

    friend ostream& operator <<(ostream& outs, const BST<T>& tree){
        bool DEBUG = false;
        if(DEBUG){
            tree_print_debug(tree.root, 0, outs);
        }
        else{
            tree_print(tree.root, 0, outs);
        }
        return outs;
    }
    BST<T>& operator +=(const BST<T>& rhs){
        tree_add(this->root, rhs.root);
        return *this;

    }
private:
    tree_node<T>* root;
};

#endif // BST_H
