#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class InvalidAmountException: public runtime_error{ //Class that creates invalid amount error
    public:
        InvalidAmountException(const string& msg): runtime_error(msg){}
};

class InsufficientFundsException: public runtime_error{ // class that created insufficient funds error
    public:
        InsufficientFundsException(const string& msg): runtime_error(msg){}
};

class BankAccount{ // bank account class
    private: 
        string actHldName; // string in shorthand for account holder name
        string bankName;
        int actNum; //interger in shorthand for account number.
        double bal; //double for balance
    public:
        BankAccount(const string& hldName, const string& bank, int accNum): actHldName(hldName), bankName(bank), actNum(accNum), bal(0.0){} // constructor
        void deposit(double amt){
            if (amt<=0){
                throw InvalidAmountException("Deposit amount must be positive."); //throws invalid amount error for deposits
            }
            bal+=amt;
            cout << "\nDeposited: " << amt << ", New balance: " << bal << endl;
        }
        
        void withdraw(double amt){
            try{
                if (amt <= 0){
                    throw InvalidAmountException("Withdrawal must be positive"); //throws invalid amount error for withdrawals
                }
                if (amt > bal){
                    throw InsufficientFundsException("Insufficient funds for withdrawal"); //throws insufficient funds error for withdrawal
                }
                bal-=amt;
                cout << "\nWithdrew: " << amt << ", New balance: " << bal << endl; //outputs withdrawn amount, and shows new blance
            }
            catch(const InvalidAmountException& e){ //Catches and throws invalid amount errors
                throw;
            }
            catch(const InsufficientFundsException& e){ //Catches and throws insufficient fund errors
                throw;
            }
        }
        
        void displayBal() const{
            cout << "Current Balance: " << bal << endl;  //This is just a a balance display
        }
};

void performTrans(BankAccount& account){ //This function performs transactions.
    double amt;
    cout << "Enter amount to deposit: ";
    cin >> amt;
    cout << endl;
    account.deposit(amt);
    
    cout << "Enter Amount to withdraw: ";
    cin >> amt;
    cout << endl;
    account.withdraw(amt);
}

int main() {
    while (true){
    string name, bank;
    int actNum;

    //Allows user input for account details.
    cout << "Enter account holder's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter bank name: ";
    cin.ignore();
    getline(cin, bank);
    cout << "Enter account number: ";
    cin >> actNum;
    cout << endl;

    BankAccount act(name, bank, actNum); // holds user information

    //performs transaction with user input.
        while (true){ 

            try{
                performTrans(act);
                act.displayBal();
            }
        
            catch(const InvalidAmountException& e){
                cerr << "Error: " << e.what() << ". Please enter a valid amount." << endl;
                continue; //Allows transaction retry
            }
        
            catch(const InsufficientFundsException& e){
                cerr << "Warning: " << e.what() << ". Funds unavailable." << endl; //log error, continue
            }
        
            catch(const exception& e){
                cerr << "Unexpected Exception: " << e.what() << endl;
                terminate(); //Terminates for unexpected errors
            }
    
            //Below lines allow you to perform more transactions.
            char choice;
            cout << "\nDo you want to perform another transaction? (y/n): ";
            cin >> choice;
            if(choice !='y' && choice !='Y'){
                break;
            }
        }
        
        char moreAct;
        cout << "Do you want to enter another account? (y/n): ";
        cin >> moreAct;
        if(moreAct !='y' && moreAct !='Y'){
            break;
        }
    }

    return 0;
};
