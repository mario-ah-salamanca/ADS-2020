#include <iostream>
#include <vector>

#include <queue>

using namespace std;

const int INF = (1 << 30); // large number to represent infinity

// Floyd-Warshall Algorithm is a Dynamic programming algorithm used to find shortest paths between pairs of cities
// Running time is O(n^3)
int find_meetup_m(const vector< vector<int> >& matrix, const int& your_city, const int& friend_city)
{
  /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
  int n = matrix.size();
  int distances[n][n];
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i == j)
      {
        distances[i][j] = 0;
      }
      else if(matrix[i][j] != -1)
      {
        distances[i][j] = matrix[i][j];
      }else{
        distances[i][j] = INF;
      }
    }
  }
  /*Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
  for(int k = 0; k < n; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
      }
    }
  }
  //finds the city m and it returns it
  int res = INF;
  int m=0;
  for(int i = 0; i < n; i++)
  {
    if(res > max(distances[your_city][i], distances[friend_city][i]))
    {
      res = max(distances[your_city][i], distances[friend_city][i]);
      m = i;
    }
  }
  return m;
}

int main(){
  return 0;
}