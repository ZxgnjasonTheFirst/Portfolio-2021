#ifndef TABLE_H
#define TABLE_H
#include <iomanip>
#include <algorithm>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Parse_Class/parse.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Record_Class/record.h"

void writetxtfile(ofstream& f, const char filename[]);

void readtxtfile(ifstream& f, const char filename[]);

class Table
{
public:
//    fstream file;

    //default:
    Table();
    //existing table with this name:
    Table(string name);

    Table(string name, vector<string> f_list);

    Table select_all(vector<string> f_list = vector<string>());
    void drop_table(vector<string> files2delete = vector<string>());

    void insert_into(vector<string> f_listactual);
    void insert_into(Record rec);

    Table select(vector<string> f_list, string condition);

    vector<long> get_rec_nos(string condition);
    Table build_new_table(string name, vector<long> recnos = vector<long>(), vector<string> f_list = vector<string>());

    int findfield(string condition);

    vector<int> findalikeindices(vector<string> vec1, vector<string> vec2);

    bool exists(){return file_exists(filename.c_str());}

    friend ostream& operator<<(ostream& outs, const Table& t);

    Table& operator = (const Table& rhs);

    vector<string> field_list;
    string filename;

private:

    typedef MMap<string, long> mmap_sl;
//    map_ss field_map;
    vector<mmap_sl> indices;
    void reindex();


    long recno;
    int numofrecs;

};

bool isOperator(const string &c);

bool isOperand(const string &symbol);

template<class output_iterator_tag, class input_iterator_tag>
output_iterator_tag myset_intersection(input_iterator_tag first1, input_iterator_tag last1,
                                       input_iterator_tag first2, input_iterator_tag last2,
                                       output_iterator_tag result){
    if (first1 == last1 && first2 == last2 && *first1 == *first2){
        *result = *first1;
        ++result;
        return result;
    }
    while (first1!=last1 && first2!=last2)
    {
      if (*first1<*first2) ++first1;
      else if (*first2<*first1) ++first2;
      else {
        *result = *first1;
        ++result; ++first1; ++first2;
      }
    }
    return result;
};

Table And(Table x, Table y);

Table Or(Table x, Table y);

Table RPN(vector<string> expression, Table t, vector<string> f_list, vector<string> &del);



#endif // TABLE_H
