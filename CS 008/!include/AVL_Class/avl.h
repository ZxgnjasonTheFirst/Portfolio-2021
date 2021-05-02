#ifndef AVL_H
#define AVL_H
#include "tree_funcs.h"

using namespace std;
template <typename T>
class AVL{
public:
    AVL():root(NULL){}
    AVL(const T* sorted_list, int size=-1){
        tree_from_sorted_list(sorted_list, size);
    }

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    AVL(const AVL<T>& copy_me){
        root = tree_copy(copy_me.root);
    }
    AVL<T>& operator =(const AVL<T>& rhs){
        if(this != &rhs){
            tree_clear(root);
            root = tree_copy(rhs.root);
        }
        return *this;
    }
    ~AVL(){
        tree_clear(root);
    }

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me){
//        cout<<"in insert"<<endl;
        tree_insert(root, insert_me);

    }
    bool erase(const T& target){
        return tree_erase(root, target);
    }
    bool search(const T& target, tree_node<T>* & found_ptr) const{
        return tree_search(root, target, found_ptr);
    }

    friend ostream& operator <<(ostream& outs, const AVL<T>& tree){
        bool DEBUG = false;
        bool PRINT_NORMAL = false;
        bool PRINT_INORDER = true;
        if(DEBUG){
            tree_print_debug(tree.root, 0, outs);
        }
        if(PRINT_NORMAL){
            tree_print(tree.root, 0, outs);
        }
        if(PRINT_INORDER){
            tree_print_inorder(tree.root, 0, outs);
        }
        return outs;
    }
    AVL<T>& operator +=(const AVL<T>& rhs){
        tree_add(this->root, rhs.root);
        return *this;

    }
private:
    tree_node<T>* root;
};

#endif // AVL_H
