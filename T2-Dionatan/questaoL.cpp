#include <iostream>
#include <cmath>

using namespace std;

void showOutput(string line){
    cout << line << endl;
}

string lexicographical(string line, int k){
    char aux;
    bool swapped;

    do {
        swapped = false;
        for (int i=0;i<line.length()-k;i++) {
            if (line[i + k] < line[i]) {
                aux = line[i];
                line[i] = line[i+k];
                line[i+k] = aux;
                swapped = true;
            }
        }
    } while (swapped);

    return line;
}   

int main(){
    int number;
    string line;

    cin >> line >> number;

    if(number < 1 || number > line.length() || (line.length()<1) || line.length()> pow(10,5))
        return 0;

    line = lexicographical(line,number);
    showOutput(line);

    return 0;
}