#include<iostream>
using namespace std;
#define show cout<<
#define take cin>>
int main(){
    float alice_d,alice_time,bob_d,bob_time;
    int test_cases;
    take test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        take alice_d>>alice_time>>bob_d>>bob_time;
        float alice_speed=alice_d/alice_time;
        float bob_speed=bob_d/bob_time;
        if (alice_speed<bob_speed)
        {
            show "Bob"<<endl;
        }
        else if (bob_speed<alice_speed)
        {
            show "Alice"<<endl;
        }
        else if (bob_speed==alice_speed)
        {
            show "Equal"<<endl;
        }
        
}}