#include <iostream>
#include <iomanip>

using namespace std;

void showCash(int amount, double valueCash, string message){
    cout<<amount<<" "<<message<<"(s) de R$ " << fixed << setprecision(2) << valueCash << endl;
}

double conditionalsNotes(double valueDouble, int valueNote){
    int cont = 0;
    while(valueDouble-valueNote >=0){
        valueDouble -= valueNote;
        cont++;
    }
    showCash(cont,valueNote,"nota");
    return valueDouble;
}

double conditionalsCoins(double valueDouble, double ValueCoin){
    double cont = 0;
    double tolerancia = 0.0001;
    while(valueDouble-ValueCoin >= 0 - tolerancia){
        valueDouble -= ValueCoin;
        cont++;
    }
    showCash(cont,ValueCoin,"moeda");
    return valueDouble;
}

double calculateNumberMinimumNotes(double valueDouble){
    valueDouble = conditionalsNotes(valueDouble,100);
    valueDouble = conditionalsNotes(valueDouble,50);
    valueDouble = conditionalsNotes(valueDouble,20);
    valueDouble = conditionalsNotes(valueDouble,10);
    valueDouble = conditionalsNotes(valueDouble,5);
    valueDouble = conditionalsNotes(valueDouble,2);
    return valueDouble;
}

void calculateNumberMinimumCoin(double valueDouble){
    valueDouble = conditionalsCoins(valueDouble,1.00);
    valueDouble = conditionalsCoins(valueDouble,0.50);
    valueDouble = conditionalsCoins(valueDouble,0.25);
    valueDouble = conditionalsCoins(valueDouble,0.10);
    valueDouble = conditionalsCoins(valueDouble,0.05);
    valueDouble = conditionalsCoins(valueDouble,0.01);
}

int main(){
    double valueDouble;

    cin >> valueDouble;
    //scanf(" %lf", &valueDouble);

    if(valueDouble < 0 || valueDouble > 1000000.00) 
        return 0;

    cout << "NOTAS:" << endl;
    double rest = calculateNumberMinimumNotes(valueDouble);
    cout << "MOEDAS:" << endl;
    calculateNumberMinimumCoin(rest);

    return 0;
}