#include <iostream>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/MultiMap_Class/mmap_class.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Map_Class/map_class.h"

using namespace std;

int main()
{
    Map<string, string> names;
    names["Jason"] = "Pambuena";
    names["Joe"] = "Anderson";
    names["Andres"] = "Jackson";
    cout<<names<<endl;
    cout<<"here b4"<<endl;
    cout<<"get: |"<<names.get("Jason")<<"|"<<endl;;
    cout<<"[]: |"<<names["jason"]<<"|"<<endl;
    cout<<"here after"<<endl;

    MMap<string, string> othernames;

    othernames["Jason"].push_back("Pambuena");
    othernames["Jason"] += "Kai";
    othernames["Jason"] = othernames["Jason"] + "Chu";
    cout<<"here b4 mmap"<<endl;
    cout<<othernames["Jason"]<<endl;
    cout<<"here after mmap"<<endl;

}
