#include <bits/stdc++.h>
using namespace std;

int main(){
    int s,s1,s2,s3;
    cin >> s;
    s1 = s/100;
    s -= s1*100;
    s2 = s/10;
    s -= s2*10;
    s3 = s;
    cout << s1+s2+s3 << endl;
}
