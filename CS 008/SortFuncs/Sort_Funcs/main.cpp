#include <iostream>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Sort_Class/sort_funcs.h"

/*
 * Name: Jason Pambuena
 * Project: Sort_Funcs
 * Purpose: Sorts an array in five different ways (Insertion, Bubble, Quick, Merge, Heap)
 * Notes: Quick sort is the fastest sort. Heap should not have recursion.
 */
using namespace std;

int main()
{
    cout<<endl<<endl;
//    int a[70000];
//    test_shuffle();
    test_insertion_sort();
    test_bubble_sort();
    test_quick_sort();
    test_merge_sort();
    test_heap_sort();
    avg_time_sort_routines();

//    shuffle(a, 50000);
//    heap_sort(a, 50000);
//    cout<<verifystr(a, 50000)<<endl;
}
