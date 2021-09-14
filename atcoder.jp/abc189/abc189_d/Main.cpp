#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;

    ll ans = pow(2,N);

    ll give_one  = pow(2,N);
    ll give_zero = pow(2,N);

    for(int i=0; i<N; i++){
        string L;
        cin >> L;
        ll giveone = give_one;
        ll givezero = give_zero;
        if(L == "AND"){
            give_one = giveone/2;
            give_zero = giveone/2 + givezero;
        }else{
            give_one = giveone + givezero/2;
            give_zero = givezero/2;
        }
    }

    cout << give_one << endl;
}
