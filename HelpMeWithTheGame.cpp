#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second


string ss;
char table[17][33];
map<char,int> mp ={{'K',0},{'Q',1},{'R',2},{'B',3},{'N',4},{'P',5}};
vector<vector<pair<pair<int,char>,char>>> white(6), black(6);

bool compBlack(const pair<pair<int, char>,char> &a, const pair<pair<int, char>,char> &b) {
    if(mp[a.s] != mp[b.s]) return mp[a.s] < mp[b.s];
    else if(a.f.f!=b.f.f)return a.f.f > b.f.f;
    else return a.f.s< b.f.s;
}

bool compWhite(const pair<pair<int, char>,char> &a, const pair<pair<int, char>,char> &b) {
    if(mp[a.s] != mp[b.s]) return mp[a.s] < mp[b.s];
    else if(a.f.f!=b.f.f)return a.f.f < b.f.f;
    else return a.f.s < b.f.s;
}


void solve(){
    for(int i = 0; i < 17; ++i){
        for(int j = 0; j < 33; ++j){
            cin>>table[i][j];
        }
    }
    int row = 9,col, whiteE = 0, blackE=0;
    for(int i = 1; i < 17; i+=2){
        row--, col=0;
        for(int j = 2; j < 33; j+=4){
            col++;
            if(table[i][j]!=':'&&table[i][j]!='.'){
                if(isupper(table[i][j])){
                    whiteE++;
                    char c = col + 'a' - 1;
                    white[mp[table[i][j]]].push_back({{row,c},table[i][j]});
                }
                else{
                    blackE++;
                    char c = col+ 'a' - 1, aux = toupper(table[i][j]);
                    black[mp[aux]].push_back({{row,c},aux});
                }
            }
        }
    }
    int cont = 0;
    cout<<"White: ";
    for(int i = 0; i < 6; ++i)sort(white[i].begin(),white[i].end(),compWhite);
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < white[i].size(); ++j){
            cont++;
            if(white[i][j].s!='P')cout<<white[i][j].s;
            cout<<white[i][j].f.s<<white[i][j].f.f;
            if(cont!=whiteE)cout<<',';
        }
    }
    cout<<'\n';
    cont=0;
    cout<<"Black: ";
    for(int i = 0; i < 6; ++i)sort(black[i].begin(), black[i].end(), compBlack);
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < black[i].size(); ++j){
            cont++;
            if(black[i][j].s!='P')cout<<black[i][j].s;
            cout<<black[i][j].f.s<<black[i][j].f.f;
            if(cont!=blackE)cout<<',';
        }
    }
}

int main(){
    solve();
    return 0;
}
