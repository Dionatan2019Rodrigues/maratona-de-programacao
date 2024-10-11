#include <iostream>
#include <cmath>

using namespace std;

void giraAntiHorario(int* matrix,int len){
    int aux[len][len];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            //aux[j][len - i - 1] = *(matrix + i*len + j); sentido horário
            aux[len-j-1][i] = *(matrix + i*len + j);
        }
    }

    for (int i=0;i<len;i++) {
        for (int j=0;j<len;j++) {
            *(matrix + i*len + j) = aux[i][j];
        }
    }
}

bool validaOrdemCrescente(int* matrix, int len){
    //valida ordem das linhas
    for (int i=0;i<len;i++) {
        for (int j=1;j<len;j++) {
            if (*(matrix+ i*len +j) < *(matrix+ i*len +j-1)) {
                return false; 
            }
        }
    }
    //valida ordem das colunas
    for (int j=0;j<len;j++) {
        for (int i=1;i<len;i++) { 
            if (*(matrix+ i*len +j) < *(matrix+ (i-1)*len +j)) {
                return false;
            }
        }
    }

    return true;
}

int contRorations(int* matrix, int len){
    int n=0;

    while(!validaOrdemCrescente(matrix,len)){
        giraAntiHorario(matrix,len);
        n++;
    }

    return n;
}

void showOutput(int number){
    cout << number << endl;
}

int main(){
    int len, n;
    cin >> len;

    if(len < 2 || len > 50)
        return 0;

    int matrix[len][len];

    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cin >> matrix[i][j];
            if(matrix[i][j] < 0 || matrix[i][j] > pow(10,5))
                return 0;
        }
    }

    n = contRorations(&matrix[0][0],len);
    showOutput(n);

    return 0;
}