#include <iostream>
#include "test_main_stack_and_queue.h"
#include "test_linkedlistfuncs.h"
#include "test_stack.h"
#include "test_queue.h"
#include "test_list.h"
#include "queue.h"
#include "stack.h"

/*
 * Name: Jason Pambuena
 * Project: stack_and_queue
 * Purpose: Take advantage of template and Linkedlists to create a
 * Stack and queue class.
 * Notes: In the .pro if the header does not have a \ after it it won't update,
 * don't forget to return what needs to be returned.
 *
 * Also *don't know if this is a bug* but if I erase/pop an empty stack or queue
 * the front/back/top won't show and anything after won't run...
 */
using namespace std;

int main()
{

    test_queuepop();
    return 0;
}
