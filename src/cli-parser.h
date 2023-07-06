#pragma once
#include <vector>

namespace cli {
  /// @todo pass by reference both parameters
  /// @brief A function that takes an argument list and parse it. 
  /// @param argument_count - The number of arguments. Normally referred as argc.
  /// @param argument_vector - The list of arguments. Usually referred as argv.
  /// @returns A list of the arguments that exists.
  std::vector<std::string> parse_arguments(int argument_count, char* argument_vector[]) {
    // Loop through the arguments vector
    std::vector<std::string> arguments = { };

    for (int i = 0; i < argument_count; i++) {
      // Verify if the argument starts with '-' (is a flag)
      std::string argument = argument_vector[i];

      if (argument.find('-') == 0) {
        continue;
      }

      arguments.push_back(argument);
    }

    return arguments;
  }
}
