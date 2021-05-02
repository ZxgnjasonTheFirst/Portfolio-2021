#ifndef ARRAY_FUNCS_H
#define ARRAY_FUNCS_H
#include <iomanip>
#include <iostream>
using namespace std;
template <class T>
T maximal(const T& a, const T& b){
    if(a > b)
        return a;
    else if(a == b)
        return a;
    else
        return b;
}                      //return the larger of the two items


template <class T>
void insert_item(T data[ ], int i, int& num_used, T entry){    //insert entry at index i in data //*
    for(int j = num_used; j > i; --j){
        data[j] = data[j-1];
    }
    data[i] = entry;
    ++num_used;
}







template <class T>
void swapping(T& a, T& b){
    T swap = a;
    a = b;
    b = swap;
}  //swap the two items

template <class T>
int index_of_maximal(T data[ ], int n);                 //return index of the largest item in data

template <class T>
void ordered_insert(T data[ ], int& n, T entry);        //insert entry into the sorted array
                                                        //data with length n

template <class T>
int first_ge(const T data[ ], int n, const T& entry){//return the first element in data that is
    int i;                                           //not less than entry
    for (i = 0;i < n; i++) {
//        cout<<"looking at: "<<data[i]<<endl;
        if(data[i] >= entry){
            return i;
        }
    }
    return n;

}

template <class T>
void attach_item(T data[ ], int& n, const T& entry){
    data[n] = entry;
    n++;
}    //append entry to the right of data

//template <class T>
//void insert_item(T data[ ], int i, int& n, T entry){    //insert entry at index i in data //*
//    for(int j = n+1; j > i; --j){
//        cout<<"data["<<j<<"] and data["<<j-1<<"]: "<<data[j]<<" "<<data[j-1]<<endl;
//        data[j] = data[j-1];

//    }
//    data[n+1] = 0;
//    data[i] = entry;
//    ++n;
//    cout<<"DATA ARRAY: "<<endl;
//    for(int k = 0; k < n ; ++k){
//        cout<<data[k]<<" ";
//    }
//    cout<<endl;
//}

template <class T>
void detach_item(T data[ ], int& n, T& entry){          //remove the last element in data and place
//    cout<<"detach_item(): "<<data[n-1]<<endl;
    entry = data[n-1];                                  //it in entry
    --n;
}

template <class T>
void delete_item(T data[ ], int i, int& n, T& entry){   //delete item at index i and place it in entry
//    cout<<"delete_item() data[i]: "<<data[i]<<endl;
    entry = data[i];
    for(int j = i; j < n; j++){
        data[j] = data[j+1];
//        cout<<"delete_item() inside for"<<endl;
    }
    --n;
}

template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2){
    for(int i = 0 ; i < n2; ++i, ++n1){
        data1[n1] = data2[i];
    }
    n2 = 0;
}   //append data2 to the right of data1

template <class T>
void split(T data1[ ], int& n1, T data2[ ], int& n2){//move n/2 elements from the right of data1 and move to data2 //*
//    cout<<"split n2: "<<n2<<endl;
    n2 = n1/2;
    for(int i = n1 - n1/2, j = 0; i < n1; ++i,++j){
//        cout<<data2[j]<<" "<<data1[i]<<endl;
        data2[j] = data1[i];

    }
//    cout<<"n1 before: "<<n1<<endl;
    n1 -= n2;
//    cout<<"n1 after: "<<n1<<endl;

}

template <class T>
void copy_array(T dest[], const T src[],
                int& dest_size, int src_size){ //copy src[] into dest[] //*
    dest_size = src_size;
    for(int i = 0; i < src_size; i++){
        dest[i] = src[i];
    }
}

template <class T>
void print_array(const T data[], int n, int pos = -1){
    for(pos = 0; pos < n ; ++pos){
        cout<<data[pos]<<" ";
    }
};  //print array data

template <class T>
bool is_gt(const T data[], int n, const T& item){
    for (int i = 0; i < n; ++i) {
        if(item <= data[i]){
            return false;
        }
    }
    return true;
}       //item > all data[i]

template <class T>
bool is_le(const T data[], int n, const T& item){
    for (int i = 0; i < n; ++i) {
        if(item > data[i]){
            return false;
        }
    }
    return true;
}       //item <= all data[i]

//-------------- Vector Extra operators: ---------------------

template <typename T>
ostream& operator <<(ostream& outs, const vector<T>& list); //print vector list

template <typename T>
vector<T>& operator +=(vector<T>& list, const T& addme){
    list.push_back(addme);
} //list.push_back addme
#endif // ARRAY_FUNCS_H
