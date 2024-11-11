#include <iostream>
#include <exception>
using namespace std;

//making exception classes
class InvalidAmountException : public exception{
public:
    char * what () {
        return "Invalid Amount";
    }
};
class InsufficientFundsException : public exception {
    public:
    char * what () {
        return "Insufficient Funds";
    }
};

//main bank account class
class BankAccount {
private:
    string accountHolderName;
    string bankName;
    int accountNumber;
    double balance;
    double depositI, withdrawI;
    string answer;
    int overdraft = 0;

public:
    //class constructor
    BankAccount() : accountHolderName("N/A"), bankName("N/A"), accountNumber(0), balance(0.0) {}
    
    //function to print information
    void printInfo() {
        cout << "Bank Account Summary:" << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Bank Name: " << bankName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << "\n\n";
    }

    //function to deposit money
    void deposit(double depositM) {
        try{
            if (depositM < 0.0) {
            throw InvalidAmountException();
            }

            balance += depositM;
        }

        catch (...) {
            throw;
        }
    }

    //function to withdraw money
    void withdraw(double withdrawM) {
        try {
            if (withdrawM > balance) {
                throw InsufficientFundsException();
            }

            else if (withdrawM < 0.0) {
                throw InvalidAmountException();
            }

            balance -= withdrawM;
        }
        
        catch (InsufficientFundsException) {
            overdraft++;
            throw;
        }
        
        catch (...) {
            throw;
        }
    }

    //main function to get info and perform transactions
    void performTransaction() {
        cout << "Enter your name: ";
        getline(cin, accountHolderName);
        cout << "Enter bank name: ";
        getline(cin, bankName); 
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter initial balance: ";
        cin >> balance;
        cout << "Enter deposit amount: ";
        cin >> depositI;
        cout << "Enter withdraw number: ";
        cin >> withdrawI;
        cout << "\n";
        try {
            deposit(depositI);
            withdraw(withdrawI);
            printInfo();
        }
        
        catch (...) {
            throw;
        }
    }
};


int main() {
char go = 'y';

//keeps interface running until error or prompt to stop
while (go == 'y') {
    try{
        BankAccount person1;
        person1.performTransaction();
    }

    catch (InvalidAmountException) {
        cout << "Invalid amount entered! Please retry.\n" << endl;
    }

    catch (InsufficientFundsException) {
        cout << "Insufficient funds for this withdraw! Please retry.\n" << endl;
    }

    catch (...) {
        cout << "Unknown Error";
        terminate();
    }

    cout << "Would you like to enter another account? (y/n): ";
    cin >> go;
    cout << "\n";
    cin.ignore();
}

//exit message
cout << "Thank you for using the Bank Account Manager!\n\n";
return 0;

}
