#pragma once

#include <string>
#include <vector>

class Setup
{
	public:
		Setup() = default;
		Setup(const Setup &other) = default;
		Setup &operator=(const Setup &other) = default;
		~Setup() = default;

		std::vector<std::string> SplitLexText(const std::string& input);
	private:
};
