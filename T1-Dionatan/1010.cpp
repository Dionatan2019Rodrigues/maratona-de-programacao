#include <iostream>
#include <iomanip>

using namespace std;

float calculateDebt(int numberPartOne, int numberPartTwo, float unitValueOne, float unitValueTwo){
    return (numberPartOne*unitValueOne)+(numberPartTwo*unitValueTwo);
}

int main(){

    int idPartOne, numberPartOne, idPartTwo, numberPartTwo;
    float unitValueOne, unitValueTwo;

    cin >> idPartOne >> numberPartOne >> unitValueOne;
    //scanf(" %d %d %f",&idPartOne, &numberPartOne, &unitValueOne);
    cin >> idPartTwo >> numberPartTwo >> unitValueTwo;
    //scanf(" %d %d %f",&idPartTwo, &numberPartTwo, &unitValueTwo);

    float valueDebt = calculateDebt(numberPartOne,numberPartTwo,unitValueOne,unitValueTwo);

    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << valueDebt << endl;

    return 0;
}