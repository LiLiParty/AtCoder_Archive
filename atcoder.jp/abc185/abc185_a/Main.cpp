#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    int min_1 = min(A,B);
    int min_2 = min(C,D);
    cout << min(min_1,min_2) << endl;
}
