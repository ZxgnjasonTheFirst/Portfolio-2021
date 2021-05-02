#ifndef Z_OUTPUT_STACK_H
#define Z_OUTPUT_STACK_H
/*
 ***** ALL RESULTS ARE VERIFIED *****

----------------------------------
Testing stack push and constructor:
----------------------------------
test->[1]->|||
test->[2]->[1]->|||
test->[3]->[2]->[1]->|||
----------------------------------

----------------------------------
Testing stack pop:
----------------------------------
test->[3]->[2]->[1]->|||
pop1->[2]->[1]->|||
pop2->[1]->|||
pop3->|||
pop4->|||
----------------------------------

----------------------------------
Testing stack top:
----------------------------------
Test:->[1]->|||
Top1: 1
Test:->[2]->[1]->|||
Top2: 2
Test:->[3]->[2]->[1]->|||
Top3: 3
Test:->[2]->[1]->|||
Top4: 2
Test:->[1]->|||
Top5: 1
Test:->|||
---------------------------------- << BUG? :Top6 does not print after this line (front is empty)

----------------------------------
Testing if stack is empty and destructor (yes):
----------------------------------
->[2]->[1]->|||
->|||
list is empty!
----------------------------------

----------------------------------
Testing if stack is empty and destructor (yes)
*testing popping after destructor:
----------------------------------
->[2]->[1]->|||
->|||
list is empty!
----------------------------------

----------------------------------
Testing if stack is empty and destructor (no):
----------------------------------
->[2]->[1]->|||
->[1]->|||
list is not empty!
----------------------------------

*/
#endif // Z_OUTPUT_STACK_H
