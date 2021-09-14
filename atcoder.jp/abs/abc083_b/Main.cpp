#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,a,b;
    cin >> N >> a >> b;
    int sum=0;

    for(int i=1; i<=N; i++){
        int s = i;
        int s1,s2,s3,s4,s5;
        s5 = s/10000;
        s -= s5*10000;
        s4 = s/1000;
        s -= s4*1000;
        s3 = s/100;
        s -= s3*100;
        s2 = s/10;
        s -= s2*10;
        s1 = s;

        if( s1+s2+s3+s4+s5 >= a && s1+s2+s3+s4+s5 <= b){
            sum += i;
        }
    }
    
    cout << sum << endl;
}
