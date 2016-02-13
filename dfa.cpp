#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;


int main()
{
    int j,init,final[10],fa[10][10],i,n;
    char input[20],ch;
    ch='Y';
    ifstream f;
    i=0;
    j=0;
    f.open("dfa.txt");
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
    cout<<"         a        b       c\n";
    for(int ii=0;ii<i;ii++)
    {
    	cout<<"q"<<ii;
        for(j=0;j<n;j++)
        {
            cout<<"       "<<fa[ii][j];
        }
        cout<<"\n";       
    }
    while(ch=='Y' || ch=='y')
	{
    	cout<<"\nEnter String: ";
    	cin.getline(input,20);
    	cout<<input<<"\n";
    	int len=strlen(input);
    	i=0;
    	int cur=init;
    	while(i<len)
    	{
            cur=fa[cur][input[i]-97];
       		if(cur== -1)
            	break;
        	else
            	i++;
    	}
    	n=i;
    	i=0;
    	j=0;
    	while(i<10)
    	{
        	if(final[i]==cur && n==len)
        	{
            	j=10;
            	break;
        	}
        	i++;
    	}
    	if(j==10)
        	cout<<"String Accepted\n\n\n";
    	else
        	cout<<"String Not Accepted\n\n\n";
    	cout<<"\n\nContinue (Y / N) :\t";
    	cin>>ch;
    	fflush(stdin);
    	cout<<ch;
	}
        return 0;	
}
