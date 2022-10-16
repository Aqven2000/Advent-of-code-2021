#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int spr_do_okola(int i,int j,vector<string> heightmap){
    bool czy_min = true;
    int min_top = 9;
    int min_right = 9;
    int min_down = 9;
    int min_left = 9;
    
    // // * -> sprawdzana @ -> liczba

    // //  . * .
    // //  . @ .
    // //  . . .

    // if(i-1>=0 && heightmap[i-1][j]<heightmap[i][j])
    //     czy_min = false;
    // //  . . .
    // //  . @ *
    // //  . . .
    // else if(j+1<=heightmap[i].size()-1 && heightmap[i][j+1]<heightmap[i][j])
    //     czy_min = false;
    // //  . . .
    // //  . @ .
    // //  . * .
    // else if(i+1<=heightmap.size()-1 && heightmap[i+1][j]<heightmap[i][j])
    //     czy_min = false;
    // //  . . .
    // //  * @ .
    // //  . . .
    // else if(j-1>=0 && heightmap[i][j-1]<heightmap[i][j])
    //     czy_min = false;
    
    //  . * .
    //  . @ .
    //  . . .

    if(i-1>=0)
        min_top = heightmap[i-1][j]-'0';
    //  . . .
    //  . @ *
    //  . . .
     if(j+1<=heightmap[i].size()-1)
        min_right = heightmap[i][j+1]-'0';
    //  . . .
    //  . @ .
    //  . * .
     if(i+1<=heightmap.size()-1)
        min_down = heightmap[i+1][j]-'0';
    //  . . .
    //  * @ .
    //  . . .
     if(j-1>=0)
        min_left = heightmap[i][j-1]-'0';
    
    int wynik = min(min(min_top,min_down),min(min_right,min_left));
        return wynik;
}

int main(){
    fstream plik("test.txt");
    string s;
    vector<string> heightmap;

    while (plik>>s)
    {
        heightmap.push_back(s);
    }
    // for (int i = 0; i < heightmap.size(); i++)
    // {
    //     for (int j = 0; j < heightmap[i].size(); j++)
    //     {
    //         cout<<heightmap[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    vector<int> LowPoints;

    int sum_of_risk_levels = 0,zlicz =0;
    for (int i = 0; i < heightmap.size(); i++)
    {
        for (int j = 0; j < heightmap[i].size(); j++)
        {
           // int current_height = heightmap[i][j]-48;
                 LowPoints.push_back(spr_do_okola(i,j,heightmap));
                // cout<<current_height<<" ";
        }
        // cout<<endl;
    }
    
    for (auto LowPoint : LowPoints)
    {
        cout<<LowPoint<<" ";
        sum_of_risk_levels+= LowPoint+1;
    }
    
    cout<<sum_of_risk_levels;
    

    return 0;
}