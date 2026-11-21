#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#define CLEAR_ANSII "\033[2J\033[H"

class BuiltinCommand {
  public:
    static void bntuan();             
    // static void brsih();
    static void dmn();
    static void dftr(const std::vector
                     <std::string>& path);
    static void ctak(const std::vector    
              <std::string>& size_line);
    static void liat(const std::vector<std::string>& line);
    static void bf(const std::vector<std::string>& name_file);
    static void pndh(const std::vector<std::string>& path);

    // inline function
    static inline void brsih() {
      std::cout << CLEAR_ANSII << '\n';
    }

    static inline void wktu() {
      std::time_t t = std::time(nullptr);

      std::cout << "[CURRENT DATE]: " << \
      // format time hours:minutes:second day month year
      std::put_time(std::localtime(&t), "%H:%M:%S %d %b %Y") << std::endl;
    }
};

using Bc = BuiltinCommand;

#endif // !COMMAND_HPP
