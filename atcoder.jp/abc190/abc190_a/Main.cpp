#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    if(A>B){
        cout << "Takahashi" << endl;
    }else if(A<B){
        cout << "Aoki" << endl;
    }else if(C == 0){
        cout << "Aoki" << endl;
    }else{
        cout << "Takahashi" << endl;
    }
}