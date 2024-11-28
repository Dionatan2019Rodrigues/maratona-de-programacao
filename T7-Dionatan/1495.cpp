#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, G, S, R;

	while(cin >> N >> G){

		int points = 0;
		vector<int> golsParaVencer;

		for(int i=0; i<N; ++i){
			cin >> S >> R;

			if(S > R)
				points += 3;
			else
				golsParaVencer.push_back(R-S+1);
		}

		sort(golsParaVencer.begin(), golsParaVencer.end());

		for(int goals:golsParaVencer){
			if(goals == 1){
				if(G >= 1){
					G -= 1;
					points += 3;
				}else
					points++;
			}else{
				if(G >= goals){
					G -= goals;
					points += 3;
				}else{
					if(G == goals - 1){
						G -= (goals - 1);
						points++;
					}else
						break;
				}
			}

		}
		cout << points << endl;
	}

}