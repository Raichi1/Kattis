#include <bits/stdc++.h>
using namespace std;

double p,a,b,c,d;
int n;

double func(int k){
    return p*(sin(a*k+b)+cos(c*k+d)+2);
}

void solve(){
    cin>>p>>a>>b>>c>>d>>n;
    double ans = 0, mx = func(1);
    for(int i = 2; i <=n; ++i){
        mx = max(mx,func(i));
        ans = max(ans,mx-func(i));
    }
    cout<<fixed<<setprecision(6)<<ans<<'\n';
}

int main(){
    solve();
    return 0;
}