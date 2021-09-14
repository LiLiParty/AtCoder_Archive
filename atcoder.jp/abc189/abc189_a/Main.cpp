#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    char A,B,C;
    cin >> A >> B >> C;
    if(A==B and B==C and C==A){
        cout << "Won" << endl;
    }else{
        cout << "Lost"  << endl;
    }
}
