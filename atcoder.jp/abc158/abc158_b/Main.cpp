#include <bits/stdc++.h>
using namespace std;


int main(){
    int64_t N,A,B;
    cin >> N >> A >> B;
    int64_t syou;
    int64_t amari;
    syou = N/(A+B);
    amari = int64_t(N%(A+B));
    if(A+B!=0){
    if(amari > A){
        cout << syou*A + A;
    }
    else{
        cout << syou*A + amari;
    }
    }
    else{
        cout << 0;
    }
}