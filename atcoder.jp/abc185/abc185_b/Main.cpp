#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N,M,T;
    cin >> N >> M >> T;
    //容量、カフェ回、帰宅時刻

    ll t=0;
    ll C=N;
    bool flag=true;
    for(ll i=0; i<M; i++){
        ll a,b;
        cin >> a >> b;
        N -= (a-t);
        if(N<=0) flag=false;
        N += (b-a);
        if( N > C ) N=C;
        t = b;
    }
    N -= (T-t);
    if(N<=0) flag=false;

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}
