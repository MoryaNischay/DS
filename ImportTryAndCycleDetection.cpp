#include "ListLibrary.cpp"
int main(){
    Node* pain = newNodeNoNext(10);
    pain after = newNodeNoNext(20);
    pain after after = newNodeNoNext(30);
    pain after after after = newNodeNoNext(40);
    pain after after after after = newNodeNoNext(50);
    //pain after after after after after = pain after after;
    //* Infinite loop Creater
    OutSinglyList(pain);
    if (DetectCycle(pain)){
        show "Cycle Detected";
    }
    else show "No cycle";
    }