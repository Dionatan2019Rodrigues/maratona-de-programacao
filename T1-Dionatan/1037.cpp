#include <iostream>

using namespace std; 

void showInterval(int start, int end, string situacao){
    cout<<"Intervalo "<<situacao<<start<<","<<end<<"]"<<endl;
}

void searchInterval(double value){
    if(value >= 0 && value <= 25.0000)
        showInterval(0,25,"[");
    else if(value > 25.0000 && value <= 50.0000000)
        showInterval(25,50,"(");
    else if(value > 50.0000000 && value <= 75.000000000)
        showInterval(50,75,"(");
    else if(value > 75.000000000 && value <= 100.00000000000)
        showInterval(75,100,"(");
}

int main(){

    double valueInput;

    cin >> valueInput;
    //scanf(" %lf", &valueInput);

    if(valueInput < 0 || valueInput > 100.00000000000)
        cout << "Fora de intervalo" << endl;

    searchInterval(valueInput);

    return 0;
}