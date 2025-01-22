#include <iostream>

//2043. Simple Bank System
//You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has n accounts numbered from 1 to n. The initial balance of each account is stored in a 0-indexed integer array balance, with the (i + 1)th account having an initial balance of balance[i].Execute all the valid transactions. A transaction is valid if:The given account number(s) are between 1 and n, andThe amount of money withdrawn or transferred from is less than or equal to the balance of the account.

class bank{
private:
    std::unordered_map<long long,long long> account_balance;
    
    static bool is_valid_account_number(int account,size_t size){
        return account >= 1 && account <= size;
    }
    
public:
    bank(const std::vector<long long>& balance){
        for(int i = 0;i<balance.size();i++)
            account_balance[i + 1] = balance[i];
    }
    
    bool transfer(int account1,int account2, long money){
        if(!is_valid_account_number(account1, account_balance.size()) || !is_valid_account_number(account2, account_balance.size()))
            return false;
        if(account_balance[account1] < money)
            return false;
        
        account_balance[account1] -= money;
        account_balance[account2] += money;
        return true;
    }
    
    bool deposit(int account,long money){
        if(!is_valid_account_number(account, account_balance.size()))
            return false;
        account_balance[account] += money;
        return true;
    }
    
    bool withdraw(int account,long money){
        if(!is_valid_account_number(account, account_balance.size()))
            return false;
        if(account_balance[account] < money)
            return false;
        account_balance[account] -= money;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
