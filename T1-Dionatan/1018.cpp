#include <iostream>

using namespace std;

void showNotes(int numbersNote, int valueNote){
    cout << numbersNote << " nota(s) de R$ " << valueNote << ",00" << endl;
}

int conditionalsNotes(int valueInteger, int valueNote){
    int cont = 0;
    while(valueInteger-valueNote >=0){
        valueInteger -= valueNote;
        cont++;
    }
    showNotes(cont,valueNote);
    return valueInteger;
}

void calculateNumberMinimumNotes(int valueInteger){
    valueInteger = conditionalsNotes(valueInteger,100);
    valueInteger = conditionalsNotes(valueInteger,50);
    valueInteger = conditionalsNotes(valueInteger,20);
    valueInteger = conditionalsNotes(valueInteger,10);
    valueInteger = conditionalsNotes(valueInteger,5);
    valueInteger = conditionalsNotes(valueInteger,2);
    valueInteger = conditionalsNotes(valueInteger,1);
}

int main(){

    int valueInteger;

    cin >> valueInteger;
    //scanf(" %d", &valueInteger);

    if(valueInteger<=0 || valueInteger>=1000000)
        return 0;

    cout << valueInteger << endl;
    calculateNumberMinimumNotes(valueInteger);

    return 0;
}