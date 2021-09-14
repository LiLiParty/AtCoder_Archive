#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;
    int ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        ans=ans+i+1;
    }
    cout << ans << endl;
}