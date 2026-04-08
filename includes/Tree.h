#pragma once

#include <string>
#include <vector>
#include <memory>

enum tree_node_type {
	NODE_LITERAL,     // 'a'
	NODE_CHARSET,     // [0-9], [a-zA-Z], .
	NODE_CONCAT,      // ab
	NODE_OR,          // a|b
	NODE_STAR,        // a*
	NODE_PLUS,        // a+
	NODE_QUESTION,    // a?
};

struct tree_node {
	enum tree_node_type type;
	char c;               // NODE_LITERAL のとき使う
	bool charset[256];    // NODE_CHARSET のとき使う
	struct tree_node *left;    // 左の子（全型で使う、LITERAL/CHARSETはNULL）
	struct tree_node *right;   // 右の子（CONCAT と OR のみ使う）
};

class Tree
{
	public:
		Tree() = default;
		Tree(const Tree &other) = default;
		Tree &operator=(const Tree &other) = default;
		~Tree() = default;

		std::vector<tree_node> StringToTree(const std::string& input);
	private:
};
