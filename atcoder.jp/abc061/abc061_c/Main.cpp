#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9+7




int main(){
    ll N,K;
    cin >> N >> K;

    vector< pair<ll,ll> > A(N);
    for(ll i=0; i<N; i++){
        ll a,b;
        cin >> a >> b;
        A.at(i) = make_pair(a,b);
    }
    sort(A.begin(),A.end());

    ll count = 0;
    for(ll i=0; i<N; i++){
        count += A.at(i).second;
        if(K<=count){
            cout << A.at(i).first << endl;
            return 0;
        }
    }
}