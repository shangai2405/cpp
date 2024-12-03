#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For rand()
#include <sstream> // For string conversion
using namespace std;

class Account {
private:
    string accountnumber;
    string name;
    double balance;

public:
    Account() : accountnumber(""), name(""), balance(0.0) {}

    string to_string(int number) {
        stringstream ss;
        ss << number;
        return ss.str();
    }
    
    string genAccnorandom() {
        string accountnumber = "";
        for (int i = 0; i < 7; ++i) {
            accountnumber += to_string(rand() % 10);
        }
        return accountnumber;
    }

    void createAccount() {
        accountnumber = genAccnorandom();
        cout << "Account Number is: " << accountnumber << "\n";
        cout << "Enter your name: ";
		cin.ignore(); // Clear the input buffer
		getline(cin, name);//This is done so tht you can give your name <space> initial...and tht wouldnt be a prob!
        balance = 0.0;
        ofstream outFile("accounts.txt", ios::app); // Append to file
        if (outFile) {
            outFile << accountnumber << " " << name << " " << balance << endl;
            cout << "Account Created successfully.\n";
        } else {
            cout << "Error saving account information.\n";
        }
        outFile.close();
    }
   
    bool checkaccnumber() {
        string enteredAccNumber;
        cout << "Enter Account Number: ";
        cin >> enteredAccNumber;
        if (enteredAccNumber == accountnumber) {
            return true;
        } else {
            cout << "Invalid Account number.\n";
            return false;
        }
    }

    void deposit() {
        if (checkaccnumber()) {
            double amount;
            cout << "Enter the amount to be deposited: ";
            cin >> amount;
            if (amount > 0) {
                balance += amount;
                cout << "Amount Deposited successfully. New Balance: " << balance << "\n";
            } else {
                cout << "Enter a valid amount to deposit.\n";
            }
        }
    }

    
    void withdraw() {
        if (checkaccnumber()) {
            double withamnt;
            cout << "Enter the amount to withdraw: ";
            cin >> withamnt;
            if (withamnt > 0 && withamnt <= balance) {
                balance -= withamnt;
                cout << "Amount Withdrawn successfully. New Balance: " << balance << "\n";
            } else if (withamnt > balance) {
                cout << "Insufficient balance. Enter a different amount after checking your balance.\n";
            } else {
                cout << "Check the amount entered.\n";
            }
        }
    }

    void displayAccount() {
        if (checkaccnumber()) {
            cout << "Account Number: " << accountnumber << endl;
            cout << "Account Holder's Name: " << name << endl;
            cout << "Balance: " << balance << endl;
        }
    }
};

int main() {
    Account acc; // Create an Account object
    int choice;  // Variable to store user menu choice

    do {
        
        cout << "\n=== Bank Management System ===\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

       
        if (choice == 1) {
            acc.createAccount();
        } else if (choice == 2) {
            acc.deposit();
        } else if (choice == 3) {
            acc.withdraw();
        } else if (choice == 4) {
            acc.displayAccount();
        } else if (choice == 5) {
            cout << "Exiting the program. Goodbye!\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0; 
}

