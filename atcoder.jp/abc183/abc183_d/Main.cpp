#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N,W;
    cin >> N >> W;

    vector< pair<ll,ll> > water;
    for(int i=0; i<N; i++){
        ll S,T,P;
        cin >> S >> T >> P;
        water.push_back( make_pair(S,P) );
        water.push_back( make_pair(T,-1*P) );
    }
    sort( water.begin(), water.end());

    ll nec=0;
    for(auto [t,p]: water){
        nec += p;
        if(nec > W){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
