#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct bingo_win
{
    int odp =0;
    int drawnNum =0;
    int zliczone_num = odp * drawnNum;
};
vector<bingo_win> karty_win;


int spr_wiersz(int i,int j,vector<vector<vector<int> > >& karty,vector<int>& drawnNum,int iterator,int& iterator_karty_win){
    int zliczP =0;
                
                for (auto a = 0; a < 5; a++)
                {
                    if(karty[i][j][a] == -1)
                        zliczP++;
                }
                if(zliczP == 5){
                    int odp=0;
                    for (auto b = 0; b < 5; b++)//y parameter
                            {
                                for (auto c = 0; c < 5; c++)
                                {
                                    if(karty[i][b][c] != -1)
                                        odp+=karty[i][b][c];
                                    cout<<karty[i][b][c]<< " ";
                                }
                                cout<<endl;
                            }
                            cout<<odp<< " "<<drawnNum[iterator]<<" "<<odp * drawnNum[iterator]<<endl<<endl;
                            karty_win.push_back(bingo_win());
                            karty_win[iterator_karty_win].odp = odp;
                            karty_win[iterator_karty_win].drawnNum = drawnNum[iterator];
                            iterator_karty_win++;
                            // for (auto a = 0; a < karty.size(); a++)
                            //     {
                            //         for (auto b = 0; b < karty[a].size(); b++)
                            //         {
                            //             for (auto c = 0; c < karty[a][b].size(); c++)
                            //             {
                            //                 cout<<karty[a][b][c]<< " ";
                            //             }
                            //             cout<<endl;
                            //         }
                            //         cout<<endl;
                            //     }
                        return 0;
                }
                return -1;
}
int spr_kolumne(int i,int z,vector<vector<vector<int> > >& karty,vector<int>& drawnNum,int iterator,int& iterator_karty_win){
    int zliczP=0;
            for(auto a = 0; a < 5; a++)
                {
                    if(karty[i][a][z] == -1)
                        zliczP++;
                }
                if(zliczP ==5){
                    int odp=0;
                    for (auto b = 0; b < 5; b++)//y parameter
                            {
                                for (auto c = 0; c < 5; c++)
                                {
                                    if(karty[i][b][c] != -1)
                                        odp+=karty[i][b][c];
                                    cout<<karty[i][b][c]<< " ";
                                }
                                cout<<endl;
                            }
                            cout<<odp<< " "<<drawnNum[iterator]<<" "<<odp * drawnNum[iterator]<<endl<<endl;
                            karty_win.push_back(bingo_win());
                            karty_win[iterator_karty_win].odp = odp;
                            karty_win[iterator_karty_win].drawnNum = drawnNum[iterator];
                            iterator_karty_win++;
                                            // for (auto a = 0; a < karty.size(); a++)
                                            // {
                                            //     for (auto b = 0; b < karty[a].size(); b++)
                                            //     {
                                            //         for (auto c = 0; c < karty[a][b].size(); c++)
                                            //         {
                                            //             cout<<karty[a][b][c]<< " ";
                                            //         }
                                            //         cout<<endl;
                                            //     }
                                            //     cout<<endl;
                                            // }
                             return 0;
                }
                return -1;
}

int main(){
    fstream in("zadanie.txt");
    int input =0;
    int zlicz =0,zliczKarty =0;
    
    //   vector<int> drawnNum{7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1};
     vector<int> drawnNum{17,25,31,22,79,72,58,47,62,50,30,91,11,63,66,83,33,75,44,18,56,81,32,46,93,13,41,65,14,95,19,38,8,35,52,7,12,70,84,23,4,42,90,60,6,40,97,16,27,86,5,48,54,64,29,67,26,89,99,53,34,0,57,3,92,37,59,9,21,78,51,80,73,82,76,28,88,96,45,69,98,1,2,71,68,49,36,15,55,39,87,77,74,94,61,85,10,43,20,24};
    vector<vector<vector<int> > > karty;
    vector<int> tep;
    vector<vector<int> > tep2D;

    while(in>>input){
         tep.push_back(input);

        zlicz++;
        zliczKarty++;
        if(zlicz == 5){
            tep2D.push_back(tep);

            tep.clear();
            zlicz = 0;
        }
        if(zliczKarty == 25){
            karty.push_back(tep2D);

            tep2D.clear();
            zliczKarty = 0;
        }
    }



    // for (auto i = 0; i < karty.size(); i++)
    // {
    //     for (auto j = 0; j < karty[i].size(); j++)
    //     {
    //         for (auto z = 0; z < karty[i][j].size(); z++)
    //         {
    //             cout<<karty[i][j][z]<< " ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    
    int iterator =0;
    int iterator_karty_win =0;
while(iterator<drawnNum.size()){
    // int zliczIndex=0;
    for (auto i = 0; i < karty.size(); i++)
    {
        
        for (auto j = 0; j < karty[i].size(); j++)
        {
            for (auto z = 0; z < karty[i][j].size(); z++)
            {
            
                if(karty[i][j][z] == drawnNum[iterator]){
                    karty[i][j][z] = -1;
                
                    if(spr_wiersz(i,j,karty,drawnNum,iterator,iterator_karty_win) == 0)
                         karty[i].clear();
                    if(spr_kolumne(i,z,karty,drawnNum,iterator,iterator_karty_win) == 0)
                        karty[i].clear();
                }
            }
            
        }
        // iterator_karty_win++;
        // zliczIndex++;
    }
    iterator++;
}
// for(auto i : karty_win){
//     cout<<i.odp<< " "<< i.drawnNum<< " "<< i.zliczone_num<<endl;
// }

    
    return 0;
}