#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <numeric>

using namespace std;

#define days 256

int main(){
   fstream plik("zadanie.txt");
   char input;
    vector<int> fish;
   
   while(!plik.eof()){
    plik.get(input);
    if(input != ',')
        fish.push_back(input-48);
   }
   

    constexpr int DaysInCycle = 9;
	std::array<int64_t, DaysInCycle> CurrentFish{};
	for (int DaysRemainingForFish : fish)
	{
		CurrentFish[DaysRemainingForFish]++;
	}

    // for (int a : CurrentFish)
	// {
	// 	cout<<a<<" ";
	// }

	for (int i = 0; i < days; ++i)
	{
		std::array<int64_t, DaysInCycle> NextFish{};
		NextFish[6] = CurrentFish[0];
		NextFish[8] = CurrentFish[0];
		for (int j = 1; j < CurrentFish.size(); ++j)
		{
			NextFish[j - 1] += CurrentFish[j];
		}

		CurrentFish = NextFish;
	}

	cout<< std::accumulate(CurrentFish.begin(), CurrentFish.end(), 0ull);

    return 0;
}