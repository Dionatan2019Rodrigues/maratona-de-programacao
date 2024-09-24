#include <iostream>

using namespace std;

void showGameTime(int hour, int minute){
    cout<<"O JOGO DUROU "<<hour<<" HORA(S) E "<<minute<<" MINUTO(S)"<<endl;
}

void calculateGameTime(int start_hour, int start_min, int end_hour, int end_min){
    int minutes_total = (end_hour*60+end_min)-(start_hour*60+start_min);

    if (minutes_total < 0) {
        minutes_total += 24 * 60;
    }

    int duration_hour = minutes_total / 60;
    int duration_minutes = minutes_total % 60;

    if(start_hour==end_hour && start_min == end_min){
        duration_hour = 24;
        duration_minutes = 0;
    }

    showGameTime(duration_hour,duration_minutes);
}

int main(){

    int start_hour, start_min, end_hour, end_min;

    cin >> start_hour >> start_min >> end_hour >> end_min;
    //scanf(" %d %d %d %d",&start_hour, &start_min, &end_hour, &end_min);

    calculateGameTime(start_hour,start_min,end_hour,end_min);

    return 0;
}