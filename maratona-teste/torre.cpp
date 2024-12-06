#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//FIXME: no time to resolve
int main(){

    int N;
    cin >> N;

    vector<int>numbers(N);
    vector<bool>usado(N,false);
    for(int i=0;i<N;i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int cont = 0;

    bool todosUsados = true;
 
    do{
        for(int i=0;i<N;i++){
            if(usado[i] == false && numbers[i] != numbers[i-1]){
                if(numbers[i]<numbers[i+1]){
                    usado[i] =true;
                    usado[i+1] = true;
                }
            }
            cont ++;
            for(int i=0;i<N;i++){
                if(usado[i] == false)
                    todosUsados=false;
                }
            }
    }while(!todosUsados);

    cout << cont << endl;

    return 0;
}