#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1000000007;

int main(){
    int A,B;
    cin >> A >> B;
    if((A%2==1 and B%2==1)or(B%2==0 and A%2==0)){
        cout << (A+B)/2;
    }else{
        cout << "IMPOSSIBLE";
    }

}