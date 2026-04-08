#pragma once

#include <string>
#include <fstream>
#include "DFA.h"

class GenerateFile
{
	public:
		GenerateFile() = default;
		GenerateFile(const GenerateFile &other) = default;
		GenerateFile &operator=(const GenerateFile &other) = default;
		~GenerateFile() = default;

		void Generate(const std::vector<dfa_node>& dfa_data, const std::vector<std::string>& file_data);
	private:
};
