#include <iostream>
#include <vector>

using namespace std;

int max_profit(const vector<int>& receitas, int custoPorDia) {
    int n = receitas.size();
    int max_lucro_atual = receitas[0] - custoPorDia;
    int max_lucro_global = max_lucro_atual;

    for (int i = 1; i < n; ++i) {
        max_lucro_atual = max(max_lucro_atual + receitas[i] - custoPorDia, receitas[i] - custoPorDia);
        max_lucro_global = max(max_lucro_global, max_lucro_atual);
    }

    return max(max_lucro_global, 0);
}

int main(){

    int N, custoPorDia;

    while(cin >> N){
        cin >> custoPorDia;
        vector<int> receitas(N);
        for(int i=0;i<N;i++){
            cin >> receitas[i];
        }
        cout << max_profit(receitas, custoPorDia) << endl;
    }

    return 0;
}