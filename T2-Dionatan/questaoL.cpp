#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int number;
    string line;

    cin >> line >> number;

    if(number < 1 || number > line.length() || (line.length()<1) || line.length()> pow(10,5))
        return 0;

    cout << line << endl << number << endl;

    return 0;
}