#include "gol.h"
#include "load_lexicon.h"

int main(int argc, char **argv)
{
  // Read from GOL lexicons if path is passed
  if (argc >= 2)
  {
    char *lexicon_file_path = argv[1];
    printf("File = %s:\n", lexicon_file_path);

    read_from_file(lexicon_file_path, GRID_DIM);
  }
  srand(time(0));
  InitWindow(GRID_SIZE, GRID_SIZE, "GOL");
  SetTargetFPS(20);

  int alive_cell_count = 0;
  bool draw_only = true;
  while (!WindowShouldClose())
  {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      // Use the mouse button to initialize alive cells
      int mouseX = (int)GetMouseX() / CELL_SIZE;
      int mouseY = (int)GetMouseY() / CELL_SIZE;
      init_grid(mouseX, mouseY);

      // InitAliveCell selected_cell = {.x = mouseX,.y = mouseY,.state=ALIVE};
      // alive_cells[cell_count] = selected_cell;
    }
    if (IsKeyPressed(KEY_ENTER))
    {
      draw_only = !draw_only;
      if (draw_only)
      {
        for (size_t i = 0; i < GRID_DIM; ++i)
        {
          for (size_t j = 0; j < GRID_DIM; ++j)
          {
            grid[i][j].current_state = DEAD;
          }
        }
      }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    alive_cell_count = draw_grid();
    if (alive_cell_count == 0)
      draw_only = true;
    if (!draw_only)
      get_next_state();

    EndDrawing();
  };
  return 0;
}

void init_grid(int x, int y)
{
  grid[x][y].current_state = !grid[x][y].current_state;
  // for (size_t i = 0; i < GRID_DIM * GRID_DIM; ++i)
  // {
  //       int x = alive_cells[i].x;
  //       int y = alive_cells[i].y;
  //       grid[x][y].state = ALIVE;
  //   }
}

int draw_grid()
{
  int alive_count = 0;
  for (size_t i = 0; i < GRID_DIM; ++i)
  {
    DrawLine(0, i * CELL_SIZE, GRID_SIZE, i * CELL_SIZE, BLACK);
    DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, GRID_SIZE, BLACK);
    for (size_t j = 0; j < GRID_DIM; ++j)
    {
      Cell cell = grid[i][j];
      if (cell.current_state == ALIVE)
      {
        DrawRectangle(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1, BLACK);
        alive_count++;
      }
    }
  }
  return alive_count;
}

void get_next_state()
{
  for (size_t i = 0; i < GRID_DIM; ++i)
  {
    for (size_t j = 0; j < GRID_DIM; ++j)
    {
      State state = check_state(i, j);
      grid[i][j].new_state = state;
    }
  }

  for (size_t i = 0; i < GRID_DIM; ++i)
  {
    for (size_t j = 0; j < GRID_DIM; ++j)
    {
      grid[i][j].current_state = grid[i][j].new_state;
    }
  }
}
State check_state(size_t i, size_t j)
{
  int alive_neighbour_count = 0;
  // Interate through the 8 neighbours of a give cell (i,j)
  for (int dx = -1; dx <= 1; ++dx)
  {
    for (int dy = -1; dy <= 1; ++dy)
    {
      // skip the central cell
      if (dx == 0 && dy == 0)
        continue;
      size_t x = i + dx;
      size_t y = j + dy;
      // check bounds
      if (x < 0 || y < 0 || x >= GRID_DIM || y >= GRID_DIM)
        continue;
      // check if the neghbours state
      if (grid[x][y].current_state == ALIVE)
        alive_neighbour_count++;
    }
  }
  if (grid[i][j].current_state == ALIVE)
  {
    /* Rule 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation*/
    if (alive_neighbour_count < 2)
      return DEAD;
    /* Any live cell with two or three neighbors lives to the next state */
    if (alive_neighbour_count >= 2 && alive_neighbour_count <= 3)
      return ALIVE;
    /* Any live cell with more than three live neighbors dies, as if by overpopulation*/
    if (alive_neighbour_count > 3)
      return DEAD;
  }
  else
  {
    /* Any dead cell with exactly three live neighbours becomes live cell */
    if (alive_neighbour_count == 3)
      return ALIVE;
  }
  return DEAD;
}