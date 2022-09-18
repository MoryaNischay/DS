#include <iostream>
#include <vector>
#include<string>
using namespace std;

bool isPalindrome(int x) {
        string str = to_string(x);
        string temp = to_string(x);
        reverse(str.begin(),str.end());
        if(str == temp){
            return true;
        }
    }

int main(){
    string s = "Name";
    int b = sizeof(s);
    int a = 121;
    if (isPalindrome(a)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}