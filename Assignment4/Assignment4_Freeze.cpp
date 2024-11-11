#include<iostream>
#include <stdexcept>
#include <string>

/*1. Define Custom Exception Classes:
- Create two custom exception classes:
- `InvalidAmountException`: Triggered if a user tries to deposit or withdraw an
 invalid amount (like negative values).
- `InsufficientFundsException`: Triggered when a withdrawal exceeds the account
 balance.
*/

class Invalid_Amount : public std::exception{
    public: const char* what() const noexcept override {
        return "Error: Invalid amount. Amount must be positive.";
};
};
class Insufficent_Funds : public std::exception {
    public: const char* what() const noexcept override {
        return "Error: Insufficent funds for this withdrawl.";
};
};
/* 2. Define a BankAccount Class:
- Implement a class `BankAccount` that includes:
- Attributes:
private:
std::string accountHolderName;
std::string bankName;
int accountNumber;
balance` (double)*/
class Bank_Account{
    private:
       std::string m_Account_Holder_Name;
       std::string m_Bank_Name;
        int m_Account_Number;
        double m_Balance;
    public: 
        Bank_Account(std::string Customer_Name, std::string Bank, int Acc_Number, double Initial_Balance): 
            m_Account_Holder_Name(Customer_Name),m_Bank_Name(Bank),m_Account_Number(Acc_Number), m_Balance(Initial_Balance){}
       /*- `deposit(double amount)`: Adds the amount to the balance. Should throw 
`InvalidAmountException` for invalid deposits. 
DEPOSIT*/

        void Deposit(double Amount){
            if (Amount <= 0){
                throw Invalid_Amount();
            }
               m_Balance += Amount;
              std::cout << "Deposited $" << Amount << ". Current Balance: $" << m_Balance << std::endl;
        }

        void Withdraw( double Amount) {
            try{
                if (Amount <=0){
                    throw Invalid_Amount();

                }
                if (Amount > m_Balance){
                    throw Insufficent_Funds();
                }
                m_Balance -= Amount; 
                std::cout << "Withdrew $" << Amount << ". Current Balance: $" << m_Balance << std::endl;
                }
            catch (const std::exception& except){
                    throw except;
                }
        }
        void Display_Balance() const{
            std::cout << "Current Balance: $" << m_Balance << std::endl;
        }
};
        void Perform_Transaction(Bank_Account Account, double Paycheck, double Bills){
            try{
                Account.Deposit(Paycheck);   
            }
            catch (const std::exception& except){
                throw except;
   
            }
            try{
                Account.Withdraw(Bills);
            }
            catch (const std::exception& except){
                throw except;
            }

        }


        
int main()
{
    double Deposit_Amount;
    double Withdraw_Amount;
    std::string Checker = "y";
    std::string Name; 
    std::string Bank_Name;
    int Account_Num;
    double Balance;
   
    

while(Checker == "y"|| Checker == "Y"|| Checker == "Yes"|| Checker == "yes"){
    std::cout << "Enter your name:";
    std::cin >> Name;
    std::cout << "Enter your Bank Name:";
    std::cin >> Bank_Name;
    std::cout << std::endl;
    std::cout << "Enter your Account Number:";
    std::cin >> Account_Num;
    std::cout << "Enter intial Balance:";
    std::cin >> Balance;
    std::cout << "Enter Deposit Amount:"; 
    std::cin >> Deposit_Amount;
    std::cout << "Enter Withdraw Amount:";
    std::cin >> Withdraw_Amount;
    
    
    Bank_Account My_Account(Name, Bank_Name,Account_Num,Balance);

     try {
        Perform_Transaction(My_Account, Deposit_Amount, Withdraw_Amount);  // Perform transactions
        std::cout << "Bank Account Summary:" << std::endl;
        std::cout << "Account Holder: " << Name << std::endl;
        std::cout << "Bank Name: " << Bank_Name << std::endl;
        std::cout << "Account Number: " << Account_Num << std::endl;
        My_Account.Display_Balance();
    } catch (const Invalid_Amount& except) {
        // Fix error: prompt user to enter valid amount and retry
       std::cout << except.what() << std::endl;
       std::cout << "Please enter a valid amount and try again." << std::endl;
    } catch (const Insufficent_Funds& except) {
        // Log the error and continue
        std::cout << except.what() << std::endl;
        std::cout << "Please check your balance and try again." << std::endl;
    } catch (const std::exception& except) {
        // Unexpected error: terminate the program
        std::cout << "Unexpected error occurred: " << except.what() << std::endl;
        std::terminate();
    }
    


    std::cout << "Would you like to enter another account? (Y/N):" << std::endl; 
}


    return 0;

};
