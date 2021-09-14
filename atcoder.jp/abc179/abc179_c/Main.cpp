#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;
    
    ll ans=0;
    for(ll A=1; A<N; A++){
        if(N%A==0){
            ans += N/A-1;
        }else{
            ans += N/A;
        }
    }

    cout << ans << endl;
}
