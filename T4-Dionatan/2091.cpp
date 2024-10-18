#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

int main(){

    uint64_t N, A;

    while(true){
        cin >> N;
        if(N==0) break;
        unordered_map<uint64_t,bool> number;

        for(int i=0;i<N;i++){
            cin >> A;

            if(number.count(A)){
                number.erase(A);
            }else{
                number[A] = true;
            }
        }
        cout << number.begin()->first << endl;

    }

    return 0;
}