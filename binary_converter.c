#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void b_to_d();
void b_to_o();
void b_to_h();
void d_to_b();
void d_to_o();
void d_to_h();
void o_to_b();
void o_to_d();
void o_to_h();
void h_to_b();
void h_to_d();
void h_to_o();
int btod(int);
int otod(int);
int dtob(int);
int htod(char[],int b);

int main()
{
    int choice;
    printf("\n\t\tBinary Convertor\t\t\n");
    printf("1.Binary to Decimal\n2.Binary to Octal\n3.Binary to Hexa-decimal\n\n4.Decimal to Binary\n5.Decimal to Octal\n6.Decimal to Hexa-decimal\n");
    printf("\n7.Octal to Binary\n8.Octal to Decimal\n9.Octal to Hexa-decimal\n\n10.Hexa-decimal to Binary\n11.Hexa-decimal to Decimal\n12.Hexa-decimal to Octal");
    printf("\nEnter your Choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        b_to_d();
        break;
    case 2:
        b_to_o();
        break;
    case 3:
        b_to_h();
        break;
    case 4:
        d_to_b();
        break;
    case 5:
        d_to_o();
        break;
    case 6:
        d_to_h();
        break;
    case 7:
        o_to_b();
        break;
    case 8:
        o_to_d();
        break;
    case 9:
        o_to_h();
        break;
    case 10:
        h_to_b();
        break;
    case 11:
        h_to_d();
        break;
    case 12:
        h_to_o();
       break;
    default:
        printf("--Enter correct option--");
        break;
    }
    
    

    return 0;
}



void b_to_d()
{
    int binary;
    int n, digit = 0, i = 0;
    int decimal = 0;
    printf("\nEnter any Binary number :");
    scanf("%d", &binary);
    n = binary;
    while (n != 0)
    {

        digit = n % 10;
        decimal += digit * pow(2, i);
        i++;
        n = n / 10;
    }
    printf("\nDecimal = %d ", decimal);
}
void b_to_o()
{
    int binary;
    int n, rem, i = 0;
    int octa = 0;
    int decimal;

    printf("\nEnter any Binary number :");
    scanf("%d", &binary);
    decimal = btod(binary);
    // printf("%d",decimal);

    // decimal to octal

    while (decimal != 0)
    {
        rem = decimal % 8;
        octa += rem * pow(10, i);
        decimal /= 8;
        i++;
    }

    printf("\nOctal = %d ", octa);
}

void b_to_h()
{
    int binary;
    int rem,a;
    char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int hexa[50],i=0;    
    printf("\nEnter any Binary number :");
    scanf("%d", &binary);
    
    int decimal=btod(binary);

    //decimal to hexa-decimal

    printf("\nHexa-decimal = ");
    while (decimal!=0) {
        rem = decimal % 16;
        hexa[i++]=rem;
        decimal /= 16;
    }
    for(int j=0;j<i;j++) {
        a=hexa[i-1-j];
        printf("%c",arr[a]);
    }
    
}

void d_to_b()
{
    int number;
    int binum;
    int temp;

    printf("Enter a number :");
    scanf("%d", &number);
    temp = number;
    int count = 0;
    while (number > 0)
    {
        number /= 2;
        count++;
    }
    // printf("%d",count);
    // int *pnewNumber=malloc(count*4);
    int newNumber[100] = {0};
    for (int i = 0; i < count; i++)
    {
        if (number < 0)
        {
            break;
        }
        binum = temp % 2;
        temp /= 2;
        newNumber[i] = binum;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d", newNumber[(count - 1) - i]);
    }
}

void d_to_o() {
    int i=0;
    int decimal,rem,octa=0;
    printf("Enter Decimal Number:");
    scanf("%d",&decimal);
    while (decimal != 0)
    {
        rem = decimal % 8;
        octa += rem * pow(10, i);
        decimal /= 8;
        i++;
    }

    printf("\nOctal = %d ", octa);
}

void d_to_h() {
    int decimal;
    int rem,a;
    char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int hexa[50],i=0;
    printf("Enter Decimal Number:");
    scanf("%d",&decimal);
     printf("\nHexa-decimal = ");
    while (decimal!=0) {
        rem = decimal % 16;
        hexa[i++]=rem;
        decimal /= 16;
    }
    for(int j=0;j<i;j++) {
        a=hexa[i-1-j];
        printf("%c",arr[a]);
    }
}

int btod(int binary)
{

    int n, digit = 0, i = 0;
    int decimal = 0;

    n = binary;
    while (n != 0)
    {

        digit = n % 10;
        decimal += digit * pow(2, i);
        i++;
        n = n / 10;
    }

    return decimal;
}
void o_to_d(){
    int octal;
    int temp;
    int decimal=0,n,i=0;
    printf("Enter any octal number :");
    scanf(" %d",&octal);
    temp=octal;
    while(octal!=0){
        n=octal%10;
        decimal+=n*pow(8,i);
        octal/=10;
        i++;

    }
    printf("\nThe decimel value is : ");
    printf("%d",decimal);

}
int otod(int new){
     int octal;
    int temp;
    int decimal=0,n,i=0;
   octal=new;
    temp=octal;
    while(octal!=0){
        n=octal%10;
        decimal+=n*pow(8,i);
        octal/=10;
        i++;

    }
    return decimal;


}
int dtob(int n){
    int decimel;
    int binary=0;
    int i=0;
    int temp;
    decimel=n;
    temp=decimel;
    while(decimel!=0){
        int new;
        new=decimel%2;
        binary=binary+new*pow(10,i);
        decimel/=2;
        i++;

    }
    return binary;


}
void o_to_b(){
    int octal;
    int binary;
    printf("Enter an Octal Number :");
    scanf(" %d",&octal);
    int decimal;
    decimal=otod(octal);
    binary=dtob(decimal);

    printf("The binary value is : %d ",binary);

    

}
void o_to_h(){
    int octal;
    int decimal;
    char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int hexa[50];
    int i=0;
    
    printf("Enter a octal number :");
    scanf(" %d",&octal);
    decimal=otod(octal);
    while(decimal!=0){
        int temp;
        temp=decimal%16;
        hexa[i]=temp;
        decimal/=16;
        i++;
    }
    for(int j=0;j<i;j++){
        printf("%c",arr[hexa[i-1-j]]);
    }


}
void h_to_d(){
    char hexa[100]="";
    int a;
    int x=0;
    int decimal=0;
    int temp;
    printf("Enter Any hexa-decimal number :");
    
    getchar();
    fgets(hexa,sizeof(hexa),stdin);
    hexa[strlen(hexa)-1]='\0';
    
    a=strlen(hexa)-1;
    for(int i=0;i<a+1;i++){
        hexa[i]=toupper(hexa[i]);

    }
    // printf("%s",hexa);
    int temp2=a;
    char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    for(int i=0;i<=a+1;i++){
        for(int j=0;j<16;j++){
            
            if(hexa[x]==arr[j]){
                temp=j;
                decimal+=temp*pow(16,temp2);
                temp2-=1;
                x++;
                
            
            }
           

        }
         
    }
    printf("decimal=%d",decimal);

}
int htod(char n[],int b){
        char hexa[100]="";
    int a;
    int x=0;
    int decimal=0;
    int temp;
    for(int i=0;i<b;i++){
        hexa[i]=n[i];
    }
    
    hexa[strlen(hexa)-1]='\0';
    
    a=strlen(hexa)-1;
    int temp2=a;
    char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    for(int i=0;i<=a+1;i++){
        for(int j=0;j<16;j++){
            
            if(hexa[x]==arr[j]){
                temp=j;
                decimal+=temp*pow(16,temp2);
                temp2-=1;
                x++;

            }
           
        }
         
    }
    return decimal;
    

}
void h_to_b(){
    char hexa[100]="";
    
    printf("Enter any hexa-decimal number :");
    getchar();
    fgets(hexa,sizeof(hexa),stdin);
    int a =strlen(hexa);
    for(int i=0;i<a;i++){
        hexa[i]=toupper(hexa[i]);//case insensitive upgrade 
    }
    // char *phexa=hexa;
    int decimal;
    int binary;
    decimal=htod(hexa,a);
    // printf("%d\n",decimal);
    binary=dtob(decimal);
    printf("The Binary Answer is = %d",binary);
}
void h_to_o(){
    char hexa[100]="";
    int decimal;
    int octal=0;
    printf("Enter a Hexa-decimal number :");
    getchar();
    fgets(hexa,sizeof(hexa),stdin);
    int a;
    a=strlen(hexa);
    for(int i=0;i<a;i++){
        hexa[i]=toupper(hexa[i]);//case insensitive upgrade
    }

    decimal=htod(hexa,a);
    int i=0;
    int temp;
    while(decimal!=0){
        temp=decimal%8;
        octal+=temp*pow(10,i);
        decimal/=8;
        i++;

    }
    printf("\nOctal= %d",octal);
    

}