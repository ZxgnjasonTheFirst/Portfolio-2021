#ifndef MMAP_CLASS_H
#define MMAP_CLASS_H
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/BPlusTree_Class/bplustree_funcs.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/MPair_Class/mpair_class.h"

template <typename K, typename V>
class MMap
{
public:
    typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator{
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it):_it(it){}
        Iterator operator ++(int unused){
            _it++;
            return _it;
        }
        Iterator operator ++(){
            ++_it;
            return _it;
        }
        MPair<K, V> operator *(){
            return *_it;
        }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
            return lhs._it == rhs._it;
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
            return lhs._it != rhs._it;
        }

    private:
        typename map_base::Iterator _it;
    };

    MMap(){

    }

//  Iterators
    Iterator begin(){
        return mmap.begin();
    }
    Iterator end(){
        return mmap.end();
    }

//  Capacity
    int size() const{
        return mmap.size();
    }
    bool empty() const{
        return mmap.empty();
    }

//  Element Access
    const vector<V>& operator[](const K& key) const{
        return mmap.get(MPair<K,V>(key)).value_list;
    }
    vector<V>& operator[](const K& key){

        return mmap.get(MPair<K,V>(key)).value_list;
    }

//  Modifiers
    void insert(const K& k, const V& v){
        mmap.insert(MPair<K,V>(k,v));
    }
    void erase(const K& key){
        mmap.remove(MPair<K,V>(key));
    }
    void clear(){
        mmap.clear_tree();
    }

//  Operations:
    bool contains(const K& key) const{
        return mmap.contains(MPair<K,V>(key));
    }
    vector<V>& get(const K& key){
        return mmap.get(MPair<K,V>(key)).value_list;
    }

    Iterator find(const K& key){
        return mmap.find(MPair<K,V>(key));
    }
    int count(const K& key);
    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    Iterator lower_bound(const K& key){
        return find(key);
    }
    Iterator upper_bound(const K& key){
        Iterator it = find(key);
        ++it;
        return it;
    }
    MPair<K,V>& equal_range(const K& key){
        Iterator temp = mmap.find(MPair<K,V>(key));
        return *temp;

    }



    bool is_valid(){
        return mmap.is_valid();
    }

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me){
        outs<<print_me.mmap;
        return outs;
    }

    void seeleaves(){
        mmap.print_leaves();
    }

    MMap<K, V>& operator=(const MMap<K, V> &rhs){
        if(this != &rhs){
            mmap = rhs.mmap;
        }
        return *this;
    }

private:
    BPlusTree<MPair<K, V> > mmap;
};


#endif // MMAP_CLASS_H
