/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//hashing




//Chaining
#ifndef Chains_h
#define Chains_h
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
void
SortedInsert (struct Node **H, int x)
{
  struct Node *t, *q = NULL, *p = *H;
  t = (struct Node *) malloc (sizeof (struct Node));
  t->data = x;
  t->next = NULL;
  if (*H == NULL)
    *H = t;
  else
    {
      while (p && p->data < x)
	{
	  q = p;
	  p = p->next;
	}
      if (p == *H)
	{
	  t->next = *H;
	  *H = t;
	}
      else
	{
	  t->next = q->next;
	  q->next = t;
	}
    }
}

struct Node *
Search (struct Node *p, int key)
{
  while (p != NULL)
    {
      if (key == p->data)
	{
	  return p;
	}
      p = p->next;
    }
  return NULL;
}
#endif /* Chains_h */
#include <stdio.h>
#include "Chains.h"
int
hash (int key)
{
  return key % 10;
}

void
Insert (struct Node *H[], int key)
{
  int index = hash (key);
  SortedInsert (&H[index], key);
}

int
main ()
{
  struct Node *HT[10];
  struct Node *temp;
  int i;
  for (i = 0; i < 10; i++)
    HT[i] = NULL;
  Insert (HT, 12);
  Insert (HT, 22);
  Insert (HT, 42);
  temp = Search (HT[hash (21)], 21);
  printf ("%d ", temp->data);
  return 0;
}







//Linear Probing
#include <stdio.h>
#define SIZE 10
int
hash (int key)
{
  return key % SIZE;
}

int
probe (int H[], int key)
{
  int index = hash (key);
  int i = 0;
  while (H[(index + i) % SIZE] != 0)
    i++;
  return (index + i) % SIZE;
}

void
Insert (int H[], int key)
{
  int index = hash (key);
  if (H[index] != 0)
    index = probe (H, key);
  H[index] = key;
}

int
Search (int H[], int key)
{
  int index = hash (key);
  int i = 0;
  while (H[(index + i) % SIZE] != key)
    i++;
  return (index + i) % SIZE;
}

int
main ()
{
  int HT[10] = { 0 };
  Insert (HT, 12);
  Insert (HT, 25);
  Insert (HT, 35);
  Insert (HT, 26);
  printf ("\nKey found at %d\n", Search (HT, 35));
  return 0;
}
