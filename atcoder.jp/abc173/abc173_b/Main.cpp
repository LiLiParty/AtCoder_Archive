#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    int N;
    cin >> N;
    int A=0;
    int W=0;
    int T=0;
    int R=0;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        if(s=="AC") A++;
        if(s=="WA") W++;
        if(s=="TLE") T++;
        if(s=="RE") R++;
    }

    cout << "AC" << " x " << A << endl;
    cout << "WA" << " x " << W << endl;
    cout << "TLE" << " x " << T << endl;
    cout << "RE" << " x " << R << endl;
}
