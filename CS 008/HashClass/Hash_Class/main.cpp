#include <iostream>
#include <iomanip>
#include <time.h>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Hash_Classes/chained_hash.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Hash_Classes/double_hash.h"

/*
 * Name: Jason Pambuena
 * Project: Hash_Class
 * Purpose: Creates an array in which we can quickly search for an item through a key or a hash function.
 * Notes: Double Hash must have a prime number for CAPACITY and CAPACITY - 2 to work, or else it ends up in an
 * infinite loop. Also, do not use setfills for the >>operator for records because that would mess up the format of
 * the users record.
 */
using namespace std;
using namespace std::chrono;
template<class T>
void test_hash_table_interactive(T& hash, string type); //FORGOT THE PASS BY REFFFF-FUUUU **future note: DONT FORGET PASS BY REF.

template<class T>
void test_hash_table_random(T& hash, int how_many, string type);
void interactive_menu();

struct record
{
    int _key;
    double _value;

    record(int k=0, double v=0):_key(k), _value(v){}
    friend bool operator ==(const record& left, const record& right){
        return left._key == right._key;
    }
    friend bool operator<(const record& left, const record& right){
        return left._key < right._key;
    }
    friend bool operator>(const record& left, const record& right){
        return left._key > right._key;
    }
    friend ostream& operator <<(ostream& outs, const record& print_me){
        outs<<print_me._key<<":"<<print_me._value;  //**NOTE: NO SETFILLS('0').
        return outs;                                //Records should not have a set format to overwrite the users info
    }
};

int main()
{
    srand(time(0));
    cout<<endl<<endl<<endl<<"----------------------"<<endl<<endl<<endl;
    const bool RANDOM_CHAINED = false;
    const bool RANDOM_DOUBLE = false;
    const bool INTERACTIVE_DOUBLE = false;
    const bool INTERACTIVE_CHAINED = true;

    if (INTERACTIVE_DOUBLE){
        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
        double_hash<record> doubled;
        test_hash_table_interactive(doubled, "double_hash_table" );
    }

    if (INTERACTIVE_CHAINED){
        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
        chained_hash<record> chained;
        test_hash_table_interactive(chained, "chained_hash_table" );
    }

    if (RANDOM_CHAINED){
        //----------- RANDOM TEST ------------------------------
        //. . . . . .  Chained Hash Table . . . . . . . . . . .;
        chained_hash<record> c_table;
        test_hash_table_random(c_table, 500, "chained_hash_table<record>");
//        cout<<c_table<<endl;
    }

    if (RANDOM_DOUBLE){
        //----------- RANDOM TEST ------------------------------
        //. . . . . .  Simple Hash Table . . . . . . . . . . .;
        double_hash<record> d_table;
        test_hash_table_random(d_table, 500, "double_hash_table<record>");
//        cout<<d_table<<endl;
    }

    cout<<endl<<endl<<endl<<"---------------------------------"<<endl;
//    AVL<int> test;
//    test.insert(75);
//    test.insert(50);
//    test.insert(25);
//    test.insert(65);
//    test.insert(95);
//    test.insert(85);
//    test.insert(110);
//    cout<<test;
//    int rnd_key;
//    double rnd_val;
//    rnd_val = rand() % 9999 + 1;
//    rnd_key = rand() % 9999 + 1;

//    chained_hash<record> test;
//    test.insert(record(1, 3000));
//    test.insert(record(11, 4500));
//    test.insert(record(300, 52));
//    test.insert(record(rnd_key, rnd_val));
//    cout<<test<<endl;
//    test.remove(300);
//    cout<<test<<endl;
    return 0;
}

template<class T>
void test_hash_table_interactive(T& hash, string type){
    bool done = false;
    char menu;
    int key;
    double val;
    int rnd_key;
    double rnd_val;
    record ans;
    cout<<type<<endl;
    cout<<"Table of {int:double}"<<endl;
    do{
        interactive_menu();
//        cout<<hash<<endl;
        cin>>menu;
        switch(toupper(menu)){
        case 'S':
            cout<<"SIZE: "<<hash.size()<<endl;
            cout<<hash;
            break;
        case 'I':
            cin>>key;
            cin>>val;
            hash.insert(record(key,val));
            cout<<key<<":"<<val<<" has been INSERTED. "<<endl;
            cout<<hash;
            break;
        case 'R':
            rnd_val = rand() % 9999 + 1;
            rnd_key = rand() % 9999 + 1;
            hash.insert(record(rnd_key,rnd_val));
            cout<<rnd_key<<":"<<rnd_val<<" has been INSERTED. "<<endl;
            cout<<hash;
            break;
        case 'D':
            cin>>key;
            hash.remove(key);
            cout<<">>"<<key<<" was REMOVED"<<endl;
            cout<<hash;
            break;
        case 'F':
            cin>>key;
            if(hash.find(key, ans)){
                cout<<">>"<<ans<<endl;
            }
            else {
                cout<<">>"<<key<<" NOT FOUND"<<endl;
            }
            cout<<hash;
            break;
        case '?':
            cin>>key;
            if(hash.is_present(key)){
                cout<<">>"<<key<<" EXISTS."<<endl;
            }
            else{
                cout<<">>"<<key<<" DOES NOT EXIST."<<endl;
            }
            cout<<hash;
            break;
        case 'X':
            done = true;
            cout<<"D O N E ."<<endl;
            break;
        default:
            cout<<"Please enter a valid key."<<endl;

        }
    }while(!done);
}

template<class T>
void test_hash_table_random(T& hash, int how_many, string type){
    int existing = 0;
    int nonexisting = 0;
    int i;
    int keys[how_many];
    int val[how_many];
    cout<<"********************************************************************************"<<endl;
    cout<<"                 R A N D O M   H A S H   T E S T: "<<type<<endl;
    cout<<"********************************************************************************"<<endl;
    srand(1);

    auto start1 = high_resolution_clock::now();
    for(i = 0; i < how_many; ++i){
        keys[i] = rand() % 5000 + 1;
        val[i] = rand() % 9999 + 1;
        hash.insert(record(keys[i], val[i]));
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<duration<double>>(stop1 - start1); //Time taken to insert how_many keys
    cout<<"---- ["<<how_many<<"] keys inserted."<<endl;

    cout<<"COLLISIONS: ";
    if(hash.collisions() >= 0){
        cout<<hash.collisions();
    }
    else {
        cout<<"N/A";
    }
    cout<<endl<<endl;


    cout<<"- - - - - - - - - Search for existing keys ----------------"<<endl;

    auto start2 = high_resolution_clock::now();
    for(i = 0; i < how_many/2; ++i){
        if(hash.is_present(keys[i])){
            existing++;
        }
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<duration<double>>(stop2 - start2); //Time taken to search for how_many/2 existing keys

    cout<<"Search for existing keys: "<<how_many/2<<" keys to be tested:"<<endl;
    cout<<"EXISTING KEYS LOOKUP: "<<existing<<". EXISTING KEYS EXAMINED: "<< how_many/2<<endl<<endl<<endl;
    cout<<"- - - - - - - - - Search for non-existent keys ----------------"<<endl;

    auto start3 = high_resolution_clock::now();
    for(i = 0; i < how_many/2; ++i){
        if(!hash.is_present(rand() % 4999 + 5000)){
            nonexisting++;
        }
    }
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<duration<double>>(stop3 - start3); //Time taken to search for how_many/2 existing keys

    cout<<"Search for nonexisting keys: "<<how_many/2<<" keys to be tested:"<<endl;
    cout<<"NONEXISTING KEYS LOOKUP: "<<nonexisting<<". NONEXISTING KEYS EXAMINED: "<< how_many/2<<endl<<endl<<endl;
    cout<<"- - - - - - - - - Time taken ----------------"<<endl;
    double exec_time_insert = 0.0;
    double exec_time_search1 = 0.0;
    double exec_time_search2 = 0.0;
    exec_time_insert = duration1.count();
    exec_time_search1 = duration2.count();
    exec_time_search2 = duration3.count();
    cout<<"TIME TAKEN TO INSERT "<<how_many<<" RECORDS: "<<fixed<<setprecision(6)<<exec_time_insert<<" seconds"<<endl;
    cout<<"TIME TAKEN TO SEARCH FOR "<<how_many/2<<" EXISTING KEYS: "<<exec_time_search1<<" seconds"<<endl;
    cout<<"TIME TAKEN TO SEARCH FOR "<<how_many/2<<" NONEXISTING KEYS: "<<exec_time_search2<<" seconds"<<endl<<endl<<endl;
    cout.unsetf(ios::fixed); //setprecision is permanent after you declare it... (kinda stupid).

    cout<<"------------------ END RANDOM TEST ----------------------"<<endl<<endl;
}

void interactive_menu(){
    cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :";
}

