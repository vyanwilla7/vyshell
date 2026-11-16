#include "command.hpp"

#include <cstddef>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

// alias for filesystem module
namespace Fs = std::filesystem;

// like a ls
void Bc::dftr(const std::vector<std::string>& path) {

  // print list a directory targets

  Fs::path targets_dir = path.size() > 1 ? Fs::path(path[1]) : Fs::current_path();

  if (Fs::exists(targets_dir) || Fs::is_directory(targets_dir)) {
    for (const auto& file : Fs::directory_iterator(targets_dir)) {
      std::cout << file.path().filename().string() << " ";
    }
    std::cout << std::endl;

  }else {
    std::cerr << "'" << path[1] << "'" <<
    " is not diretory or is not found!" << '\n';
    return;
  }
}

// like a print
void Bc::ctak(const std::vector<std::string>& s_line) {
  for (std::size_t i = 1; i < s_line.size(); ++i) {
    std::cout << s_line[i] << " ";
  }

  std::cout << std::endl;
}

// like clear
void Bc::brsih() {
  std::cout << CLEAR_ANSII << std::endl;
}

void Bc::bntuan() {
  std::cout << R"(
    -------------------------------------------
                      Vyshell
    -------------------------------------------

    Available command:
              kluar -> for exit the programs
              tlong -> show this help menu
              brsh -> clear the terminal
              dftr -> list directory contents
              dmn  -> print working directory

    -------------------------------------------
   )" << '\n';
}

// like a pwd
void Bc::dmn() {
  Fs::path current_dir = Fs::current_path();
  std::cout << current_dir.generic_string()<< '\n';
}


// TODO: add function pndh, liat
