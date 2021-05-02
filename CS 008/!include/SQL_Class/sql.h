#ifndef SQL_H
#define SQL_H
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Table_Class/table.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/MultiMap_Class/mmap_class.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Map_Class/map_class.h"

class SQL
{
public:
    SQL();
    void run();
    void readbatchfile(ifstream &f, const char filename[]);

private:
    Map<string, Table> _tables;
    MMap<string, string> _ptree;
    Parser parser;


};

#endif // SQL_H
