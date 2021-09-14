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
const ll mod = 998244353;

int main() {
    int N; cin >> N;
    vector<int> iti(N+1,0);
    vector<int> ni(N+1,0);
    for(int i=1; i<=N; i++){
        int C,P; cin >> C >> P;
        if(C==1){
            iti[i] = P;
        }else{
            ni[i] = P;
        }
    }
    for(int i=1; i<=N; i++){
        iti[i] += iti[i-1];
        ni[i] += ni[i-1]; 
    }
    vector<pp> ans;
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int L,R; cin >> L >> R;
        int a = iti[R] - iti[L-1];
        int b = ni[R] - ni[L-1];
        ans.push_back(mk(a,b));
    }

    for(pp a: ans){
        cout << a.first << " " << a.second << endl;
    }

}
