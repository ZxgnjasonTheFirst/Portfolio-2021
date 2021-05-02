#ifndef BPLUSTREE_FUNCS_H
#define BPLUSTREE_FUNCS_H
#include <iomanip>
#include <iostream>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Array_Funcs/array_funcs.h"

using namespace std;
template <class T>
class BPlusTree
{
public:
    class Iterator{
        public:
            friend class BPlusTree;
            Iterator(BPlusTree<T>* _it=NULL, int _key_ptr = 0):it(_it), key_ptr(_key_ptr){}

            T operator *(){
                assert(key_ptr < it->data_count);
                return it->data[key_ptr];
            }

            Iterator operator++(int un_used){
                Iterator hold;
                hold = it;
                key_ptr++;
                if(key_ptr == it->data_count){
                    key_ptr = 0;
                    it = it->next;
//                    cout<<"IN OPERATOR++:"<<endl;
//                    print_array(it->data,it->data_count);
//                    cout<<endl;

                }
                return hold;


            }
            Iterator operator++(){
                key_ptr++;
                if(key_ptr == it->data_count){
                    key_ptr = 0;
                    it = it->next;
//                    cout<<"IN ++OPERATOR:"<<endl;
//                    print_array(it->data,it->data_count);
//                    cout<<endl;
                }
                return it;
            }
            friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
                return lhs.it == rhs.it && lhs.key_ptr == rhs.key_ptr;
            }

            friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
                return !(lhs == rhs);
            }
            bool is_null(){return !it;}
        private:
            BPlusTree<T>* it;
            int key_ptr;
        };

    BPlusTree(bool dups = false){
//        cout<<"default ctor fired"<<endl;
        dups_ok = dups;
        data_count = 0;
        child_count = 0;
        next = NULL;
    }
    //big three:
    BPlusTree(const BPlusTree<T>& other){
//        cout<<"COPY CTOR FIRED!!"<<endl;
        dups_ok = false;
        data_count = 0;
        child_count = 0;
        next = NULL;
        copy_tree(other);
    }
    ~BPlusTree(){
//        cout<<"destructor fired!!!"<<endl;
        clear_tree();
    }
    BPlusTree<T>& operator =(const BPlusTree<T>& RHS){
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
            BPlusTree<T>* new_root = new BPlusTree<T>;
            copy_array(new_root->data, data, new_root->data_count, data_count);
            copy_array(new_root->subset, subset, new_root->child_count, child_count);
            data_count = 0;
            child_count = 1;
            subset[0] = new_root;
            fix_excess(0);
//            cout<<"INSERT() DATA_COUNT: "<<data_count<<endl;
//            cout<<"INSERT() CHILD COUNT: "<<child_count<<endl;
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
            BPlusTree<T>* shrink_ptr = subset[0];
            copy_array(data, shrink_ptr->data, data_count, shrink_ptr->data_count);
            copy_array(subset, shrink_ptr->subset, child_count, shrink_ptr->child_count);
            shrink_ptr->data_count = 0;
            shrink_ptr->child_count = 0;

        }

    }                //remove entry from the tree

    void clear_tree(/*int level = 0*/){
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
    void copy_tree(const BPlusTree<T>& other){
//        cout<<"COPY_TREE() B4 data_count: "<<data_count<<endl;
//        cout<<"COPY_TREE() data[i]: "<<endl;
//        for(int i = 0 ; i < other.data_count; i++){
//            cout<<other.data[i]<<" ";
//        }
//        cout<<endl;
        assert(empty());
        copy_array(data, other.data, data_count, other.data_count);
//        cout<<"COPY_TREE() after data_count: "<<data_count<<endl;

        for(int j = 0 ; j < other.child_count; ++j){
            subset[j] = new BPlusTree<T>;
        }

        child_count = other.child_count;

//        if(!is_leaf()){
//            if(subset[0]->is_leaf()){
//                for (int k = 0 ; k < child_count - 1; ++k) {
//                    subset[k]->next = subset[k+1];
//                }
//            }
//        }

        for(int k = 0; k < other.child_count; ++k){
            subset[k]->copy_tree(*other.subset[k]);
//            cout<<endl;
//            subset[k]->print_tree();
        }
        if(!is_leaf()){
            for(int j = 0; j < child_count - 1; ++j){
//                cout<<"====================="<<endl;
//                cout<<"this is subset[j]->get_largest_node and subset[j+1].get_smallest_node: "<<endl;
//                cout<<*subset[j+1]->get_largest_node()<<endl;
//                cout<<*subset[j]->get_smallest_node()<<endl;
//                cout<<"====================="<<endl;

                subset[j]->get_largest_node()->next = subset[j+1]->get_smallest_node();
            }
        }

    }      //copy other into this object

    bool contains(const T& entry){              //true if entry can be found in the tree
        if(find_ptr(entry))
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
    const T& get_exist_const(const T& entry)const{                     //return a reference to entry in the tree
        bool debug = false;
        int index = first_ge(data, data_count, entry);
//        cout<<"data_count "<<data_count<<endl;
//        cout<<"index "<<index<<endl;
        bool found = (index < data_count && data[index] == entry); //is data[index] == entry?
//        cout<<data[index]<<endl;
        if (is_leaf()){
            if (found){
                return data[index];
            }
            else{
                if (debug) cout<<"get_existing was called with nonexistent entry"<<endl;
                assert(found);
            }
        }
        if (found) //inner node
            return subset[index+1]->get(entry);
            //or just return true?
        else //not found yet...
            return subset[index]->get(entry);



    }

    T& get_existing(const T& entry){                     //return a reference to entry in the tree
        bool debug = false;
        int index = first_ge(data, data_count, entry);
//        cout<<"data_count "<<data_count<<endl;
//        cout<<"index "<<index<<endl;
        bool found = (index < data_count && data[index] == entry); //is data[index] == entry?
//        cout<<data[index]<<endl;
        if (is_leaf()){
            if (found){
//                cout<<endl<<"data[index]: "<<data[index]<<endl;
                return data[index];
            }
            else{
                if (debug) cout<<"get_existing was called with nonexistent entry"<<endl;
                assert(found);
            }
        }
        else{
            if (found){ //inner node
                return subset[index+1]->get(entry);
            }
            else{ //not found yet...
                return subset[index]->get(entry);
            }
        }


    }

    Iterator find(const T& entry){
        int index = first_ge(data, data_count, entry);
        bool found = (index < data_count && data[index] == entry);
        if(found){
//            cout<<"here"<<endl;
            if(is_leaf()){
                Iterator it = Iterator(this);
                for(int i = 0; i < index; i++){
                    ++it;
                }
                return it;

            }
            else{
                return subset[index + 1]->find(entry);
            }
        }
        else{
            if(is_leaf()){
//                cout<<"STOPPED HERE"<<endl;
//                return NULL;
                Iterator it = Iterator(this);
                for(int i = 0; i < index; i++){
                    ++it;
                }
                return it;
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
            subset[child_count - 1]->print_tree(level + 1);

        }

        for(int i = data_count -1; i >= 0 ; --i){
            print_level(level);
            outs<<data[i]<<" data_count: "<<data_count<<" child_count: "<<child_count<<endl;

            if(child_count != 0){
                subset[i]->print_tree(level+1);
            }

        }

    } //print a readable version of the tree

    void print_leaves(){
        BPlusTree<T>* ptr = get_smallest_node();
        while(ptr != NULL){
            cout<<"|";
            print_array(ptr->data, ptr->data_count);
            cout<<"| -> ";
            ptr = ptr->next;
        }
        cout<<"|||"<<endl;
    }

    friend ostream& operator<<(ostream& outs, const BPlusTree<T>& print_me){
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
         * if (data[last item] is NOT <= all subset[last subtree]->data
         *      return false;
         * for every data[i]
         *      if data[i] is NOT > all subset[i]->data
         *          return false;
         * //now, this is lame:
         * for every data[i]
         *      if data[i] is not in the leaves
         *          return false;
         *
         * for every subtree subset[i]
         *      if !subset[i]->is_valid()
         *          return false;
         */
        if(is_leaf()){return true;}
        if(!is_le(subset[child_count -1]->data, subset[child_count - 1]->data_count, data[data_count -1])){
//            cout<<"is_valid is_le false"<<endl;
            return false;
        }
        for(int i = 0 ; i < data_count; ++i){
            if(!is_gt(subset[i]->data, subset[i]->data_count, data[i])){
//                cout<<"is_valid is_gt false: "<<endl;
                return false;
            }
        }
        for(int j = 0 ; j < data_count; ++j){
            T entry;
            subset[j+1]->get_smallest(entry);
            if(data[j] != entry){
//                cout<<"is_valid get smallest false: "<<endl;
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

    Iterator begin(){
        return Iterator(get_smallest_node());
    }
    Iterator end(){
        return Iterator(NULL);
    }

    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;



private:

    bool dups_ok;                                   //true if duplicate keys may be inserted
    int data_count;                                 //number of data elements
    T data[MAXIMUM + 1];                            //holds the keys
    int child_count;                                //number of children
    BPlusTree* subset[MAXIMUM + 2];                     //subtrees
    BPlusTree* next;

    bool is_leaf() const {return child_count==0;}   //true if this is a leaf node

    T* find_ptr(const T& entry){                    //return a pointer to this key. NULL if not there.
        int index = first_ge(data, data_count, entry);
        bool found = (index < data_count && data[index] == entry);
        if(found){
//            cout<<"here"<<endl;
            if(is_leaf()){
                return &data[index];

            }
            else{
                return subset[index + 1]->find_ptr(entry);
            }
        }
        else{
            if(is_leaf()){
                return NULL;
            }
            else{
                return subset[index]->find_ptr(entry);
            }
        }
    }

    //insert element functions
    void loose_insert(const T& entry){              //allows MAXIMUM+1 data elements in the root
        /*
           int i = first_ge(data, data_count, entry);
           bool found = (i<data_count && data[i] == entry);

           three cases:
             found
             a. found/leaf: deal with duplicates: call +
             b. found/no leaf: subset[i+1]->loose_insert(entry)
                               fix_excess(i+1) if there is a need

             ! found:
             c. !found / leaf : insert entry in data at position i
             c. !found / !leaf: subset[i]->loose_insert(entry)
                                fix_excess(i) if there is a need

                |   found          |   !found         |
          ------|------------------|------------------|-------
          leaf  |a. dups? +        | c: insert entry  |
                |                  |    at data[i]    |
          ------|------------------|------------------|-------
                | b.               | d.               |
                |subset[i+1]->     | subset[i]->      |
          !leaf | loose_insert(i+1)|  loose_insert(i) |
                |fix_excess(i+1)   | fix_excess(i)    |
                |                  |                  |
          ------|------------------|------------------|-------
        */
        int index = first_ge(data, data_count, entry);
        bool found = (index < data_count && data[index] == entry);
//        cout<<data[index]<<endl;
        if(found){
//            cout<<"here"<<endl;
            if(is_leaf()){
                data[index] = entry;
            }
            else {
                subset[index + 1]->loose_insert(entry);
                fix_excess(index + 1);
            }
        }
        else{
            if(is_leaf()){
                 insert_item(data, index, data_count, entry);
            }
            else{
                subset[index]->loose_insert(entry);
                fix_excess(index);
            }
        }
    }
    void fix_excess(int i){                         //fix excess of data elements in child i
        //this node's child i has one too many items: 3 steps:
            //1. add a new subset at location i+1 of this node
            //2. split subset[i] (both the subset array and the data array) and move half into
            //      subset[i+1] (this is the subset we created in step 1.)
            //3. detach the last data item of subset[i] and bring it and insert
            //      it into this node's data[]
            //
            //Note that this last step may cause this node to have too many itesm.
            //  This is OK. This will be
            //  dealt with at the higher recursive level. (my parent will fix it!)
            //
            //NOTE: ODD/EVENNESS
            // when there is an excess, data_count will always be odd
            //  and child_count will always be even.
            //  so, splitting is always the same.

            //  000 B_PLUS_TREE
            //  if (subset[i]->is_leaf())
            //  transfer the middle entry to the right and...
            //  Deal with next pointers. just like linked list insert
        if(subset[i]->data_count == (MAXIMUM + 1)){
            T lastitem = T();
            //1. add a new subset at location i+1 of this node
            BPlusTree<T>* new_sub = new BPlusTree<T>;
            insert_item(subset, i+1, child_count, new_sub);
            //2. split subset[i] (both the subset array and the data array) and move half into
            // subset[i+1] (this is the subset we created in step 1.)
            split(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
            split(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count);
//            cout<<"FIX EXCESS data: "<<endl;
//            cout<<*this<<endl;
            //3. detach the last data item of subset[i] and bring it and insert it into this node's data[]
            detach_item(subset[i]->data, subset[i]->data_count, lastitem);
            insert_item(data, i, data_count, lastitem);
            if(subset[i]->is_leaf()){
                insert_item(subset[i+1]->data, 0, subset[i+1]->data_count, lastitem);
                subset[i+1]->next = subset[i]->next;
                subset[i]->next = subset[i+1];

            }

        }
    }

    //remove element functions:
    void loose_remove(const T& entry){          //allows MINIMUM-1 data elements in the root
        /* four cases:
                leaves:
                     a. not found: there is nothing to do
                     b. found    : just remove the target
                non leaf:
                     c. not found: subset[i]->loose_remove, fix_shortage(i)
                     d. found    : subset[i+1]->loose_remove, fix_shortage(i+1) [...]
                         (No More remove_biggest)

                  |   !found               |   found                 |
            ------|------------------------|-------------------------|-------
            leaf  |  a: nothing            | b: delete               |
                  |     to do              |    target               |
            ------|------------------------|-------------------------|-------
            !leaf | c:                     | d: B_PLUS_TREE          |
                  |  [i]->  loose_remove   |   [i+1]-> loose_remove  |
                  |  fix_shortage(i)       | fix_shortage(i+1) [...] |
            ------|------------------------|-------------------------|-------


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
                assert(index < child_count -1);
                subset[index + 1]->loose_remove(entry);
//                cout<<"over here~"<<endl;
                fix_shortage(index + 1);

                int new_index = first_ge(data, data_count, entry);
                bool found2 = (new_index < data_count && data[new_index] == entry);
                if(found2){
//                    cout<<"Here"<<endl;
                    T smallest;
                    subset[new_index+1]->get_smallest(smallest);
                    data[new_index] = smallest;
                }
                else{
//                    cout<<"right here!"<<endl;
                    int subset_index = first_ge(subset[new_index]->data, subset[new_index]->data_count, entry);
                    bool found3 = (subset_index < data_count && subset[new_index]->data[subset_index] == entry);
                    if(found3){
                        T smallest;
                        subset[new_index]->subset[subset_index + 1]->get_smallest(smallest);
                        subset[new_index]->data[subset_index] = smallest;
                    }
                    else{
//                        cout<<"RETURN!"<<endl;
                        return;
                    }
                }
            }
        }
        else{
            if(is_leaf()){
                return;
            }
            else{
                subset[index]->loose_remove(entry);
//                cout<<"index: "<<index<<endl;
                fix_shortage(index);
//                print_tree();
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
//        cout<<"fix_shortage this is data: "<<endl;
//        cout<<subset[i-1]->data_count<<endl;
//        cout<<"this is i in fix_shortage: "<<i<<endl;
        if(subset[i]->data_count < MINIMUM){
            if(i < child_count - 1 && subset[i+1]->data_count > MINIMUM){
//                cout<<"rotate l("<<i<<")"<<endl;
                rotate_left(i);
            }
            else if(i - 1 >= 0 && subset[i-1]->data_count > MINIMUM){
//                cout<<"rotate r("<<i<<")"<<endl;
                rotate_right(i);
            }
            else if(i - 1 < 0){
//                cout<<"merge("<<i<<") [i]"<<endl;
                merge_with_next_subset(i);
            }
            else if(i + 1 > child_count -1){
//                cout<<"merge("<<i-1<<") [i-1]"<<endl;
                merge_with_next_subset(i-1);
            }
            else {
//                cout<<"merge("<<i-1<<") [i-1]"<<endl;
                merge_with_next_subset(i-1);
            }

        }

    }                       //fix shortage of data elements in child i

    BPlusTree<T>* get_smallest_node(){
        if(!is_leaf()){
            return subset[0]->get_smallest_node();
        }
        else{
            return this;
        }
    }

    BPlusTree<T>* get_largest_node(){
        if(!is_leaf()){
            return subset[child_count - 1]->get_largest_node();
        }
        else{
            return this;
        }
    }

    void get_smallest(T& entry){
        if(!is_leaf()){
            subset[0]->get_smallest(entry);
        }
        else{
            entry = this->data[0];
        }
    }

    void get_biggest(T& entry){
        if(!is_leaf()){
            subset[child_count - 1]->get_biggest(entry);
        }
        else {
            entry = this->data[data_count - 1];
        }
    }

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
        BPlusTree<T>* tempptr;
        if(!subset[i]->is_leaf()){
            attach_item(subset[i]->data, subset[i]->data_count, data[i]);
            delete_item(subset[i+1]->data, i, subset[i+1]->data_count, temp);
            delete_item(data, i, data_count, dumbtemp);
            insert_item(data, i, data_count, temp);
            delete_item(subset[i+1]->subset, 0, subset[i+1]->child_count, tempptr);
            attach_item(subset[i]->subset, subset[i]->child_count, tempptr);
        }
        else if (subset[i]->is_leaf()){
            delete_item(subset[i+1]->data, 0, subset[i+1]->data_count, temp);
            insert_item(subset[i]->data, 0, subset[i]->data_count, temp);
            data[i] = subset[i+1]->data[0];
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
        BPlusTree<T>* tempptr;
//        cout<<"This is data[i]: "<<data[i]<<endl;
        if(!subset[i]->is_leaf()){
            insert_item(subset[i]->data, 0, subset[i]->data_count, data[i-1]);
    //        cout<<"rotate r data[i]: "<<data[i]<<endl;
            detach_item(subset[i-1]->data, subset[i-1]->data_count, temp);
            delete_item(data, i-1, data_count, dumbtemp);
            insert_item(data, i-1, data_count, temp);
            detach_item(subset[i-1]->subset, subset[i-1]->child_count, tempptr);
            attach_item(subset[i]->subset, subset[i]->child_count, tempptr);
        }
        else if (subset[i]->is_leaf()){
            detach_item(subset[i-1]->data, subset[i-1]->data_count, temp);
            insert_item(subset[i]->data, 0, subset[i]->data_count, temp);
            data[i-1] = subset[i]->data[0];
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
        BPlusTree<T>* temp;
        delete_item(data, i, data_count, entry);
        if(!subset[i]->is_leaf()){
            attach_item(subset[i]->data, subset[i]->data_count, entry);
        }
//        cout<<"data_count: "<<data_count<<endl;
        merge(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
        merge(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count);
        delete_item(subset, i+1, child_count, temp);
//        cout<<"merge: child_count: "<<child_count<<endl;
        if(subset[i]->is_leaf()){
            subset[i]->next = temp->next;
        }
//        cout<<"merge temp: "<<temp<<endl;
//        delete temp;

    }             //merge subset i with subset i+1

};
#endif // BPLUSTREE_FUNCS_H
