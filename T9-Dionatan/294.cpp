#include <iostream>
#include <cmath>

using namespace std;

int countDivisors(int number) {
  int divisorCount = 0;
  double aux = sqrt(number);

  for(int j=1;j<=aux;j++){
    if(number%j==0){
      divisorCount++;
      if(j<aux) divisorCount++;
    }    
  }
  return divisorCount;
}

int findMaxDivisors(int lowerLimit, int upperLimit) {
  int num = 0, numd = 0;
  double aux, cont;

  for(int i=lowerLimit;i<=upperLimit;i++){
    aux=pow(i,0.5);
    cont=0;
    
    for(int j=1;j<=aux;j++){
      if(i%j==0){
        cont++;
        if(j<aux) cont++;
      }   
    }
    if(cont>numd){
      numd=(int)cont;
      num=i;
    }
  }
  return num;
}

int main(){

  int cases;
  cin >> cases;

  while(cases--){

    int lowerLimit, upperLimit;
    cin>>lowerLimit>>upperLimit;

    int result = findMaxDivisors(lowerLimit, upperLimit);
    int divisors = countDivisors(result); 

    cout<<"Between "<<lowerLimit<<" and "<<upperLimit<<", "<<result<<" has a maximum of "<<divisors<<" divisors."<<endl;
  }
 return 0;
}
