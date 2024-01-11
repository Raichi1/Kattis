#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char grid[8][8];
int dir;
string s;

bool valid(int y, int x){ return x>=0 && x<8 && y>=0 && y<8; }

void solve(){
    dir=0;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            cin>>grid[i][j];
        }
    }
    cin>>s;
    pair<int,int> coord = {7,0};
    int x, y;
    for(int i = 0; i < s.size(); ++i){
        dir%=4;
        if(s[i]=='L')dir++;
        else if(s[i]=='R')dir--;
        
        if(s[i]=='F'){
            if(dir==0)++coord.s;//right
            else if(dir==-1||dir==3)++coord.f;//bottom
            else if(dir==-2||dir==2)--coord.s;//left
            else if(dir==1||dir==-3)--coord.f;//up
            if(!valid(coord.f,coord.s) || grid[coord.f][coord.s]=='I' || grid[coord.f][coord.s]=='C'){
                cout<<"Bug!";
                return;
            }
        }else{
            if(s[i]=='X'){
                x = coord.s, y = coord.f;
                if(dir==0)++x;//right
                else if(dir==-1||dir==3)++y;//bottom
                else if(dir==-2||dir==2)--x;//left
                else if(dir==1||dir==-3)--y;//up
                if(!valid(y,x) || grid[y][x] != 'I'){
                    cout<<"Bug!";
                    return;
                }else grid[y][x]='.';
            }
        }
    }
    cout<<((grid[coord.f][coord.s]=='D')?"Diamond!":"Bug!");
}

int main(){
    solve();
    return 0;
}