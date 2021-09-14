#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for( int i=0; i<N; i++ ){
        cin >> A.at(i);
    }

    int num=0;
    int ans;
    for( int k=2; k<=1000; k++){
        int count=0;
        for(auto a: A){
            if(a%k==0) count++;
        }
        num = max(num,count);
        if(num==count){
            ans = k;
        }
    }

    cout << ans << endl;


}
