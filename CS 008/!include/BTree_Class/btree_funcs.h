#ifndef BTREE_FUNCS_H
#define BTREE_FUNCS_H
#include <iomanip>
#include <iostream>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Array_Funcs/array_funcs.h"
using namespace std;
template <class T>
class BTree
{
public:
    BTree(bool dups = false){
        dups_ok = dups;
        data_count = 0;
        child_count = 0;
    }
    //big three:
    BTree(const BTree<T>& other){
        copy_tree(other);
    }
    ~BTree(){
        clear_tree();
    }
    BTree<T>& operator =(const BTree<T>& RHS){
        if(this != &RHS){
            clear_tree();
            copy_tree(RHS);
        }
        return *this;
    }

    void insert(const T& entry){
        //in order for this class to be able to keep track of the number of the keys, this function (and the functions
            //  it calls ) must return a success code.
            //If we are to keep track of the number the keys (as opposed to key/values) then the success
            //  code must distinguish between inserting a new key, or adding a new key to the existing key.
            //  (for "dupes_ok")
            //
            //loose_insert this entry into this root.
            //loose_insert(entry) will insert entry into this tree. Once it returns, all the subtrees are valid
            //  btree subtrees EXCEPT this root may have one extra data item:
            //    in this case (we have excess in the root)
            //      create a new node, copy all the contents of this root into it,
            //      clear this root node,
            //      make the new node this root's only child (subset[0])
            //
            //Then, call fix_excess on this only subset (subset[0])
        loose_insert(entry);
        if(data_count == MAXIMUM + 1){
            BTree<T>* new_root = new BTree<T>;
//            cout<<"INSERT() SUBSET: "<<endl;
//            cout<<*subset<<endl;
            copy_array(new_root->data, data, new_root->data_count, data_count);
            copy_array(new_root->subset, subset, new_root->child_count, child_count);
            data_count = 0;
            child_count = 1;
            subset[0] = new_root;
            fix_excess(0);
        }
    }                //insert entry into the tree
    void remove(const T& entry){
        //Loose_remove the entry from this tree.
            //once you return from loose_remove, the root (this object) may have no data and only a single subset
            //now, the tree must shrink:
            //  point a temporary pointer (shrink_ptr) and point it to this root's only subset
            //  copy all the data and subsets of this subset into the root (through shrink_ptr)
            //  now, the root contains all the data and poiners of it's old child.
            //  now, simply delete shrink_ptr (blank out child), and the tree has shrunk by one level.
            //  Note, the root node of the tree will always be the same, it's the child node we delete
        loose_remove(entry);
        if(data_count < MINIMUM){
            BTree<T>* shrink_ptr = subset[0];
            copy_array(data, shrink_ptr->data, data_count, shrink_ptr->data_count);
            copy_array(subset, shrink_ptr->subset, child_count, shrink_ptr->child_count);
            shrink_ptr->data_count = 0;
            shrink_ptr->child_count = 0;

        }

    }                //remove entry from the tree

    void clear_tree(){
        if(is_leaf()){
            data_count = 0;
            child_count = 0;
            return;
        }
        else if (!is_leaf()){
            for(int i = 0; i < child_count; ++i){
//                cout<<"---------------"<<endl;
//                cout<<"subset["<<i<<"](level "<<level<<"): "<<endl;
//                cout<<*subset[i]<<endl;
                subset[i]->clear_tree(/*level + 1*/);
            }
            for(int j = 0; j < child_count; ++j){
                delete subset[j];
            }
            data_count = 0;
            child_count = 0;
        }
    }                          //clear this object (delete all nodes etc.)
    void copy_tree(const BTree<T>& other){
//        cout<<"COPY_TREE() B4 data_count: "<<data_count<<endl;
//        cout<<"COPY_TREE() data[i]: "<<endl;
//        for(int i = 0 ; i < other.data_count; i++){
//            cout<<other.data[i]<<" ";
//        }
//        cout<<endl;
        copy_array(data, other.data, data_count, other.data_count);
//        cout<<"COPY_TREE() after data_count: "<<data_count<<endl;

        for(int j = 0 ; j < other.child_count; ++j){
            subset[j] = new BTree<T>;
        }

        child_count = other.child_count;

        for(int k = 0; k < other.child_count; ++k){
            subset[k]->copy_tree(*other.subset[k]);
//            cout<<k<<endl;
        }





    }      //copy other into this object

    bool contains(const T& entry){              //true if entry can be found in the tree
        if(find(entry))
            return true;
        else
            return false;
    }
    const T& get(const T& item) const{
        assert(contains(item));
        return get_exist_const(item);
    }
    T& get(const T& entry){
        if(!contains(entry)){
            insert(entry);
        }
        return get_existing(entry);
    }
    const T& get_exist_const(const T& entry){                     //return a reference to entry in the tree

        int index = first_ge(data, data_count, entry);
//        cout<<"data_count "<<data_count<<endl;
//        cout<<"index "<<index<<endl;
        bool found = (index < data_count && data[index] == entry); //is data[index] == entry?
//        cout<<data[index]<<endl;
        if(found){
             return data[index];
        }
        else{
            if(is_leaf()){
                assert(found);

            }
            else{
                return subset[index]->get(entry);
            }
        }


    }

    T& get_existing(const T& entry){                     //return a reference to entry in the tree

        int index = first_ge(data, data_count, entry);
//        cout<<"data_count "<<data_count<<endl;
//        cout<<"index "<<index<<endl;
        bool found = (index < data_count && data[index] == entry); //is data[index] == entry?
//        cout<<data[index]<<endl;
        if(found){
             return data[index];
        }
        else{
            if(is_leaf()){
                assert(found);

            }
            else{
                return subset[index]->get(entry);
            }
        }


    }
    T* find(const T& entry){                    //return a pointer to this key. NULL if not there.
        int index = first_ge(data, data_count, entry);
        bool found = (index < data_count && data[index] == entry);
        if(found){
//            cout<<"here"<<endl;
            return &data[index];
        }
        else{
            if(is_leaf()){
                return NULL;
            }
            else{
                return subset[index]->find(entry);

            }
        }
    }
    int size() const{
        int count = 0;
        return size_recurs(count);
    }                           //count the number of elements in the tree
    int size_recurs(int& count) const{
        count += data_count;
        for(int i = 0; i < child_count; ++i){
            subset[i]->size_recurs(count);
        }
        return count;
    }
    bool empty() const{
        if(child_count == 0 && data_count == 0){
            return true;
        }
        else {
            return false;
        }
    }                         //true if the tree is empty

    void print_tree(int level = 0, ostream &outs=cout) const{
        if(child_count != 0){
            subset[child_count - 1]->print_tree(level +  1);

        }

        for(int i = data_count -1; i >= 0 ; --i){
            print_level(level);
            outs<<data[i]<<" data_count: "<<data_count<<" child_count: "<<child_count<<endl;

            if(child_count != 0){
                subset[i]->print_tree(level+1);
            }

        }

    } //print a readable version of the tree

    void make_tree(){
        BTree<int>* root = new BTree<int>;
        BTree<int>* walker = root;
        walker->data[0] = 100;
        walker->data[1] = 300;
        walker->data_count=2;       //**
        walker->child_count = 3;    //**
        for (int i= 0; i< walker->child_count; i++){
            walker->subset[i] = new BTree<int>;
        }
        BTree<int>* walker2 = walker->subset[0];
        walker2->child_count= 2; //**
        walker2->data_count = 1;//**
        walker2->data[0] = 50;

        for (int i= 0; i < walker2->child_count; i++){
            walker2->subset[i] = new BTree<int>;
        }
        BTree<int>* walker3 = walker2->subset[0];
        walker3->child_count = 0; //**
        walker3->data_count = 1;  //**
        walker3->data[0] = 30;

        walker3 = walker2->subset[1];
        walker3->child_count = 0; //**
        walker3->data_count = 1;  //**
        walker3->data[0] = 80;

    //------------------------------------------------

        walker2 = walker->subset[1];
        walker2->child_count= 3;//**
        walker2->data_count = 2;//**
        walker2->data[0] =150;
        walker2->data[1] =200;

        for (int i= 0; i < walker2->child_count; i++){
            walker2->subset[i] = new BTree<int>;
        }
        walker3 = walker2->subset[0];
        walker3->child_count = 0; //**
        walker3->data_count = 1;  //**
        walker3->data[0] = 120;

        walker3 = walker2->subset[1];
        walker3->child_count = 0; //**
        walker3->data_count = 1;  //**
        walker3->data[0] = 170;

        walker3 = walker2->subset[2];
        walker3->child_count = 0; //**
        walker3->data_count = 1;  //**
        walker3->data[0] = 250;

    //------------------------------------------------

        walker2 = walker->subset[2];
        walker2->child_count= 2;//**
        walker2->data_count = 1;//**
        walker2->data[0] = 350;

        for (int i= 0; i < walker2->child_count; i++){
            walker2->subset[i] = new BTree<int>;
        }

        walker3 = walker2->subset[0];
        walker3->child_count = 0; //**
        walker3->data_count = 1;  //**
        walker3->data[0] = 310;

        walker3 = walker2->subset[1];
        walker3->child_count = 0; //**
        walker3->data_count = 1;  //**
        walker3->data[0] = 370;


        root->print_tree();
        cout<<"got: "<<root->get(370)<<endl;
        cout<<"----------------------------------"<<endl;
        root->get(370) = 375;
        root->get(90);
        root->print_tree();
        cout<<"----------------------------------"<<endl;
        root->insert(380);
        root->insert(365);
        root->insert(390);
        root->print_tree();
        cout<<"----------------------------------"<<endl;
//        cout<<"ROOT SUBSET[2]->CHILD_COUNT: "<<root->subset[2]->child_count<<endl;
        root->insert(400);
        root->print_tree();
//        BTree<int> copy;
//        int entry;
//        copy.copy_tree(*root);

//        cout<<"----------------------------------"<<endl;
//        cout<<"Copy:"<<endl;
//        copy.print_tree();
//        cout<<"size: "<<copy.size()<<endl;
//        cout<<"----------------------------------"<<endl;
//        cout<<"Deleted 30 and added 175:"<<endl;
//        copy.remove(30);
//        copy.insert(175);
//        copy.print_tree();
//        cout<<"----------------------------------"<<endl;
//        cout<<"Deleted 250:"<<endl;
//        copy.remove(250);
//        copy.print_tree();
//        cout<<"----------------------------------"<<endl;
//        cout<<"Deleted 80:"<<endl;
//        copy.remove(80);
//        copy.print_tree();
//        cout<<"size: "<<copy.size()<<endl;
//        cout<<"----------------------------------"<<endl;
//        cout<<"Deleted 50 and 90:"<<endl;
//        copy.remove(50);
//        copy.remove(90);
//        copy.print_tree();

//        cout<<"size: "<<copy.size()<<endl;
//        cout<<"----------------------------------"<<endl;
//        cout<<"Cleared tree:"<<endl;
//        copy.clear_tree();
//        cout<<copy;

//        copy.remove_biggest(entry);
//        copy.print_tree();
//        cout<<entry<<endl;
    }
    friend ostream& operator<<(ostream& outs, const BTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }
    void print_level(int level, ostream &outs=cout) const{
        for (int j = 0; j < level; ++j) {
            outs<<"     ";
        }
    }

    bool is_valid(){
        /*
         * is_valid():
         *  check to see if all B+ tree conditions are met with the current (sub)tree:
         * if is_leaf: return true;
         * if (data[last item] is <= all subset[last subtree]->data
         *      return false;
         * for every data[i]
         *      if data[i] is NOT > all subset[i]->data
         *          return false;
         * for every subtree subset[i]
         *      if !subset[i]->is_valid()
         *          return false;
         */
        if(is_leaf()){return true;}
        if(is_le(subset[child_count -1]->data, subset[child_count - 1]->data_count, data[data_count -1])){
//            cout<<"Here is data[last item]: "<<data[data_count - 1]<<endl;
            cout<<"is_valid is_le false"<<endl;
            return false;
        }
        for(int i = 0 ; i < data_count; ++i){
            if(!is_gt(subset[i]->data, subset[i]->data_count, data[i])){
                return false;
            }
        }
        for(int k = 0 ; k < child_count; ++k){
            if(!subset[k]->is_valid()){
                return false;
            }
        }
        return true;
    }

    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;



private:

    bool dups_ok;                                   //true if duplicate keys may be inserted
    int data_count;                                 //number of data elements
    T data[MAXIMUM + 1];                            //holds the keys
    int child_count;                                //number of children
    BTree* subset[MAXIMUM + 2];                     //subtrees

    bool is_leaf() const {return child_count==0;}   //true if this is a leaf node

    //insert element functions
    void loose_insert(const T& entry){              //allows MAXIMUM+1 data elements in the root
        /*
               int i = first_ge(data, data_count, entry);
               bool found = (i<data_count && data[i] == entry);

               three cases:
                 a. found: deal with duplicates
                 ! found:
                 b. leaf : insert entry in data at position i
                 c. !leaf: subset[i]->loose_insert(entry)
                           fix_excess(i) if there is a need
                    |   found     |   !found        |
              ------|-------------|-----------------|-------
              leaf  |  a. Deal    | b: insert entry |
                    |     with    |    at data[i]   |
              ------|  duplicates |-----------------|-------
                    |             | d: subset[i]->  |
              !leaf |             |    loose_insert |
                    |             |    fix_excess(i)|
              ------|-------------|-----------------|-------
        */
        int index = first_ge(data, data_count, entry);
        bool found = (index < data_count && data[index] == entry);
//        cout<<found<<endl;
//        cout<<data[index]<<endl;
        if(found){
//            cout<<"here"<<endl;
            data[index] = entry;
            return;
        }
        else{
            if(is_leaf()){
//                cout<<"Child_count before: "<<child_count<<endl;
                insert_item(data, index, data_count, entry);
                cout<<"Child_count after insert_item: "<<child_count<<endl;
                return;
            }
            else{
                subset[index]->loose_insert(entry);
//                cout<<"INDEX AFTER LOOSE_INSERT IN INSERT: "<<index<<endl;
//                cout<<"LOOSE_INSERT subset cc: "<<subset[index]->child_count<<endl;
                fix_excess(index);
                return;
            }
        }
//        cout<<"LOOSE_INSERT subset cc AT THE END: "<<subset[index]->child_count<<endl;

    }
    void fix_excess(int i){                         //fix excess of data elements in child i
        //this node's child i has one too many items: 3 steps:
        //1. add a new subset at location i+1 of this node
        //2. split subset[i] (both the subset array and the data array) and move half into
        // subset[i+1] (this is the subset we created in step 1.)
        //3. detach the last data item of subset[i] and bring it and insert it into this node's data[]
        // //Note that this last step may cause this node to have too many items. This is OK. This will be
        // dealt with at the higher recursive level. (my parent will fix it!)
        if(subset[i]->data_count == (MAXIMUM + 1)){
            T lastitem = 0;
            //1. add a new subset at location i+1 of this node
            BTree<T>* new_sub = new BTree<T>;
            insert_item(subset, i+1, child_count, new_sub);
            //2. split subset[i] (both the subset array and the data array) and move half into
            // subset[i+1] (this is the subset we created in step 1.)
            split(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
            split(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count);
            //3. detach the last data item of subset[i] and bring it and insert it into this node's data[]
            detach_item(subset[i]->data, subset[i]->data_count, lastitem);
            insert_item(data, i, data_count, lastitem);

        }
    }

    //remove element functions:
    void loose_remove(const T& entry){          //allows MINIMUM-1 data elements in the root
        /* four cases:
                 a. leaf && not found target: there is nothing to do
                 b. leaf && found target: just remove the target
                 c. not leaf and not found target: recursive call to loose_remove
                 d. not leaf and found: replace target with largest child of subset[i]

                    |   !found    |   found       |
              ------|-------------|---------------|-------
              leaf  |  a: nothing | b: delete     |
                    |     to do   |    target     |
              ------|-------------|---------------|-------
              !leaf | c: loose_   | d: replace    |
                    |    remove   |    w/ biggest |
              ------|-------------|---------------|-------


        */
        int index = first_ge(data, data_count, entry);
        bool found = (index < data_count && data[index] == entry);
//        cout<<data[index]<<endl;
        if(found){
            if(is_leaf()){
//                cout<<"found & is_leaf()"<<endl;
                T entry;
                delete_item(data, index, data_count, entry);
                return;
            }
            else{
                subset[index]->remove_biggest(data[index]);
                return;
            }
        }
        else{
            if(is_leaf()){
                return;
            }
            else{
                subset[index]->loose_remove(entry);
//                cout<<"after loose_remove()"<<endl;
                fix_shortage(index);
            }
        }
    }
    void fix_shortage(int i){
        /*
         * fix shortage in subtree i:
         * if child i+1 has more than MINIMUM, rotate left
         * elif child i-1 has more than MINIMUM, rotate right
         * elif there is a right child, merge child i with next child
         * else merge child i with left child
         */
//        cout<<"fix_shortage() data[0] and subset[i]->data_count: "<<data[0]<<" "<<subset[i]->data_count<<endl;
        if(subset[i]->data_count < MINIMUM){
            if(i < child_count - 1 && subset[i+1]->data_count > MINIMUM){
//                cout<<"rotate l"<<endl;
                rotate_left(i);
            }
            else if(i - 1 >= 0 && subset[i-1]->data_count > MINIMUM){
//                cout<<"rotate r"<<endl;
                rotate_right(i);
            }
            else if(i - 1 < 0){
//                cout<<"merge("<<i<<")"<<endl;
                merge_with_next_subset(i);
            }
            else if(i + 1 > child_count -1){
//                cout<<"merge("<<i-1<<")"<<endl;
                merge_with_next_subset(i-1);
            }
            else {
                cout<<"merge("<<i<<") [i]"<<endl;
                merge_with_next_subset(i);
            }

        }

    }                       //fix shortage of data elements in child i

    void remove_biggest(T& entry){
        // Keep looking in the last subtree (recursive)
        //  until you get to a leaf.
        // Then, detach the last (biggest) data item
        //
        // after the recursive call, fix shortage.
        if(!is_leaf()){
            subset[child_count - 1]->remove_biggest(entry);
            fix_shortage(child_count - 1);
            return;
        }
        detach_item(data, data_count, entry);

    }                  //remove the biggest child of this tree->entry
    void rotate_left(int i){
        /*
         * (0 < i < child_count) and (subset[i]->data_count > MINIMUM)
         * subset[i-1] has only MINIMUM - 1 entries.
         *
         * item transfers from child[i] to child [i-1]
         *
         * FIRST item of subset[i]->data moves up to data to replace data[i-1],
         * data[i-1] moves down to the RIGHT of subset[i-1]->data
         *
         *  i = 1:
         *              [50 100]
         *  [  ]        [65 75]       ....
         *            [a]  [b]  [c]
         *
         *  65 move up to replace 50 (data[i])
         *  65's child (its child 0) moves over to be the child of 50
         *  50 moves down to the right of subset[i]->data
         *
         *              [65 100]
         *  [50]         [ 75 ]       ....
         *     [a]      [b]  [c]
         *
         *
         *
         *
         */
        // If necessary, shift first subset of subset[i] to end of subset[i-1]
        T dumbtemp;
        T temp;
        BTree<T>* tempptr;
        attach_item(subset[i]->data, subset[i]->data_count, data[i]);
        delete_item(subset[i+1]->data, i, subset[i+1]->data_count, temp);
        delete_item(data, i, data_count, dumbtemp);
        insert_item(data, i, data_count, temp);
        if(!subset[i]->is_leaf()){
            delete_item(subset[i+1]->subset, 0, subset[i+1]->child_count, tempptr);
            attach_item(subset[i]->subset, subset[i]->child_count, tempptr);
        }

    }                        //transfer one element LEFT from child i
    void rotate_right(int i){
        /* (i < child_count - 1) and (subset[i]->data_count > MINIMUM)
         * subset[i+ 1] has only MINIMUM - 1 entries.
         *
         * item transfers from child[i] to child [i+1]
         *
         * LAST item of subset[i]->data moves up to data to replace data[i],
         * data[i] moves down to the LEFT of subset[i+1]->data
         *
         * i = 1
         *                     [50 100]
         *      [20 30]        [65 75]          [ ]
         *  [..] [..] [..]   [a] [b] [c]        [..]
         *
         *  75 moves up to replace 100 (data[i])
         *  75's child (its last child) moves over to be the (child 0) child of 100
         *  100 moves down to subset[i]->data
         *
         *                     [50 75]
         *      [20 30]          [65]          [100]
         *  [..] [..] [..]     [a] [b]        [c] [..]
         *
         *
         *
         *
         *
         */
        // If necessary, shift last subset of subset[i] to front of subset[i+1]
        T dumbtemp;
        T temp;
        BTree<T>* tempptr;
//        cout<<"This is data[i]: "<<data[i]<<endl;
        insert_item(subset[i]->data, 0, subset[i]->data_count, data[i-1]);
//        cout<<"rotate r data[i]: "<<data[i]<<endl;
        detach_item(subset[i-1]->data, subset[i-1]->data_count, temp);
        delete_item(data, i-1, data_count, dumbtemp);
        insert_item(data, i-1, data_count, temp);
        if(!subset[i]->is_leaf()){
            detach_item(subset[i-1]->subset, subset[i-1]->child_count, tempptr);
            attach_item(subset[i]->subset, subset[i]->child_count, tempptr);
        }
    }                       //transfer one element RIGHT from child i
    void merge_with_next_subset(int i){
    /*
     *  Merge subset[i] with subset [i+1] with data[i] in the middle
     *
     *   1. remove data[i] from this object
     *   2. append it to child[i]->data
     *   3. Move all data items from subset[i+1]->data to subset[i]->data
     *   4. Move all subset pointers from subset[i+1]->subset to subset[i]->subset
     *   5. delete subset[i+1] (store in a temp ptr)
     *   6. delete temp ptr
     */
        T entry;
        BTree<T>* temp;
        delete_item(data, i, data_count, entry);
        attach_item(subset[i]->data, subset[i]->data_count, entry);
        merge(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
        merge(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count);
        delete_item(subset, i+1, child_count, temp);
//        cout<<"merge temp: "<<temp<<endl;
//        delete temp;

    }             //merge subset i with subset i+1

};
#endif // BTREE_FUNCS_H
