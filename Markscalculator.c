#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
int main(){
    // This is a student grade claculator program that calculates the totalt marks and
// the grade of a student based on the marks entere in five .


char subjects[6][50]={"Math","English","Biology","Chemistry","Physics","language"};
int size=sizeof(subjects)/sizeof(subjects[0]);
int marks[6]={0};
int order[size];
float result=0;
char grade='\0';
float percentage=0;


for(int i=0;i<size;i++){
printf("Enter your marks in %s :",subjects[i]);
scanf("%d",&marks[i]);



}

Sleep(2000);
for(int i=0;i<size;i++){
printf("\nYour marks in %s is %d",subjects[i],marks[i]);
result+=marks[i];


}
int max=marks[0];
int min=marks[0];
percentage=result/size;

 
if(result/size<40){
    grade='F';

}else{
            if(result/size<=50){
                grade='C';


            }

     else if(result/size<=60){

grade='B';

     }
     else if(result/size<=80){
        grade='A';
     }else if (result/size<=90){
        grade='S';
     }else if (result/size<=100){
        grade='O';
     }

}
int count2=0;
for(int i=1;i<size;i++){
    if(max<marks[i]){
        max=marks[i];
        count2=i;
        
    }
  
}
int count=0;
for(int i=1;i<size;i++){
    if(min>marks[i]){
        min=marks[i];
        count=i;
        
        

    }

}

// while(marks[count]!=min){    //it was to find the index number of the min subject
                                //but i used a easier way above ^^
                                
//     count++;
// }





printf("\nYour total marks in the exam is %.0f :",result);
printf("\nYour grade is : %c ;",grade);
printf("\nYour percentage is :%.2f",percentage);
printf("\nYour highest marks is %d in %s",max,subjects[count2]);
printf("\nYour lowest marks is %d in %s",min,subjects[count]);
    
    return 0;
}
