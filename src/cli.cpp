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
Cli::Cli(int& argument_count, char* argument_vector[]) {
  this -> argument_count;
  parse_arguments(argument_count, argument_vector);
  parse_flags(arguments);
}

/* ----- PRIVATE ----- */
void Cli::parse_arguments(int& argument_count, char* argument_vector[]){
  for (int i = 0; i < argument_count; i++) {
    arguments.push_back(argument_vector[i]);
  }
}

void Cli::parse_flags(std::vector<std::string>& arguments) {
  for (std::string argument : arguments) {
    if (is_flag(argument)) {
      flags.push_back(argument);

      // If needed to remove '-', use: argument.substr(1, argument.size());
    }

    continue;
  }
}
