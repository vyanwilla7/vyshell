#include "command_.hpp"

#include <cstddef>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

// alias for filesystem module
namespace Fs = std::filesystem;

// like a ls
void Bc::dftr(const std::vector<std::string>& path) {

  if (path.size() <= 1) {
    Fs::path targets_dir = Fs::current_path();
    if (Fs::exists(targets_dir) && Fs::is_directory(targets_dir)) {
      for (const auto& f: Fs::directory_iterator(targets_dir)) {
        std::cout << f.path().filename().string() << " ";
      }
      std::cout << std::endl;
    }
    return;
    
  }

  //read a folder path in arg 1
  Fs::path targets_dir(path[1]);

  if (Fs::exists(targets_dir) && Fs::is_directory(targets_dir)) {
    for (const auto& f: Fs::directory_iterator(targets_dir)) {
      std::cout << f.path().filename().string() << " ";
    }
    std::cout << std::endl;
  }else {
    std::cerr << "failed to read a folder: " << path[1] << '\n';
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
