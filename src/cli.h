#pragma once
#include <vector>
#include <string>

// using arguments_t = std::vector<std::string> 

bool is_flag(std::string& argument) {
  if (argument.find('-') == 0) {
    return true;
  }

  return false;
}

// Pay attention to optimizations like pass by reference
class Cli {
public:
  int argument_count;
  std::vector<std::string> arguments;
  std::vector<std::string> flags;
  Cli(int argument_count, char* argument_vector[]) {
    this -> argument_count;
    parse_arguments(argument_count, argument_vector);
    parse_flags(arguments);
  }

  /// @brief A method that takes an argument list and parse it. 
  /// @param argument_count - The number of arguments. Normally referred as argc.
  /// @param argument_vector - The list of arguments. Usually referred as argv.
  /// @returns A list of the arguments that exists.
  void parse_arguments(int argument_count, char* argument_vector[]) {
    // Loop through the argument vector pushing back all the values to a string vector
    for (int i = 0; i < argument_count; i++) {
      arguments.push_back(argument_vector[i]);
    }
  }

  void parse_flags(std::vector<std::string>& arguments) {
    for (int i = 0; i < arguments.size(); i++) {
      if (is_flag(arguments[i])) {
        flags.push_back(arguments[i]);

        // If needed to remove '-', use
        // flags.push_back(argument.substr(1, argument.size()));
      }

      continue;
    }
  }
};
