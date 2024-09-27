#include <iostream>
#include <cmath>

using namespace std;

void showOutput(string line, int number){
    cout << line << endl << number << endl;
}

int main(){
    int number;
    string line;

    cin >> line >> number;

    if(number < 1 || number > line.length() || (line.length()<1) || line.length()> pow(10,5))
        return 0;

    //TODO: process();

    showOutput(line,number);

    return 0;
}