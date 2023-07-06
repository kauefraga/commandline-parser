#include <iostream>
#include "cli-parser.h"
#include "colors.h"

int main(int argc, char* argv[]) {
  std::cout << "How many arguments are there? " << argc << '\n';

  for (int i = 0; i < argc; i++) {
    std::cout << "Argument #" << i + 1 << ": " << argv[i] << '\n';
  }

  std::cout << "-------------------" << '\n';
  std::cout << "After CLI we got: " << '\n';

  Cli cli(argc, argv);

  // All the arguments
  for (std::string argument : cli.arguments) {
    std::cout << argument << '\n';
  }

  // Only the flags
  for (std::string flag : cli.flags) {
    std::cout << flag << '\n';
  }


  return 0;
}
