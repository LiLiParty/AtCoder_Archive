#include <bits/stdc++.h>
using namespace std;

int compare(vector<char> s, vector<char> t){
    int ans=0;
    for(int i='a'; i<='z'; i++){
        int s_num=0;
        int t_num=0;
        for(int k=0; k<t.size(); k++){
            if(s.at(s.size()-k-1)==i) s_num++;
            if(t.at(k)==i) t_num++;
        }
        ans += min(s_num,t_num);
    }
    return t.size()-ans;
}

int main() {

    int N,K;
    string S;
    cin >> N >> K;
    cin >> S;
    string T="";

    vector<char> S_vector(N);
    vector<char> S_sort(N);
    for(int i=0; i<N; i++){
        S_vector.at(i) = S.at(i);
        S_sort.at(i) = S.at(i);
    }
    sort(S_sort.begin(),S_sort.end());

    int used=0;
    int a;
    for(int i=0; i<N; i++){
        for(int k=0; k<S_sort.size(); k++){
            if(S_vector.at(i)==S_sort.at(k)){
                a = 0;
            }else{
                a = 1;
            }
            vector<char> S_sort_copy = S_sort;
            S_sort_copy.erase(S_sort_copy.begin()+k);
            if(K >= used + a + compare(S_vector,S_sort_copy) ){
                T += S_sort.at(k);
                used += a;
                S_sort.erase(S_sort.begin()+k);
                break;
            }
        }

    }

    cout <<  T << endl;
    

}

