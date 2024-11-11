#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 10000;  // Maximum number of accounts allowed

// Custom exception classes
class InvalidAmountException : public runtime_error {
public:
    InvalidAmountException(const string& message) : runtime_error(message) {}
};

class InsufficientFundsException : public runtime_error {
public:
    InsufficientFundsException(const string& message) : runtime_error(message) {}
};

// BankAccount class
class BankAccount {
private:
    string accountHolderName;
    string bankName;
    int accountNumber;
    double balance;

// Default constructor
public:
    BankAccount() : accountHolderName(""), bankName(""), accountNumber(0), balance(0.0) {} 
    BankAccount(string name, string bank, int number, double initialBalance = 0.0)
        : accountHolderName(name), bankName(bank), accountNumber(number), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException("Deposit amount must be positive.");
        }
        balance += amount;
        cout << "Deposit successful! New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw InsufficientFundsException("Insufficient funds for this withdrawal.");
        }
        balance -= amount;
        cout << "Withdrawal successful! New balance: $" << balance << endl;
    }

    void displayBalance() const {
        cout << "Current balance: $" << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    string getBankName() const {
        return bankName;
    }
};

// Function to perform transactions
void performTransaction(BankAccount& account, double amount, bool isDeposit) {
    try {
        if (isDeposit) {
            account.deposit(amount);
        } else {
            account.withdraw(amount);
        }
    } catch (...) {
        throw; // Rethrow any exception to be handled in the main
    }
}

int main() {
    BankAccount accounts[MAX_ACCOUNTS];  // Array to hold bank accounts, though I do not think it would be applicable in the real world to have a maximum number of accounts. 
    int accountCounter = 0;  // Counter to track the number of created accounts

    while (true) {
        int choice;
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n2. Select Account\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) break;

        switch (choice) {
            case 1: {
                // How to create a new account
                char addAnother = 'Y';
                while (addAnother == 'Y' || addAnother == 'y') {
                    if (accountCounter >= MAX_ACCOUNTS) {
                        cout << "Maximum number of accounts reached. Cannot create more accounts." << endl;
                        break;
                    }

                    string name, bank;
                    double initialDeposit;

                    cout << "Enter account holder's name: ";
                    cin.ignore(); // Ignore the newline character from previous input
                    getline(cin, name);

                    cout << "Enter bank name: ";
                    getline(cin, bank);

                    cout << "Enter initial deposit: ";
                    cin >> initialDeposit;

                    try {
                        if (initialDeposit < 0) {
                            throw InvalidAmountException("Initial deposit cannot be negative.");
                        }
                        accounts[accountCounter] = BankAccount(name, bank, accountCounter + 1, initialDeposit);
                        cout << "Account created successfully! Account Number: " << accountCounter + 1 << endl;
                        accountCounter++;
                    } catch (const InvalidAmountException& e) {
                        cout << "Error: " << e.what() << endl;
                    }

                    // Prompt to enter another account
                    cout << "Would you like to enter another account? (Y/N): ";
                    cin >> addAnother;
                }
                break;
            }
            case 2: {
                if (accountCounter == 0) {
                    cout << "No accounts available. Please create an account first." << endl;
                    break;
                }

                // Displaying available accounts
                cout << "\nAvailable Accounts:\n";
                for (int i = 0; i < accountCounter; ++i) {
                    cout << "Account Number: " << accounts[i].getAccountNumber()
                         << ", Account Holder: " << accounts[i].getAccountHolderName()
                         << ", Bank: " << accounts[i].getBankName() << endl;
                }

                int accountNumber;
                cout << "Enter account number to select: ";
                cin >> accountNumber;

                BankAccount* selectedAccount = nullptr;
                for (int i = 0; i < accountCounter; ++i) {
                    if (accounts[i].getAccountNumber() == accountNumber) {
                        selectedAccount = &accounts[i];
                        break;
                    }
                }

                if (selectedAccount == nullptr) {
                    cout << "Account not found." << endl;
                    break;
                }

                // Transaction menu for the selected account
                while (true) {
                    int transactionChoice;
                    cout << "\nTransaction Menu:\n";
                    cout << "1. Deposit\n2. Withdraw\n3. Display Balance\n4. Go Back\n";
                    cout << "Enter your choice: ";
                    cin >> transactionChoice;

                    if (transactionChoice == 4) break;

                    double amount;
                    cout << "Enter amount: ";
                    cin >> amount;

                    try {
                        switch (transactionChoice) {
                            case 1:
                                performTransaction(*selectedAccount, amount, true);
                                break;
                            case 2:
                                performTransaction(*selectedAccount, amount, false);
                                break;
                            case 3:
                                selectedAccount->displayBalance();
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    catch (const InvalidAmountException& e) {
                        cout << "Error: " << e.what() << endl;
                        cout << "Please enter a valid amount.\n";
                    }
                    catch (const InsufficientFundsException& e) {
                        cout << "Error: " << e.what() << endl;
                        cout << "Please try a different transaction.\n";
                    }
                    catch (...) {
                        cout << "Unexpected error occurred. Terminating program.\n";
                        terminate();
                    }
                }
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    cout << "Thank you for using this banking system. Have a nice day!\n";
    return 0;
}
