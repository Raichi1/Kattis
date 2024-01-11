#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

string ss;
char table[17][33];
map<pair<int,int>, char> mp;
bool piece = 1;

void read(string &s){
    string word = "";
    int r, c;
    for(int i = 0; i < s.size(); ++i){
        if(s[i]==' ')continue;
        if(s[i]==','){
            if(word.size()==2){
                string aux = 'P' + word;
                word=aux;
            }
            r = 9-(word[2]-'0'), c = word[1] - 'a' + 1;
            mp[{r,c}] = (piece)?word[0]:tolower(word[0]);
            word.clear();
        }
        else word+=s[i];
    }
    if(word.size()==2){
        string aux = 'P' + word;
        word=aux;
    }
    r = 9-(word[2]-'0'), c = word[1] - 'a' + 1;
    mp[{r,c}] = (piece)?word[0]:tolower(word[0]);
}

void solve(){
    cin>>ss;
    getline(cin,ss);
    read(ss);
    piece=0;
    cin>>ss;
    getline(cin,ss);
    read(ss);
    int row = 0, col;
    for(int i = 0; i < 17; ++i){
        col = 0;
        if(i&1)row++;
        for(int j = 0; j < 33; ++j){
            if(!(i&1)){
                if(j%4==0)table[i][j]='+';
                else table[i][j]='-';
            }else{
                if(j%4==0)table[i][j]='|';
                else{
                    if(j%4==1){
                        col++;
                        if((row&1 && col&1) || (row%2==0 && col%2==0))table[i][j]='.';
                        else if((row&1 && col%2==0) || (row%2==0 && col&1))table[i][j]=':';
                    }
                    if(j%4==2){
                        if(mp.count({row,col}))table[i][j]=mp[{row,col}];
                        else{
                           if((row&1 && col&1) || (row%2==0 && col%2==0))table[i][j]='.';
                           else if((row&1 && col%2==0) || (row%2==0 && col&1))table[i][j]=':'; 
                        }
                    }
                    if(j%4==3){
                        if((row&1 && col&1) || (row%2==0 && col%2==0))table[i][j]='.';
                        else if((row&1 && col%2==0) || (row%2==0 && col&1))table[i][j]=':';
                    }
                }
            }
        }
    }
    for(int i = 0; i < 17; ++i){
        for(int j = 0; j<33; ++j){
            cout<<table[i][j];
        }
        cout<<'\n';
    }
}

int main(){
    solve();
    return 0;
}
