#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    string s;
    cin>>n>>s;
    deque<int> fr, sc, dqOrg;
    for(int i = 1; i<=n; ++i){
        if(n&1){
            if(s=="out")(i<=(n/2+1))?fr.push_back(i):sc.push_back(i);
            else (i<=n/2)?fr.push_back(i):sc.push_back(i);
        }
        else (i<=n/2)?fr.push_back(i):sc.push_back(i);
        dqOrg.push_back(i);
    }
    deque<int> result;
    int cont = 0;
    bool valid;
    while(1){
        valid = 1;
        cont++;
        if(s=="out"){
            while(!fr.empty() && !sc.empty()){
                result.push_back(fr.front());
                fr.pop_front();
                result.push_back(sc.front());
                sc.pop_front();
            }
            if(!fr.empty()){
                result.push_back(fr.front());
                fr.pop_front();
            }
        }
        else{
            while(!fr.empty() && !sc.empty()){
                result.push_back(sc.front());
                sc.pop_front();
                result.push_back(fr.front());
                fr.pop_front();
            }
            if(!sc.empty()){
                result.push_back(sc.front());
                sc.pop_front();
            }
        }
        for(int i = 0 ; i < result.size(); ++i){
            if(result[i]!=dqOrg[i])valid=0;
            if(!(n&1))(i<result.size()/2)?fr.push_back(result[i]):sc.push_back(result[i]);
            else {
                if(s=="out")(i<(result.size()/2+1))?fr.push_back(result[i]):sc.push_back(result[i]);
                else (i<(result.size()/2))?fr.push_back(result[i]):sc.push_back(result[i]);
            }
        }
        if(valid)break;
        result.clear();
    }
    cout<<cont<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}