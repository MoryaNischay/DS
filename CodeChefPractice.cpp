#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define show cout<<
#define take cin>>
//check who will reach the end first if distance and speeds are given 
void check(int A,int B,int X,int Y){    
    float t1,t2;
    t1=(float)X/A;
    t2=(float)Y/B;
    if(t1>t2){
        show "Chef";
    }
    else if(t1<t2){
        show "Chefina";
    }
    else{
        show "Both";
    }
}



int main() {
	// your code goes here
    int test_case;
    int a,b,x,y;
    cin>>test_case;
    for (int i=0;i<test_case;i++){
        take a>>b>>x>>y;
        check(a,b,x,y);
        show endl;
    }
	return 0;
}

