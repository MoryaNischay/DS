#include <iostream>
using namespace std;

int main() {
    int n,k,i,j,t,f,z=0,y;
    cin>>n>>k;
    int a[n][n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(t=0;t<n;t++)
            {
                cin>>a[i][j][t];
            }
        }
    }
    for(f=0;f<k;f++)
    {
        y=a[0][0][0];
        
        for(j=0;j<n;j++)
        {
        if(j%2==0)
        {
            
            for(i=0;i<n;i++)
            {z=a[i][j][i];
            a[i][j][i]=y;
            y=z;
            }
            
            
        }
        else
        {for(i=n-1;i>=0;i--)
            {
              z=a[i][j][i];  
            a[i][j][i]=y;
            y=z;
            }
        }
        }
        a[0][0][0]=y;
        
        
        
        
        y=a[n-1][0][0];
        
        for(j=0;j<n;j++)
        {
        if(j%2==1)
        {
            
            for(i=0;i<n;i++)
            {
                z=a[i][j][n-1-i];
            a[i][j][n-1-i]=y;
            y=z;
            }
            
            
        }
        else
        {
            for(i=n-1;i>=0;i--)
            {
                z=a[i][j][n-i-1];
            a[i][j][n-1-i]=y;
            y=z;
            }
        }
        }
        a[n-1][0][0]=y;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(t=0;t<n;t++)
            {
                cout<<a[i][j][t]<<" ";
            }
        }
    }
    
    

	return 0;
}