#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int N = s.size();
    reverse(s.begin(),s.end());

    long long answer=0;

    for(int bit=0; bit<(1<<(N-1)); bit++){ //N-1ケタビット
        long long sum=0;
        long long bsum=0;
        sum += s.at(N-1) - '0';
        for(int i=N-2; i>=0; i--){
            if( bit & (1<<i) ){
                bsum += sum;
                sum = 0;
            }
            sum *= 10;
            sum += s.at(i) - '0';
        }
        bsum += sum;
        answer += bsum;
    }
    
    cout << answer << endl;
    
}
