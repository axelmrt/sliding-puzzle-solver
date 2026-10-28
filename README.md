[🇬🇧 English](README.md) | [🇫🇷 Français](README.fr.md)

# Sliding Puzzle Solver 🧩

A C++ sliding puzzle (Taquin) game featuring an optimal solver based on the **A\* search algorithm**.

This educational project aims to develop an application that allows users to play the sliding puzzle, calculate an optimal solution, and compare their moves with the minimum number of moves required to solve the puzzle.

The project is developed in C++, with **Qt** planned for the graphical user interface and the **C++ Standard Template Library (STL)** for data structures.

## 📌 Project Overview

The sliding puzzle consists of a square grid containing numbered tiles and one empty space. The objective is to arrange the tiles in ascending order, from left to right and top to bottom, leaving the empty space in the bottom-right corner.

The application is designed to support two board sizes:

- **3 × 3** — 8 numbered tiles and one empty space.
- **4 × 4** — 15 numbered tiles and one empty space.

## ✨ Features

### 🎮 Game

- [x] Board representation in C++.
- [x] Legal tile movements.
- [x] Board shuffling through successive legal moves.
- [x] Solvability checking.
- [x] Manhattan distance heuristic.
- [ ] Full support for both 3 × 3 and 4 × 4 boards.
- [ ] Interactive graphical interface using Qt.
- [ ] Move counter and victory detection.
- [ ] Comparison between the player's moves and the optimal solution.

### 🧠 Optimal Solver

- [ ] Complete implementation of the A\* search algorithm.
- [ ] Calculation of the minimum number of moves required.
- [ ] Retrieval of an optimal solution.
- [ ] Step-by-step assistance mode.
- [ ] Recalculation of the solution from the current board state.

### 📂 File Handling and Performance

- [ ] Load a puzzle configuration from a text file.
- [ ] Validate board dimensions and tile values.
- [ ] Detect invalid or unsolvable configurations.
- [ ] Measure the time required to calculate a solution.

*The checked items represent functionality already present in the codebase at this stage. They do not necessarily indicate that every edge case has been tested.*

## 🔍 The A\* Algorithm

The solver will use the A\* search algorithm to explore possible board configurations and find an optimal solution.

A\* evaluates each state using the following function:

\[
f(n) = g(n) + h(n)
\]

Where:

- `g(n)` is the cost of the path from the initial state to the current state.
- `h(n)` is the estimated cost from the current state to the goal state.

The heuristic is based on the **Manhattan distance**, calculated as the sum of the horizontal and vertical distances between each numbered tile and its target position. The empty space is excluded from this calculation.

This heuristic guides the search toward the goal while preserving optimality under the algorithm's assumptions.

## 🛠️ Technologies

- **C++** — game logic and search algorithm.
- **Qt** — planned graphical user interface.
- **STL** — data structures and containers, such as `std::vector` and `std::priority_queue`.
- **Git and GitHub** — version control and project collaboration.

## 📁 Project Structure

The repository currently includes the following files and directories:

```text
sliding-puzzle-solver/
├── jeu.cpp
├── jeu.h
├── main.cpp
├── grille/
└── exe/
```

- `jeu.h` — declaration of the `Jeu` class.
- `jeu.cpp` — implementation of the game logic, tile movements, board shuffling, solvability checking, and Manhattan distance heuristic.
- `main.cpp` — program entry point and initial tests.
- `grille/` — directory for puzzle configurations used during testing.
- `exe/` — directory currently present in the repository for execution-related files.

The project structure may evolve as the game logic, solver, file handling, and graphical interface are separated into dedicated modules.

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting C++17.
- Git.
- Qt will be required for the graphical version.

### Clone the repository

```bash
git clone https://github.com/axelmrt/sliding-puzzle-solver.git
cd sliding-puzzle-solver
```

### Compile the current console prototype

If `g++` is installed, you can try compiling the current source files with:

```bash
g++ -std=c++17 main.cpp jeu.cpp -o sliding-puzzle-solver
```

Run the executable on Linux or macOS:

```bash
./sliding-puzzle-solver
```

On Windows, run:

```bash
sliding-puzzle-solver.exe
```

These commands are intended for the current console prototype. They may need to be updated as the project evolves, especially when Qt and additional source files are introduced.

## 🌿 Development Workflow

Development can be organized using separate Git branches:

- `main` — stable version of the project.
- `feature/qt-interface` — graphical interface development.
- `feature/astar-solver` — A\* implementation and solver tests.
- `integration` — integration and validation before merging into `main`.

The goal is to develop the graphical interface and the solving algorithm independently while maintaining a shared interface between the board model and the solver.

## 🎓 Educational Objectives

This project provides practical experience with:

- Object-oriented programming in C++.
- Standard library containers and data structures.
- Graph search algorithms and state-space exploration.
- Heuristics and optimal pathfinding.
- Graphical application development with Qt.
- Modular software design, testing, and version control.

## 📚 References

- [A\* Search — Pieter Abbeel](https://www.youtube.com/watch?v=DhtSZhakyOo)

## 📄 Project Status

This project is being developed as part of an educational assignment in C++.

The implementation is ongoing, and the features listed as planned will be added progressively.
