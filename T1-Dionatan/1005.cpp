#include <iostream>
#include <iomanip>

using namespace std;

double calculateAverage(double a, double b){
    return ((3.5*a)+(7.5*b))/11;
}

int main(){

    double a,b;

    cin >> a >> b;
    //scanf(" %lf %lf",&a, &b);

    double average = calculateAverage(a,b);

    cout << "MEDIA = " << fixed << setprecision(5) << average << endl;

    return 0;
}