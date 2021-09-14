#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    double A,B,W;
    cin >> A >> B >> W;
    W *= 1000.;

    int min = ceil(W/B);
    int max = floor(W/A);

    if( min > max){
        cout << "UNSATISFIABLE" << endl;
    }else{
        cout << min << " " << max << endl;
    }



}
