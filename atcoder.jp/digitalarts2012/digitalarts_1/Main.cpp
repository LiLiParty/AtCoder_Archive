#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pp pair<ll,ll>
#define ll long long
#define ld long double
#define mk make_pair
#define INF32 2147483647 
#define INF64 9223372036854775807
#define rep(i, n) for(int i = 0; i < n; i++)
const ll MOD = 1000000007;//10^9+7
//const ll mod = 998244353;



int main() {
    vector<string> S;
    int N;
    while(1){
        string s;
        cin >> s;
        if('0' <= s[0] && '9'>=s[0]){
            N = stoi(s);
            break;
        }else{
            S.push_back(s);
        }
    }
    vector<string> T(N);
    for(int i=0; i<N; i++) cin >> T[i];
    for(int i=0; i<N; i++){
        for(int k=0; k<S.size(); k++){
            if(S[k].size() == T[i].size()){
                bool flag = true;
                
                for(int j=0; j<S[k].size(); j++){
                    if(S[k][j] != T[i][j] && T[i][j]!='*'){
                        flag = false;
                        break;
                    }
                }
                
                if(flag){
                    for(int j=0; j<S[k].size(); j++){
                        S[k][j] = '*';
                    }
                }
            }
        }
    }

    for(auto s: S){
        cout << s << " ";
    }
}
