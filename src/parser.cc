#include "parser.hpp"
#include "command.hpp"

#include <sstream>
// parsing a token input
std::vector<std::string> parse(const std::string& inputs) {

  std::string token;
  std::vector<std::string> argv;
  std::stringstream ss(inputs);

  while (ss >> token) argv.push_back(token);
  return argv;
}

// list the builtin command
const std::unordered_map<std::string, BuiltInComm> commands = {
  {"dftr", Bc::dftr},
  {"ctak", Bc::ctak},
  {"brsih", [](const args&) {Bc::brsih();}},
  {"dmn", [](const args&) {Bc::dmn();}},
  {"tlong", [](const args&) {Bc::bntuan();}}
};
