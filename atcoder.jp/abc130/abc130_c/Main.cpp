#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main(){
    ld H,W;
    cin >> H >> W;
    if(H<0) H*(-1);
    ll x,y;
    cin >> x >> y;
    printf("%lf %d\n", double(H)*double(W) / 2, x + x == H&&y + y == W);
}