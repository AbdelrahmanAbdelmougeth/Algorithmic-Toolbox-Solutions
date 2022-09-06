#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

//O(n) n is the number of stations
int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code here
    int refills = 0;
    int car_location = 0;

    if (dist <= tank)
        return refills;

    // get greedy
    int i = stops.size() - 1;
    while (tank < dist - car_location)
    {
        //get the furthest safe point the car can reach
        while (tank < stops[i] - car_location && i != -1 && car_location != stops[i]){
            i--;
        }
        //check for the safe move
        if (i == -1 || car_location == stops[i]){
            //that's not a safe move
            refills = -1;
            break;
        }

        //this is a safe move
        car_location = stops[i];
        refills++;
        i = stops.size() - 1;   
    }

    return refills;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
