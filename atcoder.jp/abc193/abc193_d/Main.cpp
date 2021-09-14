#include <bits/stdc++.h>
using namespace std;

int score(vector<int> S,int card_ura){
    vector<int> c(10,0);
    for(int i=0; i<4; i++){
        c.at(S.at(i))++;
    }
    c.at(card_ura)++;
    int sco=0;
    for(int i=1; i<=9; i++){
        sco += i*pow(10,c.at(i));
    }
    return sco;
}

int main() {
    double K;
    cin >> K;
    vector<double> Card(10,K);//Card.at(i)=K枚 数iはK枚ある。

    string s,t;
    cin >> s >> t;

    vector<int> S(4);
    vector<int> T(4);
    for(int i=0; i<4; i++){
        S.at(i) = s.at(i) - '0';
        T.at(i) = t.at(i) - '0';
        Card.at(S.at(i)) -= 1.;
        Card.at(T.at(i)) -= 1.;
    }

    double ans=0;

    for(int i=1; i<=9; i++){ //高橋君がひくカード
        if(Card.at(i)==0) continue;
        double pro = Card.at(i) / (double)(9*K-8);
        Card.at(i)--;
        for(int j=1; j<=9; j++){ //青木君がひくカード
            if(Card.at(j)==0) continue;
            if(score(S,i) <= score(T,j)) continue;
            ans += pro * Card.at(j) / (double)(9*K-9);
        }
        Card.at(i)++;
    }

    printf("%lf",ans);
}