#include <bits/stdc++.h>
using namespace std;


int main(){
    string S;
    cin >> S;
    int front = (S.at(0)-'0')*10 + S.at(1)-'0';
    int back = (S.at(2)-'0')*10 + S.at(3)-'0';
    
    if((front >= 13 or front == 0) and (1 <= back and back <= 12)){
        cout << "YYMM";
    }else if((1 <= front and front <= 12) and (back >= 13 or back == 0)){
        cout << "MMYY";
    }else if((front >= 13 and back >= 13) or (front==0 and 13 <= back) or (back==0 and 13 <= front) or (back==0 and front == 0)){
        cout << "NA";
    }else{
        cout << "AMBIGUOUS";
    }
}

//いこーるはみぎ