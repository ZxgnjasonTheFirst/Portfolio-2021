#ifndef BST_H
#define BST_H
#include "tree_funcs.h"

using namespace std;
template <typename T>
class BST{
public:
    BST():root(NULL){};
    BST(const T* sorted_list, int size=-1){
        tree_from_sorted_list(sorted_list, size);
    }

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    BST(const BST<T>& copy_me){
        copy_me = tree_copy(root);
    }
    BST<T>& operator =(const BST<T>& rhs){
        if(this != rhs){
            tree_clear(root);
            rhs = tree_copy(root);
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
        tree_search(root, target, found_ptr);
    }

    friend ostream& operator <<(ostream& outs, const BST<T>& tree){
        return tree_print(tree.root, 0, outs);
    }
    BST<T>& operator +=(const BST<T>& rhs){
        BST<T> temp;
        tree_add(temp.root, rhs.root);
        if(temp.root != NULL){
            *this = temp;
        }
        return *this;

    }
private:
 tree_node<T>* root;
};

#endif // BST_H
