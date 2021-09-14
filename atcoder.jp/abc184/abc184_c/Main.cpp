#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf

int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    if(a==c && b==d){
        cout << 0 << endl;
    }else if(a+b == c+d || a-b == c-d || abs(a-c) + abs(b-d) <= 3){
        cout << 1 << endl;
    }else if( abs(a-c) + abs(b-d) <= 6 || (a+b+c+d)%2==0 || abs(a+b-c-d)<=3 || abs(a-b-c+d)<=3 ){
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
    }
}
