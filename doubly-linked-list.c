#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink,*rlink;
}*head=NULL;

void insert_end();                      //prototype
void insert_beg();
void insert_pos();
void end_del();
void beg_del();
void pos_del();
void display();


int main()                              //menu driven main function
{
    int ch,n,data,pos;                      //initialization of essential variables
    while(1)                                    
    {
        printf("\n_________________DOUBLY LINKED LIST OPERATIONS_________________\n");                                                                           //menu
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
           pos_del();

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



void insert_end()
{
    int data;
    struct node *new,*temp;                                 //pointer initialization
    new=(struct node*)malloc(sizeof(struct node));          //memory alllocation
    
    printf("\nEnter data to be entered in the end :");
       scanf("%d",&data);
        new->data=data;                                     //data entry to new node
        new->rlink= NULL;                                   
        new->llink= NULL;
        
    if(new==NULL)
    {
        printf("\nUNABLE TO ALLOCATE MEMORY\n");
    }
    else if(head==NULL)                                     //if linked list is null
    {
        head=new;
    }
    else
    {
        temp=head;
        while(temp->rlink!=NULL)
        {
            temp=temp->rlink;   
        }
        temp->rlink=new;                                        
        new->llink=temp;
        new->rlink= NULL;
    }
    printf("\nINSERTION SUCCESSFUL");
}


void insert_beg()
{
    int data;
    struct node *new;                                       //pointer initialization
    new=(struct node*)malloc(sizeof(struct node));          //memory allocation
    
    printf("\nEnter data to be entered in the beginning :");
    scanf("%d",&data);
        new->data=data;                                     //data entry to new node
        new->rlink= NULL;                                   
        new->llink= NULL;
    
    if(new==NULL)                                           
    {
        printf("\nUNABLE TO ALLOCATE MEMORY\n");            
    }
    else if(head==NULL)                                     //if list is empty
    {
        head=new;
    }
    else
    {
        new->rlink=head;
        head->llink=new;
        head=new;
    }
    printf("\nINSERTION SUCCESSFUL");
    
}

void insert_pos()  
{  
   struct node *new,*temp;  
   int i,pos,data;  
   new = (struct node *)malloc(sizeof(struct node));  
   
                printf("\nEnter position of data(to be entered) : ");
                scanf("%d",&pos);
                
   if(new == NULL)  
   {  
       printf("\n Unable to allocate memory");  
   }  
   else if(pos==1)                              
   {
       insert_beg();
   }
   else if(head==NULL)                                  //if list is empty
   {
       insert_end();
   }
   else  
   {  
       printf("\nEnter data to be entered :");
                scanf("%d",&data);
       temp=head; 
       for(i=2;i<pos;i++)  
       {  
           temp = temp->rlink;  
           if(temp == NULL)  
           {  
               printf("\n That many elements do not exist !!!");  
               return;  
           }  
       }  
       new->data = data;  
       new->rlink = temp->rlink;  
       new -> llink = temp;  
       temp->rlink = new;  
       new->llink=new;  
       printf("\nINSERTION SUCCESSFUL\n");  
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
    else if(temp->rlink==NULL && prev==NULL)                 //in case there is only one element in the linked list
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(temp->rlink!=NULL)
        {
            prev=temp;                                      
            temp=temp->rlink;                                //incremement
        }
    }
        prev->rlink=NULL;
        free(temp);
        printf("\nDeletion from the end Successful \n");
}

void beg_del()
{
    struct node *temp;                                          //initialization                    
    if(head==NULL)                                              //incase the linked list is empty 
    {
        printf("\nNOTHING TO DELETE !!!\n");
    }
    else
    {
        temp=head;
        head=temp->rlink;
        free(temp);
        printf("\nDeletion from the beginning successful \n");
    }
}


void pos_del()
{
        struct node *temp,*todel;                                          //initialization        
    int pos,i;
     printf("\nEnter position of data(to be deleted) : ");
        scanf("%d",&pos);
    if(head==NULL)                                              //incase the linked list is empty 
    {
        printf("\nNOTHING TO DELETE !!!\n");
    }
    else if(pos==1)
    {
        beg_del();
    }
    else
    {
        temp=head;
        for(i=2;i<pos;i++)
        {
            temp=temp->rlink;    
        }
        todel=temp->rlink;
        temp->rlink=todel->rlink;
        free(todel);
            printf("\nDeletion from desired postion Successful \n");
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
        printf("\nDOUBLY LINKED LIST :");
        while (temp->rlink!=NULL)
        {
            printf("\n%d",temp->data);
            temp=temp->rlink;                                        //incremement
        }
    printf("\n%d",temp->data);
    }
}
