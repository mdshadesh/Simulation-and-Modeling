#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Exponential distribution function for interarrival and service times
double expDist(double rate) {
    double u = (double) rand() / RAND_MAX;
    return -log(1-u) / rate;
}

int main() {
    int numCustomers;  // Number of customers in the system
    double lambda, mu; // Arrival and service rates
    double simTime;    // Simulation time

    // Get input from user
    cout << "Enter number of customers: ";
    cin >> numCustomers;
    cout << "Enter arrival rate (lambda): ";
    cin >> lambda;
    cout << "Enter service rate (mu): ";
    cin >> mu;
    cout << "Enter simulation time: ";
    cin >> simTime;

    // Initialize simulation variables
    double clock = 0.0; // Simulation clock
    double nextArrival = expDist(lambda); // Time of next arrival
    double nextDeparture = simTime + 1;   // Time of next departure (initialize to large value)
    queue<double> queue; // Customer queue
    int numInSystem = 0; // Number of customers in the system
    int numServed = 0;   // Number of customers served
    double totalDelay = 0.0; // Total delay of all customers

    // Run simulation
    while (numServed < numCustomers) {
        if (nextArrival < nextDeparture) {
            // Process an arrival event
            clock = nextArrival;
            numInSystem++;
            if (numInSystem == 1) {
                // Schedule a departure event
                nextDeparture = clock + expDist(mu);
            }
            else {
                // Add customer to queue
                queue.push(clock);
            }
            // Schedule the next arrival event
            nextArrival = clock + expDist(lambda);
        }
        else {
            // Process a departure event
            clock = nextDeparture;
            numInSystem--;
            numServed++;
            totalDelay += clock - queue.front();
            queue.pop();
            if (numInSystem > 0) {
                // Schedule the next departure event
                nextDeparture = clock + expDist(mu);
            }
            else {
                // No customers in the system, set next departure to large value
                nextDeparture = simTime + 1;
            }
        }
    }

    // Output simulation results
    double avgDelay = totalDelay / numCustomers;
    cout << "Simulation results:" << endl;
    cout << "Number of customers: " << numCustomers << endl;
    cout << "Arrival rate: " << lambda << endl;
    cout << "Service rate: " << mu << endl;
    cout << "Simulation time: " << simTime << endl;
    cout << "Average delay: " << avgDelay << endl;

    return 0;
}
