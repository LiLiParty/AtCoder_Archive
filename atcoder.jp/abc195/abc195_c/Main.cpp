#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;

    int i=0;
    while(true){
        if( pow(10,i) <= N  && pow(10,(i+3) )-1 >= N ) break;
        i+=3;
    }

    ll ans = 0;

    for(int k=0; k<=i-3; k+=3){
        ans += (k/3) * ( pow( 10, (k+3)) - pow(10,k) );
    }

    ans += (i/3) * (N-pow(10,i)+1);

    cout << ans << endl;


}
