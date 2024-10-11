#include <iostream>

using namespace std;

int cont=1;
void recursive(){
    if(cont%1000 == 0)
        printf("%d ",cont);
    
    cont ++;
    recursive();
}

int main(){

    recursive();

    return 0;
}