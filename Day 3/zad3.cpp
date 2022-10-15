#include <iostream>
#include <fstream>
#include <vector>


#define y 1000
#define x 12

 
using namespace std;

int main(){
    fstream in("zadania.txt");
    vector<string> tab;
    vector<string> tabPom;
    int zlicz0 = 0,zlicz1 = 0;

    for (int i = 0; i < y; i++)
    {
        string a;
        in>>a;
        tab.push_back(a);
        // tabPom.push_back(a);
    }
in.close();
    int i = 0;
     while(i<x){  
            // for (int i = 0; i < x; i++){ 
                vector<char> porownania;
                for (int k = 0; k < x; k++){
                    for (int g = 0; g < tab.size(); g++){
                        if(tab[g][k] == '1'){
                            zlicz1++;
                        }
                        else
                            zlicz0++;
                    }
                        if(zlicz1>=zlicz0){
                            porownania.push_back('1');
                        }
                        else
                            porownania.push_back('0');
                        zlicz0 = zlicz1 = 0;
                }
                tabPom.clear();
                for (int j = 0; j < tab.size(); j++){
                    if(porownania[i] == tab[j][i]){
                        tabPom.push_back(tab[j]);
                    }
                }
                if(tab.size() == 1 || tabPom.size() == 1)
                    break;
                // for(string a : tabPom){
                //         cout<<a<<endl;
                // }
                // cout<<endl;
                i++;
                //------------------------------------------------------------------------------
                porownania.clear();
                for (int k = 0; k < x; k++){
                    for (int g = 0; g < tabPom.size(); g++){
                        if(tabPom[g][k] == '1'){
                            zlicz1++;
                        }
                        else
                            zlicz0++;
                    }
                        if(zlicz1>=zlicz0){
                            porownania.push_back('1');
                        }
                        else
                            porownania.push_back('0');
                        zlicz0 = zlicz1 = 0;
                }

                tab.clear();
                for (int j = 0; j < tabPom.size(); j++){
                    if(porownania[i] == tabPom[j][i]){
                        tab.push_back(tabPom[j]);
                    }
                }
                if(tab.size() == 1 || tabPom.size() == 1)
                    break;
                // for(string a : tab){
                //         cout<<a<<endl;
                // }
                i++;
            }
   if(tabPom.size() == 1) 
    for(string a : tabPom){
            cout<<a<<endl;
        }
else
    for(string a : tab){
            cout<<a<<endl;
    }


    //------------------Dla 0------------------------
    tab.clear();
    tabPom.clear();
fstream in2("zadania.txt");
    for (int i = 0; i < y; i++)
    {
        string a;
        in2>>a;
        tab.push_back(a);
        // tabPom.push_back(a);
    }

     i = 0;
     while(i<x){  
                vector<char> porownania;
                for (int k = 0; k < x; k++){
                    for (int g = 0; g < tab.size(); g++){
                        if(tab[g][k] == '1'){
                            zlicz1++;
                        }
                        else
                            zlicz0++;
                    }
                        if(zlicz1>=zlicz0){
                            porownania.push_back('0');
                        }
                        else
                            porownania.push_back('1');
                        zlicz0 = zlicz1 = 0;
                }
                tabPom.clear();
                for (int j = 0; j < tab.size(); j++){
                    if(porownania[i] == tab[j][i]){
                        tabPom.push_back(tab[j]);
                    }
                }
                if(tab.size() == 1 || tabPom.size() == 1)
                    break;
                // for(string a : tabPom){
                //         cout<<a<<endl;
                // }
                // cout<<endl;
                i++;
                //------------------------------------------------------------------------------
                porownania.clear();
                for (int k = 0; k < x; k++){
                    for (int g = 0; g < tabPom.size(); g++){
                        if(tabPom[g][k] == '1'){
                            zlicz1++;
                        }
                        else
                            zlicz0++;
                    }
                        if(zlicz1>=zlicz0){
                            porownania.push_back('0');
                        }
                        else
                            porownania.push_back('1');
                        zlicz0 = zlicz1 = 0;
                }

                tab.clear();
                for (int j = 0; j < tabPom.size(); j++){
                    if(porownania[i] == tabPom[j][i]){
                        tab.push_back(tabPom[j]);
                    }
                }
                if(tab.size() == 1 || tabPom.size() == 1)
                    break;
                // for(string a : tab){
                //         cout<<a<<endl;
                // }
                i++;
            }
   if(tabPom.size() == 1)
    for(string a : tabPom){
            cout<<a<<endl;
        }
   else
    for(string a : tab){
            cout<<a<<endl;
    }
   

    return 0;
}