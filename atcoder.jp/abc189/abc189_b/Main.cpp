#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N,X;
    cin >> N >> X;
    vector<ll> Al(N);
    ll put=0;
    for(int i=0; i<N; i++){
        ll v,p;
        cin >> v >> p;
        put += v*p;
        if(X*100<put){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
