#include<stdio.h>
#include<stdlib.h>           //header files

#define MAX 100         // MAXIMUM size of the circular queue

int Q[MAX];
int front = -1;             //essential global variable declaration
int rear = -1;

void enQ(int e)                             // enQ is a function implimented to add an element to the circular queue at the rear index
{
   
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
    printf("\nTHE CIRCULAR QUEUE IS FULL !!! ");                                         //checking whether the queue is full or not
       
    else
    {
        if (front == -1)
            front = 0;
            
        rear = (rear + 1) % MAX;
        Q[rear] = e;
        printf("\n %d is added to the CIRCULAR QUEUE\n\n", e);
    }
}

int dQ()                                    //dQ is a function implimented to delete an element to the circular queue at the front index
{
    if (front == -1)
        printf("\nThe queue is empty!\n");                                                  //checking whether the queue is full or not
   
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
    else
      front = (front + 1) % MAX;
  
    printf("Rear element was deleted from the queue!\n");
    }

}

void Q_display()                      //Q_display is the function implimented to display the entire circular queue 
{
   if (front == -1)
        printf("\nThe queue is empty!\n"); 
   
    else
    {
        printf("\n The CIRCULAR QUEUE elements are:"); 
       
        for (int i = front; i != rear+1; i = (i + 1) % MAX)
            printf("%d\t", Q[i]);
 
    }
    printf("\n");

}

int main()
{
    //initialization of essential variables
    int ch,e;
    //menu driven entry 
    //while loop for display of menu after every execution and operation 
    while(1)
    {
        printf("\n ____________CIRCULAR QUEUE OPERATIONS____________ \n");
        printf(" 1.Enqueue element \n");
        printf(" 2.De-queue element \n");
        printf(" 3.DISPLAY ENTIRE CIRCULAR QUEUE \n");
        printf(" 4.Exit \n");

        
        printf(" \n \nENTER your Choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
        case 1:
        printf("\n Enter element to be enqueued into the  the QUEUE :");
        scanf("%d",&e);
        enQ(e);
        break;
        
        case 2:
        dQ();
        break;
        
        case 3:
        Q_display();
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

