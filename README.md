# Command Line Parser

> 🧶 A command line (CLI) parser that will help you building your command line application.

### Features

- Just copy the file `cli.h` in your project and parse all your stuff.
- All the currently features are concisely in a class called `Cli`. 
- Easy to use and very simple to understand.
- Well documented, therefore you don't need to crack your brain.
- Written following [Google's c++ style guide](https://google.github.io/styleguide/cppguide.html).

## ⬇️ Getting Started

1. Download or clone the repository
2. Copy the file `cli.h` at `src` into your codebase
3. See [usage](#usage) and [api](#api)

```bash
# (1)
git clone https://github.com/kauefraga/commandline-parser.git
cd commandline-parser

# (2)
cp src/cli.h ../path/to/your/project
```

You are welcome to open issues and pull requests!

## Usage

To have access to the command line parser features you need to include the file `src/cli.hpp` in your source code.

Example: include the library in your code, then use the class to parse the given arguments and print it out.

```cpp
// Input: main.exe "Hiiii" -number 23

#include "../path/to/commandline-parser/cli.h" // includes <vector> and <string>

int main(int argc, char* argv[]) {
  Cli cli(argc, argv);

  // All the arguments
  for (std::string argument : cli.arguments) {
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

Expect:

```bash
# main.exe "Hiiii" -number 23

> path/to/the/executable/main.exe # the executable is part of the arguments
> Hiiii
> -number # By now, the flags are part of the arguments too
> 23
> ----------------
> -number
```

## API

### Classes

- `Cli` - It parses arguments, flags and store it.
    - `Cli(int arguments_count, char* arguments_vector)` - The constructor takes the arguments count (`argc`) and the arguments vector (`argv`).
    - Public properties: arguments_count, arguments and flags.
    - Public methods: parse_arguments and parse_flags. (These will become private)

Read the doxygen documentation at [code](src/cli.h) too.

## 🧻 Resources

These are the contents that i consume to develop this library:

- [How to use c++ classes](https://www.learncpp.com/cpp-tutorial/class-code-and-header-files) - An awesome article about classes.
- [How command line arguments work](https://www.learncpp.com/cpp-tutorial/command-line-arguments) - A wonderful content of command line arguments.
- [Command Line Interface Guidelines](https://clig.dev) - An open-source guide to help you write better command-line programs.
- [The API is inspired by Commander](https://www.npmjs.com/package/commander) - The complete solution for node.js command-line interfaces.

## 📝 License

This project is licensed under the MIT License - See the [LICENSE](https://github.com/kauefraga/commandline-parser/blob/main/LICENSE) for more information.
