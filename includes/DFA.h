#pragma once

#include <string>
#include <vector>
#include "NFA.h"

struct dfa_node {
};

class DFA
{
	public:
		DFA() = default;
		DFA(const DFA &other) = default;
		DFA &operator=(const DFA &other) = default;
		~DFA() = default;

		std::vector<dfa_node> NFAToDFA(const std::vector<nfa_node>& nfa_data);
	private:
};
