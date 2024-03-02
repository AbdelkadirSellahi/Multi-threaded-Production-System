# Multi-threaded Production Line Simulation

This project simulates a multi-threaded production line using semaphores for synchronization. It models a scenario where multiple producers create batteries and motherboards, which are then used to assemble computers. The simulation demonstrates the use of pthreads and semaphores in a C program to manage concurrent operations and resource sharing among threads.

## Project Configuration

This section outlines the key configurations and design decisions made in this project:

|  **Configuration Item**            |  **Options**             |
| ---------------------------------- | ------------------------ |
| 😊 Use of Emojis                   | Disabled                 |
| 🧠 Programming Paradigm            | Procedural               |
| 🌐 Language                        | C                        |
| 📚 Project Type                    | General Purpose          |
| 📖 Comment Style                   | Descriptive              |
| 🛠️ Code Structure                  | Modular                  |
| 🚫 Error Handling Strategy         | Basic                    |
| ⚡ Performance Optimization Level  | Not Covered              |

These configurations guide the development and contribution process for this project, ensuring consistency and clarity in its development.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

- ### Prerequisites

To compile and run this project, you will need:

- GCC compiler
- POSIX threads library
- POSIX semaphores

Most Unix-like operating systems come with these pre-installed. You can verify the presence of GCC by running `gcc --version` in your terminal.

- ### Installing

To get the project running, follow these steps:

1. Clone the repository to your local machine:

   `git clone <repository-url>`

2. Navigate to the project directory:

   `cd <project-directory>`
   
3. Compile the project using GCC:

   `gcc -o production_line_simulation main.c -lpthread`

   This will generate an executable named `production_line_simulation`.

4. Run the simulation:

   `./production_line_simulation`

## Built With

- [C](https://en.wikipedia.org/wiki/C_(programming_language)) - The programming language used
- [Pthreads](https://en.wikipedia.org/wiki/POSIX_Threads) - For creating and managing threads
- [Semaphores](https://en.wikipedia.org/wiki/Semaphore_(programming)) - For synchronization between threads

## Authors
- [**ABDELKADIR Sellahi**](https://github.com/AbdelkadirSellahi)

