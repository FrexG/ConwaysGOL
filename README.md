# Conway's Game of Life implementation in raylib C

This is a simple implementation of Conway's Game of Life simulation using C and the Raylib library. It allows you to interact with the Game of Life in two ways:

https://github.com/FrexG/ConwaysGOL/assets/25264637/031ae1e4-d59b-48ba-9ed3-79b6c8a36879

- **Drawing Patterns**: Click on the grid to manually create your initial patterns for the simulation.
- **Loading Lexicons**: Load pre-defined patterns from ASCII lexicon text files.

## Features:
Implements Conway's Game of Life rules.
Interactive grid for drawing patterns.
Ability to load patterns from ASCII lexicon files.
Visualizes the simulation with Raylib.
## How to Use:

- Download and install the Raylib library following the instructions on their website: https://www.raylib.com/.
- Make sure you have a C compiler installed.
- clone the repository
- Build the project
``` Bash
make
```
or compile it
```Bash
gcc -Wall -c gol.c -o gol -lraylib
```
### run
- Drawing patterns
```Bash
./gol
```
Click on the grid cells to turn them alive (represented by a filled cell).
Click again on a live cell to turn it dead (represented by an empty cell).
Press  `Enter` to start/stop the simulation.
- Loading Lexicons:
```Bash
./gol sample_pattern.txt
```
Place your ASCII lexicon text files in the same directory as the executable.
The lexicon file format should be a simple grid representation with asterisks (*) representing live cells and any other character representing dead cells.
Press the L key to open a file dialog. Select the desired lexicon file to load the pattern.
Note:

This is a basic implementation and may not include advanced features like wrapping around the grid edges or speed controls.
Building Upon This:

This code provides a foundation for further exploration of Conway's Game of Life. You can extend it by adding functionalities like:

Grid size customization.
Speed control for the simulation.
Saving and loading patterns in custom formats.
Feel free to modify and enhance the code to create your own customized Game of Life experience!


