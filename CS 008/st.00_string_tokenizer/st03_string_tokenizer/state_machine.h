#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_COLUMNS = 256;
const int MAX_ROWS = 30;
const int MAX_BUFFER = 500;
const int START_NUM = 0;
const int START_SPACE = 5;
const int START_PUNC = 10;
const int START_ALPHA = 15;
const int TYPE_UNKNOWN = -1;
const int TYPE_NUM = 0;
const int TYPE_SPACE = 1;
const int TYPE_PUNC = 2;
const int TYPE_ALPHA = 3;
const char DIGITS[] = "0123456789";
const char ALPHA[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const char PUNC[] = "\"';:,./?!()[]";
const char SPACE[] = " ";

//Fill all cells of the array with -1
void init_table(int _table[][MAX_COLUMNS]);

//Mark this state (row) with a 1 (success)
void mark_success(int _table[][MAX_COLUMNS], int state);

//Mark this state (row) with a 0 (fail)
void mark_fail(int _table[][MAX_COLUMNS], int state);

//true if state is a success state
bool is_success(int _table[][MAX_COLUMNS], int state);

//Mark a range of cells in the array.
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state);

//Mark columns represented by the string columns[] for this row
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state);

//Mark this row and column
void mark_cell(int row, int table[][MAX_COLUMNS], int column, int state);

//This can realistically be used on a small table
void print_table(int _table[][MAX_COLUMNS]);

//show string s and mark this position on the string:
//hello world   pos: 7
//       ^
void show_string(char s[], int &_pos);

bool get_token(char input[], int &pos, int _table[][MAX_COLUMNS], int start_state, string &token);

#endif // STATE_MACHINE_H
