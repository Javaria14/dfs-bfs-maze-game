# Maze Game using DFS & BFS

A simple console-based maze game developed in **C++** using **Data Structures & Algorithms (DSA)** concepts. The player navigates through a maze from the start point (`S`) to the exit (`E`) while avoiding blocked paths (`#`).

## Features

* Player movement using keyboard controls
* Path validation using **Depth First Search (DFS)**
* Shortest path calculation using **Breadth First Search (BFS)**
* Reset and replay functionality
* Interactive console-based gameplay

## Technologies Used

* C++
* DFS Algorithm
* BFS Algorithm
* Arrays & Structures

## Controls

| Key | Action             |
| --- | ------------------ |
| W   | Move Up            |
| S   | Move Down          |
| A   | Move Left          |
| D   | Move Right         |
| B   | Show shortest path |
| R   | Reset game         |
| Q   | Quit game          |

## Game Logic

* `DFS` checks whether the selected move still allows a valid path to the exit.
* `BFS` calculates the shortest distance from the player’s current position to the exit.

## How to Run

1. Open the project in any C++ compiler (CodeBlocks, Dev-C++, VS Code, etc.)
2. Compile the source file
3. Run the program

## Project Structure

* Maze Representation using 2D arrays
* Player movement handling
* DFS path validation
* BFS shortest path calculation

## Output

The maze is displayed in the console where:

* `P` = Player
* `S` = Start
* `E` = Exit
* `#` = Blocked path
* `.` = Open path

Built as a DSA semester project to demonstrate practical implementation of graph traversal algorithms.
