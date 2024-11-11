#include <iostream>
#include <cmath>

using namespace std;

void out(bool possivel_alcancar){
    possivel_alcancar?cout << "S" << endl:cout << "N" << endl;
}

int main(){

    double D, VF, VG, DGC, TF, TGC;

    while(cin >> D >> VF >> VG){
        DGC = sqrt((D*D)+(144));

        TF = 12/VF;
        TGC = DGC/VG;

        if(TGC<=TF)
            out(true);
        else out(false);

    }

    return 0;
}