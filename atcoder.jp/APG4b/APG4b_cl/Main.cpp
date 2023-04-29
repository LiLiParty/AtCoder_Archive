#include <iostream>
using namespace std;
int main(void){
    int N, A;
    cin >> N >> A;
    for(int i=0; i<N; i++){
        char o;
        int B;
        cin >> o >> B;
        if(o=='+'){
            A += B;
            cout << i+1 << ":" << A << endl;
        }else if(o=='-'){
            A -= B;
            cout << i+1 << ":" << A << endl;
        }else if(o=='*'){
            A *= B;
            cout << i+1 << ":" << A << endl;
        }else if(o=='/'){
            if(B==0){
                cout << "error" << endl;
                break;
            }
            A /= B;
            cout << i+1 << ":" << A << endl;

        }
        
    }
}
