#include "parser.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//logic for the run a command
void vyshl() {

  std::string input_usr;
  while (true) {
    std::cout << "vysh$ ";

    if (!std::getline(std::cin, input_usr)) {
      if (std::cin.eof()) {
        std::cout << "\nbye..\n"; break;
      }
    }

    std::vector<std::string> argv;
    std::stringstream ss(input_usr);

    while (ss >> input_usr) argv.push_back(input_usr);

    if (argv[0] == "kluar") {
      break;
    }else if (argv[0] == "dftr") {
      Bc::dftr(argv);    
     }else if (argv[0] == "ctak") {
      Bc::ctak(argv);
    }else if (argv[0] == "brsih") {
      Bc::brsih();
    }else if (argv[0] == "tlong") {
      Bc::bntuan();
    }else if (argv[0] == "dmn") {
      Bc::dmn();
    }
  }  
}
