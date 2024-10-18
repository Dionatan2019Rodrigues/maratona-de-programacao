#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string nome, opcao, ganhador;
    vector<string> yes, no;
    bool nomeJaExiste = false;

    int maiorNome=0;

    while(true){
        cin >> nome;

        if(nome == "FIM"){
            break;
        }else{ cin >> opcao; }

        if(opcao == "YES"){
            nomeJaExiste = false;
            for(int i=0;i<yes.size();i++){
                if(yes[i] == nome){
                    nomeJaExiste = true;
                }
            }
            if(!nomeJaExiste){
                yes.push_back(nome);
            }

            if(nome.size()>maiorNome){
            maiorNome = nome.size();
            ganhador = nome;
        }
        }
        else{
            no.push_back(nome);
        }

    }

    sort(yes.begin(),yes.end());
    sort(no.begin(),no.end());

    for(int i=0;i<yes.size();i++){
        cout << yes[i] << endl;
    }

    for(int i=0;i<no.size();i++){
        cout << no[i] << endl;
    }
    cout << endl << "Amigo do Habay:" << endl << ganhador << endl;

    return 0;
}