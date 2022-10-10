#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define show cout<<
#define take cin>>

template <class T>

void printvec(vector <T> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    show endl;
}

int main(){
    vector<string> vec1;
    vector<string> vec2;
    int size1,size2;
    string element;
    show "Enter the size of the vector: ";
    take size1;
    for (int i = 0; i < size1; i++)
    {
        show "Enter the First Name: ";
        take element;
        vec1.push_back(element);
    }
    show "Enter the size of the 2nd vector: ";
    take size2;
    for (int i=0;i<size2;i++)
    {
        show "Enter the Last Name: ";
        take element;
        vec2.push_back(element);
    }
    vector<string> :: iterator it = vec1.begin();
    printvec(vec1);
    printvec(vec2);
    vector <string> vec3;
    for (int i=0;i<size2;i++)
    {
        vec3.push_back(vec1[i]);
        vec3.push_back(vec2[i]);
    }
    
    printvec(vec3);
}