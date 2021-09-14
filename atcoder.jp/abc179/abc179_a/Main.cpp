#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    string s;
    cin >> s;

    if(s.back()== 's'){
        cout << s << "es" << endl;
    }else{
        cout << s << "s" << endl;
    }
}
