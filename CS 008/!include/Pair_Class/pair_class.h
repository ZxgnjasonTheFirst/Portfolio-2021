#ifndef PAIR_CLASS_H
#define PAIR_CLASS_H
#include <iomanip>
#include <iostream>
using namespace std;
template <class K, class V>
struct Pair{
    K key;
    V value;

    Pair(const K& k=K(), const V& v=V()):key(k),value(v){}
    friend ostream& operator <<(ostream& outs, const Pair<K, V>& print_me){
        bool debug = false;
        if (debug){
            outs<<"{["<<print_me.key<<"]: "<<"["<<print_me.value<<"]}";

        }
        else
            outs<<print_me.key<<" "<<print_me.value;
        return outs;
    }
    friend bool operator ==(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return lhs.key == rhs.key;
    }
    friend bool operator !=(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return !(lhs == rhs);
    }
    friend bool operator < (const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return lhs.key<rhs.key;
    }
    friend bool operator > (const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return rhs < lhs;
    }
    friend bool operator <= (const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return !(rhs < lhs);
    }
    friend bool operator >= (const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        return !(lhs < rhs);
    }
    friend Pair<K, V>& operator + (const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        if(lhs != rhs){
            assert(lhs == rhs);
        }
        else{
            return rhs;
        }
    }
    Pair<K, V>& operator = (const Pair<K, V>& rhs){
        if(this != &rhs){
           value = rhs.value;
           key = rhs.key;
        }
        return *this;
    }
};

#endif // PAIR_CLASS_H
