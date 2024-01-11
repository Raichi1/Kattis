#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char x,y;
int rx,ry;

bool valid(int cx, int cy){ return cx>0&&cx<=8&&cy>0&&cy<=8; }

bool isSame(){
    int cx = x-'A', cy = y-'A';
    if((cx&1 && rx&1) || (cx%2==0 && rx%2==0)){
        if((cy&1 && ry&1 )|| (ry%2==0 && cy%2==0))return 1;
    }
    if((cx&1 && rx%2==0) || (cx%2==0 && rx&1)){
        if((cy&1 && ry%2==0 )|| (ry&1 && cy%2==0))return 1;
    }
    return 0;
}

void solve(){
    cin>>x>>rx>>y>>ry;
    queue<pair<char,int>> que;
    if(isSame()){
        if(x!=y || rx!=ry){
            if(abs(x-y)==abs(rx-ry))cout<<1<<' '<<x<<' '<<rx<<' '<<y<<' '<<ry;
            else{
                int sx = x-'A'+1, ey = y-'A'+1; 
                que.push({x,rx});
                int ax = sx+1, axr = rx+1;
                while(valid(ax,axr) && que.size()<3){
                    if(abs(ey-ax)==abs(ry-axr)){
                        que.push({ax-1+'A', axr});
                        que.push({y, ry});
                    }
                    ax++,axr++;
                }
                ax = sx-1, axr = rx-1;
                while(valid(ax,axr) && que.size()<3){
                    if(abs(ey-ax)==abs(ry-axr)){
                        que.push({ax-1+'A', axr});
                        que.push({y, ry});
                    }
                    ax--,axr--;
                }
                ax = sx+1, axr = rx-1;
                while(valid(ax,axr) && que.size()<3){
                    if(abs(ey-ax)==abs(ry-axr)){
                        que.push({ax-1+'A', axr});
                        que.push({y, ry});
                    }
                    ax++,axr--;
                }
                ax = sx-1, axr = rx+1;
                while(valid(ax,axr) && que.size()<3){
                    if(abs(ey-ax)==abs(ry-axr)){
                        que.push({ax-1+'A', axr});
                        que.push({y, ry});
                    }
                    ax--,axr++;
                }
                cout<<2;
                while(!que.empty()){
                    cout<<' '<<que.front().f<<' '<<que.front().s;
                    que.pop();
                }
            }
        }
        else cout<<0<<' '<<x<<' '<<rx;
    }else cout<<"Impossible";
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
