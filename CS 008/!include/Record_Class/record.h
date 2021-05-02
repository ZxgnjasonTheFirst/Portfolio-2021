#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool file_exists(const char filename[]);

void open_fileRW(fstream& f, const char filename[]) throw(char*);
void open_fileW(fstream& f, const char filename[]);


static const int MAX = 50;

class Record{
public:
    char record[MAX][MAX];

    Record(){
        recno = -1;
    }

    Record(vector<string>& str){
        for(int i = 0; i < str.size(); ++i){
            strcpy(record[i], str[i].c_str());
        }
    }

    Record(char str[][MAX]){
        for(int i = 0; i < MAX; i++){
            strcpy(record[i], str[i]);
        }
    }
    int getrecno(){
        return recno;
    }
    string getrecord(int i){
        return record[i];
    }
    long overwrite(fstream &outs);
    long write(fstream& outs);
    long read(fstream& ins, long recno);


    friend ostream& operator<<(ostream& outs,
                               const Record& r);
private:
    int numofrecs;
    int recno;
};

void save_list(Record list[], int count, const char filename[]);

#endif // RECORD_H
