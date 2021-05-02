#ifndef Z_OUTPUT_MAIN_H
#define Z_OUTPUT_MAIN_H
/*
***** ALL RESULTS ARE VERIFIED ******
*
**
***
****
No DEBUG
**********************
200
100
**********************
**********************
     400
     200
200
     100
**********************
**********************
     400
     200
200
     110
     100
**********************
**********************
     400
     200
200
     120
     110
110
     100
**********************
**********************
          400
          200
     200
          130
          120
120
          110
     110
          100
**********************
**********************
          400
          200
     200
          130
          120
120
          110
     110
          105
          100
**********************
**********************
          450
          400
     400
          200
     200
          130
          120
120
          110
     110
          105
          100
**********************
**********************
          450
          400
     400
          200
200
          130
          125
     125
          120
120
          110
     110
          105
          100
tree is valid:
|100 105 | -> |110 | -> |120 | -> |125 130 | -> |200 | -> |400 450 | -> |||
**********************
COPY:
          450
          400
     400
          200
200
          130
          125
     125
          120
120
          110
     110
          105
          100
tree is valid:
|100 105 | -> |110 | -> |120 | -> |125 130 | -> |200 | -> |400 450 | -> |||
**********************
**********************
COPY INSERTED 115:
          450
          400
     400
          200
200
          130
          125
     125
          120
120
          115
          110
     110
          105
          100
|100 105 | -> |110 115 | -> |120 | -> |125 130 | -> |200 | -> |400 450 | -> |||
**********************
**********************
COPY DESTUCTOR:
**********************
ORIGINAL:
          450
          400
     400
          200
200
          130
          125
     125
          120
120
          110
     110
          105
          100
**********************
removed 125:
          450
          400
     400
          200
200
          130
     130
          120
120
          110
     110
          105
          100
|100 105 | -> |110 | -> |120 | -> |130 | -> |200 | -> |400 450 | -> |||
**********************
**********************
removed 200:
          450
     450
          400
400
          130
     130
          120
120
          110
     110
          105
          100
|100 105 | -> |110 | -> |120 | -> |130 | -> |400 | -> |450 | -> |||
**********************
**********************
removed 130:
          450
     450
          400
400
          120
     120
          110
     110
          105
          100
|100 105 | -> |110 | -> |120 | -> |400 | -> |450 | -> |||
**********************
W/ DEBUG
**********************
200 data_count: 2 child_count: 0
100 data_count: 2 child_count: 0
**********************
**********************
     400 data_count: 2 child_count: 0
     200 data_count: 2 child_count: 0
200 data_count: 1 child_count: 2
     100 data_count: 1 child_count: 0
**********************
**********************
     400 data_count: 2 child_count: 0
     200 data_count: 2 child_count: 0
200 data_count: 1 child_count: 2
     110 data_count: 2 child_count: 0
     100 data_count: 2 child_count: 0
**********************
**********************
     400 data_count: 2 child_count: 0
     200 data_count: 2 child_count: 0
200 data_count: 2 child_count: 3
     120 data_count: 2 child_count: 0
     110 data_count: 2 child_count: 0
110 data_count: 2 child_count: 3
     100 data_count: 1 child_count: 0
**********************
**********************
          400 data_count: 2 child_count: 0
          200 data_count: 2 child_count: 0
     200 data_count: 1 child_count: 2
          130 data_count: 2 child_count: 0
          120 data_count: 2 child_count: 0
120 data_count: 1 child_count: 2
          110 data_count: 1 child_count: 0
     110 data_count: 1 child_count: 2
          100 data_count: 1 child_count: 0
**********************
**********************
          400 data_count: 2 child_count: 0
          200 data_count: 2 child_count: 0
     200 data_count: 1 child_count: 2
          130 data_count: 2 child_count: 0
          120 data_count: 2 child_count: 0
120 data_count: 1 child_count: 2
          110 data_count: 1 child_count: 0
     110 data_count: 1 child_count: 2
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
**********************
**********************
          450 data_count: 2 child_count: 0
          400 data_count: 2 child_count: 0
     400 data_count: 2 child_count: 3
          200 data_count: 1 child_count: 0
     200 data_count: 2 child_count: 3
          130 data_count: 2 child_count: 0
          120 data_count: 2 child_count: 0
120 data_count: 1 child_count: 2
          110 data_count: 1 child_count: 0
     110 data_count: 1 child_count: 2
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
**********************
**********************
          450 data_count: 2 child_count: 0
          400 data_count: 2 child_count: 0
     400 data_count: 1 child_count: 2
          200 data_count: 1 child_count: 0
200 data_count: 2 child_count: 3
          130 data_count: 2 child_count: 0
          125 data_count: 2 child_count: 0
     125 data_count: 1 child_count: 2
          120 data_count: 1 child_count: 0
120 data_count: 2 child_count: 3
          110 data_count: 1 child_count: 0
     110 data_count: 1 child_count: 2
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
tree is valid:
|100 105 | -> |110 | -> |120 | -> |125 130 | -> |200 | -> |400 450 | -> |||
**********************
COPY:
          450 data_count: 2 child_count: 0
          400 data_count: 2 child_count: 0
     400 data_count: 1 child_count: 2
          200 data_count: 1 child_count: 0
200 data_count: 2 child_count: 3
          130 data_count: 2 child_count: 0
          125 data_count: 2 child_count: 0
     125 data_count: 1 child_count: 2
          120 data_count: 1 child_count: 0
120 data_count: 2 child_count: 3
          110 data_count: 1 child_count: 0
     110 data_count: 1 child_count: 2
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
tree is valid:
|100 105 | -> |110 | -> |120 | -> |125 130 | -> |200 | -> |400 450 | -> |||
**********************
**********************
COPY INSERTED 115:
          450 data_count: 2 child_count: 0
          400 data_count: 2 child_count: 0
     400 data_count: 1 child_count: 2
          200 data_count: 1 child_count: 0
200 data_count: 2 child_count: 3
          130 data_count: 2 child_count: 0
          125 data_count: 2 child_count: 0
     125 data_count: 1 child_count: 2
          120 data_count: 1 child_count: 0
120 data_count: 2 child_count: 3
          115 data_count: 2 child_count: 0
          110 data_count: 2 child_count: 0
     110 data_count: 1 child_count: 2
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
|100 105 | -> |110 115 | -> |120 | -> |125 130 | -> |200 | -> |400 450 | -> |||
**********************
**********************
COPY DESTUCTOR:
**********************
ORIGINAL:
          450 data_count: 2 child_count: 0
          400 data_count: 2 child_count: 0
     400 data_count: 1 child_count: 2
          200 data_count: 1 child_count: 0
200 data_count: 2 child_count: 3
          130 data_count: 2 child_count: 0
          125 data_count: 2 child_count: 0
     125 data_count: 1 child_count: 2
          120 data_count: 1 child_count: 0
120 data_count: 2 child_count: 3
          110 data_count: 1 child_count: 0
     110 data_count: 1 child_count: 2
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
**********************
removed 125:
          450 data_count: 2 child_count: 0
          400 data_count: 2 child_count: 0
     400 data_count: 1 child_count: 2
          200 data_count: 1 child_count: 0
200 data_count: 2 child_count: 3
          130 data_count: 1 child_count: 0
     130 data_count: 1 child_count: 2
          120 data_count: 1 child_count: 0
120 data_count: 2 child_count: 3
          110 data_count: 1 child_count: 0
     110 data_count: 1 child_count: 2
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
|100 105 | -> |110 | -> |120 | -> |130 | -> |200 | -> |400 450 | -> |||
**********************
**********************
removed 200:
          450 data_count: 1 child_count: 0
     450 data_count: 1 child_count: 2
          400 data_count: 1 child_count: 0
400 data_count: 2 child_count: 3
          130 data_count: 1 child_count: 0
     130 data_count: 1 child_count: 2
          120 data_count: 1 child_count: 0
120 data_count: 2 child_count: 3
          110 data_count: 1 child_count: 0
     110 data_count: 1 child_count: 2
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
|100 105 | -> |110 | -> |120 | -> |130 | -> |400 | -> |450 | -> |||
**********************
**********************
removed 130:
          450 data_count: 1 child_count: 0
     450 data_count: 1 child_count: 2
          400 data_count: 1 child_count: 0
400 data_count: 1 child_count: 2
          120 data_count: 1 child_count: 0
     120 data_count: 2 child_count: 3
          110 data_count: 1 child_count: 0
     110 data_count: 2 child_count: 3
          105 data_count: 2 child_count: 0
          100 data_count: 2 child_count: 0
|100 105 | -> |110 | -> |120 | -> |400 | -> |450 | -> |||
**********************
#endif // Z_OUTPUT_MAIN_H
