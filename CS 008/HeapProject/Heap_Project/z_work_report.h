#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H
/*
    Features:
        -Not Implemented: none

        -Implemented: Ability to create a heap through random insertion, popping the max value, ability to have the heap
        automatically sort itself when inserting and when popping. Ability to see the index of the array by hard-coding a
        debug option into print_tree.


        -Partly implemented: none

    Bugs     : no bugs

    Reflections: Interesting. I had a little trouble with pop, however I figured out that insert() works from the bottom-up,
    while pop() works from the top-down. As a result, I first was confused that my pop was getting random values, but that was
    because I wasn't checking whether or not the current node is a leaf, which gives it a place to stop.



*/
#endif // Z_WORK_REPORT_H
