# Haiku Daemon System (C)

## Overview

This project demonstrates a simple **daemon-based system written in C** designed to generate haiku poems using a dictionary of words.

The system simulates a background service architecture composed of multiple cooperating components. It explores concepts related to **system programming, modular design, and process-oriented workflows**.

The project is intended to demonstrate how different modules can interact within a structured system while being compiled and managed through a **Makefile build process**.

---

## System Architecture

The project is organized into three main modules:

### Master Daemon

The master component acts as the central controller of the system.
It manages the generation process and coordinates the interaction between other components.

### Student Module

This module generates haiku lines using words from the dictionary file.
It represents the logic responsible for creating the poem structure.

### Librarian Module

The librarian component manages the storage and retrieval of generated haiku data.

Together, these modules simulate a **daemon-like service workflow** where different parts of the system perform specialized tasks.

---

## Project Structure

```
Makefile
README.md

librarian/
    librarian.c
    librarian.h

master/
    dictionary.txt
    haiku_master.c
    haiku_master.h

student/
    haiku_student.c
    haiku_student.h
```

### Key Files

* **Makefile** – builds the project and compiles all modules.
* **dictionary.txt** – word list used for generating haiku lines.
* **librarian module** – handles storage and management of generated haiku.
* **master module** – coordinates the system and runs the main daemon logic.
* **student module** – generates haiku structures using dictionary data.

---

## Features

* Modular system design in C
* Multiple cooperating components
* Haiku generation using dictionary-based word selection
* Organized project structure with separate modules
* Build automation using **Makefile**

---

## Technologies Used

* C programming language
* Makefile build system
* Modular system architecture
* File-based word dictionary

---

## How to Build and Run

1. Open a terminal in the project directory.
2. Compile the project using:

```
make
```

3. Run the generated executable according to the Makefile configuration.

---

## Purpose

This project explores basic **systems programming concepts**, including modular program structure, build automation, and background-service style application design.

