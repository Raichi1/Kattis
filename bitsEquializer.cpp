#include <bits/stdc++.h>
using namespace std;

int i = 1;

void solve(){
    string s,t;
    cin>>s>>t;
    int zerosOnes = 0, onesZeros = 0, q = 0, zeros = 0, ones = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i]=='?'){
            (t[i]=='1')?ones++:zeros++;
            q++;
            continue;
        }
        if(s[i]!=t[i]){
            (s[i]=='1')?onesZeros++:zerosOnes++;
        }
    }
    cout<<"Case "<<i++<<": ";
    int ans = min(onesZeros,zerosOnes), res = abs(onesZeros-zerosOnes);
    if(zerosOnes>=onesZeros){
        cout<<ans+q+res;
    }else{
        if(res<=ones){
            ans+=ones;
            ones-=res;
            if(q>=ones)cout<<ans+(q-ones);
            else cout<<-1;
        }else cout<<-1;
    }
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