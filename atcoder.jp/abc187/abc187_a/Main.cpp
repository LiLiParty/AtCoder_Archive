#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    string a,b;
    cin >> a >> b;
    int A=0;
    int B=0;
    for(int i=0; i<3; i++){
        A += a.at(i)-'0';
        B += b.at(i)-'0';
    }
    if(A>=B){
        cout << A << endl;
    }else{
        cout << B << endl;
    }
}
