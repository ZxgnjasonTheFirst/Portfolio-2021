#ifndef MPAIR_CLASS_H
#define MPAIR_CLASS_H
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

template <typename K, typename V>
struct MPair{
    K key;
    vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
    //--------------------------------------------------------------------------------
    MPair(const K& k=K()){
//        cout<<"mpair ctor fired!"<<endl;
        key = k;
        value_list = vector<V>();
    }
    MPair(const K& k, const V& v){
        key = k;
        value_list.push_back(v);
    }
    MPair(const K& k, const vector<V>& vlist){
        key = k;
        value_list = vlist;
    }
    //--------------------------------------------------------------------------------

    //You'll need to overlod << for your vector:
    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me){
        bool debug = false;
        if (debug){
            outs<<"{["<<print_me.key<<"]: "<<"["<<print_me.value_list<<"]}";

        }
        else
            outs<<print_me.key<<" "<<print_me.value_list;
        return outs;

    }

    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs){
//        cout<<"OPERATOR == lhs.key and rhs.key: "<<lhs.key<<" "<<rhs.key<<endl;
        return lhs.key == rhs.key;
    }
    friend bool operator !=(const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return !(lhs == rhs);
    }
    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return lhs.key < rhs.key;
    }
    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return !(rhs < lhs);
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return rhs < lhs;
    }
    friend bool operator >= (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        return !(lhs < rhs);
    }
    friend MPair<K, V>& operator + (const MPair<K, V>& lhs, const MPair<K, V>& rhs){
        if(lhs != rhs){
            assert(lhs == rhs);
        }
        else{
            lhs.value_list.insert(lhs.value_list.end(), rhs.value_list.begin(), rhs.value_list.end());
            return lhs;
        }
    }
    MPair<K, V>& operator = (const MPair<K, V>& rhs){
        if(this != &rhs){
           value_list = rhs.value_list;
           key = rhs.key;
        }
        return *this;
    }
};

template<class V>
ostream& operator <<(ostream& outs, const vector<V>& print_me){
    for(int i = 0 ; i < print_me.size(); ++i){
        outs<<print_me[i];
        if(i != print_me.size() - 1){
            outs<<" ";
        }
    }
    return outs;
}

template<class K, class V>
vector<K>& operator+=(vector<K>& left, V& right){
//    cout<<"right: "<<right<<endl;
    left.push_back(right);
    return left;
}

template<class K, class V>
vector<K>& operator+=(vector<K>& left, const V& right){
//    cout<<"right: "<<right<<endl;
    left.push_back(right);
    return left;
}

template<class K>
vector<K>& operator+=(vector<K>& left, vector<K>& right){
//    cout<<"right: "<<right<<endl;
    for(int i = 0; i < right.size(); ++i){
        left.push_back(right[i]);
    }
    return left;
}

template<class K>
vector<K>& operator+=(vector<K>& left, const vector<K>& right){
//    cout<<"right: "<<right<<endl;
    for(int i = 0; i < right.size(); ++i){
        left.push_back(right[i]);
    }
    return left;
}

template<class K, class V>
vector<K>& operator+(vector<K>& left, V& right){
//    cout<<"right: "<<right<<endl;
    left.push_back(right);
    return left;
}

template<class K, class V>
vector<K>& operator+(vector<K>& left, const V& right){
//    cout<<"right: "<<right<<endl;
    left.push_back(right);
    return left;
}



#endif // MPAIR_CLASS_H
