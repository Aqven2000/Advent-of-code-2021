#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    fstream in("przyklad.txt");
    int input =0;
    int zlicz =0;
    
    vector<int> drawnNum{7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1};
    // vector<int> drawnNum{17,25,31,22,79,72,58,47,62,50,30,91,11,63,66,83,33,75,44,18,56,81,32,46,93,13,41,65,14,95,19,38,8,35,52,7,12,70,84,23,4,42,90,60,6,40,97,16,27,86,5,48,54,64,29,67,26,89,99,53,34,0,57,3,92,37,59,9,21,78,51,80,73,82,76,28,88,96,45,69,98,1,2,71,68,49,36,15,55,39,87,77,74,94,61,85,10,43,20,24};
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
    int zliczIndex=0;
    for (auto i = 0; i < karty.size(); i++)
    {
        for (auto j = 0; j < karty[i].size(); j++)
        {
            if(karty[i][j] == drawnNum[iterator]){
                karty[i][j] = -1;
            }
            int zliczP =0;
            
            for (auto a = 0; a < 5; a++)
            {
                if(karty[i][a] == -1)
                    zliczP++;
            }
            if(zliczP == 5){
                int odp=0;
                for (auto b = i-zliczIndex; b < i-zliczIndex+5; b++)//y parameter
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
            else
                zliczP=0;
            for (auto a = i-zliczIndex; a < i-zliczIndex+5; a++)
            {
                if(karty[a][j] == -1)
                    zliczP++;
            }
             if(zliczP ==5){
                int odp=0;
                for (auto b = i-zliczIndex; b < i-zliczIndex+5; b++)//y parameter
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
            else
                zliczP=0;
            
        }
        if(zliczIndex == 4)
            zliczIndex = 0;
        zliczIndex++;
    }
    iterator++;
}

    
    return 0;
}