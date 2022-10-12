#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>


#define y 12
#define x 5

 
using namespace std;
 
 
int convert(long long n) {
  int dec = 0, i = 0, rem;
 
  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
 
  return dec;
}

 
int main(){
    fstream in("przyklad.txt");
    char input;
    string wynik1="",wynik0="";
    int tab[y][x];
    vector<vector<int> > zapisane1;
    vector<vector<int> > zapisane2;

    int zlicz1=0,zlicz0=0;
    
    for (int i = 0; i < y; i++)//1000
    {
        for (int j = 0; j < x; j++)//12
        {
            in>>input;
            tab[i][j] = input-48;
            // cout<<tab[i][j];
        }
        // cout<<endl;
    }
 
vector<int> porownania;
for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++)
        {
            if(tab[j][i] == 1){
                zlicz1++;
            }
            else
                zlicz0++;
        }
        if(zlicz1>=zlicz0){
            porownania.push_back(1);
       }
       else
            porownania.push_back(0);
        zlicz0 = zlicz1 = 0;
}
// for(int a:porownania){
//     cout<<a<<" ";
// }

// cout<<endl;
    
    int k=0;
            for (int j = 0; j < y; j++)//1000
            {
                vector<int> tep;
                if(((porownania[k] == 1) && (tab[j][k] == 1)) || ((porownania[k] == 0) && (tab[j][k] == 0))){  
                    for (int i = 0; i < x; i++)//12
                    {
                        tep.push_back(tab[j][i]);
                    }
                    zapisane1.push_back(tep);
                }
                k++;
            }
                
     
    for (int i = 0; i < zapisane1.size(); i++)
    {
        for (int j = 0; j < zapisane1[i].size(); j++)
        {
            cout<<zapisane1[i][j];
        }
        cout<<'\n';
    }
    //         cout<<'\n';
    // for (int i = 0; i < zapisane2.size(); i++)
    // {
    //     for (int j = 0; j < zapisane2[i].size(); j++)
    //     {
    //         cout<<zapisane2[i][j];
    //     }
    //     cout<<'\n';
    // }
    
 
    return 0;
}