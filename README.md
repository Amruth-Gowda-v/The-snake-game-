# Snake Game in C

A classic console-based Snake game implemented in C for Windows. The player controls the snake, collects food, and tries to avoid the walls and its own body.

## Features

- Console-based game board
- Keyboard controls using W, A, S, and D
- Food generation
- Snake growth and score tracking
- Wall and self-collision detection
- Exit using X

## Requirements

- Windows
- A C compiler that supports `conio.h` and the Windows API

The source uses Windows-specific functions such as `_kbhit()`, `_getch()`, `Sleep()`, and `system("cls")`. It will not compile unchanged with a typical Linux or macOS toolchain.

## Compile

Using GCC/MinGW on Windows:

```bash
gcc 1.c -o snake
```

## Run

```bash
snake.exe
```

## Controls

| Key | Action |
|---|---|
| W | Move up |
| A | Move left |
| S | Move down |
| D | Move right |
| X | Exit the game |

## Concepts demonstrated

C structures, enumerations, arrays, functions, random number generation, keyboard input, and game-loop logic.
