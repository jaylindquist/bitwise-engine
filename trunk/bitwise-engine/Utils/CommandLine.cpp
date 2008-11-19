#include "CommandLine.h"
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
using namespace BitwiseEngine;

CommandLine::CommandLine(int argc, char** argv)
{
	for(int i = 0; i < argc; i++)
	{
		m_argv.push_back(argv[i]);
		m_argvLower.push_back(argv[i]);
		transform(m_argvLower[i].begin(), m_argvLower[i].end(), m_argvLower[i].begin(), tolower);
	}
}

CommandLine::~CommandLine()
{
}


bool 
CommandLine::IsOption(const char* optName) const
{
	vector< string >::const_iterator iArg = FindOpt(optName);
	return iArg != m_argv.end();
}



bool 
CommandLine::GetOption(const char* optName, bool& optVal) const
{
	vector< string >::const_iterator iArg = FindOpt(optName);
	
	if(!HasOption(iArg))
	{
		return false;
	}

	vector< string >::difference_type iDiff = iArg - m_argv.begin();
	iArg = m_argvLower.begin() + iDiff;
	
	istringstream buffer(*iArg);
	if(buffer >> boolalpha >> optVal)
	{
		return true;
	}


	return false;
}


bool 
CommandLine::GetOption(const char* optName, string& optVal) const
{
	vector< string >::const_iterator iArg = FindOpt(optName);
	if(!HasOption(iArg))
	{
		return false;
	}

	optVal = *iArg;
	return true;
}

bool 
CommandLine::GetExecutable(string& optVal) const
{
	optVal = *m_argv.begin();
	return true;
}


vector< string >::const_iterator 
CommandLine::FindOpt(const char* optName) const
{
	string name(optName);
	transform(name.begin(), name.end(), name.begin(), tolower);

	vector< string >::const_iterator iArg;
	iArg = find(m_argvLower.begin(), m_argvLower.end(), name);

	vector< string >::difference_type iDiff = iArg - m_argvLower.begin();
	return m_argv.begin() + iDiff;
}


bool 
CommandLine::HasOption(vector< string >::const_iterator& iArg) const
{
	if(iArg == m_argv.end())
	{
		return false;
	}

	iArg++;
	if(iArg == m_argv.end())
	{
		return false;
	}

	return true;
}