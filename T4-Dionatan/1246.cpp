#include <iostream>
#include <vector>

using namespace std;

void showOutput(int number){
    cout << number << endl;
}

int main(){

    int parkingLength, events, placa, vehicleLenght, proximo;
    char status;

    while(cin >> parkingLength >> events){

        vector<int> estacionamento(parkingLength, -1);
        int faturamento = 0;

        for(int i=0;i<events;i++){

            cin >> status >> placa;

            if (status == 'C') {

                cin >> vehicleLenght;

                int cont =0, i;
                for(i=0;i<estacionamento.size();i++){
                    if(estacionamento[i]==-1){
                        cont++;
                        if(cont==vehicleLenght){
                            break;
                        }
                    }else{
                        cont=0;
                    }
                }

                if(i!=estacionamento.size()){
                    faturamento += 10;
                    for(int j=0;j<vehicleLenght;j++){
                        estacionamento[j+i-cont+1] = placa;
                    }
                }
            }else{
                for(int i=0;i<estacionamento.size();i++){
                    if(estacionamento[i]==placa){
                        estacionamento[i] = -1;
                    }
                }
            }
        }
        cout << faturamento << endl; 
    }
    return 0;
}