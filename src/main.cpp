#include <iostream>
#include "cli-parser.h"
#include "colors.h"

int main(int argc, char* argv[]) {
  std::cout << "How many arguments are there? " << argc << '\n';

  for (int i = 0; i < argc; i++) {
    std::cout << "Argument #" << i + 1 << ": " << argv[i] << '\n';
  }

  std::vector<std::string> arguments = cli::parse_arguments(argc, argv);

  std::cout << arguments.at(0) << '\n';

  return 0;
}
