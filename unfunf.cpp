#include<iostream>
using namespace std;
//function to take input in 3d array

void input(int arr[][3][3],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin>>arr[i][j][k];
            }
            
        }
        
    }
    
}

//function to print 3d array
void print(int arr[][3][3],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout<<arr[i][j][k]<<" ";
            }
            
            
        }
        
        
    }
    
}

//program to take the first column of the first matrix second column of the second matrix and third column of the third matrix and store it in a new 2d array 
void make2dbackward(int arr[][3][3],int n){
    int arr2[3][3];
    for (int i = 0; i < n; i++)
    {
        
        int count=0;
        for (int j = 0; j < n; j++)
        {
            
            arr2[i][j]=arr[count][i][j];
            count++;
        }
        
    }   
    
    //reverse the row of array if the condition is sa   

    for (int i = 0; i < n; i++)
    {
        if ((i-1)%2==0){
            //reverse the row
            for (int j = 0; j < n/2; j++)
            {
                int temp=arr2[i][j];
                arr2[i][j]=arr2[i][n-1-j];
                arr2[i][n-1-j]=temp;
            }
        }
        
    }

    int temp=0;
    int maxlen=n*n;
    int arr57[maxlen];
    //copy the elements of a 2d array in a 1d array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr57[temp]=arr2[i][j];
            temp++;
        }
         
    }
    int temp2=arr57[(maxlen)-1];
    for(int i=maxlen-1;i>0;i--)
    {
        arr57[i]=arr57[i-1];
    }
    arr57[0]=temp2;
    
    int temp3=0;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            arr2[i][j]=arr57[temp3];
            temp3++;
        }
         
    }
    for (int i = 0; i < n; i++)
    {
        if ((i-1)%2==0){
            //reverse the row
            for (int j = 0; j < n/2; j++)
            {
                int temp=arr2[i][j];
                arr2[i][j]=arr2[i][n-1-j];
                arr2[i][n-1-j]=temp;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        
        int count=0;
        for (int j = 0; j < n; j++)
        {
            
            arr[count][i][j]=arr2[i][j];
            count++;
        }
        
    }  
    
}

//function to move the first element to the 2nd position and 2nd element to the 3rd position and so on in a 2d array
void move(int arr[3][3],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            arr[i][j]=arr[i][j+1];
        }
        
    }
    
}

//function for forward rotation
void make2dforward(int arr[][3][3],int n){
    int arr2[3][3];
    for (int i = 0; i < n; i++)
    {
        
        int count=n-1;
        for (int j = 0; j < n; j++)
        {
            
            arr2[i][j]=arr[count][i][j];
            count--;
        }
        
    }   
    for (int i = 0; i < n; i++)
    {
        if ((i-1)%2==0){
            //reverse the row
            for (int j = 0; j < n/2; j++)
            {
                int temp=arr2[i][j];
                arr2[i][j]=arr2[i][n-1-j];
                arr2[i][n-1-j]=temp;
            }
        }
        
    }
    int temp=0;
    int maxlen=n*n;
    int arr57[maxlen];
    //copy the elements of a 2d array in a 1d array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr57[temp]=arr2[i][j];
            temp++;
        }
         
    }
    int temp2=arr57[(maxlen)-1];
    for(int i=maxlen-1;i>0;i--)
    {
        arr57[i]=arr57[i-1];
    }
    arr57[0]=temp2;
    
    int temp3=0;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            arr2[i][j]=arr57[temp3];
            temp3++;
        }
         
    }
    for (int i = 0; i < n; i++)
    {
        if ((i-1)%2==0){
            //reverse the row
            for (int j = 0; j < n/2; j++)
            {
                int temp=arr2[i][j];
                arr2[i][j]=arr2[i][n-1-j];
                arr2[i][n-1-j]=temp;
            }
        }
        
    }

    
    //print 2d array
    
    
    for (int i = 0; i < n; i++)
    {
        
        int count=n-1;
        for (int j = 0; j < n; j++)
        {
            
            arr[count][i][j]=arr2[i][j];
            count--;
        }
        
    }  
       
}
//main function to take dimensions of array and then take input and print it
int main(){
    int n;
    cin>>n;
    int testiterations;
    cin>>testiterations;
    int arr[n][3][3];
    input(arr,n);
    for (int i = 0; i < testiterations; i++)
    {
        make2dbackward(arr,n);
        make2dforward(arr,n);
    }
    
    print(arr,n);
    
}