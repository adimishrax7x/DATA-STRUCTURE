#include<stdio.h>
//universal initialization of essential variables
#define size 10

int A[size],top=-1;
//HERE push() refers to the entry of element onto the top index of the STACK

void push(int n)
{
    if(top==size-1)
        printf("\n STACK OVERFLOW \n");
    else
    {
        top++;
        A[top]=n;
    }
}



//HERE pop() works for the deletion/removal of element on the top index of the STACK
void pop()
{   
    if(top==-1)
    {
        printf("\n STACK UNDERFLOW \n");
    }
    else 
        printf("\n TOP STACK ELEMENT %d REMOVED  \n",A[top]);
        top--;
}



//HERE peek() works for the display of element on the top index of the STACK
void peek()
{
    if(top==-1)
    {
        printf("\n STACK UNDERFLOW \n");
    }
    else
        printf("\n TOP STACK ELEMENT is %d  \n",A[top]);
}



//HERE DisplayStack() works for the display of the entire STACK
void DisplayStack()
{   
    if(top==-1)
    {
        printf("\n STACK UNDERFLOW \n");
    }
    else 
    {
    printf("\n STACK is :  \n");    
    while(top>=0)
    {
       printf("\n %d  ",A[top]);
       top--;
    }
    }
}


//main funtion
int main()
{
    //initialization of essential variables
    int ch,n;
    //menu driven entry 
    //while loop for display of menu after every execution and operation 
    while(1)
    {
        printf("\n ____________STACK OPERATIONS____________ \n");
        printf(" 1.Push \n");
        printf(" 2.Pop \n");
        printf(" 3.Peek \n");
        printf(" 4.DISPLAY ENTIRE STACK \n");
        printf(" \n \nENTER your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        printf("\n Enter element to be pushed onto the top of the STACK :");
        scanf("%d",&n);
        push(n);
        break;
        
        case 2:
        pop();
        break;
        
        case 3:
        peek();
        break;
        
        case 4:
        DisplayStack();
        break;
        
        default: 
        printf("Invalid choice !!! ");
        break;
        }
            
    }
    return 0;
}
