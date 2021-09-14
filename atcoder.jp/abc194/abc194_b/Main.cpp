#include <bits/stdc++.h>
using namespace std;



int main() {
    int N;
    cin >> N;
    vector< pair<int,int> > EA(N); //かかる時間,従業員番号
    vector< pair<int,int> > EB(N);
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        EA.at(i) = make_pair(a,i);
        EB.at(i) = make_pair(b,i);
    }

    sort(EA.begin(),EA.end());
    sort(EB.begin(),EB.end());

    if(EA.at(0).second != EB.at(0).second){ //A,Bで一番が違う人
        cout << max(EA.at(0).first,EB.at(0).first) << endl;
    }else{
        int only = EA.at(0).first + EB.at(0).first;
        int twoA = max(EA.at(1).first,EB.at(0).first);
        int twoB = max(EA.at(0).first, EB.at(1).first);
        int two = min(twoA,twoB);
        cout << min(only,two) << endl;
    }
}

