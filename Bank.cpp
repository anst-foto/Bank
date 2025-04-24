#include <iostream>

#include "Bank.h"
#include "AccountWithPassword.h"

#include "ConsoleInput.h"
#include "ConsoleLogger.h"

using namespace std;

int main()
{
    auto logger = new ConsoleLogger();
    auto console = new ConsoleInput();
    
    auto bank = new Bank();

    const auto account1 = new AccountWithPassword(1, "1234", console, logger);
    bank->add(account1);

    const auto account2 = new AccountWithPassword(2, "1234", console, logger);
    bank->add(account2);

    account1->debit(10);
    cout << account1->getNumber() << " " << account1->getBalance() << endl;

    account2->debit(100);
    cout << account2->getNumber() << " " << account2->getBalance() << endl;

    bank->transfer(account2, account1, 50);
    cout << account1->getNumber() << " " << account1->getBalance() << endl;
    cout << account2->getNumber() << " " << account2->getBalance() << endl;
}
