#include <iostream>
#include <exception>
#include <string>
#include <limits>

// Custom Exception Classes
class InvalidAmountException : public std:: exception {
    public: 
    const char*what() const noexcept override{
    return "Invalid Amount entered";}
};

class InsufficientFundsException : public std:: exception{
    public:
    const char* what() const noexcept override{ // the onexcept keyworkd tells the compiler that the function what is not going to throw any exceptions itself
        return " Insufficient funds!"; //the override keyword ensures that the what function overrides a virtual function from the std:: exception class. This ensures that th what() in our class is called and not the what from the base class.
    }

};
// BankAccount Class
class BankAccount {
private:
    std::string accountHolderName;
    std::string bankName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& holder, const std::string& bank, int accNumber, double initialBalance)
        : accountHolderName(holder), bankName(bank), accountNumber(accNumber), balance(initialBalance) {}

    // Deposit method
    void deposit(double amount) {
        if (amount < 0) {
            throw InvalidAmountException();
        }
        balance += amount;
        std::cout << "Deposited: $" << amount << std::endl;
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount < 0) {
            throw InvalidAmountException();
        }
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        std::cout << "Withdrew: $" << amount << std::endl;
    }

    // Display account summary
    void displayAccountSummary() const {
        std::cout << "\nBank Account Summary:\n";
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Bank Name: " << bankName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }
};

// Function to get user input for a transaction
void performTransaction(BankAccount& account) {
    double depositAmount, withdrawAmount;

    try {
        // Deposit
        std::cout << "Enter deposit amount: $";
        std::cin >> depositAmount;
        account.deposit(depositAmount);

        // Withdraw
        std::cout << "Enter withdraw amount: $";
        std::cin >> withdrawAmount;
        account.withdraw(withdrawAmount);

    } catch (const InvalidAmountException& e) {
        std::cerr << e.what() << " Please enter a valid amount.\n";
    } catch (const InsufficientFundsException& e) {
        std::cerr << e.what() << " Transaction declined.\n";
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    account.displayAccountSummary();
}

// Main Program
int main() {
    char anotherAccount = 'Y';

    while (anotherAccount == 'Y' || anotherAccount == 'y') {
        std::string name, bankName;
        int accountNumber;
        double initialBalance;

        // Get account details from user
        std::cout << "\nEnter your name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        std::getline(std::cin, name);

        std::cout << "Enter bank name: ";
        std::getline(std::cin, bankName);

        std::cout << "Enter account number: ";
        std::cin >> accountNumber;

        std::cout << "Enter initial balance: $";
        std::cin >> initialBalance;

        // Create a new BankAccount instance
        BankAccount account(name, bankName, accountNumber, initialBalance);

        // Perform deposit and withdrawal transactions
        performTransaction(account);

        // Ask if user wants to enter another account
        std::cout << "\nWould you like to enter another account? (Y/N): ";
        std::cin >> anotherAccount;
    }

    std::cout << "\nThank you for using the Bank Account Manager!" << std::endl;
    return 0;
}

