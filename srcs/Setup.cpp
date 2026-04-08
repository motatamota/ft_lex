#include "Setup.h"

#include <sstream>

std::vector<std::string> Setup::SplitLexText(const std::string &input)
{
	std::istringstream iss(input);

	std::vector<std::string> ans;

	std::string str;
	std::string buf_str;

	while (std::getline(iss, buf_str))
	{
		if (buf_str.compare(0, 2, "%%") == 0)
		{
			ans.push_back(str);
			continue;
		}

		str += buf_str + '\n';
	}
	ans.push_back(str);
	return ans;
}
