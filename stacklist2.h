
#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<SDL3/SDL.h>
#include<SDL3/SDL_stdinc.h>
struct node{
    int data;
    struct node* next;
    SDL_FRect* data_sdl;
};
struct stack{
    struct node* listhead;
    int size;
};
void traverseList(struct stack* s);
int push(struct stack* s,int data);
int pop(struct stack* s);
bool isFUll(struct stack* s);
int  peek(struct stack* s,int pos);
SDL_FRect* push_sdl(struct stack* s,SDL_FRect* rect);//pushes SDL_FRect* type of data to the stack 
SDL_FRect* pop_sdl_Frect(struct stack* s);//pop from the stack that has SDL_FRect* type as data 
// int main(){
//     struct node* head=(struct node*)malloc(sizeof(struct node));
//     head->data=10;
//     head->next=NULL;
//     struct stack s;
//     s.listhead=NULL;
//     for(int i=0;i<10;i++){
//         push(&s,i);

//     }
//     int d=pop(&s);
//     int newD=pop(&s);
//     traverseList(&s);
//     int get=peek(&s,4);
//     pop(&s);
    
//     printf("%d\n",d);
//     printf("%d\n",newD);
//     printf("%d\n",get);
    


//     return 0;
// }
void traverseList(struct stack* s ){
    struct node* p=s->listhead;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}
int push(struct stack* s ,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=s->listhead;
    ptr->data=data;
    ptr->next=p;
    s->listhead=ptr;
    return 1;//its indicator that the programme ran fine 

}
int pop(struct stack* s){
    if(s->listhead==NULL){
        printf("Stack Underflow!!");
        return -1;
    }
    struct node* p=s->listhead;
    s->listhead=p->next;
    int data=p->data;
    free(p);
    return data;//its sending back the data that has been poped

    
}
bool isFUll(struct stack* s){
    struct node* p=s->listhead;
    if(p==NULL){
        printf("The Stack is empty");
        return false;
    }
    else{
        return true;

    }
}
int  peek(struct stack* s,int pos){
    struct node* p=s->listhead;
    int i=0;
    while(i!=pos){
        p=p->next;
        i++;
    }
    int returnValue;
    returnValue=p->data;
    return returnValue;

}
void traverse_SDL(struct stack* s){
    struct node* ptr=s->listhead;


}
SDL_FRect* push_sdl(struct stack* s,SDL_FRect* rect){
    struct node* ptr=s->listhead;
    struct node* p=(struct node*)malloc(sizeof(struct node));
    
    p->data_sdl=rect;
    s->listhead=p;
    p->next=ptr;

}

SDL_FRect* pop_sdl_Frect(struct stack* s){
    struct node* ptr=s->listhead;
    s->listhead=ptr->next;
    SDL_FRect* new_Rect=ptr->data_sdl;
    free(ptr);
    return new_Rect;

   
}
struct stack* stack_init(){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->listhead=NULL;
    return s;
}
void stack_destroy(struct stack* s){
    free(s);

}

#endif