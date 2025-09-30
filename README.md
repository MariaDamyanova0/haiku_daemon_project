# Haiku Daemon Project

## Description

The Haiku Daemon Project is a set of programs that simulate the creation of "Artificial Haiku" poems based on a word dictionary. The project consists of:

1. **Haiku Masters**: A daemon program that sends words from a dictionary to students via network sockets.
2. **Haiku Students**: Clients that collect words and form them into Haikus (5-7-5 word structure).
3. **Librarian**: A program that collects completed Haikus and logs them into a file.

## Features

- Multiple Haiku Masters can run simultaneously.
- Students organize words into Haikus and print them when completed.
- The Librarian collects and logs Haikus from Students.

## Requirements

- GCC (GNU Compiler Collection) to compile the code.
- A Unix-like operating system (Linux/macOS) or Windows with a Unix shell (like Git Bash).

## Installation

1. Clone the repository (or download the project files).
2. Navigate to the project directory.
3. Run `make` to compile the project.

## Usage

1. To start a Haiku Master:  
   `./master/haiku_master <port> <dictionary_file> <cooldown>`

2. To start a Haiku Student:  
   `./student/haiku_student <master_IP> <master_port> [more_ports]`


3. To start the Librarian:  
   `./librarian/librarian`

4. To stop: 
` Ctrl + C  `

5. To open student.log:
` cat student.log ` 

## Example

### Start a Haiku Master:

```bash
./master/haiku_master 9012 ./master/dictionary.txt 2
./student/haiku_student 46.10.253.12 9012
./librarian/librarian

