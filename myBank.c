#include <stdio.h>
#include "myBank.h"

//1 it's mean that the account is open, 0 it's mean's it's close
#define theAmountCode 1
#define openOrCloseStatusCode 0 
double accounts[accountsSize][openOrCloseSize]={0};

void o_new_account (double amount) 
{
int i=0;
    while(accounts[i][openOrCloseStatusCode]==1)
    //when it will be equals to 1 you can have 
    //a empty place to create a new account 
    {
    i++;
    }//end while
    if(i < 50){
        amount = (int)(amount*100);//to take just the 2 digits after the
        amount/=100;               //decimal point
        accounts[i][theAmountCode]=amount;
        accounts[i][openOrCloseStatusCode]=1;
        i+=901;
        printf("The Account id number is %d\n",i);
    }
    else
    {
        printf("The Bank is full, you can't create your account\n");
    }
}//end void o_new_account

void b_balance (int account_number)
{
    account_number-=901;
    if((account_number>=0) && (account_number<50)){
        //if it's equal to 1 at the place 0 that is openOrCloseStatusCode at the specific account_number
        //it mean's that the account is open, and then print out the account
        if(accounts[account_number][openOrCloseStatusCode]==1){
           printf("The account balance is %.2lf\n",accounts[account_number][theAmountCode]);
        }
        else 
            printf("The account is still close, so can't to print\n");
    }
    else
        printf("The account number id is invalid\n");
}//end b_balance

void d_new_balanceDeposit (int account_number){
    account_number-=901;
    double deposit=0;
    int check=0;//to check if the deposit is currect or not
    if((account_number>=0) && (account_number<50)){
        if(accounts[account_number][openOrCloseStatusCode]==1){
            //if it's equal to 1 at the place 0 that is openOrCloseStatusCode at the specific account_number
            //it mean's that the account is open, and then add the Deposit to the account
            printf("Insert the deposit\n");
            check=scanf("%lf",&deposit); 
            while(check!=1){//if the amount to deposit is incurrect he can try again
               printf("You insert a invalid deposit, please try again"); 
               printf("Insert the deposit\n");
               check=scanf("%lf",&deposit);
            }
            printf("The account old balance is %.2lf\n",accounts[account_number][theAmountCode]);
            accounts[account_number][theAmountCode]+=deposit;
            printf("The account new balance after add is %.2lf\n",accounts[account_number][theAmountCode]);
        }
        else 
            printf("The account is still close, so can't to add balance\n");
    }
    else
        printf("The account number id is invalid\n");
}//end of d_new_balance

void w_new_balancePull (int account_number){
    account_number-=901;
    double pull=0;
    double tempAmount=0;//temp to check if after the pull the acount not at minus
    int check=0;//to check if the deposit is currect or not
        if((account_number>=0) && (account_number<50)){
            if(accounts[account_number][openOrCloseStatusCode]==1){
                //if it's equal to 1 at the place 0 that is openOrCloseStatusCode at the specific account_number
                //it mean's that the account is open, and then subtruct the pull from the account
                printf("Insert the Amount to puling\n");
                check=scanf("%lf",&pull); 
                while (check!=1){//if the amount to pull is incurrect he can try again
                    printf("You insert a invalid puling, please try again"); 
                    printf("Insert the puling\n");
                    check=scanf("%lf",&pull);
                }
                tempAmount=accounts[account_number][theAmountCode]-pull;
                if(tempAmount>=0){
                    printf("The account old balance is %.2lf\n",accounts[account_number][theAmountCode]);
                    accounts[account_number][theAmountCode]-=pull;
                    printf("The account new balance after the pull is %.2lf\n",accounts[account_number][theAmountCode]);
                }
                else
                    printf("You can't pull money from the account because after it you will bt at minus");
            }
            else 
                printf("The account is still close, so you can't to pull from\n");
        }
        else
            printf("The account number id is invalid\n");
}//end of w_new_balancePull

void c_closeAccount (){
    int accountNumber=0;
    int check=0;//to check if account number is currect
    printf("Insert the account nubmer to close\n");
    check=scanf("%d",&accountNumber);
    while(check!=1){//if he put a wrong account number he cna try again
        printf("You put a worng account number, please try again");
        printf("Insert the account nubmer to close\n");
        check=scanf("%d",&accountNumber);
    }
    accountNumber-=901;
    if((accountNumber>=0) && (accountNumber<50)){
        if(accounts[accountNumber][openOrCloseStatusCode]==1){
            //if it's equal to 1 at the place 0 that is openOrCloseStatusCode at the specific account_number
            //it mean's that the account is open, and then you can close the account
            accounts[accountNumber][theAmountCode]=0;
            accounts[accountNumber][openOrCloseStatusCode]=0;//and nullify the account
            accountNumber+=901;
            printf("The Account that was cloused id number is : %d\n",accountNumber);
       }
        else
            printf("The account is already close\n");
    }
    else
        printf("The account number is invalid\n");
}//end c_closeAccount

void i_add_interest (double interest){
    double reaiInterest=(interest/100)+1;
    int count=0;
    for (int i=0; i<accountsSize; i++){
        if(accounts[i][openOrCloseStatusCode]==1){//to check if the bank have at least one account
            accounts[i][theAmountCode]=accounts[i][theAmountCode]*reaiInterest;
            count++;
        }   
    }    
    if(count==0)
        printf("All accounts stil close so you can't add the interest to them\n");
}//i_add_interest

void p_print_all_openAccounts(){
    int count=0;
    for (int i=0; i<accountsSize; i++){
        if(accounts[i][openOrCloseStatusCode]==1){//to check if the bank have at least one account
            printf("The account id is %d and the balance is %.2lf .\n",(i+901),accounts[i][theAmountCode]);
            count++;
        }
    }   
    if(count==0)
        printf("The all accounts are stil close and no have what to print\n");
}//end p_print_all_openAccounts

void e_closeAllAndEnd(){
    for(int n=0;n<accountsSize;n++){
        if(accounts[n][openOrCloseStatusCode]==1){//it mean's the account is open
            accounts[n][openOrCloseStatusCode]=0;
            accounts[n][theAmountCode]=0;
        }
    }
    printf("The program is end's !\n");
}//end e_closeAllAndEnd
