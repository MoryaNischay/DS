#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define show cout<<
#define take cin>>

class clothes
{
    public:
    string color;
    int durability;
    int identifier;
    clothes(string color, int durability, int identifier)
    {
        this->color=color;
        this->durability=durability;
        this->identifier=identifier;
    }
};

void colorSort(vector<clothes> &clothesList)
{
    int n=clothesList.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(clothesList[j].color>clothesList[j+1].color)
            {
                clothes temp=clothesList[j];
                clothesList[j]=clothesList[j+1];
                clothesList[j+1]=temp;
            }
        }
    }
}
void durabilitySort(vector<clothes> &clothesList)
{
    int n=clothesList.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(clothesList[j].durability>clothesList[j+1].durability)
            {
                clothes temp=clothesList[j];
                clothesList[j]=clothesList[j+1];
                clothesList[j+1]=temp;
            }
        }
    }
}

int main()
{
    int test_cases;
    take test_cases;
    vector<int> result;
    for (int i = 0; i<test_cases;i++){
    int n;
    
    take n;
    string color;
    int durability;
    int identifier;
    
    vector<clothes> items; 
    for(int i=0;i<n;i++)
    {
        take color>>durability>>identifier;
        clothes item(color,durability,identifier);
        items.push_back(item);
    }
    vector<clothes> items1=items;
    colorSort(items);
    
    durabilitySort(items1);

    int count=0;
    
    for(int i=0;i<n;i++)
    {
        if(items[i].identifier==items1[i].identifier)
        {
            count++;
            result.push_back(count);
        }
    }
    
    }

    for(int i=0;i<test_cases;i++)
    {
        show "Case #"<<i+1<<": "<<result[i]<<endl;
    }
    

    return 0;
}