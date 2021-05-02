#include "runway.h"
#include <cassert>
#include <cstdlib>
using namespace std;

bool_source::bool_source(double p){
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}

bool bool_source::query() const{
    return (rand() < probability * RAND_MAX);
}

averager::averager(){
    count = 0;
    sum = 0;
}

void averager::next_number(double value){
    ++count; //count in sum/count
    sum += value;
}

double averager::average() const{
    assert(how_many_numbers() > 0);
    return sum/count;
}

runway::runway(unsigned int s_land, unsigned int s_takeoff){
    time_for_landing = s_land;
    time_for_takeoff = s_takeoff;
    landing_time_left = 0;
    takeoff_time_left = 0;
}

void runway::one_second(){
    if(is_busy() && takeoff_time_left == 0){
        --landing_time_left;
    }
    else if (is_busy() && landing_time_left == 0){
        --takeoff_time_left;
    }
}

void runway::start_landing(){
    assert(!is_busy());
    landing_time_left = time_for_landing;
}

void runway::start_takeoff(){
    assert(!is_busy());
    takeoff_time_left = time_for_takeoff;
//    cout<<"TAKE OFF TIME LEFT: "<<takeoff_time_left;
}

