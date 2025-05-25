# Rock, Paper, Scissors – C++ Game

This is a command-line implementation of the classic Rock, Paper, Scissors game written in C++, with win/loss tracking and input validation.

The game was developed as a midterm project for a Computer Science 2 course in Spring 2025, with a focus on object-oriented programming concepts, particularly classes, inheritance, and recursive function calls.

---

## Project Objectives

This project was designed to demonstrate:
- Class design and usage
- Inheritance between game components
- Recursive input validation
- Use of simple game logic and control flow
- User interaction via the console

---

## Game Rules

- The user chooses Rock (r), Paper (p), or Scissors (s)
- The computer randomly selects a tool
- The outcome is determined by the standard rules:
  - Rock beats Scissors
  - Paper beats Rock
  - Scissors beats Paper
- The program keeps track of both the user's and computer's win count
- The user can exit the game at any time by entering `e`

---

## Build Instructions

### Requirements
- A C++ compiler such as `g++`
- Compatible with C++11 and above

### Compile
From the terminal, run:

```bash
g++ -o rps_game "Rock_Paper_Scissors .cpp"
```
---

## Example Output 
```
***Enter e to end***

Enter a tool (r,p,s): r
You chose Rock
Computer chose Scissors
You win!

Your winnings: 1 Computer winnings: 0
**********************************

Enter a tool (r,p,s): p
You chose Paper
Computer chose Rock
You win!

Your winnings: 2 Computer winnings: 0
**********************************

Enter a tool (r,p,s): e
Thank you for playing.
```
---

## Program Structure

The program is organized into two main classes:

- game: Tracks and displays win counts

- tool: Inherits from game, handles tool selection, comparison logic, and user interaction

A struct is used to associate each tool with a unique numeric value, allowing the game logic to calculate win/loss conditions based on simple arithmetic.

---

## Notable Features

Object-Oriented Design (OOP)

Inheritance from base class game

Use of recursive calls for input validation

Clean console output with user prompts and game summaries

Random number generation for computer choice

Modular and readable code

---

## Files

Rock_Paper_Scissors .cpp – Main source code for the game

README.md – This documentation file

---

## Author

Tyler Parnell
Mathematics and Big Data Student | Spring 2025
Developed for the CS2 Midterm Project
