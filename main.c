#include <stdio.h>
#include "myBank.h"

int main()
{
    double amount=0,interest=1; ;
    int acountNumber=0,check=0;
    char opartion= 'a';
    while(opartion != 'E'){
        printf("Insert your Transaction type,one of these:\n");
        printf("O - To open a new account,\n");
        printf("B - To check the balance of specific a account,\n");
        printf("D - To deposit money to the acount and print the new balance,\n");
        printf("W - To pull money from the acount and print the new balance,\n");
        printf("C - To close a open acount,\n");
        printf("I - To add interest to all open acounts,\n"); 
        printf("P - To print the all open acounts,\n");
        printf("E - to close the all open acounts and ent the program\n");
        scanf(" %c",&opartion);
            switch (opartion){
            case 'O' :
                printf("Insert the amount number\n");
                check=scanf("%lf",&amount);
                if(check==1){
                    o_new_account (amount);}break;

            case 'B' :
                printf("Insert the account number between 901 to 950\n");
                check=scanf("%d",&acountNumber);  
                if(check==1){
                    b_balance (acountNumber);} break;

            case 'D' :
                printf("Insert the account number between 901 to 950\n");
                check=scanf("%d",&acountNumber); 
                if(check==1){
                    d_new_balanceDeposit (acountNumber);} break;

            case 'W' :
                printf("Insert the account number between 901 to 950\n");
                check=scanf("%d",&acountNumber); 
                if(check==1){
                    w_new_balancePull (acountNumber);} break;

            case 'C' :
                c_closeAccount (); break;

            case 'I' :
                printf("Insert the interest for all accounts in percent from 0 to 100\n");
                check=scanf("%lf",&interest); 
                if(check==1){
                    i_add_interest (interest);} break;

            case 'P' :
                p_print_all_openAccounts(); break;

            case 'E' :
                e_closeAllAndEnd(); break;

            default :
                printf("YOU INSERT A WRONG OPERATION ! \n");
                printf("Please try again \n"); break;
                } 
            }
    return 0;
}