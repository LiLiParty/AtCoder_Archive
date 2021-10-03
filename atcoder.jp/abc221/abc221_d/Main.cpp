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
    map<int,int> P;
    for(int i=0; i<N; i++){
        int A,B; cin >> A >> B;
        P[A]++;
        P[A+B]--;
    }
    //cout << endl;
    vector<int> Ans(N+1,0);

    int before_p = 0;
    int before_d = 0;
    for(pp p: P){
        //cout << p.first << " " << p.second << " " << before_p <<endl;
        Ans[before_p] += p.first - before_d; 
        int change = p.second;
        before_p += change;
        before_d = p.first;
    }

    for(int i=1; i<=N; i++){
        cout << Ans[i] << " ";
    }
}
