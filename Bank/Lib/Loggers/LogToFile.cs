namespace Bank.Lib.Loggers;

public class LogToFile : ILogging
{
    private readonly string _path;

    public LogToFile(string path = "log.txt")
    {
        _path = path;
    }

    private void WriteToFile(string message)
    {
        var file = new StreamWriter(_path, append: true);
        file.WriteLine(message);
        file.Close();
    }

    public void Info(string message)
    {
        var msg = $"[INFO] {DateTime.Now:G} {message}";
        WriteToFile(msg);
    }

    public void Error(string message)
    {
        var msg = $"[ERROR] {DateTime.Now:G} {message}";
        WriteToFile(msg);
    }
}