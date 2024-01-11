#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int win = 0, stars = 0, rank = 25;
    for(int i = 0; i < s.size(); ++i){
        if(rank==0)break;
        if(s[i]=='W'){
            win++;
            stars++;
            if(win>=3 && rank>=6)stars++;
            
            if(rank>=21 && stars>=3)rank--, stars -=2;
            else if(rank>=16 && stars>=4)rank--, stars-=3;
            else if(rank>=11 && stars>=5)rank--, stars-=4;
            else if(rank>=1 && stars>=6)rank--, stars-=5;
        }
        else{
            win = 0;
            if(rank<=20){
                stars--;
                if(rank==20 && stars<0)stars=0;
                else{
                    if(rank < 10 && stars < 0)rank++, stars = 4;
                    else if(rank < 15 && stars < 0)rank++, stars = 3;
                    else if(rank < 20 && stars < 0 )rank++, stars = 2;
                }
            }
        }
    }
    if(rank)cout<<rank;
    else cout<<"Legend";
}

int main(){
    solve();
    return 0;
}