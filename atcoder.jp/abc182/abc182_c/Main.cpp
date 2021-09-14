#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;

    ll k=0;
    vector<ll> num;
    while(N !=0){
        k++;
        num.push_back( N%10 );
        N -= N%10;
        N /= 10;
    }

    ll ans = 0;
    for(ll bit=0; bit < (1<<k); bit++){
        ll flag=0;
        ll sum=0;
        for(int i=0; i<k; i++){
            if( bit & (1<<i)){
                sum += num.at(i);
                flag++;
            }
        }
        if( sum%3 == 0){
            ans = max(ans,flag);
        }
    }
    if(ans == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << k-ans << endl;
}
