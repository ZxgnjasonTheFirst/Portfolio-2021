#ifndef HEAP_CLASS_H
#define HEAP_CLASS_H
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
template <typename T>
class Heap{
public:
    void insert(const T& insert_me){
        //Can't use find here because it takes time to search through the whole vector
        //if there are duplicates.
        array.push_back(insert_me);
        swap_with_parent(size()-1);
    }

    T Pop(){
        //Better to have the program terminate. In this level you shouldn't tell the user what to do with his life.
        //The message is for the programmer that you F**ed up here.
        assert(!is_empty());
        T item = array[0];
        array[0] = array[size()-1]; //assigns the first with the last.
        array.pop_back();         //takes out the last element which is now the first.
        swap_with_big_child(0);
        return item;

    }

    bool is_empty() const{
        return array.empty();
    }

    int size() const{
        return array.size();
    }

    int capacity() const{
        return array.capacity();
    }

    friend ostream& operator << (ostream& outs, const Heap<T>& print_me){
        print_me.print_tree();
        return outs;
    }

private:
    void print_tree(ostream& outs = cout) const{
        //calls the other recursive print tree so that the arguments won't interfere.
        print_tree(0);
    }
    void print_tree(unsigned int root, int level = 0, ostream& outs = cout) const{
        //Just like BSTs.
        bool DEBUG = false; //DEBUG
        if(root >= size()){
            return;
        }
        level++;

        print_tree(right_child_index(root), level);
        outs<<endl;
        for(int i = 0; i < level-1; ++i){
            outs<<"     ";
        }
        outs<<"|"<<array[root]<<"|";
        if(DEBUG) //to see index
            outs<<" i: "<<root;
        outs<<endl;
        print_tree(left_child_index(root), level);
    }


    bool is_leaf(unsigned int i) const{  //checks to see if node is a root or a leaf
//        cout<<"left i: "<<left_child_index(i)<<" size: "<<size()<<endl;
        if(left_child_index(i) > size()-1)  //if there is no left child then current node is a leaf.
            return true;
        else
            return false;
    }

    unsigned int parent_index(unsigned int i) const{
        return (i-1)/2;
    }

    unsigned int left_child_index(unsigned int i)const{
        return (2*i)+1;
    }

    unsigned int right_child_index(unsigned int i) const{
        return (2*i)+2;
    }

    unsigned int big_child_index(unsigned int i) const{
        //I use this to pop the heap and make the most recent value sink.
        if(right_child_index(i) > size()){
            return left_child_index(i);
        }
        else {
            if(array[left_child_index(i)] > array[right_child_index(i)]){
                return left_child_index(i);
            }
            else {
                return right_child_index(i);
            }
        }

    }

    void swap_with_parent(unsigned int i){  //Cleaner to be called from insert.
        while(i > 0 && array[i] > array[parent_index(i)]){ //if the current element is larger than parent (belongs to top)
            swap(array[i], array[parent_index(i)]);     //makes sure that the index doesn't go under zero.
            i = parent_index(i);
        }
    }

    void swap_with_big_child(unsigned int i){ //Cleaner to be called from pop
        unsigned int big_child;
        while(!is_leaf(i) && array[i] < array[big_child_index(i)]){
            //if the current element is smaller than parent (bring to top, let it sink)
            //also checking to make sure if the current index is a leaf

            //DEBUG
//            cout<<"i: "<<i<<" and big_child_index: "<<big_child_index(i)<<" "<<array[i]<<" and "<<array[big_child_index(i)]<<endl;
//            cout<<"size: "<<size()<<endl;
            //DEBUG

            //DEBUG
//            cout<<"swapping "<<array[i]<<" and "<<array[big_child_index(i)]<<endl;
            //DEBUG
            big_child = big_child_index(i);
            swap(array[i], array[big_child_index(i)]);
            i = big_child;
            //DEBUG
//            cout<<"++++++++i: "<<i<<" and big_child_index: "<<big_child_index(i)<<" "<<array[i]<<" and "<<array[big_child_index(i)]<<endl;
//            cout<<"size: "<<size()<<endl;
            //DEBUG


        }
    }

    vector<T> array;

};
#endif // HEAP_CLASS_H
