#pragma once
#include <vector>
#include <string>

/// @brief Verify if an argument is a flag by searching for '-' at the initial position (0) of the argument.
/// @param argument - The argument to be verified.
/// @returns A boolean that is true when the given argument matches the condition.
bool is_flag(std::string& argument);

class Cli {
public:
  Cli(
    int& arguments_count,
    char* arguments_vector[],
    std::string name,
    std::string version
  );

  int get_arguments_count();
  std::vector<std::string> get_arguments();
  std::vector<std::string> get_flags();
  
  std::string get_name();
  std::string get_version();

private:
  int m_arguments_count;
  std::vector<std::string> m_arguments;
  std::vector<std::string> m_flags;

  std::string m_name;
  std::string m_version;

  /// @brief A method that takes an argument list and parse it.
  /// @param argument_count - The number of arguments. Normally referred as argc.
  /// @param argument_vector - The list of arguments. Usually referred as argv.
  void parse_arguments(int& arguments_count, char* arguments_vector[]);

  /// @brief A method that uses the argument vector, parse it and store the flags.
  void parse_flags();
};
