#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7






int main(){
    string N;
    cin >> N;
    ll sum=0;
    for(int i=0; i<N.size(); i++){
        sum += N.at(i)-'0';
        sum%=9;
    }

    if(sum==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
