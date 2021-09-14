#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;
    ll ans=0;
    for(int n=1; n<=N; n++){
        ll N_t = n;
        ll N_e = n;
        bool flag = true;
        while( N_t != 0){
            if(N_t%10 == 7){
                flag = false;
                break;
            }else{
                N_t -= N_t%10;
                N_t /= 10;
            } 
        }
        while( N_e != 0){
            if(N_e%8 == 7){
                flag = false;
                break;;
            }else{
                N_e -= N_e%8;
                N_e /= 8;
            } 
        }
        if(flag) ans++;
    }

    cout << ans << endl;
}
