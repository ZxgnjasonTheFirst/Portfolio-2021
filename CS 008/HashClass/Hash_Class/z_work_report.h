#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H
/*
    Features:
        -Not Implemented: none

        -Implemented: The ability to show the size, insert, insert random records, delete a certain record,
        find the value of a record, and see if the record exists through the key. Also implemented a large random test,
        setting both CAPACITIES of both chained and double hash to 811, giving them how_many values to insert, and search for how_many/2
        existing and nonexisting keys. I also implemented a time feature to time how long it takes to insert how_many records and search
        how_many/2 records. I also tweaked the AVL_Class to have a in_order print function when you cout avl, this is used because you can't
        have the tree's root nicely print right next to the index number, the index number will print before or after the tree, because you
        can't interrupt the print_function in the middle of executing.


        -Partly implemented: none

    Bugs     : no bugs

    Reflections: **HUGE NOTE: CAPACITY for double hash and CAPACITY - 2 must both be prime numbers or else the program will freeze
    being in an infinite loop. Also the records themselves should not have a format of setfill('0')s because that would look weird to
    the user accessing the records. It's interesting how the chained hash is 2x slower to insert and search for non-existent keys, than
    the double hash, perhaps it may be because the chained hash class must generate the tree over and over again when it inserts or searches,
    while the double hash and open hash has less layers to go through for itself. It's also interesting to see that the chained and double hash
    have a 7:5 ratio in time to search for the record, again this maybe because of how many layers the program must go through.



*/
#endif // Z_WORK_REPORT_H
