#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    int X,Y;
    cin >> X >> Y;
    if(X<Y && X+3>Y){
        cout << "Yes" << endl;
        return 0;
    }
    if(X>Y && X<Y+3){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
