#include <iostream>

using namespace std;

struct parts_barbecue{
    string part;
    int valid_data;
};

void showOutput(parts_barbecue vet[], int length){
    for(int i=0;i<length;i++){
        cout << vet[i].part;
        if(i != length-1)
            cout << " ";
    }
    cout << endl;
}

void quick_sort(parts_barbecue vet[], int first, int last){

    int i, j, pivot;
    parts_barbecue temp;

    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(vet[i].valid_data<=vet[pivot].valid_data&&i<last)
                i++;
            while(vet[j].valid_data>vet[pivot].valid_data)
                j--;
            if(i<j){
                temp=vet[i];
                vet[i]=vet[j];
                vet[j]=temp;
            }
        }
        temp=vet[pivot];
        vet[pivot]=vet[j];
        vet[j]=temp;
        quick_sort(vet,first,j-1);
        quick_sort(vet,j+1,last);
    }
}

int main(){

    int number_parts_barbecue, data;
    string line;

    while( cin >> number_parts_barbecue){
        if(number_parts_barbecue < 0 || number_parts_barbecue > 10)
            return 0;

        parts_barbecue vet[number_parts_barbecue];
        for(int i=0;i<number_parts_barbecue;i++){
            cin >> line >> data;
            vet[i].part = line;
            vet[i].valid_data = data;
        }

        quick_sort(vet,0,number_parts_barbecue-1);

        showOutput(vet,number_parts_barbecue);

    }

    return 0;
}