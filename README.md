# sh-ovel

`sh-ovel` (Shell + Shovel) is a minimal, low-level UNIX shell written in C with a focus on simplicity, performance, and direct system calls. Designed as a personal exploration into operating systems concepts, `sh-ovel` offers an educational and lightweight shell that implements core shell functionalities.

## Features

- **Basic Command Execution**: Run standard UNIX commands like `ls`, `echo`, `cat`, etc.
- **Environment Variables**: Supports basic variable substitution.
- **Custom Builtins**: Includes a few built-in commands (e.g., `cd`, `exit`).
- **Minimal Dependencies**: Uses direct syscalls where possible, avoiding bloated libraries.
- **History Logging**: Saves the command history in a file after closing the shell.

## Motivation

The project was inspired by a desire to learn more about the internals of UNIX-like systems and shell behavior. 

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/alexionut-tincu/sh-ovel.git
   cd sh-ovel
   ```

2. Build the shell:
   ```bash
   make
   ```

3. Run the shell:
   ```bash
   ./sh-ovel
   ```

## Usage

- **Start the Shell**: Launch the shell by running `./sh-ovel`.
- **Execute Commands**: Type any valid UNIX command and press Enter.

## Built-in Commands

- `cd [directory]`: Change the current working directory.
- `exit`: Exit the shell.
- `help`: Display basic information abuot the project.

## Architecture

The shell is built to be lightweight and leverages:
- **Fork and Exec**: For creating and running new processes.
- **Syscalls**: Direct system calls to avoid unnecessary overhead.
- **Parser**: A basic tokenizer to parse input into commands, arguments, and operators.

## Contributing

Contributions are welcome! If you have suggestions for improving the shell or want to add features, feel free to open an issue or submit a pull request.

## Roadmap

Planned features and improvements:
- Support for background processes (`&`).
- Navigable command history.
- Tab completion.
- Input and Output Redirection: Redirect input/output using `<` and `>`.
- Pipelining: Execute commands connected by pipes (`|`).
- Enhanced error handling.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by the UNIX shell and tools.
- Special thanks to the Linux and open-source communities for their extensive documentation and examples.
- The name 'sh-ovel' is inspired by my nickname I have used for the longest time in online spaces.
