# Conway's Game of Life (C++ Console Version)

This is a simple visual simulation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) implemented in C++. The simulation randomly generates a board and evolves it according to the rules of the Game of Life, displaying the cells live in the Windows console.

> 💡 **Inspired by [LeetCode 289 - Game of Life](https://leetcode.com/problems/game-of-life/)**

## 🧠 Rules of the Game

1. **Underpopulation:** A live cell with fewer than 2 live neighbors dies.
2. **Survival:** A live cell with 2 or 3 live neighbors continues living.
3. **Overpopulation:** A live cell with more than 3 live neighbors dies.
4. **Reproduction:** A dead cell with exactly 3 live neighbors becomes a live cell.

## 🎮 Features

- Random board generation on each run.
- Console visualization of the board using `o` for live cells.
- Live updates every 1.5 seconds using `Sleep()` and `system("cls")`.
- Cycle and live cell counter on each frame.
- Windows-specific green text color for a retro vibe.

## 🔧 Requirements

- C++ compiler (MSVC or g++)
- Windows OS (uses `windows.h` and `SetConsoleTextAttribute`)

## 🚀 How to Run

1. Clone this repository or copy the source code.
2. Compile the code with a C++ compiler:
   ```bash
   g++ game_of_life.cpp -o game_of_life
