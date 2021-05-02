#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H
/*
    Features:
        -Not Implemented: []operator for multimap: I didn't catch how to implement this especially because it requires the BPlusTree.

        -Implemented: Ability to be able to print, insert, get (get_existing and both constant and non-constant). Array functions
        maximal, swapping, first_ge, insert_item, split, copy_array, and += operators are implemented. BTree constructor is set
        up as well. To help with insert, is_leaf, loose_insert, and fix_excess has been implemented.

        Update 5/12/2019: Ability to copy, clear, and remove nodes from the tree. The big three is also implemented although I am unsure
        about the destructor. Array functions attach_item, detach_item, delete_item, and merge are implemented. To help with remove,
        loose_remove, fix_shortage, remove_biggest, rotate_left, rotate_right, and merge_with_next_subset has been implemented. Size and
        empty functions are implemented as well.


        -Partly implemented: map [] operator: I have implemented but not have tested this function because I didn't know how to.
        destructor and in turn clear_tree(): For clear_tree I implemented it so that it would go through each subset and delete the pointer.
        I am unsure whether or not this was correct.



    Bugs     : no bugs

    Reflections: I still haven't done the []operator for Multimap yet, unsure what to do with it. Other than this and clear_tree, I am happy to
    see everything working well! I am a little anxious about the upcoming projects as we near the final. I'll do my best to keep up and implement
    everything correctly!



*/
#endif // Z_WORK_REPORT_H
