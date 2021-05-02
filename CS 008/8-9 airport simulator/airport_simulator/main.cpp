#include <iostream>
#include <ctime>
#include "simulate.h"
using namespace std;
/*
 * Name: Jason Pambuena
 * Project: airport_simulator
 * Purpose: Takes advantage of our queue class to create an airport simulator
 * that tracks a queue of planes waiting to land and a queue of planes waiting
 * to leave.
 * Notes: The tracking of which planes crashed is by seeing how long the plane waited by the next
 * time the runway isn't busy, if it is > 20 then it pops() and ++CRASHED_PLANES.
 *
 */
int main()
{

    srand(time(0));
    airport_simulate(15, 0.08, 5, 0.1, 20, 100000);
    return 0;
}


