#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    ll K;
    cin >> K;
    vector<ll> a(K+2);
    a.at(1) = 7%K;

    for(int i=1; i<=K; i++){
        if(a.at(i)==0){
            cout << i << endl;
            return 0;
        }else{
            a.at(i+1) = (a.at(i)*10 + 7)%K;
        }
    }

    cout << -1 << endl;
}
