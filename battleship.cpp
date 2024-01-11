#include <bits/stdc++.h>
using namespace std;


void solve(){
    int w,h,n, ships1 = 0, ships2=0;
    cin>>w>>h>>n;
    char pl1[h][w];
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin>>pl1[i][j];
            if(pl1[i][j]=='#')++ships1;
        }
    }
    char pl2[h][w];
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin>>pl2[i][j];
            if(pl2[i][j]=='#')++ships2;
        }
    }
    bool turn = 1, end = 0;
    int x,y;
    for(int i = 0; i < n; ++i){
        cin>>x>>y;
        if(end)continue;
        y=(h-1)-y;
        if(turn){
            if(pl2[y][x]=='#'){
                pl2[y][x]='_';
                --ships2;
                if(ships2==0)turn = !turn;
            }
            else turn = !turn;
        }else{
            if(pl1[y][x]=='#'){
                pl1[y][x]='_';
                --ships1;
                if(ships1==0)end=1;
            }else turn = !turn;
        }
    }
    if(ships1 && ships2) cout<<"draw";
    else if(ships1) cout<<"player one wins";
    else if(ships2) cout<<"player two wins";
    else cout<<"draw";
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}