#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    string text="";
    cin>>n>>t;
    long long arr[n],sum=0, even=0;
    for(int i = 0; i <n; ++i){
        cin>>arr[i];
        sum+=arr[i];
        if(!(arr[i]&1))even+=arr[i];
        text+='a'+(arr[i]%26);
    }
    if(t==1)cout<<7;
    else if(t==2){
        if(arr[0]>arr[1])cout<<"Bigger";
        else if(arr[0]==arr[1])cout<<"Equal";
        else cout<<"Smaller";
    }else{
        if(t==3){
            sort(arr,arr+3);
            cout<<arr[1];
        }
        else if(t==4)cout<<sum;
        else if(t==5)cout<<even;
        else if(t==6)cout<<text;
        else{
            int i = 0;
            bool v[n];
            memset(v, 0, sizeof v);
            while(1){
                i = arr[i];
                if(i>=n){cout<<"Out"; break;}
                else if(i==n-1){cout<<"Done"; break;}
                else{
                    if(v[i]){cout<<"Cyclic"; break;}
                    v[i]=1;
                }
            }
        }
    }
    return 0;
}