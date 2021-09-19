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
    vector<char> abc;
    for(int i=0; i<26; i++){
        abc.push_back('a' + i);
    }
    int N,K; cin >> N >> K;
    string S; cin >> S;

    string ans;
    int left = 0,right = N-K;
    for(int i=0; i<K; i++){
        bool flag = false;
        for(char a: abc){
            for(int j=left; j<=right; j++){
                if(S[j] == a){
                    ans.push_back(a);
                    left = j+1;
                    right++;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
    }

    cout << ans << endl;
}
