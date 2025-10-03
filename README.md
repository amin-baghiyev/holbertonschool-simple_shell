# Simple Shell

## Description
This project is a simple UNIX command interpreter written in C.  
It provides a basic command line interface that mimics the functionality of standard shells such as `sh` or `bash`.

## Features
- Display a prompt (`#cisfun$ `)
- Execute commands with arguments
- Handle the `PATH` to find executables
- Implement built-in commands (`exit`, `env`)
- End of File (Ctrl+D) handling
- Works in both interactive and non-interactive mode

## Compilation
To compile the shell, use:
`''bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh


## Flowchart
![shell drawio](https://github.com/user-attachments/assets/b8acdf0c-82e2-4047-a756-b40d71c00665)

## Custom Commands

Basic Shell supports the following custom commands:

- `exit`: The command causes the shell or program to terminate. If performed within an interactive command shell, the user is logged out of their current session, and/or user's current console or terminal connection is disconnected. Typically an optional exit code can be specified, which is typically a simple integer value that is then returned to the parent process.
- `env`: The env command allows you to display your current environment or run a specified command in a changed environment.


## Contributing

Contributions are what make the open-source community an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
1. Create your Feature Branch (git checkout -b feature/AmazingFeature)
1. Commit your Changes (git commit -m 'Add some AmazingFeature')
1. Push to the Branch (git push origin feature/AmazingFeature)
1. Open a Pull Request



## Authors Amin Baghiyev and Mahammad Atlukhanov on 28 September - 05 October
