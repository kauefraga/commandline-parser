#include <iostream>
#include "cli.h"
#include "colors.h"

void* operator new(size_t bytes) {
  std::cout << "Allocate " << bytes << " bytes" << '\n';
  return malloc(bytes);
}

int main(int argc, char* argv[]) {
  std::cout << "Simply looping through argv and printing it out" << '\n';
  std::cout << "How many arguments are there? " << argc << '\n';

  for (int i = 0; i < argc; i++) {
    std::cout << "Argument #" << i + 1 << ": " << argv[i] << '\n';
  }

  std::cout << "-------------------" << '\n';
  std::cout << "Using the command line parser: " << '\n';

  Cli cli(argc, argv);

  // All the arguments
  for (std::string argument : cli.arguments) {
    std::cout << fore::green << argument << style::reset << '\n';
  }

  std::cout << "-------------------" << '\n';

  // Only the flags
  for (std::string flag : cli.flags) {
    std::cout << fore::yellow << flag << style::reset << '\n';
  }

  return 0;
}
