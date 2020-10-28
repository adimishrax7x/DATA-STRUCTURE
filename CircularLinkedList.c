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
void insert_pos();
void end_del();
void beg_del();
void pos_del(int pos);
void display();

int main()                              //menu driven main function
{
    int ch,n,data,pos;                      //initialization of essential variables
    while(1)                                    
    {
        printf("\n_________________CIRCULAR LINKED LIST OPERATIONS_________________\n");                                                                           //menu
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
                
                insert_pos();
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
        new=(struct node*)malloc(sizeof(struct node));          //memory allocation

    if(new==NULL)//if space is full
    {
        printf("\nUNABLE TO ALLOCATE MEMORY\n");
    }
    else
    {
        printf("\nEnter data to be entered in the end :");
        scanf("%d",&data);  //entry of element
        new->data=data;
        
        if(head==NULL)
        {
            head=new;
            head->link=head;        //as per cicular linked list the last element contains the link to the first element
        }
        else
        {
            temp=head;
            while(temp->link!=head)
                temp=temp->link;
                
            temp->link=new;       
            new->link=head;        //as per cicular linked list the last element contains the link to the first element
        }
    printf("\nDATA ENTERED AT THE END OF LINKED LIST\n");

    }
}

void insert_beg()                                           //function to enter value at end of the linked list 
{   
        struct node *new, *temp;                            //initialization of pointers
        new=(struct node*)malloc(sizeof(struct node));          //memory allocation

        int data,pos;
     printf("\nEnter data to be entered :");
                scanf("%d",&data);
    
    if(new==NULL)
    {
        printf("\nUNABLE TO ALLOCATE MEMORY\n");
    }
    else
    {
        printf("\nEnter data to be entered in the end :");
        scanf("%d",&data);
        new->data=data; 
        
        if(head==NULL)
        {
            head=new;
            head->link=head;                //as per cicular linked list the last element contains the link to the first element
        }
        else
        {
            temp=head;
            while(temp->link!=head)
                temp=temp->link;
                
            temp->link=new;    
            new->link=head;             //as per cicular linked list the last element contains the link to the first element  
            head=new;
        }
    printf("\nDATA ENTERED AT THE BEGINNING OF LINKED LIST\n");
    }
}

void insert_pos()
{
    struct node *new , *temp;       //initilaizaiton
    int i,pos,data;
                printf("\nEnter position of data(to be entered) : ");
                scanf("%d",&pos);
    
    if(head==NULL)              //empty list
    {
        printf("\nNO position to insert !!!\n");
    }
    else if(pos==1)         //only one element on the list
    {
        insert_beg();       //funciton call
    }
    else
    {
        printf("\nEnter data to be entered :");
                scanf("%d",&data);
        new=(struct node*)malloc(sizeof(struct node));  //memory allocation
        new->data=data;     
        
        temp=head;      
        for(i=2;i<pos-1;i++)
        {
            temp=temp->link;
        }
        new->link=temp->link;
        temp->link=new;
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
    else if(temp->link==head && prev==NULL)                 //in case there is only one element in the linked list
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(temp->link!=head)
        {
            prev=temp;                                      
            temp=temp->link;                                //incremement
        }
    }
        prev->link=head;
        free(temp);
        printf("\nDELETE Successful \n");
}

void beg_del()                                              //function to delete value from the beginning of thelinked list
{   
    struct node *temp,*ptr;                                          //initialization                    
    if(head==NULL)                                              //incase the linked list is empty 
    {
        printf("\nNOTHING TO DELETE !!!\n");
    }
    else
    {
        temp=head;
        while(temp->link!=head)
            temp=temp->link;                            //increment
        
        ptr=head;
        ptr=ptr->link;
        head=ptr;
        temp->link=head;
        
        printf("\nDELETE Successful \n");

    }
}

void pos_del(int pos)
{
        struct node *toDel, *temp;                                  //initialization of pointers
            int i = 0;

        if(head == NULL)                                            //empty liked list
        {
            printf("\nEmptyLinked List !!!");
        }
        else
        {
        

            if(pos==1)
            {
              beg_del();
            }
            else
            {
                toDel = head;
                while(i != pos-1)
                {
                temp = toDel;
                toDel = toDel->link;
                i++;
            }
            
            temp->link = toDel->link;
            
            free(toDel);
            
            printf("\nDeletion  successful!\n", pos);
            }
        }
}


void display()                                          // function to display the entire linked list
{
    struct node *temp;                                          //initialization                    
    if(head==NULL)
    printf("\nEmpty LINKED LIST !");                              //incase the linked list is empty 
    else
    {
        temp=head;
        printf("\nLINKED LIST :");
            while (temp->link!=head)
            {
                
                printf("\n%d ",temp->data);
                temp=temp->link;                                        //increment
            }
        printf("\n%d ",temp->data);
    }
        
}
