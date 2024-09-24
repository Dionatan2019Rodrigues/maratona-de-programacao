#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void showMediumDistance(double value){
    cout << fixed << setprecision(1) << value << endl;
}
double calculateMediumDistance(double sum_distance, int amount){
    return sum_distance/amount;
}

int main(){

    string s;
    //char s[100];
    int num_friends=0, distance , sum_distance = 0 ;

    //while(scanf("%s", s) == 1){}
    while(cin >> s){
        if(s[0] <= '9'){
            sum_distance += stoi(s);
            num_friends++;
        }
    }

    double medium = calculateMediumDistance(sum_distance,num_friends);
    showMediumDistance(medium);

    return 0;
}