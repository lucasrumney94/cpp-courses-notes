
#include <iostream>

class Log
{

// public member variables
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;

// private member variables
private:
	// use m to prefix class _m_ember variable that is private
	// and thus probably should not be used directly outside
	// it also helps to differentiate between the member variables
	// and the args to functions
	int m_LogLevel = LogLevelInfo;

// public methods
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout<< "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}

};


int main()
{
	Log log;
	log.SetLevel(log.LogLevelInfo);
	log.Warn("Hello, this is a warning!");
	log.Info("This is some info!");
	log.Error("This is some Error!");

	std::cin.get();
}