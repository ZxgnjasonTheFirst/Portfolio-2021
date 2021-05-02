#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H

/*
    Features:
        -Not Implemented: None

        -Implemented: Created a linked list template, a list template class that builds
        upon the linked list template, a stack template class that builds upon the list
        template class, and a queue template class that builds upon the linked list template.

            *The list, queue, and stack class can do the Big Three.

            *The linked list can initialize head, delete all, see if empty, copy lists, insert
        values at head, insert values after a point "after," delete head node, and can print
        the list.

            *The list can assign lists to each other, insert(), insert() after a certain point
        "here," clear(), erase() returning what you erased, and can get head value, it can also
        be couted.

            *The stack can push(), pop(), top(), empty(), and cout itself.

            *The queue can assign queues to each other, push(), pop(), empty(), front(), back()
        and cout itself.

            *Both queue and stack is implemented correctly -- stack being a first-in-last-out list
        and queue being a first-in-first-out list.

        -Partly implemented: None

    Bugs     : Do not know if this is a bug but when you have an empty list the values for front,
               top, or back makes the program not execute the code after couting/calling those values.

    Reflections: I was stuck for a while because my terminal wouldn't update whenever I changed test_
                 stack.h however it turns out that the last header added in the .pro file doesn't have
                 a "\" at the end of it:

                        was:"list.h \"
                            "test_list.h"
                        supposed to be: "list.h \"
                                        "test_list.h \"
                                                    ^^^

                 guess I have to check everywhere for a program because of this and also because I was
                 missing a "return" command for one of my functions. The "&" sign is also a sneaky debugging mess.




*/


#endif // Z_WORK_REPORT_H
