#include <iostream>
#include <iomanip>

using namespace std;

void show_balance(double balance);
double withdraw(double balance);
double deposit();

int main()
{
    double balance = 0;
    int choice = 0;

    cout << "*******************************************\n"
         << "WELCOME TO SPAMTON BANK, ENTER YOUR CHOICE!\n"
         << "*******************************************\n";
      

    do{ 
        cout << "-------------------------------------------\n"
             << "1. SHOW BALANCE\n"
             << "2. WITHDRAW KROMERS\n" 
             << "3. DEPOSIT KROMERS\n"
             << "4. EXIT (no, please come back!!)\n";
        
        cin >> choice;

        cin.clear();
        fflush(stdin);

        switch(choice){
            case 1: 
            show_balance(balance);
                break;
            case 2: 
            balance -= withdraw(balance);
            show_balance(balance);
                break;
            case 3: 
            balance += deposit();
            show_balance(balance);
                break;
            case 4: 
            cout << "************************\n"
                 << "THANKS FOR YOUR KROMERS!\n"
                 << "************************\n";
                break;
            default: 
            cout << "*********************************\n"
                 << "INVALID CHOICE, PLEASE TRY AGAIN!\n"
                 << "*********************************\n";
                break;
        }
    }while(choice != 4);

    return 0;
}

void show_balance(double balance)
{
    cout << "YOUR (KROMER) BALANCE IS: $K" << setprecision(2) << fixed
         << balance << '\n';
    return;
}
double withdraw(double balance)
{
    double amount = 0;

    cout << "ENTER AMOUNT (KROMER) YOU WISH TO WITHDRAW: $K";
    cin >> amount;

    if (amount > balance) {
        cout << "INSUFFICIENT KROMERS!! \n";
        return 0;
    }
    else if (amount < 0){
        cout << "THAT'S NOT A VALID AMOUNT! \n";
        return 0;
    }
    else {
        return amount;
    }
}
double deposit()
{
    double amount = 0;

    cout << "ENTER AMOUNT (KROMER) YOU WISH TO DEPOSIT: $K";
    cin >> amount;

    if (amount > 0) {
        return amount;
    }
    else {
        cout << "THAT'S NOT A VALID AMOUNT!! \n";
        return 0;
    }
}