#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int L, C, R1, R2;
    double D, somaDiametros;

    while(cin>>L>>C>>R1>>R2){
        if(L==0&&C==0&R1==0&&R2==0)
            continue;

        D = sqrt((L*L)+(C*C));
        double D1 = R1*2;
        double D2 = R2*2;
        somaDiametros = D1+D2;
        double menorDimensao = (L<C)?L:C; 

        //TODO: make do the second elevator test case
        if(somaDiametros <= D){
            cout << "S" << endl;
        }else{
            cout << "N" << endl;
        }
    }

    return 0;
}