#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7

ll dig(ll a){
    ll re=0;
    while(a != 0){
        a/=10;
        re++;
    }
    return re;
}

int main(){
    ll A,B,X;
    cin >> A >> B >> X;

    ll ans = -1;
    //bool flag=false;
    for(ll d=1; d<=10; d++){
        if( X - B*d <= 0 ){
            break;
        }
        ll N = (X - B*d)/A;
        //cout << dig(N) << " " << d << endl;
        if(dig(N) <= d){
            ans = max(ans,N);
        }
    }

    if(A+B>X){
        cout << 0 << endl;
    }else if(A*1000000000+B*10 <= X){
        cout << 1000000000 << endl;
    }else{
        cout << ans << endl;
    }

}
