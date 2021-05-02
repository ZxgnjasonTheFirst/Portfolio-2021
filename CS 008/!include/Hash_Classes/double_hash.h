#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H
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
class double_hash
{
public:
    // MEMBER CONSTANT -- See Appendix E if this fails to compile.
    enum {CAPACITY = 13};  //****CAPACITY AND CAPACITY - 2 MUST BE PRIME NUMBERS FOR IT TO WORK AND NOT FREEZE WHEN NEAR FULL
    // CONSTRUCTOR
    double_hash( );
    // MODIFICATION MEMBER FUNCTIONS
    bool insert(const T& entry);
    bool remove(int key);
    // CONSTANT MEMBER FUNCTIONS
    bool is_present(int key) const;
    bool find(int key, T& result) const;
    int size( ) const { return used; }
    int collisions(){return _collisions;}
    template<class TT>
    friend ostream& operator << (ostream& outs,const double_hash<TT>& h);         //print entire table with keys, etc.
private:
    // MEMBER CONSTANTS -- These are used in the key field of special records.
    static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;
    // MEMBER VARIABLES
    T data[CAPACITY];
    int used;
    int _collisions;
    // HELPER FUNCTIONS
    int hash(int key) const{return (key % CAPACITY);}
    int hash2(int key) const{return (1 + (key % (CAPACITY - 2)));}
    int next_index(int index,int key) const{return ((index + hash2(key)) % CAPACITY);}
    void find_index(int key, bool& found, int& index) const;
    bool never_used(int index) const;
    bool is_vacant(int index) const;
};

template<class T>
double_hash<T>::double_hash(){
    used = 0;
    for (int i = 0; i < CAPACITY; ++i)
        data[i]._key = NEVER_USED; // Indicates a spot that’s never been used.
}

template<class T>
bool double_hash<T>::insert(const T& entry){
    bool already_present; // True if entry.key is already in the table
    int index; // data[index] is location for the new entry
    assert(entry._key >= 0);
    // Set index so that data[index] is the spot to place the new entry.
    find_index(entry._key, already_present, index);
    // If the key wasn’t already there, then find the location for the new entry.
    if (!already_present)
    {
        assert(size( ) < CAPACITY);
        index = hash(entry._key);
        while (!is_vacant(index)){
            index = next_index(index, entry._key);
            ++_collisions;
        }
        ++used;
    }
    data[index] = entry;
}

template<class T>
bool double_hash<T>::remove(int key){
    bool found; // True if key occurs somewhere in the table
    int index; // Spot where data[index].key == key
    assert(key >= 0);
    find_index(key, found, index);
    if (found){ // The key was found, so remove this record and reduce used by 1.
        data[index]._key = PREVIOUSLY_USED; // Indicates a spot that’s no longer in use.
        --used;
    }
    return found;
}

template<class T>
bool double_hash<T>::is_present(int key) const{
    bool found;
    int index;
    assert(key >= 0);
    find_index(key, found, index);
    return found;
}

template<class T>
bool double_hash<T>::find(int key, T& result) const{
    int index;
    bool found = false;
    assert(key >= 0);
    find_index(key, found, index);
    if (found)
        result = data[index];
    return found;
}

template<class T>
void double_hash<T>::find_index(int key, bool& found, int& index) const{
    int count; // Number of entries that have been examined
    count = 0;
    index = hash(key);
    while((count < CAPACITY) && (!never_used(index)) && (data[index]._key != key)) {
        ++count;
        index = next_index(index, key);
    }
    found = (data[index]._key == key);
}

template<class T>
bool double_hash<T>::never_used(int index) const{
    return (data[index]._key == NEVER_USED);
}

template<class T>
bool double_hash<T>::is_vacant(int index) const{
    return (data[index]._key < 0);
}

template<class TT>
ostream& operator<<(ostream& outs, const double_hash<TT>& h){
    for (int index = 0; index < h.CAPACITY; index++) {
        outs<<"["<<setfill('0')<<setw(3)<<index<<"] ";
        if(h.data[index]._key < 0){
            if(h.data[index]._key == h.PREVIOUSLY_USED)
                outs<<" - - - - - - ";
            else
                outs<<"";
        }
        else{
            outs<<setfill('0')<<setw(4)<<h.data[index]._key<<":"<<setfill('0')<<setw(4)<<h.data[index]._value<< //**NOTE: HAS SETFILLS('0')
                  "("<<setfill('0')<<setw(3)<<h.hash(h.data[index]._key)<<") ";                                 //USED TO ORGANIZE THE DATA
            if(index != h.hash(h.data[index]._key)){
                outs<<"*";
            }
        }
        outs<<endl;
    }
    return outs;
}
#endif // DOUBLE_HASH_H
