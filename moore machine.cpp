#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;


int main()
{
    int j,init,final[10],fa[10][10],i,n;
    char input[20],ch;
    ifstream f;
    i=0;
    j=0;
    f.open("moore.txt");
    f>>init;
    char a;
    a=f.get();
    while(1)
    {
        
        a=f.get();
        if(a=='\n')
            break;
        else if(a!=' ')
            final[i++]=a-48;
    }
    int k=i;
    i=0;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            fa[i][j]=-1;
    j=0;
    i=0;
    while(1)
    {
        int aa;
        f>>aa;
        if(f.eof())
            break;
        a=f.get();
        fa[i][j]=aa;
        j++;
        if(a=='\n')
        {
            i++;
            n=j;
            j=0;
        }
    }
    cout<<"      o    0    1\n";
    for(int ii=0;ii<i;ii++)
     {
         cout<<"q"<<ii;
         for(j=0;j<n;j++)
         {
            cout<<"    "<<fa[ii][j];
         }
         cout<<"\n";
     }
    do{
    cout<<"Enter String: ";
    fflush(stdin);
    cin.getline(input,20);
    cout<<input<<"\n";
    int len=strlen(input);
    i=0;
    int cur=init;
    while(i<len)
    {
        cur= fa[cur][input[i] - 48 + 1];
        if(cur == -1)
        {
            //cout<<"Machine Stopped Abruptly\n";
            i=-1;
            break;
        }
        else
        {
            cout<<fa[cur][0];
            i++;
        }
    }
    
    
    if(i==-1)
        cout<<"\nMachine Stopped Abruptly\n";
    else
        cout<<"\nOutput generated Succesfully\n";
    
    cout<<"\n\n";
    
    fflush(stdin);
    cout<<"\nContinue (Y/N):\t";
    cin>>ch;
    
    if(ch=='Y' || ch=='y')
        continue;
    else
        break;
        
    }while(1);
    return 0;	
}
