#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N,M;
    cin >> N >> M;

    vector<ll> space;
    vector<ll> A(M+1);
    for(ll i=0; i<M; i++){
        ll a;
        cin >> a;
        //cout << a << endl;
        A.at(i) = a;
    }
    A.at(M) = N+1;
    sort(A.begin(),A.end());
    /*
    //cout << "A:";
    for(ll i=0; i<M; i++){
        cout << " " << A.at(i);
    }
    //cout << endl;
    */

    int x=0;
    //cout << "space:"; 
    for(ll i=0; i<M+1; i++){
        ll s = A.at(i) - x -1;
        space.push_back(s);
        x = A.at(i);
    }
    //cout << endl;

    ll s_min=1000000003;
    for(ll ss: space){
        if(ss==0) continue;
        s_min = min(s_min,ss);
    }
    //cout << "s_min " << s_min << endl;

    ll ans=0;
    for(ll ss: space){
        if( ss%s_min == 0){
            ans += ss/s_min;
        }else{
            ans += ss/s_min + 1;
        }
    }

    cout << ans << endl;

}
