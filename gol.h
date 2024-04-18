#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <raylib.h>

#define GRID_SIZE 1000 
#define CELL_SIZE 10 

#define GRID_DIM (GRID_SIZE / CELL_SIZE)

#define BACKGROUND ' '
#define CELL_SYMBOL '+'

typedef enum
{
  DEAD,
  ALIVE
} State;

typedef struct
{
  State current_state;
  State new_state;
} Cell;

// Initialize Grid of characters
Cell grid[GRID_DIM][GRID_DIM] = {{DEAD}};
// InitAliveCell alive_cells [GRID_DIM * GRID_DIM] = {{.state=DEAD}};

void init_grid(int,int);
int draw_grid();
void get_next_state();
State check_state(size_t i , size_t j);