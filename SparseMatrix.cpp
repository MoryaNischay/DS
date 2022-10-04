#include<iostream>
using namespace std;

#define show cout<<
#define take cin>>
int maxlen=10;
void MakeTable(int array[4][4],int value){
    int table[4][3];
    int count=0;
    for (int i=0;i<value;i++){
        for (int j=0;j<value;j++){
            if (array[i][j]!=0){
                table[count][0]=i;
                table[count][1]=j;
                table[count][2]=array[i][j];
                count++;
            }
        }
    }
    for (int i=0;i<count;i++){
        for (int j=0;j<3;j++){
            show table[i][j]<<" ";
        }
        show endl;
    }
}
int main(){
    
    
    int arr[4][4] = {0,0,3,0,0,0,5,7,0,0,0,0,0,2,6,0};
    for (int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            show arr[i][j]<<" ";
        }
        show endl;
    }
    show endl;
    MakeTable(arr,4);
    return 0;
}