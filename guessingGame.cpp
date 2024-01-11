#include <bits/stdc++.h>
using namespace std;

int num;
string s;
vector<string> v(11);
bool valid=1;

void solve(){
    if(s!="right on"){
        if(v[num].size()>0 && v[num]!=s)valid=0;
        v[num]=s;
    }
    else{
        for(int i = num; i <=10; ++i){
            if(v[i].size()>0 && v[i]=="too low")valid=0;
        }
        for(int i = num; i>0; --i){
            if(v[i].size()>0 && v[i]=="too high")valid=0;
        }
        cout<<((valid)?"Stan may be honest": "Stan is dishonest")<<'\n';
        v.clear();
        v.resize(11);
        valid=1;
    }
}

int main(){
    while(cin>>num,num){
        cin.ignore();
        getline(cin,s);
        solve();
    }
    return 0;
}