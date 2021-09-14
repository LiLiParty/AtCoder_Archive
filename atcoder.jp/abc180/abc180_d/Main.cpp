#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll X,Y,A,B;
    cin >> X >> Y >> A >> B;
    ll ans=0;
    while( B >= X*(A-1) && X<Y ){
        if(X*A<0) break;
        if(X*(A-1)<0) break;
        X *= A;
        ans++;
    }
    if(X>=Y){
        X /= A;
        ans--;
    }
    
    ll a = Y-X;
    if(a%B==0){
        ans += a/B -1;
    }else{
        ans += a/B;
    }
    
    cout << ans << endl;
}
