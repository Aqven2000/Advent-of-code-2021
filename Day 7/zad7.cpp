#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;


int fuel_needed_for_current_position(int position_element, int current_max_position){
    auto Distance = abs(position_element-current_max_position);
    auto Fuel = Distance * (Distance + 1) / 2;
    
    return Fuel;
}

int main(){
    fstream plik("zadanie.txt");
    vector<int> positions;
     char input;
    int a = 0;
    int Current_max_distance =0;
    
    while (plik>>input)
    {
        if(input != ',')
            a = (a*10)+(input-48);
        else{
            if(a>Current_max_distance)
                Current_max_distance = a;

            positions.push_back(a);
            a = 0;
        }
    }
    positions.push_back(a);
    

    // Current_max_distance =5;
    size_t fuel_needed =0,fuel_min = INT_MAX;
    int fuel_cost =0;
    Current_max_distance++;

    while (Current_max_distance--)
    {
        fuel_needed = 0;
        for (auto position_element : positions)
        {
            fuel_needed += fuel_needed_for_current_position(position_element,Current_max_distance);
        }
        if(fuel_min>fuel_needed)
            fuel_min = fuel_needed;
    }

    cout<<fuel_min;

    
    return 0;
}