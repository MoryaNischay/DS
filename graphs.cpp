#include<iostream>
using namespace std;

#define show cout<<
#define take cin>>

void print_asterik(int ast){
    if (ast==0){
        return;
    }
    else {
        cout<<"* ";
        print_asterik(ast-1);
    }
}

void print_space(int num){
    if (num==0){
        return;
    }
    cout<<" ";
    print_space(num-1);
}

void upper_matrix(int n,int num){
    if (n>num){
        return;
    }
    else {
        print_space(num-n);
        print_asterik(n);
        show endl;
        upper_matrix(n+1,num);
    }
}

void lower_matrix(int n,int num){
    if (n>num){
        return;
    }
    else{
        print_space(n);
        print_asterik(num-n+1);
        show endl;
        lower_matrix(n+1,num);
    }
}

void pattern(int n){
    upper_matrix(1,n);
    lower_matrix(1,n-1);
}

int main(){
    int a=8;
    pattern(a);
}