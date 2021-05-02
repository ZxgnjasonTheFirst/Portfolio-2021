#ifndef Z_OUTPUT_TEST_BST_H
#define Z_OUTPUT_TEST_BST_H
/*
***** ALL RESULTS ARE VERIFIED ******
*
**
***
****
****test_BST_CTOR()
================================
CTOR fired (comment out the cout in the CTOR)
================================
*
**
***
****
****test_BST_COPY_CTOR()
================================
Original

          |96|

     |84|

          |64|

               |57|

                    |56|

                         |50|

|46|

          |41|

     |22|

               |8|

          |4|
Copy

          |96|

     |84|

          |64|

               |57|

                    |56|

                         |50|

|46|

          |41|

     |22|

               |8|

          |4|
================================
*
**
***
****
****test_BST_ASSIGNMENT()
================================
Original

          |96|

     |84|

          |64|

               |57|

                    |56|

                         |50|

|46|

          |41|

     |22|

               |8|

          |4|
Copy

          |96|

     |84|

          |64|

               |57|

                    |56|

                         |50|

|46|

          |41|

     |22|

               |8|

          |4|
================================
*
**
***
****
****test_BST_DTOR()
================================
Original

          |96|

     |84|

          |64|

               |57|

                    |56|

                         |50|

|46|

          |41|

     |22|

               |8|

          |4|
Destructed
================================
*
**
***
****
****test_BST_erase()
================================
Original

          |96|

     |84|

          |64|

               |57|

                    |56|

                         |50|

|46|

          |41|

     |22|

               |8|

          |4|
Erased 8 and 84

          |96|

     |64|

          |57|

               |56|

                    |50|

|46|

          |41|

     |22|

          |4|
================================
*
**
***
****
****test_BST_search()
================================

          |96|

     |84|

          |64|

               |57|

                    |56|

                         |50|

|46|

          |41|

     |22|

               |8|

          |4|
4 was found!
99 wasn't found!
================================
*
**
***
****
****test_BST_add()
================================
Original

     |96|

|84|

     |64|

          |57|

               |56|

                    |50|
Adding this

|46|

          |41|

     |22|

               |8|

          |4|
Added

     |96|

|84|

     |64|

          |57|

               |56|

                    |50|

                         |46|

                                   |41|

                              |22|

                                        |8|

                                   |4|
================================
*/
#endif // Z_OUTPUT_TEST_BST_H