#include <bits/stdc++.h>
using namespace std;

int n, k, c1,c2;
string s1,s2;
    
void solve(){
    cin>>n>>k;
    vector<bool> v(n+1,0);
    map<string,int>mp;
    int matching=0;
    while(k--){
        cin>>c1>>c2>>s1>>s2;
        if(s1!=s2){
            if(!v[c1])mp[s1]++;
            if(!v[c2])mp[s2]++;
        }else{
            matching++;
            mp.erase(s1);
        }
        v[c1]=v[c2]=1;
    }
    n-=(matching*2);
    int matchCards = 0, single=0;
    for(auto e: mp){
        if(e.second==2)matchCards++;
        else single++;
    }
    if(n==matchCards*2+single*2)cout<<matchCards+single;
    else if(n==matchCards*2+2)cout<<matchCards+1;
    else cout<<matchCards;
    cout<<'\n';
}

int main(){
    solve();
    return 0;
}