#ifndef PARSER_HPP
#define PARSER_HPP

#include <functional>
#include <vector>
#include <string>
#include <unordered_map>

using args = std::vector<std::string>;
using BuiltInComm = std::function<void(const args&)>;

extern const std::unordered_map<std::string, BuiltInComm> commands;

std::vector<std::string> parse(const std::string& inputs);

#endif // !PARSER_HPP
