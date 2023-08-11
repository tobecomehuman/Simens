#include<iostream>
#include <string>
#include<cstdlib>

using namespace std;

class CommandAttribute
{
public:
	CommandAttribute();
	CommandAttribute(string desc, string cmd, string analysis);
	~CommandAttribute();

	string Desc;
	string Cmd;
	string Analysis;

private:

};

