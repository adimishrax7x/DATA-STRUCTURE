#include<stdio.h>           //header files
#include<stdlib.h>
#define max 100             // MAXIMUM size of the queue

int Q[max];
int rear=0,front=0;             //initialization of essential global variable

void enQ(int e)                 //function to enqueue element into the rear index of the queue (as per concept)
{
    if(rear==max-1)
        printf("\nQUEUE is FULL");          //checking whether the queue is full or not
        
    else {
    Q[rear]=e;
    rear++;}
}

void dQ()                       //function to remove element from the front index of the QUEUE (as per concept)
{
    if(front>rear)
        printf("\nQUEUE is Empty");         //checking whether the queue is full or not
    else 
        printf("\nQUEUE ELEMENT %d at %d is deleted \n",Q[front],front);
        front++;
        
}

void view_Q()                   //function to display the entire QUEUE
{
    printf("\nQUEUE :");
    for(int i=front;i<rear;i++)
    {
        printf("\nQUEUE ELEMENT at %d is %d  \n",i,Q[i]);
    }
}

int main()
{
    //initialization of essential variables
    int ch,e;
    //menu driven entry 
    //while loop for display of menu after every execution and operation 
    while(1)
    {
        printf("\n ____________QUEUE OPERATIONS____________ \n");
        printf(" 1.Enqueue element \n");
        printf(" 2.De-queue element \n");
        printf(" 3.DISPLAY ENTIRE QUEUE \n");
        printf(" 4.Exit \n");

        
        printf(" \n \nENTER your Choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
        case 1:
        printf("\n Enter element to be enqueued into the QUEUE :");
        scanf("%d",&e);
        enQ(e);
        break;
        
        case 2:
        dQ();
        break;
        
        case 3:
        view_Q();
        break;
        
        case 4:
        exit(1);
        break;
        
        default: 
        printf("Invalid choice !!! ");
        break;
        }
            
    }
    return 0;
}

