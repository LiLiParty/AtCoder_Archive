#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    ll N,D;
    cin >> N >> D;
    D = D*D;
    ll ans=0;
    for(int i=0; i<N; i++){
        ll X,Y;
        cin >> X >> Y;
        if(D >= X*X+Y*Y){

            ans++;
        }
    }

    cout << ans << endl;
}
