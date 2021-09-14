#include <bits/stdc++.h>
using namespace std;



int main() {
    int N;
    cin >> N;

    vector<int> box_top;
    int w_1;
    cin >> w_1;
    box_top.push_back(w_1);
    int ans=1;

    for(int i=1; i<N; i++){
        int w;
        cin >> w;
        vector< pair<int,int> > can_load; //pair(重さ、番号)
        //載せられる場所とその重さを調べる
        for(int k=0; k < box_top.size(); k++){
            if(box_top.at(k) >= w){
                can_load.push_back( make_pair(box_top.at(k),k) );
            }
        }
        if(can_load.size()==0){
            ans++;
            box_top.push_back(w);
            continue;
        }
        //載せられる場所の中で一番軽い場所を調べる
        int box_light=1000000;
        int box_light_num;
        for(int k=0; k < can_load.size(); k++){
            box_light = min(can_load.at(k).first , box_light);

            if(box_light == can_load.at(k).first){
                box_light_num = can_load.at(k).second;
            }

        }
        box_top.at(box_light_num) = w;
    }

    cout << ans << endl;
}

