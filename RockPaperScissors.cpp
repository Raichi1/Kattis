#include <bits/stdc++.h>
using namespace std;

int n,k, games, pl1, pl2;
string m1,m2;

void solve(){
    games = k*(n*(n-1))/2;
    vector<int> wons(n+1, 0), losts(n+1, 0);
    while(games--){
        cin>>pl1>>m1>>pl2>>m2;
        if(m1==m2)continue;
        else{
            if(m1=="rock"){
                if(m2=="scissors")wons[pl1]++,losts[pl2]++;
                if(m2=="paper")wons[pl2]++, losts[pl1]++;
            }
            if(m1=="paper"){
                if(m2=="scissors")wons[pl2]++,losts[pl1]++;
                if(m2=="rock")wons[pl1]++, losts[pl2]++;
            }
            if(m1=="scissors"){
                if(m2=="rock")wons[pl2]++,losts[pl1]++;
                if(m2=="paper")wons[pl1]++,losts[pl2]++;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(wons[i]==0 && losts[i]==0)cout<<"-\n";
        else cout<<fixed<<setprecision(3)<<(wons[i]*1.0)/(wons[i]+losts[i])<<'\n';
    }
    cout<<'\n';
}

int main(){
    while(cin>>n>>k, n){
        solve();
    }
    return 0;
}
