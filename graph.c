/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Graph Traversals
#ifndef Queue_h
#define Queue_h
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;
void
enqueue (int x)
{
  struct Node *t;
  t = (struct Node *) malloc (sizeof (struct Node));
  if (t == NULL)
    printf ("Queue is FUll\n");
  else
    {
      t->data = x;
      t->next = NULL;
      if (front == NULL)
	front = rear = t;
      else
	{
	  rear->next = t;
	  rear = t;
	}
    }
}

int
dequeue ()
{
  int x = -1;
  struct Node *t;
  if (front == NULL)
    printf ("Queue is Empty\n");
  else
    {
      x = front->data;
      t = front;
      front = front->next;
      free (t);
    }
  return x;
}

int
isEmpty ()
{
  return front == NULL;
}
#endif /* Queue_h */
#include <stdio.h>
#include "Queue.h"
void
BFS (int G[][7], int start, int n)
{
  int i = start, j;
  int visited[7] = { 0 };
  printf ("%d ", i);
  visited[i] = 1;
  enqueue (i);
  while (!isEmpty ())
    {
      i = dequeue ();
      for (j = 1; j < n; j++)
	{
	  if (G[i][j] == 1 && visited[j] == 0)
	    {
	      printf ("%d ", j);
	      visited[j] = 1;
	      enqueue (j);
	    }
	}
    }
}

void
DFS (int G[][7], int start, int n)
{
  static int visited[7] = { 0 };
  int j;
  if (visited[start] == 0)
    {
      printf ("%d ", start);
      visited[start] = 1;
      for (j = 1; j < n; j++)
	{
	  if (G[start][j] == 1 && visited[j] == 0)
	    DFS (G, j, n);
	}
    }
}

int
main ()
{
  int G[7][7] = { {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 1, 0, 1, 1},
  {0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0}
  };
  DFS (G, 4, 7);
  return 0;
}




//Prims
#include <iostream>
#define I INT_MAX
using namespace std;
int cost[][8] = { {I, I, I, I, I, I, I, I},
{I, I, 25, I, I, I, 5, I},
{I, 25, I, 12, I, I, I, 10},
{I, I, 12, I, 8, I, I, I},
{I, I, I, 8, I, 16, I, 14},
{I, I, I, I, 16, I, 20, 18},
{I, 5, I, I, I, 20, I, I},
{I, I, 10, I, 14, 18, I, I}
};
int near[8] = { I, I, I, I, I, I, I, I };

int t[2][6];
int
main ()
{
  int i, j, k, u, v, n = 7, min = I;
  for (i = 1; i <= n; i++)
    {
      for (j = i; j <= n; j++)
	{
	  if (cost[i][j] < min)
	    {
	      min = cost[i][j];
	      u = i;
	      v = j;
	    }
	}
    }
  t[0][0] = u;
  t[1][0] = v;
  near[u] = near[v] = 0;
  for (i = 1; i <= n; i++)
    {
      if (near[i] != 0)
	{
	  if (cost[i][u] < cost[i][v])
	    near[i] = u;
	  else
	    near[i] = v;
	}
    }
  for (i = 1; i < n - 1; i++)
    {
      min = I;
      for (j = 1; j <= n; j++)
	{
	  if (near[j] != 0 && cost[j][near[j]] < min)
	    {
	      k = j;
	      min = cost[j][near[j]];
	    }
	}
      t[0][i] = k;
      t[1][i] = near[k];
      near[k] = 0;
      for (j = 1; j <= n; j++)
	{
	  if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
	    near[j] = k;
	}
    }
  for (i = 0; i < n - 1; i++)
    {
      cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }
}





//Kruskals
#include <stdio.h>
#define I 65535
int edge[9][3] = { {1, 2, 28}, {1, 6, 10}, {2, 3, 16}, {2, 7, 14}, {3, 4, 12},
{4, 5, 22}, {4, 7, 18}, {5, 6, 25}, {5, 7, 24}
};
int set[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
int included[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void
join (int u, int v)
{
  if (set[u] < set[v])
    {
      set[u] += set[v];
      set[v] = u;
    }
  else
    {
      set[v] += set[u];
      set[u] = v;
    }
}

int
find (int u)
{
  int x = u, v = 0;
  while (set[x] > 0)
    {
      x = set[x];
    }
  while (u != x)
    {
      v = set[u];
      set[u] = x;
      u = v;
    }
  return x;
}

int t[2][7];
int
main (int argc, const char *argv[])
{
  int u = 0, v = 0, i, j, k = 0, min = 65535, n = 9;
  i = 0;
  while (i < 6)
    {
      min = 65535;
      for (j = 0; j < n; j++)
	{
	  if (included[j] == 0 && edge[j][2] < min)
	    {
	      u = edge[j][0];
	      v = edge[j][1];
	      min = edge[j][2];
	      k = j;
	    }
	}
      if (find (u) != find (v))
	{
	  t[0][i] = u;
	  t[1][i] = v;
	  join (find (u), find (v));
	  included[k] = 1;
	  i++;
// printf("%d %d %d %d\n",u,v,find(u),find(v));
	}
      else
	{
	  included[k] = 1;
	}
    }
  printf ("Spanning Tree\n");
  for (i = 0; i < 6; i++)
    {
      printf ("%d %d\n", t[0][i], t[1][i]);
    }
  return 0;
}
