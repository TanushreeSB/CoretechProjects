#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
using namespace std;

vector<string> transactionLog;

string getCurrentTime() {
    auto now = chrono::system_clock::now();
    auto time_t_now = chrono::system_clock::to_time_t(now);
    return string(ctime(&time_t_now));
}

void logTransaction(const string& transaction) {
    transactionLog.push_back(getCurrentTime() + " - " + transaction);
    cout << getCurrentTime() << " - " << transaction << endl;
}

class BankAccount {
private:
    double balance;
    int accountNumber;
    static int nextAccountNumber;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {
        accountNumber = nextAccountNumber++;
    }

    double getBalance() {
        return balance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) {
        balance += amount;
        logTransaction("Deposited Rs." + to_string(amount));
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            logTransaction("Withdrawal failed. Insufficient funds.");
            return false;
        }
        balance -= amount;
        logTransaction("Withdrew Rs." + to_string(amount));
        return true;
    }

    bool transfer(BankAccount* otherAccount, double amount) {
        if (this->withdraw(amount)) {
            otherAccount->deposit(amount);
            logTransaction("Transferred Rs." + to_string(amount) + " to account number " + to_string(otherAccount->getAccountNumber()));
            return true;
        }
        return false;
    }

    void applyInterest(double rate) {
        double interest = balance * rate / 100;
        balance += interest;
        logTransaction("Applied interest of Rs." + to_string(interest));
    }

    void printTransactionHistory() {
        cout << "\nTransaction History for Account " << accountNumber << ":\n";
        for (const auto& log : transactionLog) {
            if (log.find(to_string(accountNumber)) != string::npos) {
                cout << log << endl;
            }
        }
    }
};

int BankAccount::nextAccountNumber = 1000;

class Bank {
private:
    vector<BankAccount*> accounts;

public:
    void addAccount(BankAccount* account) {
        accounts.push_back(account);
    }

    BankAccount* getAccount(int accountNumber) {
        for (auto& account : accounts) {
            if (account->getAccountNumber() == accountNumber) {
                return account;
            }
        }
        return nullptr;
    }

    void deleteAccount(int accountNumber) {
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if ((*it)->getAccountNumber() == accountNumber) {
                accounts.erase(it);
                logTransaction("Account number " + to_string(accountNumber) + " deleted.");
                cout << "Account number " << accountNumber << " has been deleted.\n";
                return;
            }
        }
        cout << "Account number " << accountNumber << " not found.\n";
    }

    void printAllAccounts() {
        if (accounts.empty()) {
            cout << "No accounts available.\n";
            return;
        }
        cout << "\nAll Accounts:\n";
        for (const auto& account : accounts) {
            cout << "Account Number: " << account->getAccountNumber() << ", Balance: Rs." << account->getBalance() << endl;
        }
    }
};

class Customer {
private:
    BankAccount* account;
    string name;

public:
    Customer(BankAccount* acc, const string& customerName) : account(acc), name(customerName) {}

    void performTransactions(Bank& bank) {
        int choice;
        double amount;

        cout << "\n" << name << ", choose an action:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer to another account\n";
        cout << "4. View balance\n";
        cout << "5. Apply Interest\n";
        cout << "6. View transaction history\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: Rs.";
                cin >> amount;
                account->deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: Rs.";
                cin >> amount;
                if (!account->withdraw(amount)) {
                    cout << name << ": Insufficient funds to withdraw Rs." << amount << ".\n";
                }
                break;
            case 3: {
                cout << "Enter account number to transfer to: ";
                int targetAccountNumber;
                cin >> targetAccountNumber;
                BankAccount* targetAccount = bank.getAccount(targetAccountNumber);
                if (targetAccount) {
                    cout << "Enter amount to transfer: Rs.";
                    cin >> amount;
                    account->transfer(targetAccount, amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 4:
                cout << name << " balance: Rs." << account->getBalance() << "\n";
                break;
            case 5:
                cout << "Enter interest rate (%): ";
                double rate;
                cin >> rate;
                account->applyInterest(rate);
                break;
            case 6:
                account->printTransactionHistory();
                break;
            case 7:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }
};

int main() {
    Bank bank;
    BankAccount account1(500);
    BankAccount account2(300);
    bank.addAccount(&account1);
    bank.addAccount(&account2);

    Customer customer1(&account1, "Aarav");
    Customer customer2(&account2, "Priya");

    int choice;
    while (true) {
        cout << "\nWelcome to the Bank\n";
        cout << "1. Aarav's account\n";
        cout << "2. Priya's account\n";
        cout << "3. Create a new account\n";
        cout << "4. Delete an account\n";
        cout << "5. View all accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            customer1.performTransactions(bank);
        } else if (choice == 2) {
            customer2.performTransactions(bank);
        } else if (choice == 3) {
            double initialBalance;
            cout << "Enter initial balance for new account: Rs.";
            cin >> initialBalance;
            BankAccount* newAccount = new BankAccount(initialBalance);
            bank.addAccount(newAccount);
            cout << "New account created with Account Number: " << newAccount->getAccountNumber() << "\n";
        } else if (choice == 4) {
            int accountNumber;
            cout << "Enter account number to delete: ";
            cin >> accountNumber;
            bank.deleteAccount(accountNumber);
        } else if (choice == 5) {
            bank.printAllAccounts();
        } else if (choice == 6) {
            cout << "Exiting the system...\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
