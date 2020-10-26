#include<stdio.h>
#include<stdlib.h>

struct node                             //structure of the node
{
    int data;                           //data
    struct node *link;                  //aadress link to next
}*head;

struct node *head=NULL;

void insert_end();                      //prototype
void insert_beg();
void insert_pos(int data, int pos);
void end_del();
void beg_del();
void pos_del(int pos);
void display();

int main()                              //menu driven main function
{
    int ch,n,data,pos;                      //initialization of essential variables
    while(1)                                    
    {
        printf("\n_________________LINKED LIST OPERATIONS_________________\n");                                                                           //menu
        printf("\n1.Enter element in the end of the LINKED LIST");
        printf("\n2.Enter element at the beginning of the LINKED LIST");
        printf("\n3.Enter element at at any position of the LINKED LIST");
        printf("\n4.Delete element from the end of the LINKED LIST");
        printf("\n5.Delete element from the beginning of the LINKED LIST");
        printf("\n6.Delete element from any position of the LINKED LIST");
        printf("\n7.DISPLAY LIST");
        printf("\n8.EXIT");
        
        printf("\nEnter choice :"); 
        scanf("%d",&ch);
   
        switch (ch)
        {
            case 1:
                insert_end();
            break;
            
            case 2:
                insert_beg();
            break;

            case 3:
                printf("\nEnter data to be entered :");
                scanf("%d",&data);
                printf("\nEnter position of data(to be entered) : ");
                scanf("%d",&pos);
                insert_pos(data,pos);
            break;
            
            case 4:
                end_del();
            break;
                
            case 5:
                beg_del();
            break;
            
            case 6:
            printf("\nEnter position of data(to be deleted) : ");
                scanf("%d",&pos);
            pos_del(pos);

            break;
            
            case 7:
                display();
            break;
            
            case 8 :
                exit(1);
            break;
            
            default:
            printf("\nWRONG CHOICE TRY AGAIN !");
            break;
        }
    }
    return 0;
}


void insert_end()                                           //function to enter value at end of the linked list 
{   
    int data;
        struct node *new, *temp;                            //initialization of pointers
        new=(struct node*)malloc(sizeof(struct node));

    if(new==NULL)
    {
        printf("\nUNABLE TO ALLOCATE MEMORY\n");
    }
    
     printf("\nEnter data to be entered in the end :");
       scanf("%d",&data);
        new->data=data;                                     //data entry to new node
        new->link= NULL;                                    //address of last node of the Linked list is NULL always
    if(head==NULL)                                          //incase the linked list is empty 
    {
        head=new;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;                                        //incremement
        }
    temp->link=new;
    printf("\nDATA ENTERED AT THE END OF LINKED LIST\n");
    }
}


void insert_beg()                                               //function to enter value at beginning of the linked list 
{
    int data;
    struct node *new, *temp;                                    //initialization of pointers
    new=(struct node*)malloc(sizeof(struct node));
    
    if(new==NULL)
        printf("\nUNABLE TO ALLOCATE MEMORY\n");
    
    printf("\nEnter data to be entered in the beginning :");
       scanf("%d",&data);
        new->data=data;                                     //data entry to new node
    if(head==NULL)                                          //incase the linked list is empty 
    {
        head=new;
    }
    else
    {
        new->link=head;                                     //linking to the head
        head=new;                                           //new is the new head now
    }

        printf("\nDATA ENTERED AT THE BEGINNING OF LINKED LIST\n");

}
void insert_pos(int data, int pos)                              //function to enter value at any desired of the linked list 
{
   
    int i;                                                      //looping variable
    struct node *new, *temp;                                    //pointer initilaization

    new = (struct node*)malloc(sizeof(struct node));            //memory allocation

    if(new == NULL)
        printf("Allocation of memory unavialable !");
    else
    {
        new->data = data;
        new->link = NULL;                                       //entry of data to new node

        temp = head;

        for(i=2; i<=pos-1; i++)
        {
            temp = temp->link;                                  //increment

            if(temp == NULL)
                break;
        }
        if(temp != NULL)
        {
            
            new->link = temp->link;
            
            temp->link = new;
            printf("\nData insertion was successful!\n");
           
        }
        else
        {
           
            printf("\nUnable to insert data at the given position\n");
           
        }
       
    }
   
}

void end_del()                                      //function to delete value from the end of thelinked list
{   
    struct node *prev,*temp;                                //initialization of pointers
        prev=NULL;
        temp=head;                                          //temporary variable initilaization
    
           
    if(head==NULL)                                          //incase the linked list is empty 
    {
        printf("\nNOTHING TO DELETE !!!\n");
    }
    else if(temp->link==NULL && prev==NULL)                 //in case there is only one element in the linked list
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(temp->link!=NULL)
        {
            prev=temp;                                      
            temp=temp->link;                                //incremement
        }
    }
        prev->link=NULL;
        free(temp);
        printf("\nDELETE Successful \n");
}

void beg_del()                                              //function to delete value from the beginning of thelinked list
{   
    struct node *temp;                                          //initialization                    
    if(head==NULL)                                              //incase the linked list is empty 
    {
        printf("\nNOTHING TO DELETE !!!\n");
    }
    else
    {
        temp=head;
        head=temp->link;
        free(temp);
        printf("\nDELETE Successful \n");
    }
}

void pos_del(int pos)                                       //function to delete value from any desired of thelinked list    
{
   
    int i;                                                  //looping variable
    struct node *toDel, *prev;                               //initialization of pointers

        toDel = head;                                       //position initalization    
        prev = head;

        for(i=2; i<=pos; i++)
        {
            prev = toDel;
            toDel = toDel->link;

            if(toDel == NULL)
                break;
        }

        if(toDel != NULL)
        {
            if(toDel == head)
                head = head->link;
 
            prev->link = toDel->link;
            toDel->link = NULL;
            free(toDel);
            printf("\nDELETED NODE from the LINKED  LIST\n");
           
        }

        else
            printf("\nInvalid position !!!");
}

void display()                                          // function to display the entire linked list
{
    struct node *temp;                                          //initialization                    
    int i=1;
    if(head==NULL)
    printf("\nEmpty LINKED LIST !");                              //incase the linked list is empty 
    else
    {
        temp=head;
        printf("\nLINKED LIST :");
        while (temp!=NULL)
        {
            printf("\n%d at %d and LINKED LIST POSITION :%d",temp->data,temp->link,i);
            temp=temp->link;                                        //incremement
            i++;
        }
    }
}
