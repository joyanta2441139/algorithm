/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Queue using Array
#include <stdio.h>
#include <stdlib.h>
struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};
void
create (struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = -1;
  q->Q = (int *) malloc (q->size * sizeof (int));
}

void
enqueue (struct Queue *q, int x)
{
  if (q->rear == q->size - 1)
    printf ("Queue is Full");
  else
    {
      q->rear++;
      q->Q[q->rear] = x;
    }
}

int
dequeue (struct Queue *q)
{
  int x = -1;
  if (q->front == q->rear)
    printf ("Queue is Empty\n");
  else
    {
      q->front++;
      x = q->Q[q->front];
    }
  return x;
}

void
Display (struct Queue q)
{
  int i;
  for (i = q.front + 1; i <= q.rear; i++)
    printf ("%d ", q.Q[i]);
  printf ("\n");
}

int
main ()
{
  struct Queue q;
  create (&q, 5);
  enqueue (&q, 10);
  enqueue (&q, 20);
  enqueue (&q, 30);
  Display (q);
  printf ("%d ", dequeue (&q));
  return 0;
}





//Queue using CPP
#include <iostream>
using namespace std;
class Queue
{
private:
  int front;
  int rear;
  int size;
  int *Q;
public:
    Queue ()
  {
    front = rear = -1;
    size = 10;
    Q = new int[size];
  }
  Queue (int size)
  {
    front = rear = -1;
    this - >size = size;
    Q = new int[this->size];
  }
  void enqueue (int x);
  int dequeue ();
  void Display ();
};

void
Queue::enqueue (int x)
{
  if (rear == size - 1)
    printf ("Queue Full\n");
  else
    {
      rear++;
      Q[rear] = x;
    }
}

int
Queue::dequeue ()
{
  int x = -1;
  if (front == rear)
    printf ("Queue is Empty\n");
  else
    {
      x = Q[front + 1];
      front++;
    }
  return x;
}

void
Queue::Display ()
{
  for (int i = front + 1; i <= rear; i++)
    printf ("%d ", Q[i]);
  printf ("\n");
}

int
main ()
{
  Queue q (5);
  q.enqueue (10);
  q.enqueue (20);
  q.enqueue (30);
  q.Display ();
  return 0;
}



//Circular Queue
#include <stdio.h>
#include <stdlib.h>
struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};
void
create (struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (int *) malloc (q->size * sizeof (int));
}

void
enqueue (struct Queue *q, int x)
{
  if ((q->rear + 1) % q->size == q->front)
    printf ("Queue is Full");
  else
    {
      q->rear = (q->rear + 1) % q->size;
      q->Q[q->rear] = x;
    }
}

int
dequeue (struct Queue *q)
{
  int x = -1;
  if (q->front == q->rear)
    printf ("Queue is Empty\n");
  else
    {
      q->front = (q->front + 1) % q->size;
      x = q->Q[q->front];
    }
  return x;
}

void
Display (struct Queue q)
{
  int i = q.front + 1;
  do
    {
      printf ("%d ", q.Q[i]);
      i = (i + 1) % q.size;
    }
  while (i != (q.rear + 1) % q.size);
  printf ("\n");
}

int
main ()
{
  struct Queue q;
  create (&q, 5);
  enqueue (&q, 10);
  enqueue (&q, 20);
  enqueue (&q, 30);
  enqueue (&q, 40);
  enqueue (&q, 50);
  enqueue (&q, 60);
  Display (q);
  printf ("%d ", dequeue (&q));
  return 0;
}





//Queue using Linked List
#include <stdio.h>
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

void
Display ()
{
  struct Node *p = front;
  while (p)
    {
      printf ("%d ", p->data);
      p = p->next;
    }
  printf ("\n");
}

int
main ()
{
  enqueue (10);
  enqueue (20);
  enqueue (30);
  enqueue (40);
  enqueue (50);
  Display ();
  printf ("%d ", dequeue ());
  return 0;
}
