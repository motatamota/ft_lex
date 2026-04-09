#include <iostream>
#include <fstream>
#include <string>
#include <Setup.h>
#include <Tree.h>
#include <NFA.h>
#include <DFA.h>
#include <GenerateFile.h>


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Argument error" << std::endl;
		exit(1);
	}

	std::ifstream ifs(av[1]);
	std::string f_data((std::istreambuf_iterator<char>(ifs)),
						std::istreambuf_iterator<char>());

	Setup setup{};
	Tree tree{};
	DFA dfa{};
	NFA nfa{};
	GenerateFile generate_file{};

	// 0:プレフィックス、1:データ、2:サフィックス
	auto split_text = setup.SplitLexText(f_data);
	auto tree_data = tree.StringToTree(split_text);
	auto nfa_data = nfa.TreeToNFA(tree_data);
	auto dfa_data = dfa.NFAToDFA(nfa_data);
	generate_file.Generate(dfa_data, split_text);

}
