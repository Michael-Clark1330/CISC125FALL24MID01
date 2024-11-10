#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// We first can use custom execution classes for invalid amounts/insufficient funds.
class InvalidAmountException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid amount entered. Amount must be positive.";
    }
};

class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds for this withdrawal.";
    }
};

// We then define the "BankAccount" class.
class BankAccount {
private:
    string accountHolderName;
    string bankName;
    int accountNumber;
    double balance;

public:
    // Constructor for the name/bank name/account number/balance.
    BankAccount(string holder, string bank, int accountNum, double initialBalance)
        : accountHolderName(holder), bankName(bank), accountNumber(accountNum), balance(initialBalance) {}

    // Now we add a deposit method, and then a withdraw method!
    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException();
        }
        balance += amount;
        cout << "Deposited: $" << amount << "\n";
    }

    void withdraw(double amount) {
        try {
            if (amount <= 0) {
                throw InvalidAmountException();
            }
            if (amount > balance) {
                throw InsufficientFundsException();
            }
            balance -= amount;
            cout << "Withdrew: $" << amount << "\n";
        } catch (...) {
            // Rethrow the exception to be handled in main
            throw;
        }
    }

    // Then we can add a line for displaying the balance after withdrawing/depositing.
    void displayBalance() const {
        cout << "Current Balance: $" << balance << "\n";
    }
};

// Next is a helper function to perform transactions.
void performTransaction(BankAccount& account) {
    double depositAmount, withdrawAmount;

    cout << "\nEnter deposit amount: ";
    cin >> depositAmount;
    account.deposit(depositAmount);

    cout << "Enter withdrawal amount: ";
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);
}

int main() {
    string name, bank;
    int accNum;
    double initialBalance;

    // The code can then get the user input for account information.
    cout << "Enter account holder's name: ";
    getline(cin, name);
    cout << "Enter bank name: ";
    getline(cin, bank);
    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Then it can create a BankAccount instance with user input.
    BankAccount myAccount(name, bank, accNum, initialBalance);

    try {
        // Displaying the current balance.
        myAccount.displayBalance();

        // Performing deposit and withdrawal with error handling included as well!
        try {
            performTransaction(myAccount);
        } catch (const InvalidAmountException& e) {
            cout << e.what() << " Please enter a valid amount.\n";
        } catch (const InsufficientFundsException& e) {
            cout << e.what() << " Please try a smaller amount.\n";
        }

        // Displaying the balance after transactions are made.
        myAccount.displayBalance();

        // Additional deposit with error handling too.
        try {
            double additionalDeposit;
            cout << "\nEnter an additional deposit amount: ";
            cin >> additionalDeposit;
            myAccount.deposit(additionalDeposit);
        } catch (const InvalidAmountException& e) {
            cout << e.what() << " Retrying with a valid amount.\n";
        }

        try {
            double additionalWithdrawal;
            cout << "Enter an additional withdrawal amount: ";
            cin >> additionalWithdrawal;
            myAccount.withdraw(additionalWithdrawal);
        } catch (const InsufficientFundsException& e) {
            cout << e.what() << " Unable to complete transaction.\n";
        }

        // Lastly, the final display of the balance.
        myAccount.displayBalance();

    } catch (...) {
        cout << "An unexpected error occurred. Terminating program.\n";
        terminate();
    }

    return 0;
}
