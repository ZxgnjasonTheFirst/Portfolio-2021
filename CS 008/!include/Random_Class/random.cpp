#include <ctime>
#include <cstdlib>
#include <iostream>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Random_Class/random.h"

using namespace std;

//----------------------------------------------------------------------
//initialization of the static member variable must be done in the .cpp file.
//
int Random::objectCount=0;
//
//----------------------------------------------------------------------


Random::Random(){
    objectCount++;
    if (objectCount==1){
        //cout<<endl<<"random number generator seeded..."<<endl;
        //-----------------------------------------------
        srand(time(0));
    }
}

int Random::next(int lo, int hi){
    int r = rand()%(hi-lo+1)+lo;
    return r;

}























