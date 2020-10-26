#include<stdio.h>           //header files
#include<stdlib.h>
#define max 100             // MAXIMUM size of the queue

int Q[max],P[max];
int rear=-1,front=-1;             //initialization of essential global variable

void enQ(int e,int p)                 //function to enqueue element into the rear index of the queue (as per concept)
{   
    int index,i,j;
    if(rear==max-1)
        printf("\nQUEUE is FULL");          //checking whether the queue is full or not
        
    else if(front==-1 && rear==-1 )             //if whether the queue is empty
    {
        rear++;
        front++;
        Q[rear]=e;
        P[rear]=p;
    }
    else
    {
        if(p>P[rear])                           //if the priority of the entered element is greater than the rear priority array element
        { 
        rear++;
        Q[rear]=e;
        P[rear]=p;
        }
        else
        {
            int r=rear;
            while(P[r]>p)
            {
                Q[r+1]=Q[r];
                P[r+1]=P[r];
                r--;
            }
            Q[r+1]=e;
            P[r+1]=p;
            rear++;
        }
    }
}

void dQ()                       //function to remove element from the front index of the QUEUE (as per concept)
{
    if(front>rear)
        printf("\nQUEUE is Empty");         //checking whether the queue is full or not
    else 
        printf("\nQUEUE ELEMENT %d at %d with priority %d is deleted \n",Q[front],front,P[front]);
        front++;
        
}

void view_PandQ()                   //function to display the entire QUEUE
{
    if(front>rear)
        printf("\nQUEUE is Empty"); 
    else
    {
        printf("\nQUEUE :\n");
        for(int i=front;i<=rear;i++)
            printf("\t%d\t",Q[i]);
        
        printf("\nPRIORITY QUEUE :\n");
        for(int i=front;i<=rear;i++)
            printf("\t%d\t",P[i]);
            
    }
}

int main()
{
    //initialization of essential variables
    int ch,e,p;
    //menu driven entry 
    //while loop for display of menu after every execution and operation 
    while(1)
    {
        printf("\n ____________QUEUE OPERATIONS____________ \n");
        printf(" 1.Enqueue element by priority \n");
        printf(" 2.De-queue element \n");
        printf(" 3.DISPLAY QUEUE and Priority QUEUE \n");
        printf(" 4.Exit \n");

        
        printf(" \n \nENTER your Choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
        case 1:
        printf("\n Enter element to be enqueued into the QUEUE :");
        scanf("%d",&e);
        printf("\n Enter PRIORITY element to be enqueued into the QUEUE :");
        scanf("%d",&p);
        enQ(e,p);
        break;
        
        case 2:
        dQ();
        break;
        
        case 3:
        view_PandQ();
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
