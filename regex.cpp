#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<cmath>

using namespace std;

bool isChar(char a)
{
    a = int(a);
    if (((a>=65)&&(a<=90))||((a>=97)&&(a<=122)) || a=='*')
        return true;
    else return false;
}

bool isOperator(char a)
{
    switch (a)
    {
        case '+': return true;
        case '.': return true;
        case '*': return true;
        case '(': return true;
        case ')': return true;
        default: return false;
    }
}

int order(char op)
{
    switch (op)
    {
        case '+': return 1;
        case '.': return 2;
        default: return 0;
    }
}

bool isHigher(char a, char b)
{
    if(order(a)>=order(b)) return true;
    else return false;
}

string pop(string s)
{
    return s.substr(0,s.size()-1);
}

string toPostfix(string infix)
{
    string postfix, stack;
    
    for(int i=0; i<infix.length(); ++i)
    {
        
        if(isChar(infix[i]))
        {
            postfix.push_back(infix[i]);
        }
        
        else if(isOperator(infix[i]))
        {
            
            if(stack.empty())
            {
                stack.push_back(infix[i]);
            }
            
            else if(!stack.empty())
            {
                if(infix[i]=='(')
                {
                    stack.push_back(infix[i]);
                }
                
                else if(infix[i]==')')
                {
                    while(*(stack.end()-1)!='(')
                    {
                        
                        postfix.push_back(*(stack.end()-1));
                        stack = pop(stack);
                    }
                    stack=pop(stack);
                }
                
                else
                {
                    while(isHigher(*(stack.end()-1),infix[i]))
                    {
                        postfix.push_back(*(stack.end()-1));
                        stack = pop(stack);
                    }
                    
                    if(!(isHigher(*(stack.end()-1),infix[i])))
                        stack.push_back(infix[i]);
                }
            }
        }
    }
    
    while(!stack.empty())
    {
        string::iterator tos = stack.end() - 1;
        postfix.push_back(*tos);
        stack = pop(stack);
    }
    
    return postfix;
}

int verify(string ip,string regex)
{
    
}
int main()
{
    string infix, postfix,input;
    
    cout<<endl<<"Enter the regular expression : ";
    cin>>infix;
    
    postfix= toPostfix(infix);
    
    cout<<"The postfix form of the expression is : ";
    cout<<postfix<<endl;
    
    cout<<endl<<"Enter the input string : ";
    cin >>input;
    verify(input,postfix);
    return 0;
}