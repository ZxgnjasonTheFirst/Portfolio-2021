#ifndef Z_OUTPUT_MAIN_H
#define Z_OUTPUT_MAIN_H
/*
***** ALL RESULTS ARE VERIFIED ******

**OUTPUT W/ DEBUG**
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 44

|44| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 98

     |98| h: 0 bf: 0

|44| h: 1 bf: 1
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: i
? 99
-- Inserting 99

          |99| h: 0 bf: 0

     |98| h: 1 bf: 1

|44| h: 2 bf: 2
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 34

          |99| h: 0 bf: 0

     |98| h: 1 bf: 1

|44| h: 2 bf: 1

     |34| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 80

          |99| h: 0 bf: 0

     |98| h: 1 bf: 0

          |80| h: 0 bf: 0

|44| h: 2 bf: 1

     |34| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 19

          |99| h: 0 bf: 0

     |98| h: 1 bf: 0

          |80| h: 0 bf: 0

|44| h: 2 bf: 0

     |34| h: 1 bf: 1

          |19| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 4

          |99| h: 0 bf: 0

     |98| h: 1 bf: 0

          |80| h: 0 bf: 0

|44| h: 3 bf: 1

     |34| h: 2 bf: 2

          |19| h: 1 bf: 1

               |4| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 80

          |99| h: 0 bf: 0

     |98| h: 1 bf: 0

          |80| h: 0 bf: 0

|44| h: 3 bf: 1

     |34| h: 2 bf: 2

          |19| h: 1 bf: 1

               |4| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 93

          |99| h: 0 bf: 0

     |98| h: 2 bf: 1

               |93| h: 0 bf: 0

          |80| h: 1 bf: 1

|44| h: 3 bf: 0

     |34| h: 2 bf: 2

          |19| h: 1 bf: 1

               |4| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: s
? 99
item is found. |99|

          |99| h: 0 bf: 0

     |98| h: 2 bf: 1

               |93| h: 0 bf: 0

          |80| h: 1 bf: 1

|44| h: 3 bf: 0

     |34| h: 2 bf: 2

          |19| h: 1 bf: 1

               |4| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: s
? 45
item not found.

          |99| h: 0 bf: 0

     |98| h: 2 bf: 1

               |93| h: 0 bf: 0

          |80| h: 1 bf: 1

|44| h: 3 bf: 0

     |34| h: 2 bf: 2

          |19| h: 1 bf: 1

               |4| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: c
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: x
=========================
================================
*
**
***
****
*****
******
================**OUTPUT W/OUT DEBUG**==============
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 27

|27|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 76

     |76|

|27|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 58

     |76|

          |58|

|27|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 39

     |76|

          |58|

               |39|

|27|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 30

     |76|

          |58|

               |39|

                    |30|

|27|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 65

     |76|

               |65|

          |58|

               |39|

                    |30|

|27|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 17

     |76|

               |65|

          |58|

               |39|

                    |30|

|27|

     |17|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 25

     |76|

               |65|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 84

          |84|

     |76|

               |65|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 86

               |86|

          |84|

     |76|

               |65|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: i
? 8
-- Inserting 8

               |86|

          |84|

     |76|

               |65|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|

          |8|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: i
? 5
-- Inserting 5

               |86|

          |84|

     |76|

               |65|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|

          |8|

               |5|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 94

                    |94|

               |86|

          |84|

     |76|

               |65|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|

          |8|

               |5|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: r
-- Inserting 60

                    |94|

               |86|

          |84|

     |76|

               |65|

                    |60|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|

          |8|

               |5|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: s
? 5
item is found. |5|

                    |94|

               |86|

          |84|

     |76|

               |65|

                    |60|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|

          |8|

               |5|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: s
? 60
item is found. |60|

                    |94|

               |86|

          |84|

     |76|

               |65|

                    |60|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|

          |8|

               |5|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: s
? 99
item not found.

                    |94|

               |86|

          |84|

     |76|

               |65|

                    |60|

          |58|

               |39|

                    |30|

|27|

          |25|

     |17|

          |8|

               |5|
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: c
=========================
[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: x
=========================
================================
*/
#endif // Z_OUTPUT_MAIN_H
