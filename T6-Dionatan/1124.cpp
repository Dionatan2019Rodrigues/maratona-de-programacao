#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int L, C, R1, R2;
    double distanciaCentros;

    while(cin>>L>>C>>R1>>R2){
        if(L==0&&C==0&R1==0&&R2==0)
            continue;

        if (2 * R1 > L || 2 * R1 > C || 2 * R2 > L || 2 * R2 > C) {
            cout << "N" << endl;
            continue;
        }

        distanciaCentros = sqrt(pow(L - R1 - R2, 2) + pow(C - R1 - R2, 2)); 

        if (distanciaCentros >= R1 + R2) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}