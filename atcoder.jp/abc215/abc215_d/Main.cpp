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

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back(mk(a, ex));
    }
    // 最後に残った数について
    if (N != 1) res.push_back(mk(N, 1));
    return res;
}

int main() {
    int N,M;
    cin >> N >> M;

    vector<ll> ans(M+1,1);

    set<ll> prime_set;
    for(int i=0; i<N; i++){
        int A;
        cin >> A;
        vector<pp> p_list = prime_factorize(A);
        for(pp p: p_list){
            prime_set.insert(p.first);
        }
    }

    for(auto p: prime_set){
        int prime = p;
        for(int i=1; i<=M/p; i++){
            ans[p*i] = -1;
        }
    }

    vector<int> ANS;
    
    for(int i=1; i<=M; i++){
        if(ans[i]==1){
            ANS.push_back(i);
        }
    }
    cout << ANS.size() << endl;
    for(int i: ANS){
        cout << i << endl;
    }
}
