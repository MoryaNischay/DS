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
    int size;
    string element;
    show "Enter the size of the vector: ";
    take size;
    for (int i = 0; i < size; i++)
    {
        show "Enter the Name: ";
        take element;
        vec1.push_back(element);
    }
    vector<string> :: iterator it = vec1.begin();
    printvec(vec1);

    vec1.insert(it+2,"Rahul");
    printvec(vec1);
}