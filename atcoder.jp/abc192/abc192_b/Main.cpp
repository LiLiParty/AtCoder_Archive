#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    bool flag = true;
    for(int i=0; i<S.size(); i++){
        if(i%2==0){//奇数番目
            if(S.at(i)>='a' && S.at(i)<='z'){
            }else{
                flag = false;
            }
        }else{
            if(S.at(i)>='A' && S.at(i)<='Z'){
            }else{
                flag = false;
            }
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}