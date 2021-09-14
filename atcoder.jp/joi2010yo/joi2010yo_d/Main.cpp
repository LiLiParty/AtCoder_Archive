#include <bits/stdc++.h>
using namespace std;

/* next combination */
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}


int main() {
    int N,K;
    cin >> N >> K;

    vector<int> Card(N);
    for(int i=0; i<N; i++){
        cin >> Card.at(i);
    }

    vector<int> Card_num_list;
    int ans=0;

    int bit = (1<<K)-1;  // bit = {0, 1, 2}
    for (;bit < (1<<N); bit = next_combination(bit)) {//大きさK部分集合
        vector<int> S;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { 
                S.push_back(i);//選んだK枚のカード
            }
        }

        do{
            int Card_num=0;
            int up=0;
            for(int i=0; i<K; i++){
                Card_num += Card.at(S.at(i)) * pow(10, i+up);
                if(Card.at(S.at(i))>=10) up++;
            }
            bool flag=true;
            for(int i=0; i<Card_num_list.size(); i++){
                if( Card_num == Card_num_list.at(i) ) flag=false;
            }

            if(flag){
                Card_num_list.push_back(Card_num);
                ans ++;
            }

        }while(next_permutation(S.begin(),S.end()));

    }

    cout << ans << endl;

}

