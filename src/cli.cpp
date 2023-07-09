#include "cli.h"

/* ----- UTILS ----- */

bool is_flag(std::string& argument) {
  if (argument.find('-') == 0) {
    return true;
  }

  return false;
}

/* ----- PUBLIC ----- */

// Constructor
Cli::Cli(
  int& arguments_count,
  char* arguments_vector[],
  std::string name,
  std::string version
) {
  m_arguments_count = arguments_count;
  m_name = name;
  m_version = version;

  parse_arguments(arguments_count, arguments_vector);
  parse_flags();
}

int Cli::get_arguments_count() {
  return m_arguments_count;
}

std::vector<std::string> Cli::get_arguments() {
  return m_arguments;
}

std::vector<std::string> Cli::get_flags() {
  return m_flags;
}

std::string Cli::get_name() {
  return m_name;
}

std::string Cli::get_version() {
  return m_version;
}

/* ----- PRIVATE ----- */

void Cli::parse_arguments(int& arguments_count, char* arguments_vector[]){
  for (int i = 0; i < arguments_count; i++) {
    m_arguments.push_back(arguments_vector[i]);
  }
}

void Cli::parse_flags() {
  for (std::string argument : m_arguments) {
    if (is_flag(argument)) {
      m_flags.push_back(argument);

      // If needed to remove '-', use: argument.substr(1, argument.size());
    }

    continue;
  }
}
