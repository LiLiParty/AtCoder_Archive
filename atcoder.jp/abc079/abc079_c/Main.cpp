#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    reverse(s.begin(),s.end());


    for(int bit=0; bit<(1<<3); bit++){ //3ケタビット
        int sum=0;
        sum += s.at(3) - '0';
        //cout << s.at(3) - '0';
        for(int i=2; i>=0; i--){
            if(bit & (1<<i)){
                sum += s.at(i) - '0';
                //cout << "+" << s.at(i) - '0';
            }else{
                sum -= s.at(i) - '0';
                //cout << "-" << s.at(i) - '0';
            }
        }
        //cout << "=" << sum << endl;

        if(sum == 7){
            cout << s.at(3) - '0';
            for(int i=2; i>=0; i--){
                if(bit & (1<<i)){
                    //sum += s.at(i) - '0';
                    cout << "+" << s.at(i) - '0';
                }else{
                    //sum -= s.at(i) - '0';
                    cout << "-" << s.at(i) - '0';
                }
            }
            cout << "=" << sum << endl;
            return(0);
        }

    }
    
}
