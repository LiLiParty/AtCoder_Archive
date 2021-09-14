#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807

int main() {
    int N,X;
    cin >> N >> X;
    vector<int> n;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(a!=X) n.push_back(a);
    }
    for(auto i: n){
        cout << i << " ";
    }
}