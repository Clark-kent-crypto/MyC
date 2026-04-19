#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    
};
void listTraverse(struct node*ptr);
struct node* insert(struct node*ptr,int data,struct node* in);
void insertFirst(struct node* ptr,int data,struct node* head);
struct node* insertAtIndex(int index,int data);
struct node* insertAtEnd(struct node* head,int data);
void deleteAtFirst(struct node* head);
int  deleteAtIndex(struct node* head,int index);
int  deleteAtEnd(struct node* head);
struct node* Head;

int main(){
    
    
    struct node* head=(struct node*)malloc(sizeof(struct node));
     struct node* first=(struct node*)malloc(sizeof(struct node));
      struct node* second=(struct node*)malloc(sizeof(struct node));
      struct node* third=(struct node*)malloc(sizeof(struct node));
      Head=head;
      head->data=7;
      first->data=10;
      second->data=15;
      third->data=30;
      head->next=first;
      first->next=second;
      second->next=third;
      third->next=NULL;
      struct node* fourth=(struct node*)malloc(sizeof(struct node));
      struct node* fifth;
     
    //   insert(fourth,45,head);
    insertFirst(fourth,45,head);
     fifth=insert(fifth,69,fourth);
     struct node* sixth=insertAtIndex(4,47);
     struct node* idk=insertAtIndex(4,55);
     

     head=insertAtEnd(Head,90);
    
     listTraverse(Head);
     printf("\n");
     deleteAtFirst(Head);
     deleteAtEnd(Head);
      listTraverse(Head);

    return 0;
}
void listTraverse(struct node*ptr){//Function to traverse the list
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}
struct node* insert(struct node*ptr,int data,struct node* in){//Function made to insert after a spectific node
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=in->next;
    in->next=ptr;
    ptr->data=data;
    return ptr;

    
}
void insertFirst(struct node* ptr,int data,struct node* head){//Funcntion made to insert node at the start of the list
    ptr->data=data;
    ptr->next=head;
    Head=ptr;
    
}
struct node* insertAtIndex(int index,int data){//Function made to insert at the index
    int i=1;
    struct node* p=Head;
    while(i!=index){
        p=p->next;
        i++;
    }
 
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;
    return ptr;


}
struct node* insertAtEnd(struct node* head,int data){//Function made to insert node  at the end 
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node*p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
void deleteAtFirst(struct node* head){
    Head=head->next;
    free(head);
}
int  deleteAtIndex(struct node* head,int index){//This is a specific function made to delete node in between the head and the end node
    struct node*p;
    struct node* pr;
    if(!index){
        printf("Index has to be more than zero\n");
        return 1;
        
    }
    
   
    p=head;
    int i=0;
    while(i!=index){
        pr=p;
        p=p->next;
        i++;
    }
    if(p==NULL){
        printf("Index out of bound\n");
        return 1;
    }
    pr->next=p->next;
    free(p);
    return 0;
    
    
}
int  deleteAtEnd(struct node* head){//This is a specific function made to delete node from the end 
    struct node* p;
    struct node* pr;

    p=head;
    while(p->next!=NULL){
        pr=p;
        p=p->next;
    }
    pr->next=NULL;
    return 0;


}