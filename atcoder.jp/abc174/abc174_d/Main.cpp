#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    ll N;
    cin >> N;
    string c;
    cin >> c;

    ll R=0;
    for(int i=0; i<N; i++){
        if(c.at(i)=='R'){
            R++;
        }
    }
    
    if(R==0 || R==N){
        cout << 0 << endl;
        return 0;
    }

    ll ans=0;
    for(int i=0; i<=R-1; i++){
        if(c.at(i)=='W'){
            ans++;
        }
    }

    cout << ans << endl;



}
