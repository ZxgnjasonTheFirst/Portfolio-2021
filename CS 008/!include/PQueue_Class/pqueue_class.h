#ifndef PQUEUE_CLASS_H
#define PQUEUE_CLASS_H
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Heap_Class/heap_class.h"
template <typename T>
struct info{
    T item;
    int priority;

    info(T i = T(), int p = 0): item(i), priority(p){}

    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
        outs<<"|"<<print_me.item<<"| priority: "<<print_me.priority;
        return outs;

    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs){
        return lhs.priority < rhs.priority;
    }

    friend bool operator >(const info<T>& lhs, const info<T>& rhs){
        return lhs.priority > rhs.priority;
    }
};

template <typename T>
class PQueue
{
public:
    PQueue(){}
    bool insert(const T& value, int p){
        try{
            heap.insert(info<T>(value, p));

        }catch(...){
            cout<<"an unknown error occurred..."<<endl;
            return false;
        }
        return true;
    }

    T Pop(){
        return heap.Pop().item;
    }

    info<T> Pop_info(){
        return heap.Pop();
    }

    bool is_empty() const{
        return heap.is_empty();
    }
    int size() const{
        return heap.size();
    }
    void print_tree() const{
        cout<<heap;
    }
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me){
        print_me.print_tree();
        return outs;
    }

private:
    Heap<info<T>> heap;

};
#endif // PQUEUE_CLASS_H
