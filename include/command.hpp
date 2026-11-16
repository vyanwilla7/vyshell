#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>

#define CLEAR_ANSII "\033[2J\033[H"

class BuiltinCommand {
  public:
    static void bntuan();             
    static void brsih();
    static void dftr(const std::vector
                     <std::string>& path);
    static void ctak(const std::vector    
              <std::string>& size_line);
    static void dmn();
};

using Bc = BuiltinCommand;

#endif // !COMMAND_HPP
