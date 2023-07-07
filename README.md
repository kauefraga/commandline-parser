# Command Line Library

> 🧶 A command line (CLI) library that will help you to build your command line applications with out of the box.

### Features

- Just copy the files `cli.h` and `cli.cpp` in your project and create your whole CLI with c++.
- All the currently features are concisely in the class called `Cli`. 
- Easy to use and very simple to understand.
- Well documented, therefore you don't need to crack your brain.
- Written following [Google's c++ style guide](https://google.github.io/styleguide/cppguide.html).

## ⬇️ Getting Started

1. Download or clone the repository
2. Copy the files `cli.h` and `cli.cpp` at `src` into your codebase
3. See [usage](#usage) and [api](#api)

```bash
# (1)
git clone https://github.com/kauefraga/cpp-commandline.git
cd cpp-commandline

# (2)
cp src/cli.h src/cli.cpp ../path/to/your/project
```

You are welcome to open issues and pull requests!

## Usage

To have access to the command line library features you need to include the files `src/cli.h` and `src/cli.cpp` in your source code.

Example: include the library in your code, then use the class to parse the given arguments and print it out.

```cpp
// Input: main.exe "Hiiii" -number 23

#include "../path/to/cpp-commandline/cli.h" // includes <vector> and <string>

int main(int argc, char* argv[]) {
  // If there is only one argument or less, then print help
  if (argc <= 1) {
    std::cout << "Usage: [name].exe [options]" << '\n';
    std::cout << "  -help (boolean)" << '\n';
      
    return 1;
  }

  Cli cli(argc, argv, "[name]", "[version]");

  // All the arguments
  for (std::string argument : cli.arguments) {
    if (argument == "-help") {
      std::cout << "HERE IS YOUR HELP MY FRIEND" << '\n';
    }

    std::cout << argument << '\n';
  }

  std::cout << "----------------" << '\n';

  // Only the flags
  for (std::string flag : cli.flags) {
    std::cout << flag << '\n';
  }

  return 0;
}
```

Expected:

```bash
# main.exe -help

> path/to/the/executable/main.exe # the executable is part of the arguments
> HERE IS YOUR HELP MY FRIEND
> -help # By now, the flags are part of the arguments too
> ----------------
> -help
```

## API

### Classes

- `Cli` - It parses arguments, flags and store it.
    - `Cli(int arguments_count, char* arguments_vector, string name, string version)` - The constructor takes the arguments count (`argc`), the arguments vector (`argv`), the application name, the version and stores it.
    - Public methods: currently, there are only getters methods.
    - Private methods: `parse_arguments` and `parse_flags`.
    - Private properties: `m_arguments_count`, `m_arguments`, `m_flags`, `m_name` and `m_version`.

### Util functions

- `bool is_flag(string argument)` - Verify if there is a '-' at the initial position (0) of the argument.

Read the doxygen documentation at [code](src/cli.h) too.

## 🧻 Resources

These are the contents that i consume to develop this library:

- [How to use c++ classes](https://www.learncpp.com/cpp-tutorial/class-code-and-header-files) - An awesome article about classes.
- [How command line arguments work](https://www.learncpp.com/cpp-tutorial/command-line-arguments) - A wonderful content of command line arguments.
- [Command Line Interface Guidelines](https://clig.dev) - An open-source guide to help you write better command-line programs.
- [The API is inspired by Commander](https://www.npmjs.com/package/commander) - The complete solution for node.js command-line interfaces.
- [C++ Colors](https://github.com/kauefraga/cpp-colors) - A collection of namespaces (ANSI escape code for colors) and functions that will help you to style and bring life to your console outputs. 

## 📝 License

This project is licensed under the MIT License - See the [LICENSE](https://github.com/kauefraga/cpp-commandline/blob/main/LICENSE) for more information.
