#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> K(32);
    K.at(0)=1;
    K.at(1)=1;
    K.at(2)=1;
    K.at(3)=2;
    K.at(4)=1;
    K.at(5)=2;
    K.at(6)=1;
    K.at(7)=5;
    K.at(8)=2;
    K.at(9)=2;
    K.at(10)=1;
    K.at(11)=5;
    K.at(12)=1;
    K.at(13)=2;
    K.at(14)=1;
    K.at(15)=14;
    K.at(16)=1;
    K.at(17)=5;
    K.at(18)=1;
    K.at(19)=5;
    K.at(20)=2;
    K.at(21)=2;
    K.at(22)=1;
    K.at(23)=15;
    K.at(24)=2;
    K.at(25)=2;
    K.at(26)=5;
    K.at(27)=4;
    K.at(28)=1;
    K.at(29)=4;
    K.at(30)=1;
    K.at(31)=51;
    int A;
    cin >> A;
    cout << K.at(A-1);
}

