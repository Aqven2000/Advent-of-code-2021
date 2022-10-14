#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define plik "zadanie.txt"

void przypis_danych(int& x1,int& y1,int& x2,int& y2,string s){
    int i=0;
    while(s[i]!=',')
    {
        x1= (x1*10)+(s[i]-48);
        i++;
    } 
    i++;
    while(s[i]!=' ')
    {
         y1= (y1*10)+(s[i]-48);
         i++;
    } 
    i+=4;
    while(s[i]!=',')
    {
        x2= (x2*10)+(s[i]-48);
        i++;
    } 
    i++;
    while(i<s.size())
    {
         y2= (y2*10)+(s[i]-48);
         i++;
    } 
}

int main(){
    fstream in(plik);
    int x1 =0 ,y1=0,x2=0,y2=0;
    string s;
    int max_wielgosc_y = 0,max_wielgosc_x = 0;
    while (getline(in,s))
    {
        przypis_danych(x1,y1,x2,y2,s);

        if(max_wielgosc_x<x1)
            max_wielgosc_x = x1;
        else if(max_wielgosc_x<x2)
            max_wielgosc_x = x2;

        if(max_wielgosc_y<y1)
            max_wielgosc_y = y1;
        else if(max_wielgosc_y<y2)
            max_wielgosc_y = y2;
        x1=x2=y2=y1=0;
    }
    max_wielgosc_y+=1;
    max_wielgosc_x+=1;

    

    char tab[max_wielgosc_y][max_wielgosc_x];
    
    for(int i=0;i<max_wielgosc_y;i++){
        for(int j=0;j<max_wielgosc_x;j++){
            tab[i][j] = '.';
        }
    }
        s ="";
        in.close();
         fstream in2(plik);


    while(getline(in2,s)){
        przypis_danych(x1,y1,x2,y2,s);

        if((x1==x2 || y1==y2) && (x1<=x2 && y1<=y2)){
            for (int i = y1; i <= y2; i++)
            {
                for (int j = x1; j <= x2; j++)
                {
                    if(tab[i][j] == '.'){
                        tab[i][j] = '1';
                    }
                    else{
                        tab[i][j]+=1;
                    }
                }
                
            }
        }
        else if((x1==x2 || y1==y2) &&(x1>=x2 && y1<=y2)){
            for (int i = y1; i <= y2; i++)
            {
                for (int j = x2; j <= x1; j++)
                {
                    if(tab[i][j] == '.'){
                        tab[i][j] = '1';
                    }
                    else{
                        tab[i][j]+=1;
                    }
                }
                
            }
        }
        else if((x1==x2 || y1==y2) &&(x1<=x2 && y1>=y2)){
            for (int i = y2; i <= y1; i++)
            {
                for (int j = x1; j <= x2; j++)
                {
                    if(tab[i][j] == '.'){
                        tab[i][j] = '1';
                    }
                    else{
                        tab[i][j]+=1;
                    }
                }
                
            }
        }
        else if((x1==x2 || y1==y2) &&(x1>=x2 && y1>=y2)){
            for (int i = y2; i <= y1; i++)
            {
                for (int j = x2; j <= x1; j++)
                {
                    if(tab[i][j] == '.'){
                        tab[i][j] = '1';
                    }
                    else{
                        tab[i][j]+=1;
                    }
                }
                
            }
        }//-------------------diagonal-------------------
        else if(x1<x2 && y1<y2){
            int j = y1;
            for (int i = x1; i <= x2; i++)
            {
                    if(tab[j][x1] == '.'){
                        tab[j][x1] = '1';
                    }
                    else{
                        tab[j][x1]+=1;
                    }
                x1++;j++;
            }
        }
        else if(x1>x2 && y1<y2){
            int j = y2;
            for (int i = x2; i <= x1; i++)
            {
                    if(tab[j][x2] == '.'){
                        tab[j][x2] = '1';
                    }
                    else{
                        tab[j][x2]+=1;
                    }
                x2++;j--;
            }
        }
        else if(x1<x2 && y1>y2){
            int j = y1;
            for (int i = x1; i <= x2; i++)
            {
                    if(tab[j][x1] == '.'){
                        tab[j][x1] = '1';
                    }
                    else{
                        tab[j][x1]+=1;
                    }
                x1++;j--;
            }
        }
        else if(x1>x2 && y1>y2){
            int j = y2;
            for (int i = x2; i <= x1; i++)
            {
                    if(tab[j][x2] == '.'){
                        tab[j][x2] = '1';
                    }
                    else{
                        tab[j][x2]+=1;
                    }
                x2++;j++;
            }
        }
        x1=x2=y2=y1=0; 
    }
    int zlicz =0;
        for(int i=0;i<max_wielgosc_y;i++){
            for(int j=0;j<max_wielgosc_x;j++){
                if(tab[i][j]>='2'){
                    zlicz++;
                }
               // cout<<tab[i][j]<<" ";
            }
           // cout<<endl;
        }
        cout<<zlicz<<endl;



    return 0;
}