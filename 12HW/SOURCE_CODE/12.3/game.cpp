#include <bits/stdc++.h>

using namespace std;

class PuzzleBoard{
private:
  vector< set<int> > edges;
  vector< vector<int> > fields;
  int number_of_nodes;
  int boardSize;
  int actual_X, actual_Y;
  int get_node(const int& x, const int& y)
  {
    return (x*boardSize + y);
  }

  bool out_of_borders(const int& x, const int& y)
  {
    if((x < 0 || x >= boardSize || y < 0 || y >= boardSize)){
      return 1;
    }
    else{
      return 0;
    }
  }

public:
  /*constructor should create thegraph (as you defined my_iterator in subpoint (a) with the values from fields.If fields is null, then initialize the fields of the board withrandom values between 1 and boardSize-1.*/
  PuzzleBoard(int boardSize, int **fields = NULL){
    if(fields == NULL)
    {
      srand(time(NULL));
      fields = new int*[boardSize];
      for(int i = 0; i < boardSize; i++)
      {
        fields[i] = new int[boardSize];
        for(int j = 0; j < boardSize; j++)
        {
          fields[i][j] = rand()%boardSize + 1;
        }
      }
    }
    this->boardSize = boardSize;
    number_of_nodes = boardSize*boardSize;
    edges.resize(number_of_nodes, set<int>());
    for(int i = 0; i < boardSize; i++)
    {
      for(int j = 0; j < boardSize; j++)
      {
        int Current_Node = get_node(i, j);
        int next;
        if(!out_of_borders(i + fields[i][j], j))
        {
          next = get_node(i + fields[i][j], j);
          edges[Current_Node].insert(next);
        }
        if(!out_of_borders(i - fields[i][j], j))
        {
          next = get_node(i - fields[i][j], j);
          edges[Current_Node].insert(next);
        }
        if(!out_of_borders(i, j + fields[i][j]))
        {
          next = get_node(i, j + fields[i][j]);
          edges[Current_Node].insert(next);
        }
        if(!out_of_borders(i, j - fields[i][j]))
        {
          next = get_node(i, j - fields[i][j]);
          edges[Current_Node].insert(next);
        }
      }
    }
    for(int i = 0; i < boardSize; i++)
    {
      for(int j = 0; j < boardSize; j++)
      {
        this->fields[i][j] = fields[i][j];
      }
    }
    actual_X = actual_Y = 0;
  }

/*makes the move (if valid), direction is 0 for up, 1for right, 2 for down, 3 for left. Returns true if the move was valid, false otherwise.*/
  bool makeMove(int direction){
    int next_x;
    int next_y;
    int current;
    int next;
    set<int>::iterator my_iterator;
    switch(direction){
      //up
      case 0:
      next_x = actual_X - fields[actual_X][actual_Y];
      next_y = actual_Y;
      if(out_of_borders(next_x, next_y))
      {
        return 0;
      }
      current = get_node(actual_X, actual_Y);
      next = get_node(next_x, next_y);
      my_iterator = edges[current].find(next);
      if(my_iterator == edges[current].end())
      {
        return 0;
      }
      actual_X = next_x;
      actual_Y = next_y;
      break;

      //right
      case 1:
      next_x = actual_X;
      next_y = actual_Y + fields[actual_X][actual_Y];
      if(out_of_borders(next_x, next_y))
      {
        return 0;
      }
      current = get_node(actual_X, actual_Y);
      next = get_node(next_x, next_y);
      my_iterator = edges[current].find(next);
      if(my_iterator == edges[current].end())
      {
        return 0;
      }
      actual_X = next_x;
      actual_Y = next_y;
      break;

      //down
      case 2:
      next_x = actual_X + fields[actual_X][actual_Y];
      next_y = actual_Y;
      if(out_of_borders(next_x, next_y))
      {
        return 0;
      }
      current = get_node(actual_X, actual_Y);
      next = get_node(next_x, next_y);
      my_iterator = edges[current].find(next);
      if(my_iterator == edges[current].end())
      {
        return 0;
      }
      actual_X = next_x;
      actual_Y = next_y;
      break;

      //left
      case 3:
      next_x = actual_X;
      next_y = actual_Y - fields[actual_X][actual_Y];
      if(out_of_borders(next_x, next_y))
      {
        return 0;
      }
      current = get_node(actual_X, actual_Y);
      next = get_node(next_x, next_y);
      my_iterator = edges[current].find(next);
      if(my_iterator == edges[current].end())
      {
        return 0;
      }
      actual_X = next_x;
      actual_Y = next_y;
      break;
    }
    // true if is a valid move
    return 1;
  }

//checks if the game is not over, aka checks if the actual value of x and y are the bottom right corner
  bool getResult(){
    return (actual_X == boardSize-1 && actual_Y == boardSize-1);
  }


  friend ostream& operator<<(ostream &os, const PuzzleBoard& m);



/*returns the minimum number of moves needed to solve the puzzle,and -1 if it is not solvable.*/

  int solve(){
    int d[number_of_nodes];
    memset(d, -1, sizeof(d));
    queue<int> my_queue;
    d[0] = 0;
    my_queue.push(0);
    while(!my_queue.empty())
    {
      int current = my_queue.front();
      my_queue.pop();
      for(auto next : edges[current])
      {
        if(d[next] == -1)
        {
          d[next] = d[current] + 1;
          my_queue.push(next);
        }
      }
    }

    if(d[number_of_nodes-1] == -1)
    {
      return -1;
    }
    return (d[number_of_nodes]);
  }
};