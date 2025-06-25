# Checkers in c++

A two-player Checkers game built entirely in C++, playable through the terminal. This project focuses on game mechanics, logic implementation, and input(with no external libraries or GUI).

## About the Project

This is a basic implementation of the classic checkers board game using standard C++. It serves as a learning project to practice array manipulation, input handling, game flow control, and decision logic.

The game is played between two users in turns and runs entirely in the console.

## Features
- Two-player local gameplay (Player 1 = Black `b`, Player 2 = Red `r`)
- Valid move enforcement: diagonal forward movement only on black squares (`x`)
- Piece capturing via jumps over opposing pieces
- Illegal move handling with option to retry or quit
- Automatic win/draw detection
- Turn-based loop with alternating control
- Clear console-based board rendering

## Sample Gameplay
              0   1   2   3   4   5   6   7  
           +---+---+---+---+---+---+---+---+
       0.  |   | b |   | b |   | b |   | b |
       1.  | b |   | b |   | b |   | b |   |
       2.  |   | b |   | b |   | b |   | b |
       3.  | x |   | x |   | x |   | x |   |
       4.  |   | x |   | x |   | x |   | x |
       5.  | r |   | r |   | r |   | r |   |
       6.  |   | r |   | r |   | r |   | r |
       7.  | r |   | r |   | r |   | r |   |
           +---+---+---+---+---+---+---+---+

Player 1's turn

Enter position of piece you would like to move:
Row No: 2
Col No: 1

Enter position you would like to move to:
Row No: 3
Col No: 0
