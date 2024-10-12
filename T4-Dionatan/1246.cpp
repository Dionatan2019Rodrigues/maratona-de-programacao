#include <iostream>

using namespace std;

void showOutput(int number){
    cout << number << endl;
}

int main(){

    int parkingLength, events, placa, vehicleLenght;
    string status;

    cin >> parkingLength >> events;
    if(parkingLength<1 || parkingLength>1000 || events<1 || events>1000)
        return 0;

    for(int i=0;i<events;i++){
        cin >> status >> placa;
        if(placa<1000 || placa>9999)
            return 0;
        if(status == "C"){
            cin >> vehicleLenght;
            if(vehicleLenght<1 || vehicleLenght>1000)
                return 0;
        }

    }


    return 0;
}