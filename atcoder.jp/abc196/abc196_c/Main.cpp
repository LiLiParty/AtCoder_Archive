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
    ll N;
    cin >> N;
    ll digit = dig(N);

    if( digit%2 == 1){
        ll n=digit/2;
        ll ans=0;
        for(int i=0; i<n; i++){
            ans += 9*pow(10,i);
        }
        cout << ans << endl;
        return 0;
    }


    ll n=digit/2-1;
    ll ans=0;
    for(int i=0; i<n; i++){
        ans += 9*pow(10,i);
    }
    ll i = digit/2;
    ll first = N/pow(10,i);
    ll second = N-first*pow(10,i);
    //cout << second << endl;
    ll first_d = first - pow(10,(i-1));
    //cout << first_d << endl;
    ll second_d = second - pow(10,(i-1));
    //cout << second_d << endl;
    if(first_d <= second_d){
        ans += first_d + 1;
    }else{
        ans += first_d;
    }
    cout << ans << endl;

}
