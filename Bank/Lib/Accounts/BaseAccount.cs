namespace Bank.Lib.Accounts;

public class BaseAccount : IAccount
{
    private string _name;
    private double _money;

    public BaseAccount()
    {
        _money = 0;
    }

    public void Init(string name, double money = 0)
    {
        _name = name;
        _money = money;
    }

    public void Deposit(double money)
    {
        if (money > 0)
        {
            _money += money;
        }
    }

    public bool Withdraw(double money)
    {
        if (money < 0)
        {
            return false;
        }

        if (money > _money)
        {
            return false;
        }

        _money -= money;
        return true;
    }
}