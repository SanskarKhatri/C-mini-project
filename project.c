#include<stdio.h>
#include<string.h>
#include<ctype.h>
int indexof(char [100], char);
void start();
void perform(int);
void encrypt();
void decrypt();
/* updates or changes to be made:
capital letters*/

int main(){
    start();
}

//definition of indexof() function
int indexof(char p[100], char x){
    int i=0;
    while(p[i] != x)
    {
        i++;
    }
    return i;
}
//definition of start() function
void start(){
    int task;
    // taking task input
    printf("\nWhat task do you want to perform?\n");
    printf("1)Encryption 2)Decryption 3)Quit\n");
    scanf("%d",&task);

    //using a buffer getchar() statement, as scanf also returns a \n after reading which doesnt let fgets() work
    char buffer=getchar();

    //to perform the task
    perform(task);
}
//definition of perform() function
void perform(int task){
    switch(task){
        case 1:
        encrypt();
        break;
        case 2:
        decrypt();
        break;
        case 3:
        printf("closing...\n");
        break;
        default:
        printf("Invalid task!");
    }
}
//definition of encrypt() function
void encrypt(){
    char a[100]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char user_str[100], *s;
    int shift_amount=0;
    s=user_str;
    //taking the string input
    printf("\nEnter the string to be encrypted:\n");
    scanf("%[^\n]s",user_str);
    //taking number of shifts 
    printf("enter the number of shifts you want to do:\n");
    scanf("%d",&shift_amount);
    //checking if shift<=26 and >=0
    if ((shift_amount>26) || (shift_amount<0)){
        printf("Invalid!! shift amount should be >=0 and <=26\n");
        printf("Restarting...\n");
        start();
    }
    else {
        int old_position, p;
        char new_char;
        printf("\nthe encrypted string is as follows(shift amount should be >=0 and <=26):\n");
        while(*s!='\0'){
            if(isalpha(*s)!=0){
                old_position=indexof(a,*s);
                p=old_position+shift_amount;
                new_char=a[p];
                printf("%c",new_char);
                s++;
            }
            else {
                printf("%c",*s);
                s++;
            }
        }
        printf("\n");

        //to run the software again:
        start();
    }
    
}
//definition of decrypt() function
void decrypt(){
    char a[100]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char user_str[100], *s;
    int shift_amount=0;
    s=user_str;
    //taking the string input
    printf("\nEnter the string to be decrypted:\n");
    scanf("%[^\n]s",user_str);
    //taking number of shifts 
    printf("enter the number of shifts you want to do(shift amount should be >=0 and <=26):\n");
    scanf("%d",&shift_amount);
    //checking if shift<=26 and >=0
    if ((shift_amount>26) || (shift_amount<0)){
        printf("Invalid!! shift amount should be >=0 and <=26\n");
        printf("Restarting...\n");
        start();
    }
    else {
        int old_position, p;
        char new_char;
        printf("\nthe encrypted string is as follows:\n");
        while(*s!='\0'){
            if(isalpha(*s)!=0){
                old_position=indexof(a,*s);
                p=old_position-shift_amount+26;
                new_char=a[p];
                printf("%c",new_char);
                s++;
            }
            else {
                printf("%c",*s);
                s++;
            }
        }
        printf("\n");

        //to run the software again:
        start();
    }
    
}
