#pragma once

#include <string>
#include <vector>
#include "Tree.h"

struct nfa_node {
};

class NFA
{
	public:
		NFA() = default;
		NFA(const NFA &other) = default;
		NFA &operator=(const NFA &other) = default;
		~NFA() = default;

		std::vector<nfa_node> TreeToNFA(const std::vector<tree_node>& tree_data);
	private:
};
