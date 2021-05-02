#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H
/*
    Features:
        -Not Implemented: none

        -Implemented: Shows the probability of new planes arriving to land and to
        take off. Shows the time to take off and to land. Shows the total time of the simulation.
        Implemented crashed planes and fuel times. Shows how many landed and took off.
        Shows how many planes crashed, average waiting time to take off and land. And shows
        the amount of planes left in the queue to land and take off.


        -Partly implemented: none

    Bugs     : no bugs

    Reflections:

        With 1440 time units of simulation, a dozen runs, 5 units of time to take off, 15 units to land,
    20 units of fuel time, 0.1 probability of planes to enter in landing, and 0.08 probability of
    planes that enter in to take off, at least 122 and at most 161 landed, at least 40 and at most 55 took off,
    at most 4 planes crashed, average waiting times to land were mostly 8-9 units of time, and average waiting times
    to take off were 319-482 units of time, almost no planes were left in queue for landing, and 53-76 planes were left
    in queue for taking off.

        With 100000 time units of simulation, 6 runs, 5 units of time to take off, 15 units to land,
    20 units of fuel time, 0.1 probability of planes to enter in landing, and 0.08 probability of
    planes that enter in to take off, at least 9876 and at most 10100 landed, at least 3300 and at most 3375 took off,
    95-127 planes crashed, average waiting times to land were still 8-9 units of time, and average waiting times
    to take off were 28k-30k units of time, 4 out of 6 runs left several planes in queue for landing, and 4550-4750
    planes were left in queue for taking off.




*/
#endif // Z_WORK_REPORT_H
