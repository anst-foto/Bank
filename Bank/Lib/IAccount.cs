namespace Bank.Lib;

public interface IAccount
{
    public void Init(string name, double money = 0);
    public void Deposit(double money);
    public bool Withdraw(double money);
}