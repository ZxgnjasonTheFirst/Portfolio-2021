#ifndef MAP_CLASS_H
#define MAP_CLASS_H
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/BPlusTree_Class/bplustree_funcs.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Pair_Class/pair_class.h"

using namespace std;
template <class K, class V>
class Map
{
public:
    typedef BPlusTree<Pair<K, V> > map_base;
    class Iterator{
    public:
        friend class Map;
        Iterator(typename map_base::Iterator it):_it(it){}
        Iterator operator ++(int unused){
            _it++;
            return _it;
        }
        Iterator operator ++(){
            ++_it;
            return _it;
        }
        Pair<K, V> operator *(){
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

    Map(){
        key_count = 0;
    }

//  Iterators
    Iterator begin(){
        return map.begin();
    }
    Iterator end(){
        return map.end();
    }

//  Capacity
    int size() const{
        return map.size();
    }
    bool empty() const{
        return map.empty();
    }

//  Element Access
    V& operator[](const K& key){
        return map.get(Pair<K,V>(key)).value;
    }
    V& at(const K& key);
    const V& at(const K& key) const;


//  Modifiers
    void insert(const K& k, const V& v){
        map.insert(Pair<K,V>(k,v));
    }
    void erase(const K& key){
        map.remove(key);
    }
    void clear(){
        map.clear_tree();
    }
    V& get(const K& key){
//        cout<<map.get(Pair<K,V>(key))<<endl;
        return map.get(Pair<K,V>(key)).value;
    }

//  Operations:
    Iterator find(const K& key){
        return map.find(Pair<K,V>(key));
    }
    bool contains(const Pair<K, V>& target) const{
        return map.contains(target);
    }

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
    Pair<K,V>& equal_range(const K& key){
        Iterator temp = map.find(Pair<K,V>(key));
        return *temp;

    }

    bool is_valid(){return map.is_valid();}

    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me){
        outs<<print_me.map;
        return outs;
    }

    Map<K, V>& operator=(const Map<K, V> &rhs){
        if(this != &rhs){
            map = rhs.map;
        }
        return *this;
    }
private:
    int key_count;
    BPlusTree<Pair<K, V> > map;
};


#endif // MAP_CLASS_H
