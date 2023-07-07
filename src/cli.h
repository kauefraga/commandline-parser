#pragma once
#include <vector>
#include <string>

/// @brief Verify if an argument is a flag by searching for '-' at the initial position (0) of the argument.
/// @param argument - The argument to be verified.
/// @returns A boolean that is true when the given argument matches the condition.
bool is_flag(std::string& argument) {
  if (argument.find('-') == 0) {
    return true;
  }

  return false;
}

class Cli {
public:
  int argument_count;
  std::vector<std::string> arguments;
  std::vector<std::string> flags;

  Cli(int& argument_count, char* argument_vector[]) {
    this -> argument_count;
    parse_arguments(argument_count, argument_vector);
    parse_flags(arguments);
  }

  /// @brief A method that takes an argument list and parse it.
  /// @param argument_count - The number of arguments. Normally referred as argc.
  /// @param argument_vector - The list of arguments. Usually referred as argv.
  void parse_arguments(int& argument_count, char* argument_vector[]) {
    for (int i = 0; i < argument_count; i++) {
      arguments.push_back(argument_vector[i]);
    }
  }

  /// @brief A method that takes an argument vector, parse it and store the flags.
  /// @param arguments - A vector with arguments.
  void parse_flags(std::vector<std::string>& arguments) {
    for (std::string argument : arguments) {
      if (is_flag(argument)) {
        flags.push_back(argument);

        // If needed to remove '-', use: argument.substr(1, argument.size());
      }

      continue;
    }
  }
};
