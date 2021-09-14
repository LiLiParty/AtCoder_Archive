#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;
    ll man=0;
    ll Euc_sum=0;
    ll che=0;
    
    for(int i=0; i<N; i++){
        ll x;
        cin >> x;
        x = abs(x);
        man += x;
        Euc_sum += pow(x,2);
        che = max(che,x);
    }

    double Euc = sqrt( (double)Euc_sum);

    cout << man << endl;
    printf("%.11lf\n",Euc);
    cout << che << endl;

}
