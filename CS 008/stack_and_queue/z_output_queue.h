#ifndef Z_OUTPUT_QUEUE_H
#define Z_OUTPUT_QUEUE_H
/*
 ***** ALL RESULTS ARE VERIFIED *****

----------------------------------
Testing queue copy constructor and push:
----------------------------------
test->[1]->[2]->[3]->[4]->|||

yes->[1]->[2]->[3]->[4]->|||

----------------------------------

----------------------------------
Testing queue destructor (filled queue):
----------------------------------
->[1]->[2]->|||

this is test after destructor->|||

----------------------------------

----------------------------------
Testing queue destructor (empty queue):
----------------------------------
->|||

this is test after destructor->|||

----------------------------------

----------------------------------
Testing queue equals operator:
----------------------------------
test->[1]->[2]->|||
yes->[1]->[2]->|||
----------------------------------

----------------------------------
Testing queue pop:
----------------------------------
test->[1]->[2]->[3]->|||
pop1->[2]->[3]->|||
pop2->[3]->|||
pop3->|||
pop4->||| //<< called pop on empty queue
----------------------------------

----------------------------------
Testing front:
----------------------------------
Test:->[1]->|||
Front1: 1
Test:->[1]->[2]->|||
Front2: 1
Test:->[1]->[2]->[3]->|||
Front3: 1
Test:->[2]->[3]->|||
Front4: 2
Test:->[3]->|||
Front5: 3
Test:->|||
---------------------------------- << BUG? :Front6 does not print after this line (front is empty)

----------------------------------
Testing back:
----------------------------------
Test:->[1]->|||
Back1: 1
Test:->[1]->[2]->|||
Back2: 2
Test:->[1]->[2]->[3]->|||
Back3: 3
Test:->[2]->[3]->|||
Back4: 3
Test:->[3]->|||
Back5: 3
Test:->|||
---------------------------------- << BUG? :Back6 does not print after this line (front is empty)

----------------------------------
Testing if queue is empty (no):
----------------------------------
->[1]->[2]->|||
->[2]->|||
list is not empty!
----------------------------------

----------------------------------
Testing if queue is empty (yes):
----------------------------------
->[1]->[2]->|||
->|||
list is empty!
----------------------------------

----------------------------------
Testing if queue is empty (yes)
*testing popping after deconstructor*:
----------------------------------
->[1]->[2]->|||
->|||
list is empty!
----------------------------------

*/
#endif // Z_OUTPUT_QUEUE_H
