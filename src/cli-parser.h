#pragma once
#include <vector>

namespace cli {
  std::vector<std::string> parse_arguments(int argument_count, char* argument_vector[]) {
    // If the program has only one parameter (executable path), return it
    /* std::string program;

    if (argument_count <= 1) {
      for (int i = 0; i < argument_count; i++) {
        std::cout << "This feature is not implemented yet..." << '\n';
      }
    } */

    // Loop through the arguments vector
    std::vector<std::string> arguments = { };

    for (int i = 0; i < argument_count; i++) {
      arguments.push_back(argument_vector[i]);
    }

    return arguments;
  }
}
