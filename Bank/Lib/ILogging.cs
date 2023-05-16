namespace Bank.Lib;

public interface ILogging
{
    public void Info(string message);
    public void Error(string message);
}