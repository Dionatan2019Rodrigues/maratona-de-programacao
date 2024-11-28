#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//TODO: corrigir lógica de compra de gols e pontuações 
int main() {
    int N, G;
    while (cin >> N >> G) {
        vector<int> diferencaDeGols(N);
        for (int i = 0; i < N; ++i) {
            int S, R;
            cin >> S >> R;
            diferencaDeGols[i] = R - S; //(negativo se perdeu)
        }
        
        sort(diferencaDeGols.begin(), diferencaDeGols.end());
        int points = 0;
        
        for(int i=0;i<diferencaDeGols.size();i++){
            if(diferencaDeGols[i] == 0){
                if(G > 0){
                    G--;
                    points += 3;
                }else {
                    points++;
                }

            }else if(diferencaDeGols[i] >0){
                points +=3;
            }else{
                int golsNecessarios = (diferencaDeGols[i]*(-1))+1;
                if(G>= golsNecessarios){
                    G -= golsNecessarios;
                    points += 3;
                }else if(G -1 == golsNecessarios){
                    G = 0;
                    points +=1;
                }
            }
        }
        
        cout << points << endl;
    }
    return 0;
}