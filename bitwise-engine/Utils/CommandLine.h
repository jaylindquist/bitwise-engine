#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace BitwiseEngine {

class CommandLine
{
public:
	CommandLine(int argc, char** argv);
	virtual ~CommandLine();

	bool IsOption(const char* optName) const;
	bool GetOption(const char* optName, int& optVal) const { return GetOpt<int>(optName, optVal); }
	bool GetOption(const char* optName, unsigned int& optVal) const { return GetOpt<unsigned int>(optName, optVal); }
	bool GetOption(const char* optName, short& optVal) const { return GetOpt<short>(optName, optVal); }
	bool GetOption(const char* optName, unsigned short& optVal) const { return GetOpt<unsigned short>(optName, optVal); }
	bool GetOption(const char* optName, char& optVal) const { return GetOpt<char>(optName, optVal); }
	bool GetOption(const char* optName, unsigned char& optVal) const { return GetOpt<unsigned char>(optName, optVal); }
	bool GetOption(const char* optName, float& optVal) const { return GetOpt<float>(optName, optVal); }
	bool GetOption(const char* optName, double& optVal) const { return GetOpt<double>(optName, optVal); }

	bool GetOption(const char* optName, bool& optVal) const;
	bool GetOption(const char* optName, std::string& optVal) const;

	bool GetExecutable(std::string& optVal) const;
	
protected:

	template<class T> 
	bool GetOpt(const char* optName, T& optVal) const;
	std::vector< std::string >::const_iterator FindOpt(const char* optName) const;
	bool HasOption(std::vector< std::string >::const_iterator& iArg) const;


	std::vector< std::string > m_argv;
	std::vector< std::string > m_argvLower;
};


template<class T> 
bool 
CommandLine::GetOpt(const char* optName, T& optVal) const
{
	std::vector< std::string >::const_iterator iArg = FindOpt(optName);
	if(!HasOption(iArg))
	{
		return false;
	}

	std::istringstream buffer(*iArg);
	if(buffer >> optVal)
	{
		return true;
	}

	return false;
}

}