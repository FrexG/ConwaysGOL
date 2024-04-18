char gol_lexicon_string[] =
    "....**......**....\n...*.*......*.*...\n...*..........*...\n**.*.........."
    "*.**\n**.*.*..**..*.*.**\n...*.*.*..*.*.*...\n...*.*.*..*.*.*...\n**.*.*.."
    "**..*.*.**\n**.*..........*.**\n...*..........*...\n...*.*......*.*...\n.."
    "..**......**....";

int read_from_file(char* file_path, size_t buffer_size){
  FILE* file = fopen(file_path,"r");
  if(file == NULL){
    fprintf(stderr,"Error opening file: %s\n",file_path);
    return 1;
  }
  // Buffer to store a line of text
  char line[buffer_size];
  // read line
  int row = 0;
  while(fgets(line,sizeof(line),file) !=NULL){
    // Remove the newline character at the end (if present)
    size_t len = strlen(line);
    if (line[len - 1] == '\n') {
      line[len - 1] = '\0'; // Replace newline with null terminator
    }
    // 
    for(size_t i = 0; i < len;++i){
      if(line[i] == '*'){
        grid[i][row].current_state = ALIVE;
      }
    }
    row++;
  }
  return 0;
}
void convertToArray(char *lexicon, int rows, int cols, int arr[rows][cols])
{
  char *token = strtok(lexicon, "\n");
  printf("Token = %s\n",token);

  int row = 0;
  while (token != NULL)
  {
    int col_count = 0;
    for (size_t col = 0; col < cols; ++col)
    {
       arr[row][col] = (token[col] == '*') ? 1 : 0;
      col_count++;
    }
    row++;
    token = strtok(NULL, "\n");
    printf("Cols = %i\n", col_count);
  }

  printf("Rows = %i\n", row);
}