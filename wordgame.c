#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
void welcome();
void rules();
void ask(char words[],int size,char lastchar);

int main(){
    welcome();
    rules();
    srand(time(NULL));
    int randNum=rand()%25;
    char charechters[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char words[50]="";
    int ssize=sizeof(words);
    // char *pWords=words;

    printf("\tEnter a word with the intial letter of %c(all with capital letters )",charechters[randNum]);
    fgets(words,sizeof(words),stdin);
    words[strlen(words)-1]='\0';
    char lastchar='\0';
    int size=strlen(words);
    for(int i=0;i<size;i++){
        lastchar=words[i];


    }
    printf("%c",lastchar);
    ask(words,ssize,lastchar);
    printf("Game over");
    // while(words[0]==lastchar){
       
    //     words[strlen(words)-1]='\0';
    //     ssize=ssize-10;
    //     int size=strlen(words);
    //     for(int i=0;i<size;i++){
    //         lastchar=words[i];
    //     }
    //     printf("%c",lastchar);
        




    // }
    



     

    return 0;
}

void welcome(){

    printf("##### Welcome to the Word game #####\n");
    printf("\n\n");
    printf("###  Here are the rules ###\n\n");



}
void rules(){
    printf("1.\tWrite a word with the given letter\n");
    printf("2.\tnext person would write a word with the last letter of the last word\n");


}
void ask(char words[],int size,char lastchar){
    int a=1;
    
    char lastcharN=lastchar;
  
        while(a==1){
            char words[50]="";
              printf("Now enter a new word(with only 4 words):");
    fgets((words),sizeof(words),stdin);
       
        words[strlen(words)-1]='\0';
        // size=size-10;
        int size=strlen(words);
        // for(int i=0;i<size;i++){
        //     lastcharN=words[i];
        // }
        if(size>4){
            printf("too many letters\n");
            break;
    //                   printf("Now enter a new word :");
    // fgets((words),sizeof(words),stdin);

        }
        if(words[0]!=lastcharN){
            break;
        }
          for(int i=0;i<size;i++){
            lastcharN=words[i];
        }
        printf("%c",lastcharN);
        




    }
    
    


}