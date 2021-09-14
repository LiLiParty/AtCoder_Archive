#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N,C;
    cin >> N >> C; //サービス数,プライム価格
    vector<pair<ll,ll>> day_price;

    for(ll i=0; i<N; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        day_price.push_back( make_pair(a-1,c) );
        day_price.push_back( make_pair(b,-1*c) );
    }
    sort(day_price.begin(),day_price.end());
    ll ans=0;
    ll price_now=0;
    ll day_now=0;

    for( auto [d,p]: day_price){
        if(day_now != d){
            ans += min(price_now,C) * (d-day_now);
            day_now = d;
        }
        price_now += p;
    }

    cout << ans << endl;

}
