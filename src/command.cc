#include "command.hpp"

#include <cstddef>
#include <filesystem>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

// alias for filesystem module
namespace Fs = std::filesystem;

// like a ls
void Bc::dftr(const std::vector<std::string>& path) {

  // print list a directory targets

  Fs::path targets_dir = path.size() > 1 ? Fs::path(path[1]) : Fs::current_path();

  if (Fs::exists(targets_dir) && Fs::is_directory(targets_dir)) {
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
void brsih();

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
              tgl -> show current date
              ctak -> print text to terminal
              liat -> display file contents
              bf -> create new file
              pndh -> change working directory

    -------------------------------------------
   )" << '\n';
}

// like a pwd
void Bc::dmn() {
  Fs::path current_dir = Fs::current_path();
  std::cout << current_dir.generic_string()<< '\n';
}

//like a date
void wktu();

// like a cat
void Bc::liat(const std::vector<std::string>& line) {

  if (line.size() > 1) {
    std::ifstream file_path(line[1], std::ios::in);

    if (file_path.is_open()) {
      std::string str_line;
      while(std::getline(file_path, str_line)) {
        std::cout << str_line << '\n';
      }
    }
  }else {
    std::cerr << "missing one argument!" << '\n';
  }
}

// like a touch
void Bc::bf(const std::vector<std::string>& argv) {

  for (std::size_t f = 1; f < argv.size(); f++){
    std::string name_file = argv.size() > 1 ? argv[f] : throw std::invalid_argument("missng arguments!\n");
     std::ofstream new_file(name_file, std::ios::app);
    new_file.close();
  }
}

// like a cd
void Bc::pndh(const std::vector<std::string>& path) {
  // move next and temp directory

  if (path.size() > 1) {
    Fs::path works_dir = Fs::path(path[1]);

    if (Fs::exists(works_dir) && Fs::is_directory(works_dir)) {
      Fs::current_path(works_dir);
      std::cout << "move dir" << '\n';
    }
  }else {
    std::cerr << "missing arguments" << '\n';
  }
}
