#ifndef SIMULATE_H
#define SIMULATE_H
#include "runway.h"

void airport_simulate
(unsigned int takeoff_time, double takeoff_probability, unsigned int landing_time,
double landing_probability, unsigned int fuel_limit, unsigned int total_time){        //total time you will run the simulation.
    // Precondition: 0 <= arrival_prob <= 1.
    // Postcondition: The function has simulated a car wash where wash_time is the number of
    // seconds needed to wash one car, arrival_prob is the probability of a customer arriving in
    // any second, and total_time is the total number of seconds for the simulation. Before the
    // simulation, the function has written its three parameters to cout. After the simulation, the
    // function has written two pieces of information to cout: (1) the number of cars washed and
    // (2) the average waiting time of a customer.

    Queue<unsigned int> arrival_times; // Time stamps of the waiting airplanes to land
    Queue<unsigned int> departure_times; //Time stamps of the waiting airplanes to takeoff
    unsigned int next_to_land;
    unsigned int next_to_takeoff;                 // A value taken from the queue
    bool_source arrival(landing_probability);
    bool_source departure(takeoff_probability);
    runway runway(landing_time, takeoff_time);
    averager wait_landtimes, wait_takeofftimes;
    unsigned int current_second;
    unsigned int CRASHED_PLANES = 0;
    bool DEBUG = false;

    // Write the parameters to cout.
    cout << endl;
    cout << "============================================="<<endl;
    cout << "Time to take off: " << takeoff_time << endl;
    cout << "Time to land: " << landing_time << endl;
    cout << "Probability of landing: ";
    cout << landing_probability << endl;
    cout << "Probability of takeoff: ";
    cout << takeoff_probability << endl;
    cout << "Fuel: time to crash: ";
    cout << fuel_limit <<endl;
    cout << "Total simulation time: " << total_time << endl;
    cout << endl << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . "<<endl;
    for (current_second = 1; current_second <= total_time; ++current_second) { // Simulate the passage of one second of time.
    // Check whether a new customer has arrived.
        if(DEBUG){
            cout<<"----------------"<<current_second<<" second has passed"<<endl;
        }

        if (arrival.query( )){
            arrival_times.push(current_second);
            if(DEBUG)
                cout<<"A plane wants to land!"<<endl;
        }
        if (departure.query()){
            departure_times.push(current_second);
            if(DEBUG)
                cout<<"A plane wants to depart!"<<endl;
        }
    // Check whether we can start landing or taking off.
        if ((!runway.is_busy( )) && (!arrival_times.empty( ))) {
            next_to_land = arrival_times.pop( );
            while((current_second - next_to_land) > fuel_limit && (!arrival_times.empty())){

                if(DEBUG){
                    cout<<"EEEEeeerrr BOOM! A PLANE HAS CRASHED!"<<endl;
                    cout<<"This plane waited for "<<(current_second - next_to_land)<< " to land!"<<endl;
                }
                next_to_land = arrival_times.pop();
                ++CRASHED_PLANES;
            }
            wait_landtimes.next_number(current_second - next_to_land);
            runway.start_landing( );

            if(DEBUG){
                cout<<"A plane is now landing on the runway!"<<endl;
                cout<<"This plane waited "<<(current_second - next_to_land)<<" to land!"<<endl;
            }
        }
        else if  ((!runway.is_busy( )) && (arrival_times.empty( )) && (!departure_times.empty())) {
            next_to_takeoff = departure_times.pop();
            wait_takeofftimes.next_number(current_second - next_to_takeoff);
            runway.start_takeoff();

            if(DEBUG){
                cout<<"A plane is on the runway to take off!"<<endl;
                cout<<"This plane waited "<<(current_second - next_to_takeoff)<<" to take off!"<<endl;
            }

        }
    // Tell the washer to simulate the passage of one second.
              runway.one_second( );
    }
    // Write the summary information about the simulation.
    cout <<  wait_landtimes.how_many_numbers( ) << " landed" << endl;
    cout <<  wait_takeofftimes.how_many_numbers( ) <<" took off" <<endl;
    cout << CRASHED_PLANES << " planes crashed";
    if(CRASHED_PLANES > 0)
        cout<<" :( "<<endl;
    else
        cout<<" :) "<<endl;
    if (wait_landtimes.how_many_numbers( ) > 0)
        cout << "Average waiting times to land: " << wait_landtimes.average( ) << endl;
    if (wait_takeofftimes.how_many_numbers( ) > 0)
        cout << "Average waiting times to takeoff: " << wait_takeofftimes.average( ) << endl;
    cout<<"Planes in landing queue: "<<arrival_times.count()<<endl;
    cout<<"Planes in take off queue:"<<departure_times.count()<<endl;
    cout << "============================================="<<endl;

}

#endif // SIMULATE_H
