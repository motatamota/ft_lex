#include "Tree.h"
#include <iostream>
#include <cstdlib>

void Tree::PrintError(const std::string &filename, int line_num, const std::string &msg)
{
	std::cerr << filename << ":" << line_num << ": " << msg << "\n";
	std::exit(1);
}

std::vector<tree_node> Tree::StringToTree(const std::vector<std::string> &input, const std::string &filename)
{
	SetDefine(input[0], filename);
	CreateNode(input[1], filename);
	return std::vector<tree_node>();
}

bool Tree::IsValidName(const std::string &name)
{
	if (name.empty() || (!isalpha(name[0]) && name[0] != '_'))
		return false;
	for (std::size_t i = 1; i < name.size(); i++)
	{
		if (!isalnum(name[i]) && name[i] != '_')
			return false;
	}
	return true;
}

std::string Tree::ExpandDefine(const std::string &val)
{
	std::string result;
	std::size_t i = 0;

	while (i < val.size())
	{
		if (val[i] == '{')
		{
			std::size_t end = val.find('}', i + 1);
			if (end != std::string::npos)
			{
				std::string key = val.substr(i + 1, end - i - 1);
				auto it = define_map_.find(key);
				if (it != define_map_.end())
					result += it->second;
				else
					result += val.substr(i, end - i + 1);
				i = end + 1;
				continue;
			}
		}
		result += val[i++];
	}
	return result;
}

void Tree::SetDefine(const std::string &str, const std::string &filename)
{
	std::istringstream iss(str);

	std::string line;
	int line_num = 0;
	int depth = 0;
	while (std::getline(iss, line))
	{
		line_num++;
		if (line == "%{")
		{
			depth++;
			continue;
		}
		if (line == "%}")
		{
			if (depth == 0)
				PrintError(filename, line_num, "unexpected '%}'");
			depth--;
			continue;
		}
		// %{ %} 内または行頭空白はCコードとして保存
		if (depth > 0 || (!line.empty() && isspace(line[0])))
		{
			c_prefix_ += line + '\n';
			continue;
		}
		if (line.empty())
			continue;
		// % で始まるディレクティブはスキップ
		if (line[0] == '%')
			continue;
		// 名前定義
		std::size_t sep = line.find_first_of(" \t");
		if (sep == std::string::npos)
			PrintError(filename, line_num, "missing value for name '" + line + "'");
		std::string name = line.substr(0, sep);
		if (!IsValidName(name))
			PrintError(filename, line_num, "invalid name '" + name + "'");
		std::size_t val_start = line.find_first_not_of(" \t", sep);
		if (val_start == std::string::npos)
			PrintError(filename, line_num, "missing value for name '" + name + "'");
		define_map_[name] = ExpandDefine(line.substr(val_start));
	}
	if (depth > 0)
		PrintError(filename, line_num, "unclosed '%{'");
}

std::vector<tree_node> Tree::Parse(const std::string &str)
{
	return std::vector<tree_node>();
}

void Tree::CreateNode(const std::string &str, const std::string &filename)
{
	std::istringstream iss(str);

	std::string line;
	int line_num = 0;
	int depth = 0;
	while (std::getline(iss, line))
	{

	}
}
