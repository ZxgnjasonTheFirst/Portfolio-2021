v#ifndef SORT_FUNCS_H
#define SORT_FUNCS_H
#include <iostream>
#include <iomanip>
#include <exception>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Time_Class/time.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Random_Class/random.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Heap_Class/heap_class.h"

using namespace std;

const int HUGE_SIZE = 70000;
const int BIG_SIZE = 50000;
//shuffle elements of a[]
void shuffle(int a[], unsigned int size){
    Random r;
    for(unsigned int i = 0; i < size; ++i){
        a[i] = i;
    }

    for(unsigned int k = 0; k < size - 1; ++k){
        int randindex = r.next(0, size - 1);
        int swap = a[k];
        a[k] = a[randindex];
        a[randindex] = swap;
    }
}


template <class T>
void copy_array(T dest[], const T src[], unsigned int size){
    for(unsigned int i = 0; i < size; ++i){
        dest[i] = src[i];
    }
}

//return true if a[] is in ascending order
template <class T>
bool verify(const T a[], unsigned int size){
    if(size == 0 || size == 1){
        return true;
    }
    for(unsigned int i = 1; i < size; ++i){
        if(a[i - 1] > a[i])
            return false;
    }
    return true;
}

//return a string "SORTED" or "NOT SORTED" depending if a[] is sorted
template <class T>
string verifystr(const T a[], unsigned int size){
    if(verify(a, size)){
        return "SORTED";
    }
    else {
        return "UNSORTED";
    }
}

//print the array if status_only is true along with info on sortedness of a[]
template <class T>
void print_array(const T a[], int size, bool status_only = false){
    if(status_only){
        cout<<verifystr(a,size)<<endl;
    }
    else {
        cout<<verifystr(a,size)<<endl;
        for(unsigned int i = 0; i < size; ++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;

    }
}

//print a[] from start to end
template <class T>
void print_array_segment(T a[], unsigned int start, unsigned int end){
    for(unsigned int i = start; i <= end; ++i){
        cout<<a[i];
    }
}

template <class T>
void insertion_sort(T a[], unsigned int size){
    int i, sortedkey, j;
    for(i = 1; i < size; ++i){
        sortedkey = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > sortedkey){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j + 1] = sortedkey;
    }
}

template <class T>
void bubble_sort(T a[], unsigned int size){
    bool swapped;
    unsigned int lastunsorted = size;
    do{
        swapped = false;
        for(unsigned int i = 0; i < lastunsorted - 1; ++i){
            if(a[i] > a[i + 1]){
                T swap = a[i];
                a[i] = a[i+1];
                a[i+1] = swap;
                swapped = true;
            }
//            for(unsigned int j = 0; j < size; ++j){
//                cout<<a[j]<<" ";
//            }
//            cout<<endl;
        }
        --lastunsorted;
    }while(swapped);
}


template<class T>
unsigned int partition(T start[], unsigned int size){
    unsigned int storeIndex;
    storeIndex = 1;
    for(unsigned int i = 1; i < size; ++i){
        if(start[i] <= start[0]){
            T swap = start[i];
            start[i] = start[storeIndex];
            start[storeIndex] = swap;
            storeIndex++;
        }
    }
    T swap = start[0];
    start[0] = start[storeIndex-1];
    start[storeIndex-1] = swap;
    return storeIndex;
}

template <class T>
void quick_sort(T a[], unsigned int size){
//    for(int i = 0 ; i < size; ++i){
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
    if(size >= 10){
        unsigned int i = partition(a, size);
        unsigned int newsize = size - i;
        quick_sort(a, i);
        quick_sort(a + i , newsize);
    }
    else{
        insertion_sort(a, size);
//        storeIndex = size;
//        for(unsigned int j = 0; j < 20; ++j){
//            cout<<a[j]<<" ";
//        }
//        cout<<endl;
        return;
    }
}

template<class T>
void merge(T a[], unsigned int size){
    unsigned int i = 0, j = 0, cindex = 0;
    unsigned int left = size/2;
    unsigned int right = size - left;
    T a1[left], a2[right], copy[size];
    copy_array(a1, a, left);
    copy_array(a2, a + left, right);
    while(i < left && j < right){
        if(a1[i] <= a2[j]){
            copy[cindex] = a1[i];
            ++i;
        }
        else {
            copy[cindex] = a2[j];
            ++j;
        }
        ++cindex;
    }
    while(i < left){
        copy[cindex] = a1[i];
        ++i;
        ++cindex;
    }
    while(j < right){
        copy[cindex] = a2[j];
        ++j;
        ++cindex;
    }
    copy_array(a, copy, size);
}

template <class T>
void merge_sort(T a[], unsigned int size){
    if(size > 1){
        merge_sort(a, size/2);
        merge_sort(a + size/2, size - (size/2));
        merge(a,  size);

    }
}

template <class T>
void heap_sort(T a[], unsigned int size){
    Heap<T> t;
    for(unsigned int i = 0; i < size; ++i){
        t.insert(a[i]);
    }
    for(int j = size - 1; j >= 0; --j){
//        cout<<j<<endl;
        a[j] = t.Pop();
    }
}

void test_insertion_sort(){
    cout<<"---------------Insertion Sort-------------"<<endl;
    int a[7] = {12, 43, 2, 87, 32, 31, 10};
    print_array(a, 7);
    insertion_sort(a, 7);
    print_array(a, 7);

}

void test_bubble_sort(){
    cout<<"---------------Bubble Sort-------------"<<endl;
    int a[7] = {12, 5, 2, 87, 32, 31, 10};
    print_array(a, 7);
    bubble_sort(a, 7);
    print_array(a, 7);

}

void test_quick_sort(){
    cout<<"---------------Quick Sort-------------"<<endl;
    int a[20] = {7, 11, 0, 8, 1, 10, 4, 9, 6, 3, 2, 5, 12, 14, 19, 18, 17, 13, 15, 16};
    print_array(a, 20);
    quick_sort(a, 20);
    print_array(a, 20);

}

void test_merge_sort(){
    cout<<"---------------Merge Sort-------------"<<endl;
    int a[20] = {7, 11, 0, 8, 1, 10, 4, 9, 6, 3, 2, 5, 12, 14, 19, 18, 17, 13, 15, 16};
    print_array(a, 20);
    merge_sort(a, 20);
    print_array(a, 20);

}

void test_heap_sort(){
    cout<<"---------------Heap Sort-------------"<<endl;
    int a[20] = {7, 11, 0, 8, 1, 10, 4, 9, 6, 3, 2, 5, 12, 14, 19, 18, 17, 13, 15, 16};
    print_array(a, 20);
    heap_sort(a, 20);
    print_array(a, 20);

}

void test_shuffle(){
    int a[1000];
    shuffle(a, 1000);
    for(int i = 0; i < 1000; ++i){
        cout<<a[i]<<" ";
    }
}

float time_sort_routine(int a[], unsigned int size, void (*f)(int *, unsigned int)){
    timer t;
    t.start();
    f(a, size);
    t.stop();
    return t.duration();
}

float avg_time_sort_routine(void (*f)(int *, unsigned int), int how_many){
    int a[HUGE_SIZE];
    float total_d = 0;
    for (unsigned int i = 0; i < how_many; ++i) {
        shuffle(a, BIG_SIZE);
        float d = time_sort_routine(a, BIG_SIZE, f);
        assert(verify(a, BIG_SIZE));
        total_d += d;
    }
    return total_d/how_many;

}

float avg_time_sort_routines(){

    int a[HUGE_SIZE];
    float d;

    cout<<"---------------AVG Time-------------"<<endl;
    d = avg_time_sort_routine(insertion_sort, 5);
    cout<<"average duration - insertSort("<<BIG_SIZE<<"): "<<fixed<<setprecision(9)<<d<<endl;

    d = avg_time_sort_routine(bubble_sort, 2);
    cout<<"average duration - bubbleSort("<<BIG_SIZE<<"): "<<fixed<<setprecision(9)<<d<<endl;

    d = avg_time_sort_routine(quick_sort, 500);
    cout<<"average duration - quickSort("<<BIG_SIZE<<"): "<<fixed<<setprecision(9)<<d<<endl;

    d = avg_time_sort_routine(merge_sort, 500);
    cout<<"average duration - mergeSort("<<BIG_SIZE<<"): "<<fixed<<setprecision(9)<<d<<endl;

    d = avg_time_sort_routine(heap_sort, 500);
    cout<<"average duration - heapSort("<<BIG_SIZE<<"): "<<fixed<<setprecision(9)<<d<<endl;
}


#endif // SORT_FUNCS_H
