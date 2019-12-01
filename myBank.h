#ifndef myBank
#define myBank

#define accountsSize 50
#define openOrCloseSize 2
extern double accounts[accountsSize][openOrCloseSize];

void o_new_account (double amount);
void b_balance (int account_number);
void d_new_balanceDeposit (int account_number);
void w_new_balancePull (int account_number);
void c_closeAccount ();
void i_add_interest (double interest);
void p_print_all_openAccounts();
void e_closeAllAndEnd();

#endif //myBank