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
    string S;
    cin >> S;

    int N = S.size();
    vector<int> count(N,0);
    string CH = "chokudai";

    for(int i=0; i<N; i++){
        if(S[i]=='i') count[i] = 1;
    }

    for(int i=6; i>=0; i--){
        char t = CH[i];
        int num = 0;
        for(int j=N-1; j>=0; j--){
            if(S[j] == CH[i+1]){
                num+=count[j];
                num %= MOD;
            }
            if(S[j] == CH[i]){
                count[j] = num;
            }
        }
    }

    ll ans = 0;

    for(int i=0; i<N; i++){
        if(S[i]=='c'){
            ans += count[i];
            ans %= MOD;
        }
    }

    cout << ans << endl;


}
