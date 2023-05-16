namespace Bank.Lib.Loggers;

public class LogToConsole : ILogging
{
    private static void WriteToConsole(string message, ConsoleColor color)
    {
        Console.ForegroundColor = color;
        Console.WriteLine(message);
        Console.ResetColor();
    }
    
    public void Info(string message)
    {
        var msg = $"[INFO] {DateTime.Now:G} {message}";
        WriteToConsole(msg, ConsoleColor.Blue);
    }

    public void Error(string message)
    {
        var msg = $"[ERROR] {DateTime.Now:G} {message}";
        WriteToConsole(msg, ConsoleColor.Red);
    }
}