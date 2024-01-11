#include <bits/stdc++.h>
using namespace std;

map<char,int> dom = {{'A',11},{'K',4},{'Q',3},{'J',20},{'T',10},{'9',14},{'8',0},{'7',0}};
map<char,int> ndom = {{'A',11},{'K',4},{'Q',3},{'J',2},{'T',10},{'9',0},{'8',0},{'7',0}};
int n;
char ch;
string s;

void solve(){
    int ans = 0;
    cin>>n>>ch;
    n*=4;
    while(n--){
        cin>>s;
        ans+=((s[1]==ch)?dom[s[0]]:ndom[s[0]]);
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}