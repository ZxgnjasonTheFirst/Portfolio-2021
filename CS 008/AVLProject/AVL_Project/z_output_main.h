#ifndef Z_OUTPUT_MAIN_H
#define Z_OUTPUT_MAIN_H
/*
***** ALL RESULTS ARE VERIFIED ******
*
**
***
****
**** TESTING WHEN YOU DELETE A NODE MAKING AN IMBALANCE
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 56

|56| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 50

|56| h: 1 bf: -1

     |50| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 70
-- Inserting 70

     |70| h: 0 bf: 0

|56| h: 1 bf: 0

     |50| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 60
-- Inserting 60

     |70| h: 1 bf: -1

          |60| h: 0 bf: 0

|56| h: 2 bf: 1

     |50| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 80
-- Inserting 80

          |80| h: 0 bf: 0

     |70| h: 1 bf: 0

          |60| h: 0 bf: 0

|56| h: 2 bf: 1

     |50| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: d
? 50
-- Deleting 50

     |80| h: 0 bf: 0

|70| h: 2 bf: -1

          |60| h: 0 bf: 0

     |56| h: 1 bf: 1
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: x
=========================
================================
*
**
***
****
**** NORMAL RUN (W/ DEBUG)
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 58

|58| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 1

|58| h: 1 bf: -1

     |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 16

     |58| h: 0 bf: 0

|16| h: 1 bf: 0

     |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 51

     |58| h: 1 bf: -1

          |51| h: 0 bf: 0

|16| h: 2 bf: 1

     |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 38

          |58| h: 0 bf: 0

     |51| h: 1 bf: 0

          |38| h: 0 bf: 0

|16| h: 2 bf: 1

     |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 55

     |58| h: 1 bf: -1

          |55| h: 0 bf: 0

|51| h: 2 bf: 0

          |38| h: 0 bf: 0

     |16| h: 1 bf: 0

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 73

          |73| h: 0 bf: 0

     |58| h: 1 bf: 0

          |55| h: 0 bf: 0

|51| h: 2 bf: 0

          |38| h: 0 bf: 0

     |16| h: 1 bf: 0

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 100

               |100| h: 0 bf: 0

          |73| h: 1 bf: 1

     |58| h: 2 bf: 1

          |55| h: 0 bf: 0

|51| h: 3 bf: 1

          |38| h: 0 bf: 0

     |16| h: 1 bf: 0

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 69

               |100| h: 0 bf: 0

          |73| h: 1 bf: 0

               |69| h: 0 bf: 0

     |58| h: 2 bf: 1

          |55| h: 0 bf: 0

|51| h: 3 bf: 1

          |38| h: 0 bf: 0

     |16| h: 1 bf: 0

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 63

               |100| h: 0 bf: 0

          |73| h: 1 bf: 1

     |69| h: 2 bf: 0

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 3 bf: 1

          |38| h: 0 bf: 0

     |16| h: 1 bf: 0

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 47

               |100| h: 0 bf: 0

          |73| h: 1 bf: 1

     |69| h: 2 bf: 0

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 3 bf: 0

               |47| h: 0 bf: 0

          |38| h: 1 bf: 1

     |16| h: 2 bf: 1

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 72

               |100| h: 0 bf: 0

          |73| h: 1 bf: 0

               |72| h: 0 bf: 0

     |69| h: 2 bf: 0

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 3 bf: 0

               |47| h: 0 bf: 0

          |38| h: 1 bf: 1

     |16| h: 2 bf: 1

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 58

               |100| h: 0 bf: 0

          |73| h: 1 bf: 0

               |72| h: 0 bf: 0

     |69| h: 2 bf: 0

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 3 bf: 0

               |47| h: 0 bf: 0

          |38| h: 1 bf: 1

     |16| h: 2 bf: 1

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 35

               |100| h: 0 bf: 0

          |73| h: 1 bf: 0

               |72| h: 0 bf: 0

     |69| h: 2 bf: 0

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 3 bf: 0

               |47| h: 0 bf: 0

          |38| h: 1 bf: 0

               |35| h: 0 bf: 0

     |16| h: 2 bf: 1

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 79

               |100| h: 1 bf: -1

                    |79| h: 0 bf: 0

          |73| h: 2 bf: 1

               |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

               |47| h: 0 bf: 0

          |38| h: 1 bf: 0

               |35| h: 0 bf: 0

     |16| h: 2 bf: 1

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 78

                    |100| h: 0 bf: 0

               |79| h: 1 bf: 0

                    |78| h: 0 bf: 0

          |73| h: 2 bf: 1

               |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

               |47| h: 0 bf: 0

          |38| h: 1 bf: 0

               |35| h: 0 bf: 0

     |16| h: 2 bf: 1

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 99

               |100| h: 1 bf: -1

                    |99| h: 0 bf: 0

          |79| h: 2 bf: 0

                    |78| h: 0 bf: 0

               |73| h: 1 bf: 0

                    |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

               |47| h: 0 bf: 0

          |38| h: 1 bf: 0

               |35| h: 0 bf: 0

     |16| h: 2 bf: 1

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 81

                    |100| h: 0 bf: 0

               |99| h: 1 bf: 0

                    |81| h: 0 bf: 0

          |79| h: 2 bf: 0

                    |78| h: 0 bf: 0

               |73| h: 1 bf: 0

                    |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

               |47| h: 0 bf: 0

          |38| h: 1 bf: 0

               |35| h: 0 bf: 0

     |16| h: 2 bf: 1

          |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: d
? 1
-- Deleting 1

                    |100| h: 0 bf: 0

               |99| h: 1 bf: 0

                    |81| h: 0 bf: 0

          |79| h: 2 bf: 0

                    |78| h: 0 bf: 0

               |73| h: 1 bf: 0

                    |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

          |47| h: 0 bf: 0

     |38| h: 2 bf: -1

               |35| h: 0 bf: 0

          |16| h: 1 bf: 1
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 1
-- Inserting 1

                    |100| h: 0 bf: 0

               |99| h: 1 bf: 0

                    |81| h: 0 bf: 0

          |79| h: 2 bf: 0

                    |78| h: 0 bf: 0

               |73| h: 1 bf: 0

                    |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

          |47| h: 0 bf: 0

     |38| h: 2 bf: -1

               |35| h: 0 bf: 0

          |16| h: 1 bf: 0

               |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: s
? 99
item is found. |99|

                    |100| h: 0 bf: 0

               |99| h: 1 bf: 0

                    |81| h: 0 bf: 0

          |79| h: 2 bf: 0

                    |78| h: 0 bf: 0

               |73| h: 1 bf: 0

                    |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

          |47| h: 0 bf: 0

     |38| h: 2 bf: -1

               |35| h: 0 bf: 0

          |16| h: 1 bf: 0

               |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: s
? 100
item is found. |100|

                    |100| h: 0 bf: 0

               |99| h: 1 bf: 0

                    |81| h: 0 bf: 0

          |79| h: 2 bf: 0

                    |78| h: 0 bf: 0

               |73| h: 1 bf: 0

                    |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

          |47| h: 0 bf: 0

     |38| h: 2 bf: -1

               |35| h: 0 bf: 0

          |16| h: 1 bf: 0

               |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: s
? 5
item not found.

                    |100| h: 0 bf: 0

               |99| h: 1 bf: 0

                    |81| h: 0 bf: 0

          |79| h: 2 bf: 0

                    |78| h: 0 bf: 0

               |73| h: 1 bf: 0

                    |72| h: 0 bf: 0

     |69| h: 3 bf: 1

               |63| h: 0 bf: 0

          |58| h: 1 bf: 0

               |55| h: 0 bf: 0

|51| h: 4 bf: 1

          |47| h: 0 bf: 0

     |38| h: 2 bf: -1

               |35| h: 0 bf: 0

          |16| h: 1 bf: 0

               |1| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: c
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 2
-- Inserting 2

|2| h: 0 bf: 0
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: c
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: x
=========================
================================
*
**
***
****
**** NORMAL RUN
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 98

|98|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 25

|98|

     |25|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 14

     |98|

|25|

     |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 53

     |98|

          |53|

|25|

     |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 79

          |98|

     |79|

          |53|

|25|

     |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 80

     |98|

          |80|

|79|

          |53|

     |25|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 62

     |98|

          |80|

|79|

               |62|

          |53|

     |25|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 40

     |98|

          |80|

|79|

               |62|

          |53|

               |40|

     |25|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 62

     |98|

          |80|

|79|

               |62|

          |53|

               |40|

     |25|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 34

     |98|

          |80|

|79|

               |62|

          |53|

     |40|

               |34|

          |25|

               |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 84

          |98|

     |84|

          |80|

|79|

               |62|

          |53|

     |40|

               |34|

          |25|

               |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 18

               |98|

          |84|

               |80|

     |79|

               |62|

          |53|

|40|

          |34|

     |25|

               |18|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 41

               |98|

          |84|

               |80|

     |79|

               |62|

          |53|

               |41|

|40|

          |34|

     |25|

               |18|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 42

               |98|

          |84|

               |80|

     |79|

               |62|

          |53|

                    |42|

               |41|

|40|

          |34|

     |25|

               |18|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 46

               |98|

          |84|

               |80|

     |79|

               |62|

          |53|

                    |46|

               |42|

                    |41|

|40|

          |34|

     |25|

               |18|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 67

               |98|

          |84|

               |80|

     |79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

|40|

          |34|

     |25|

               |18|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 95

               |98|

                    |95|

          |84|

               |80|

     |79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

|40|

          |34|

     |25|

               |18|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: r
-- Inserting 85

                    |98|

               |95|

                    |85|

          |84|

               |80|

     |79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

|40|

          |34|

     |25|

               |18|

          |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: d
? 14
-- Deleting 14

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

     |40|

               |34|

          |25|

               |18|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: d
? 18
-- Deleting 18

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

     |40|

               |34|

          |25|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: d
? 34
-- Deleting 34

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

               |67|

          |62|

     |53|

                    |46|

               |42|

                    |41|

          |40|

               |25|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 34
-- Inserting 34

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

               |67|

          |62|

     |53|

                    |46|

               |42|

                    |41|

          |40|

                    |34|

               |25|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 18
-- Inserting 18

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

               |67|

          |62|

     |53|

                    |46|

               |42|

                    |41|

          |40|

                    |34|

               |25|

                    |18|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 14
-- Inserting 14

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

     |40|

               |34|

          |25|

               |18|

                    |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: s
? 98
item is found. |98|

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

     |40|

               |34|

          |25|

               |18|

                    |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: s
? 18
item is found. |18|

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

     |40|

               |34|

          |25|

               |18|

                    |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: s
? 99
item not found.

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

     |40|

               |34|

          |25|

               |18|

                    |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: s
? 1
item not found.

               |98|

          |95|

               |85|

     |84|

          |80|

|79|

                    |67|

               |62|

          |53|

                    |46|

               |42|

                    |41|

     |40|

               |34|

          |25|

               |18|

                    |14|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: c
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: i
? 24
-- Inserting 24

|24|
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: c
=========================
[R]andom  [I]nsert  [D]elete  [C]lear  [S]earch   e[X]it: x
=========================
================================
*/
#endif // Z_OUTPUT_MAIN_H
