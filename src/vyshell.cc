#include "vyshell.hpp"
#include "parser.hpp"

#include <iostream>
#include <vector>
#include <string>

void vyshell() {

  // main loop
  while (true) {
    std::cout << "vyshell~# ";

    std::string inputs;

    if (!std::getline(std::cin, inputs)) {
      if (std::cin.eof()) {
        std::cout << "\nbye..\n"; break;
      }
      std::cerr << "input not valid!" << '\n';
    }

    std::vector<std::string> argv = parse(inputs);

    if (argv.empty()) continue;
    if (argv[0] == "kluar") break;

    auto it = commands.find(argv[0]);
    if (it != commands.end()) {
      it->second(argv);
    } else {
      std::cout << "command '" << argv[0] << "'" << " not found!" << '\n';
    }
  }
}
