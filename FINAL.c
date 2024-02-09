// title:-
//      ******CYPHER PROJECT*****
// mini-project by Sanskar, Prashil and Rashid of Sem-2, Section E.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void start();
void perform(int);
void encrypt();
void decrypt();
void file_redirect(char []);
void request_redirect(char []);


int main()
{

    // calling the function start() to initiate the program
    start();
}


//definition of start() function
void start()
{

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
void perform(int task)
{

    switch(task)
    {
        case 1://1 is for encryption
        encrypt();
        break;
        case 2://2 is for decryption
        decrypt();
        break;
        case 3://3 is for closing the program
        printf("closing...\n");
        break;
        default://for any unwanted values entered
        printf("Invalid task!\n");
        start();
    }
}


//definition of encrypt() function
void encrypt()
{

    char user_str[100], *s;
    char file_adress[100];
    int shift_amount=0;
    s=user_str;

    //asking how the user wants to give the string
    int ans_input;
    printf("\nSelect option:\n1)import text from file 2)Enter text\n");
    scanf("%d",&ans_input);

    //using a buffer getchar() statement, as scanf also returns a \n after reading which doesnt let fgets() work
    char buffer=getchar();

    switch(ans_input)
    {
        case 1:
        printf("Enter the file adress:\n");
        gets(file_adress);
        
        //opening the file in read mode
        FILE *fp=fopen(file_adress,"r");

        if(fp==NULL)//for error in opening the file
        {
            printf("couldn't open the file");
            fclose(fp);//closing the opened file 
            encrypt();           
        }
        else//for printing the string in the file
        {   
            fgets(user_str,100,fp);
            fclose(fp);//closing the opened file
        }
        break;

        case 2:
        //taking the string input
        printf("\nEnter the string to be encrypted:\n");
        scanf("%[^\n]s",user_str);
        break;

        default:
        printf("Invalid input!");
        encrypt();

    }

    //taking number of shifts 
    printf("enter the number of shifts you want to do:\n");
    scanf("%d",&shift_amount);

    //using a buffer getchar() statement, as scanf also returns a \n after reading which doesnt let fgets() work
    buffer=getchar();

    //changing and printing the string
    printf("\nthe encrypted string is as follows:\n");
    while(*s!='\0')
    {
        *s = *s + shift_amount;
        printf("%c",*s);
        s++;
    }
    printf("\n\n");

    //requesting redirection
    request_redirect(user_str);

    //to run the software again
    start();
}


//definition of decrypt() function
void decrypt()
{

    char user_str[100], *s;
    char file_adress[100];
    int shift_amount=0;
    s=user_str;

    //asking how the user wants to give the string
    int ans_input;
    printf("\nSelect option:\n1)import text from file 2)Enter text\n");
    scanf("%d",&ans_input);

    //using a buffer getchar() statement, as scanf also returns a \n after reading which doesnt let fgets() work
    char buffer=getchar();

    switch(ans_input)
    {
        case 1:
        printf("Enter the file adress:\n");
        gets(file_adress);
        
        //opening the file in read mode
        FILE *fp=fopen(file_adress,"r");

        if(fp==NULL)//for error in opening the file
        {
            printf("couldn't open the file");
            fclose(fp);//closing the opened file
            decrypt();
        }
        else//for printing the string in the file
        {   
            fgets(user_str,100,fp);
            fclose(fp);//closing the opened file
        }
        break;

        case 2:
        //taking the string input
        printf("\nEnter the string to be decrypted:\n");
        scanf("%[^\n]s",user_str);
        break;

        default:
        printf("Invalid input!");
        decrypt();

    }

    //taking number of shifts 
    printf("enter the number of shifts you want to do:\n");
    scanf("%d",&shift_amount);

    //using a buffer getchar() statement, as scanf also returns a \n after reading which doesnt let fgets() work
    buffer=getchar();

    //changing and printing the string
    printf("\nthe decrypted string is as follows:\n");
    while(*s!='\0')
    {
        *s = *s - shift_amount;
        printf("%c",*s);
        s++;
    }
    printf("\n\n");

    //requesting redirection
    request_redirect(user_str);

    //to run the software again
    start();
    
}


//definition of file_redirect() function
void file_redirect(char message[])
{
    char file_adress[100];
    printf("Enter the file adress:\n");
    gets(file_adress);
        
    //opening the file in read mode
    FILE *fp=fopen(file_adress,"w");

    if(fp==NULL)//for error in opening the file
    {
        printf("couldn't open the file");
    }
    else//for printing the string in the file
    {
        fputs(message,fp);
        printf("The output has been redirected to the %s.\n", file_adress);
    }
    fclose(fp);//closing the opened file
}


// defintion of request_redirect() function
void request_redirect(char message[])
{

    //asking if redirection to file is required
    char ans_redirect;
    printf("Do you want to store the output in a file?(y/n)\n");
    scanf("%c",&ans_redirect);

    //using a buffer getchar() statement, as scanf also returns a \n after reading which doesnt let fgets() work
    char buffer=getchar();

    // using switch case so that conditions can be satisfied
    switch(ans_redirect)
    {
        case 'y':
        file_redirect(message);
        break;
        case 'n':
        printf("No redirection performed.\n");
        break;
        default:
        printf("Invalid reply!\n");
        request_redirect(message);
    }
}

