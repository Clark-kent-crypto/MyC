#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stacklist.h"
int isOpen(char c);
int isClosed(char c);
int mathcChecker(char arr[]);
char closeTick(char c);
int main(){
    char eqtn[50]="";
    printf("Type a eqtn :");
    scanf(" %[^\n]",&eqtn);
    // struct stack newS;
    // newS.listhead=NULL;
    // for(int i=0;i<strlen(eqtn);i++){
    //     push(&newS,i*8);
    // }
    // for(int i=0;i<strlen(eqtn);i++){
    //     pushc(&newS,eqtn[i]);
    // }
    // popc(&newS);
    // traverseListC(&newS);
    // printf("%s",eqtn); 
    int isMatched=mathcChecker(eqtn);
    if(isMatched){
        printf("The braces are matched");
    }
    else if(!isMatched){
        printf("The braces are not matched");
    }
  
    return 0;
}
int isOpen(char c){
    char ch=c;
    if(ch=='('||ch=='{'||ch=='['){
        return 1;
    }
    return 0;
      
}
int isClosed(char c){
    char ch=c;
    if(ch==')'||ch=='}'||ch==']'){
        return 1;
    }
    return 0;
}
int mathcChecker(char arr[]){
    struct stack s;
    s.listhead=NULL;
    int size=strlen(arr);
    for(int i=0;i<size;i++){
        if(isOpen(arr[i])){

            pushc(&s,arr[i]);


        }
        if(isClosed(arr[i])){
            if(!isFUll(&s)){
                   
                   return 0;
               }
            if(closeTick(arr[i])==peekTop(&s)){
            
            if(!popc(&s)){
                printf("You can not do that\n ");
                return 0;
            }
            
        }
            
        }
    }
    if(s.listhead==NULL){
        printf("The braces are mathced .\n");
        return 1;
    }
    printf("braces are not matched\n");
    return 0;
}

char closeTick(char c){
    char arr[4]="({[";
    char returnArr[4]=")}]";
    for(int i=0;i<strlen(arr);i++){
        if(c==returnArr[i]){
            return arr[i];

        }
    }
}
