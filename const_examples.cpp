/**
 * constの使用例を示すサンプルコード集
 */
#include <iostream>
#include <string>
#include <vector>

// 1. グローバル定数の例
const int MAX_PLAYERS = 4;
const double PI = 3.14159;

// 2. クラスでのconst使用例
class BankAccount {
private:
    const std::string accountNumber;  // 口座番号は変更不可
    double balance;
    mutable int accessCount;  // constメンバ関数内でも変更可能

public:
    BankAccount(const std::string& number, double initialBalance)
        : accountNumber(number)  // const メンバは初期化子リストで初期化
        , balance(initialBalance)
        , accessCount(0)
    {}

    // constメンバ関数の例
    double getBalance() const {
        accessCount++;  // mutableなので変更可能
        return balance;
    }

    const std::string& getAccountNumber() const {
        return accountNumber;
    }

    // 非constメンバ関数の例
    void deposit(double amount) {
        balance += amount;
    }

    // constと非constのオーバーロード例
    const std::vector<std::string>& getTransactionHistory() const {
        accessCount++;
        return transactionHistory;
    }

    std::vector<std::string>& getTransactionHistory() {
        accessCount++;
        return transactionHistory;
    }

private:
    std::vector<std::string> transactionHistory;
};

// 3. const参照を使用する関数の例
void displayAccountInfo(const BankAccount& account) {
    // account.deposit(100);  // エラー: constオブジェクトでは非constメンバ関数は呼び出せない
    std::cout << "口座番号: " << account.getAccountNumber() << std::endl;
    std::cout << "残高: " << account.getBalance() << std::endl;
}

// 4. constポインタの例を示す関数
void demonstrateConstPointers() {
    int value = 42;
    int another = 100;

    // データが const (ポインタが指す先は変更不可)
    const int* ptr1 = &value;
    // *ptr1 = 43;  // エラー: データを変更できない
    ptr1 = &another;  // OK: ポインタ自体は変更可能

    // ポインタ自体が const
    int* const ptr2 = &value;
    *ptr2 = 43;  // OK: データは変更可能
    // ptr2 = &another;  // エラー: ポインタを変更できない

    // データとポインタの両方が const
    const int* const ptr3 = &value;
    // *ptr3 = 43;      // エラー: データを変更できない
    // ptr3 = &another; // エラー: ポインタを変更できない
}

int main() {
    BankAccount account("1234-5678", 1000.0);
    
    // constオブジェクトの例
    const BankAccount constAccount("8765-4321", 2000.0);
    std::cout << "Const account balance: " << constAccount.getBalance() << std::endl;
    // constAccount.deposit(100);  // エラー: constオブジェクトでは非constメンバ関数は呼び出せない

    // 通常のオブジェクトでの操作
    account.deposit(500);
    displayAccountInfo(account);

    demonstrateConstPointers();

    return 0;
} 