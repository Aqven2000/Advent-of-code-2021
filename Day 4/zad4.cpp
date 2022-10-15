#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    fstream in("przyklad.txt");
    int input =0;
    int zlicz =0;
    
    vector<int> drawnNum{7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1};
    vector<vector<int> > karty;
    vector<int> tep;

    while(in>>input){
         tep.push_back(input);

        zlicz++;
        if(zlicz == 5){
            karty.push_back(tep);

            tep.clear();
            zlicz = 0;
        }
    }
    int iterator =0;
    
while(iterator<drawnNum.size()){
    for (auto i = 0; i < karty.size(); i++)
    {
        for (auto j = 0; j < karty[i].size(); j++)
        {
            if(karty[i][j] == drawnNum[iterator]){
                karty[i][j] = -1;
            }
            int zliczIndex=-1;
                for (auto a = 0; a < karty.size(); a++)
                {int zliczP =0; zliczIndex++;
                    for (auto b = 0; b < karty[a].size(); b++)
                    {
                        if(karty[a][b] == -1)
                            zliczP++;
                    }//------------------------WYNIK------------------------------
                    if(zliczIndex == 5)zliczIndex=0;
                    int odp =0;
                    if(zliczP==5){
                        for (auto b = a-zliczIndex; b < a-zliczIndex+5; b++)//y parameter
                        {
                            for (auto c = 0; c < 5; c++)
                            {
                                if(karty[b][c] != -1)
                                    odp+=karty[b][c];
                                cout<<karty[b][c]<< " ";
                            }
                            cout<<endl;
                        }
                        cout<<odp<< " "<<drawnNum[iterator]<<" "<<odp * drawnNum[iterator]<<endl;
                        return 0;
                    }//------------------------WYNIK-----------------------------
                    zliczP =0;
                }
                zliczIndex=-1;
                for (auto a = 0; a < 5; a++)//karty x index
                {int zliczP =0;zliczIndex++;
                    for (auto b = 0; b < karty.size(); b++)
                    {
                        zliczIndex++;
                        if(karty[a][b] == -1)
                            zliczP++;
                        if(zliczIndex==5){
                            if(zliczIndex == 5)zliczIndex=0;
                            int odp =0;
                            if(zliczP==5){
                                for (auto b = a-zliczIndex; b < a-zliczIndex+5; b++)//y parameter
                                 {
                                    for (auto c = 0; c < 5; c++)
                                    {
                                        if(karty[b][c] != -1)
                                            odp+=karty[b][c];
                                        cout<<karty[b][c]<< " ";
                                    }
                                    cout<<endl;
                                }
                                cout<<odp<< " "<<drawnNum[iterator]<<" "<<odp * drawnNum[iterator]<<endl;
                                return 0;
                            }    
                        }                               
                                
                        else
                            zliczP = zliczIndex =0;
                    }
                    zliczP =0;
                    
                }
        }
    }
    iterator++;
}

    
    // for (auto i = 0; i < karty.size(); i++)
    // {
    //     for (auto j = 0; j < karty[i].size(); j++)
    //     {
    //         cout<<karty[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}