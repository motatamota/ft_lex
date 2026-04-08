#pragma once

#include <string>
#include <memory>

class Tree
{
	public:
		Tree() = default;
		Tree(const Tree &other) = default;
		Tree &operator=(const Tree &other) = default;
		~Tree() = default;

		void StringToTree(const std::string& input);
	private:
};
