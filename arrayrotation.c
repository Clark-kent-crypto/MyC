#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
int main(){
    int n;
    int D;

    printf("Enter the number of subjects :");
    scanf(" %d",&n);
    printf("how much would you rotate ?");
    scanf(" %d",&D);
    int *num=malloc(n*4);
    int *num2=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter some numbers :");
        scanf(" %d",&num[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
        
    }
    for(int i=0;i<n-D;i++){
        num2[i]=num[i+D];

    }
    for(int i=n-D;i<n;i++){
        num2[i]=num[i-(n-D)];
    }
    printf("\n");
     for(int i=0;i<n;i++){
        printf("%d ",num2[i]);
        
    }


    free(num);
    
    
    return 0;

}