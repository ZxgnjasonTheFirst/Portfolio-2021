#ifndef RUNWAY_H
#define RUNWAY_H
#include <cstdlib>
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/stack_and_queue/queue.h"

using namespace std;

class bool_source
{
public:
    //CTOR
    bool_source(double p = 0.5);
    //CONSTANT MEMBER FUNCTION
    bool query() const;
private:
    double probability;
};

class averager
{
public:
    //CTOR
    averager();
    //MODIFICATION MEMBER FUNCTION
    void next_number(double value);
    std::size_t how_many_numbers() const { return count; }
    double average() const;
private:
    std::size_t count; //How many numbers have been given to the averager
    double sum;        //Sum of all the numbers given to the averager
};

class runway
{
public:
    //CTOR
    runway(unsigned int s_land = 5, unsigned int s_takeoff = 15);
    //MODIFICATION MEMBER FUNCTIONS
    void one_second();
    void start_landing();
    void start_takeoff();
    //CONSTANT MEMBER FUNCTION
    bool is_busy() const {return (landing_time_left + takeoff_time_left > 0);}
private:
    unsigned int time_for_landing; //time for a single landing
    unsigned int landing_time_left;   //time until the runway is clear from landing
    unsigned int time_for_takeoff; //time for a single takeoff
    unsigned int takeoff_time_left;   //time until the runway is clear from takeoff
};

#endif // RUNWAY_H
