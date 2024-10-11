#include <iostream>

using namespace std;

#define T 5

int visitados[T][T], matrix[T][T], cont=1;

void travelMatrix(int line, int column){
    if(line>=0 && line<T && column>=0 && column<T){
        if(visitados[line][column] == 0){
            visitados[line][column] = cont++;
            //cout << "(" << line << "," << column << ")" << endl;
            travelMatrix(line,column+1);
            travelMatrix(line,column-1);
            travelMatrix(line-1,column);
            travelMatrix(line+1,column);
        }
    }
}

void initializeZero(){
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            visitados[i][j] = 0;
        }
    }
}

void showVisited(){
    for(int line=0;line<T;line++){
        for(int column=0;column<T;column++){
            //cout << visitados[line][column] << " ";
            printf("%2d ",visitados[line][column]);
        }
        cout << endl;
    }
}

int main(){
    int line, column;

    cin >> line >> column;
    initializeZero();

    travelMatrix(line,column);

    //showVisited();

    return 0;
}