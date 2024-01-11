#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
char grid[3][3];
int rowx[3], colx[3], rowo[3], colo[3];

void solve(){
    char ch;
    memset(rowx, 0, sizeof rowx);
    memset(colx, 0, sizeof colx);
    memset(rowo, 0, sizeof rowo);
    memset(colo, 0, sizeof colo);
    int x= 0, o=0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin>>grid[i][j];
            if(grid[i][j]=='X'){
                x++;
                rowx[i]++,colx[j]++;
            }
            if(grid[i][j]=='O'){
                o++;
                rowo[i]++; colo[j]++;
            }
        }
    }
    bool winX = 0, winO = 0;
    for(int i = 0; i < 3; ++i){
        if(rowx[i]==3 || colx[i]==3)winX=1;
        if(rowo[i]==3 || colo[i]==3)winO=1;
    }
    
    if(grid[1][1]==grid[0][0]&&grid[0][0]==grid[2][2]&&grid[1][1]=='O')winO=1;
    else if(grid[1][1]==grid[0][2]&&grid[1][1]==grid[2][0]&&grid[1][1]=='O')winO=1;
    if(grid[1][1]==grid[0][0]&&grid[0][0]==grid[2][2]&&grid[1][1]=='X')winX=1;
    else if(grid[1][1]==grid[0][2]&&grid[1][1]==grid[2][0]&&grid[1][1]=='X')winX=1;

    if(!winX && !winO){
        cout<<((x==o||x-o==1)?"yes":"no");
    }
    else{
        if(winO && winX)cout<<"no";
        else{
            if(winX && !winO)cout<<((x-o==1)?"yes":"no");
            else if(winO && !winX)cout<<((x==o)?"yes":"no");
        }
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
        cin.ignore();
    }
    return 0;
}