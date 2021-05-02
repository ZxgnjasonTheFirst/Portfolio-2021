#ifndef CHAINED_HASH_H
#define CHAINED_HASH_H
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/AVL_Class/avl.h"

using namespace std;

/*
FILE: table1.h (part of the namespace main_savitch_12A)
TEMPLATE CLASS PROVIDED: table<RecordType> (a table of records with keys)
    This class is a container template class for a table of records.
    The template parameter, RecordType, is the data type of the records in the table.
    It may be any of the bulit-in C++ types (int, char, etc.), or a class with a default constructor,
    an assignment operator, and an integer member variable called key.

TYPEDEFS and MEMBER CONSTANT for the table<RecordType> class:
    static const size_t CAPACITY = _____
    table<RecordType>::CAPACITY is the maximum number of records held by a table.
CONSTRUCTOR for the table<RecordType> template class:
    table( )
        Postcondition: The table has been initialized as an empty table.
MODIFICATION MEMBER FUNCTIONS for the table<RecordType> class:
    void insert(const RecordType& entry)
    Precondition: entry.key >= 0. Also if entry.key is not already a key in the table, then
    the table has space for another record (that is, size( ) < CAPACITY).
    Postcondition: If the table already had a record with a key equal to entry.key, then that
    record is replaced by entry. Otherwise, entry has been added as a new record of the table.
void remove(int key)
    Postcondition: If a record was in the table with the specified key, then that record has
    been removed. Otherwise the table is unchanged.
CONSTANT MEMBER FUNCTIONS for the table<RecordType> class:
    bool is_present(int key) const
    Postcondition: The return value is true if there is a record in the table with the
    specified key. Otherwise, the return value is false.
void find(int key, bool& found, RecordType& result) const
    Postcondition: If a record is in the table with the specified key, then found is true, and
    result is set to a copy of the record with that key. Otherwise found is false,
    and the result contains garbage.
size_t size( ) const
    Postcondition: Return value is the total number of records in the table.
*/


template <class T>
class chained_hash
{
public:
    enum { TABLE_SIZE = 10 };
    // Or: static const int TABLE_SIZE = 811;

    chained_hash():total_records(0){
    }                                    //CTOR

    bool insert(const T& entry);                        //insert entry
    bool remove(int key);                               //remove this key
    int collisions(){return _collisions;}

    bool find(int key, T& result) const;                //result <- record with key
    bool is_present(int key) const;                     //is this key present in table?
    int size( ) const { return total_records; }         //number of keys in the table
    template<class TT>
    friend ostream& operator << (ostream& outs,         //print entire table with keys, etc.
                                 const chained_hash<TT>& h);
private:
    AVL<T> _data[TABLE_SIZE];                          //table chains
    int total_records;                                  //number of keys in the table
    int _collisions = -1;
    int hash(int key) const{ return (key % TABLE_SIZE);}                            //hash function
//    typename AVL<T>::Iterator find_node(int key) const;//find this key in the table
};

template<class T>
bool chained_hash<T>::insert(const T& entry){
    size_t index; // data[index] is location for the new entry
    assert(entry._key >= 0);
    assert(size( ) < TABLE_SIZE);
//    cout<<"after assert"<<endl;
    index = hash(entry._key);
//    cout<<"after hash"<<endl;
    _data[index].insert(entry);
    ++total_records;


}

template<class T>
bool chained_hash<T>::remove(int key){
    size_t index;
    assert(key >= 0);
    index = hash(key);
    if(_data[index].erase(key)){
        --total_records;
        return true;
    }
    else {
        return false;
    }

}

template<class T>
bool chained_hash<T>::find(int key, T& result) const{
    std::size_t index;
    tree_node<T>* found_ptr;
    bool found;
    assert(key >= 0);
    index = hash(key);   //finds the index
    if(_data[index].search(key, found_ptr)){
        found = true;
    } //searches within the AVL for the key. avl.search(target, found_ptr) returns a bool
    else {
        found = false;
    }
    result = found_ptr->_item; //gives the found item as result.
    return found;
}

template<class T>
bool chained_hash<T>::is_present(int key) const{
    bool found;
    tree_node<T>* found_ptr;
    std::size_t index;
    assert(key >= 0);
    index = hash(key);   //finds the index
    if(_data[index].search(key, found_ptr)){
        found = true;
    } //searches within the AVL for the key. avl.search(target, found_ptr) returns a bool
    else {
        found = false;
    }
    return found;
}

template<class TT>
ostream& operator<<(ostream& outs, const chained_hash<TT>& h){
    for (unsigned int index = 0; index < h.TABLE_SIZE; index++) {
        outs<<"["<<setfill('0')<<setw(3)<<index<<"] ";
        outs<<h._data[index];
        outs<<endl;
    }
    return outs;
}

#endif // CHAINED_HASH_H
