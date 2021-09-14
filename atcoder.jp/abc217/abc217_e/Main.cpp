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
    int Q;
    cin >> Q;
    queue<int> que;
    priority_queue<int, vector<int>, greater<int>> pque;

    vector<int> ans;
    for(int i=0; i<Q; i++){
        int q; cin >> q;
        
        if(q == 1){
            int x; cin >> x;
            que.push(x);
        }else if(q == 2){
            if(pque.empty()){
                ans.push_back(que.front());
                que.pop();
            }else{
                ans.push_back(pque.top());
                pque.pop();
            }
        }else{
            while(!que.empty()){
                pque.push(que.front());
                que.pop();
            }
        }
    }

    for(auto a: ans){
        cout << a << endl;
    }
}