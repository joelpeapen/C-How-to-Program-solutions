// determine whether a department - store customer has exceeded the credit limit on a charge account
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int acc = 0;
    double balance_begin = 0, total_charge = 0, total_credits = 0, credit_limit = 0;

    while (acc != -1) {
        // accept
        printf("%s", "Enter account number (-1 to end): ");
        scanf("%d", &acc);
        if (acc == -1) {
            break;
        }

        printf("%s", "Enter beginning balance: ");
        scanf("%lf", &balance_begin);
        printf("%s", "Enter total charges: ");
        scanf("%lf", &total_charge);
        printf("%s", "Enter total credits: ");
        scanf("%lf", &total_credits);
        printf("%s", "Enter credit limit: ");
        scanf("%lf", &credit_limit);

        // print
        double new_balance = balance_begin + total_charge - total_credits;
        printf("Account:\t%d\n", acc);
        printf("Credit limit:\t%lf\n", credit_limit);
        printf("Balance:\t%lf\n", new_balance);

        if (new_balance > credit_limit) {
            printf("Credit Limit Exceeded\n");
        }
    }

    return 0;
}
