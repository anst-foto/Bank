namespace Bank.Lib.Accounts;

public class ProxyAccount : IAccount
{
    private readonly IAccount _account;
    private readonly List<ILogging> _loggers;

    public ProxyAccount()
    {
        _account = new BaseAccount();
        _loggers = new List<ILogging>();
    }

    public void AddLogger(ILogging logger)
    {
        _loggers.Add(logger);
    }
    
    public void Init(string name, double money = 0)
    {
        foreach (var logger in _loggers)
        {
            logger.Info($"Init account: {name}, {money}");
        }
        _account.Init(name, money);
    }

    public void Deposit(double money)
    {
        foreach (var logger in _loggers)
        {
            logger.Info($"Deposit: {money}");
        }
        _account.Deposit(money);
    }

    public bool Withdraw(double money)
    {
        var result = _account.Withdraw(money);
        if (result)
        {
            foreach (var logger in _loggers)
            {
                logger.Info($"Withdraw: {money}");
            }

            return true;
        }
        else
        {
            foreach (var logger in _loggers)
            {
                logger.Error($"Withdraw: {money}");
            }

            return false;
        }
    }
}