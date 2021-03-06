/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Diagonal Matrix C
#include <stdio.h>
  struct Matrix
{
  int A[10];
  int n;
};
void
Set (struct Matrix *m, int i, int j, int x)
{
  if (i == j)
    m->A[i - 1] = x;
}

int
Get (struct Matrix m, int i, int j)
{
  if (i == j)
    return m.A[i - 1];
  else
    return 0;
}

void
Display (struct Matrix m)
{
  int i, j;
  for (i = 0; i < m.n; i++)
    {
      for (j = 0; j < m.n; j++)
	{
	  if (i == j)
	    printf ("%d ", m.A[i]);
	  else
	    printf ("0 ");
	}
      printf ("\n");
    }
}

int
main ()
{
  struct Matrix m;
  m.n = 4;
  Set (&m, 1, 1, 5);
  Set (&m, 2, 2, 8);
  Set (&m, 3, 3, 9);
  Set (&m, 4, 4, 12);
  printf ("%d \n", Get (m, 2, 2));
  Display (m);
  return 0;
}









//Sparse Matrix using C
#include <stdio.h>
#include<stdlib.h>
  struct Element
{
  int i;
  int j;
  int x;
};
struct Sparse
{
  int m;
  int n;
  int num;
  struct Element *ele;
};
void
create (struct Sparse *s)
{
  int i;
  printf ("Eneter Dimensions");
  scanf ("%d%d", &s->m, &s->n);
  printf ("Number of non-zero");
  scanf ("%d", &s->num);
  s->ele = (struct Element *) malloc (s->num * sizeof (struct Element));
  printf ("Eneter non-zero Elements");
  for (i = 0; i < s->num; i++)
    scanf ("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s - >ele[i].x);
}

void
display (struct Sparse s)
{
  int i, j, k = 0;
  for (i = 0; i < s.m; i++)
    {
      for (j = 0; j < s.n; j++)
	{
	  if (i == s.ele[k].i && j == s.ele[k].j)
	    printf ("%d ", s.ele[k++].x);
	  else
	    printf ("0 ");
	}
      printf ("\n");
    }
}

struct Sparse *
add (struct Sparse *s1, struct Sparse *s2)
{
  struct Sparse *sum;
  int i, j, k;
  i = j = k = 0;
  if (s1->n != s2->n && s1->m != s2->m)
    return NULL;
  sum = (struct Sparse *) malloc (sizeof (struct Sparse));
  sum->ele = (struct Element *) malloc ((s1->num + s2 -
					 >num) * sizeof (struct Element));
  while (i < s1->num && j < s2->num)
    {
      if (s1->ele[i].i < s2->ele[j].i)
	sum->ele[k++] = s1->ele[i++];
      else if (s1->ele[i].i > s2->ele[j].i)
	sum->ele[k++] = s2->ele[j++];
      else
	{
	  if (s1->ele[i].j < s2->ele[j].j)
	    sum->ele[k++] = s1->ele[i++];
	  else if (s1->ele[i].j > s2->ele[j].j)
	    sum->ele[k++] = s2->ele[j++];
	  else
	    {
	      sum->ele[k] = s1->ele[i];
	      sum->ele[k++].x = s1->ele[i++].x + s2->ele[j + +].x;
	    }
	}
    }
  for (; i < s1->num; i++)
    sum->ele[k++] = s1->ele[i];
  for (; j < s2->num; j++)
    sum->ele[k++] = s2->ele[j];
  sum->m = s1->m;
  sum->n = s1->n;
  sum->num = k;
  return sum;
}

int
main ()
{
  struct Sparse s1, s2, *s3;
  create (&s1);
  create (&s2);
  s3 = add (&s1, &s2);
  printf ("First Matrix\n");
  display (s1);
  printf ("Second Matrix\n");
  display (s2);
  printf ("Sum Matrix\n");
  display (*s3);
  return 0;
}







//Diagonal Matrix CPP
#include <iostream>
  using namespace std;
class Diagonal
{
private:
  int *A;
  int n;
public:
    Diagonal ()
  {
    n = 2;
    A = new int[2];
  }
  Diagonal (int n)
  {
    this->n = n;
    A = new int[n];
  }
  ~Diagonal ()
  {
    delete[]A;
  }
  void Set (int i, int j, int x);
  int Get (int i, int j);
  void Display ();
  int GetDimension ()
  {
    return n;
  }
};

void
Diagonal::Set (int i, int j, int x)
{
  if (i == j)
    A[i - 1] = x;
}

int
Diagonal::Get (int i, int j)
{
  if (i == j)
    return A[i - 1];
  return 0;
}

void
Diagonal::Display ()
{
  for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
	{
	  if (i == j)
	    cout << A[i - 1] << b ";
else
cout<<" 0 ";
}
cout<<endl;
}
}
int main()
{
int d;
cout<<" Enter Dimensions ";
cin>>d;
Diagonal dm(d);
int x;
cout<<" Enter All Elements ";
for(int i=1;i<=d;i++)
{
for(int j=1;j<=d;j++)
{
cin>>x;
dm.Set(i,j,x);
}
}
dm.Display();
return 0;
}



//Sparse Matrix using C
#include <stdio.h>
#include<stdlib.h>
struct Element
{
int i;
int j;
int x;
};
struct Sparse
{
int m;
int n;
int num;
struct Element *ele;
};
void create(struct Sparse *s)
{
int i;
printf(" Eneter Dimensions ");
scanf(" % d % d ",&s->m,&s->n);
printf(" Number of non - zero ");
scanf(" % d ",&s->num);
s->ele=(struct Element *)malloc(s->num*sizeof(struct
Element));
printf(" Eneter non - zero Elements ");
for(i=0;i<s->num;i++)
scanf(" % d % d % d ",&s->ele[i].i,&s->ele[i].j,&s-
>ele[i].x);
}
void display(struct Sparse s)
{
int i,j,k=0;
for(i=0;i<s.m;i++)
{
for(j=0;j<s.n;j++)
{
if(i==s.ele[k].i && j==s.ele[k].j)
printf(" % d ",s.ele[k++].x);
else
printf(" 0 ");
}
printf(" \ n ");
}
}
struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
struct Sparse *sum;
int i,j,k;
i=j=k=0;
if(s1->n != s2->n && s1->m != s2->m)
return NULL;
sum=(struct Sparse *)malloc(sizeof(struct Sparse));
sum->ele=(struct Element *)malloc((s1->num+s2-
>num)*sizeof(struct Element));
while(i<s1->num && j<s2->num)
{
if(s1->ele[i].i<s2->ele[j].i)
sum->ele[k++]=s1->ele[i++];
else if(s1->ele[i].i>s2->ele[j].i)
sum->ele[k++]=s2->ele[j++];
else
{
if(s1->ele[i].j<s2->ele[j].j)
sum->ele[k++]=s1->ele[i++];
else if(s1->ele[i].j>s2->ele[j].j)
sum->ele[k++]=s2->ele[j++];
else
{
sum->ele[k]=s1->ele[i];
sum->ele[k++].x=s1->ele[i++].x+s2->ele[j+
+].x;
}
}
}
for(;i<s1->num;i++)sum->ele[k++]=s1->ele[i];
for(;j<s2->num;j++)sum->ele[k++]=s2->ele[j];
sum->m=s1->m;
sum->n=s1->n;
sum->num=k;
return sum;
}
int main()
{
struct Sparse s1,s2,*s3;
create(&s1);
create(&s2);
s3=add(&s1,&s2);
printf(" First Matrix \ n ");
display(s1);
printf(" Second Matrix \ n ");
display(s2);
printf(" Sum Matrix \ n ");
display(*s3);
return 0;
}

Lower Triangular C
#include <stdio.h>
#include <stdlib.h>
struct Matrix
{
int *A;
int n;
};
void Set(struct Matrix *m,int i,int j,int x)
{
if(i>=j)
m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
}
int Get(struct Matrix m,int i,int j)
{
if(i>=j)
return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
else
return 0;
}
void Display(struct Matrix m)
{
int i,j;
for(i=1;i<=m.n;i++)
{
for(j=1;j<=m.n;j++)
{
if(i>=j)
printf(" % d ",m.A[m.n*(j-1)+
(j-2)*(j-1)/2+i-j]);
else
printf(" 0 ");
}
printf(" \ n ");
}
}
int main()
{
struct Matrix m;
int i,j,x;
printf(" Enter Dimension ");
scanf(" % d ",&m.n);
m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));
printf(" enter all elements ");
for(i=1;i<=m.n;i++)
{
for(j=1;j<=m.n;j++)
{
scanf(" % d ",&x);
Set(&m,i,j,x);
}
}
printf(" \ n \ n ");
Display(m);
return 0;
}



//Sparse Matrix using C++
#include <iostream>
using namespace std;
class Element
{
public:
int i;
int j;
int x;
};
class Sparse
{
private:
int m;
int n;
int num;
Element *ele;
public:
Sparse(int m,int n,int num)
{
this->m=m;
this->n=n;
this->num=num;
ele=new Element[this->num];
}
~Sparse()
{
delete [] ele;
}
Sparse operator+(Sparse &s);
friend istream & operator>>(istream &is,Sparse &s);
friend ostream & operator<<(ostream &os,Sparse &s);
};
Sparse Sparse::operator+(Sparse &s)
{
int i,j,k;
if(m!=s.m || n!=s.n)
return Sparse(0,0,0);
Sparse *sum=new Sparse(m,n,num+s.num);
i=j=k=0;
while(i<num && j<s.num)
{
if(ele[i].i<s.ele[j].i)
sum->ele[k++]=ele[i++];
else if(ele[i].i > s.ele[j].i)
sum->ele[k++]=s.ele[j++];
else
{
if(ele[i].j<s.ele[j].j)
sum->ele[k++]=ele[i++];
else if(ele[i].j > s.ele[j].j)
sum->ele[k++]=s.ele[j++];
else
{
sum->ele[k]=ele[i];
sum->ele[k++].x=ele[i++].x+s.ele[j++].x;
}
}
}
for(;i<num;i++)sum->ele[k++]=ele[i];
for(;j<s.num;j++)sum->ele[k++]=s.ele[j];
sum->num=k;
return *sum;
}
istream & operator>>(istream &is,Sparse &s)
{
cout<<" Enter non - zero elements ";
for(int i=0;i<s.num;i++)
cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
return is;
}
ostream & operator<<(ostream &os,Sparse &s)
{
int k=0;
for(int i=0;i<s.m;i++)
{
for(int j=0;j<s.n;j++)
{
if(s.ele[k].i==i && s.ele[k].j==j)
cout<<s.ele[k++].x<<" ";
else
cout<<" 0 ";
}
cout<<endl;
}
return os;
}
int main()
{
Sparse s1(5,5,5);
Sparse s2(5,5,5);
cin>>s1;
cin>>s2;
Sparse sum=s1+s2;
cout<<" First Matrix "<<endl<<s1;
cout<<" Second MAtrix "<<endl<<s2;
cout<<" Sum Matrix "<<endl<<sum;
return 0;
}



//Lower Triangular CPP
#include <stdio.h>
#include <stdlib.h>
struct Matrix
{
int *A;
int n;
};
void Set(struct Matrix *m,int i,int j,int x)
{
if(i>=j)
m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
}
int Get(struct Matrix m,int i,int j)
{
if(i>=j)
return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
else
return 0;
}
void Display(struct Matrix m)
{
int i,j;
for(i=1;i<=m.n;i++)
{
for(j=1;j<=m.n;j++)
{
if(i>=j)
printf(" % d ",m.A[m.n*(j-1)+
(j-2)*(j-1)/2+i-j]);
else
printf(" 0 ");
}
printf(" \ n ");
}
}
int main()
{
struct Matrix m;
int i,j,x;
printf(" Enter Dimension ");
scanf(" % d ",&m.n);
m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));
printf(" enter all elements ");
for(i=1;i<=m.n;i++)
{
for(j=1;j<=m.n;j++)
{
scanf(" % d ",&x);
Set(&m,i,j,x);
}
}
printf(" \ n \ n ");
Display(m);
return 0;
}



//Polynomial Representation
#include <stdio.h>
#include<stdlib.h>
struct Term
{
int coeff;
int exp;
};
struct Poly
{
int n;
struct Term *terms;
};
void create(struct Poly *p)
{
int i;
printf(" Number of terms ? ");
scanf(" % d ",&p->n);
p->terms=(struct Term*)malloc(p->n*sizeof(struct
Term));
printf(" Enter terms \ n ");
for(i=0;i<p->n;i++)
scanf(" % d % d ",&p->terms[i].coeff,&p-
>terms[i].exp);
}
void display(struct Poly p)
{
int i;
for(i=0;i<p.n;i++)
printf(" % dx % d + ",p.terms[i].coeff,p.terms[i].exp);
printf(" \ n ");
}
struct Poly *add(struct Poly *p1,struct Poly *p2)
{
int i,j,k;
struct Poly *sum;
sum=(struct Poly*)malloc(sizeof(struct Poly));
sum->terms=(struct Term *)malloc((p1->n+p2-
>n)*sizeof(struct Term));
i=j=k=0;
while(i<p1->n && j<p2->n)
{
if(p1->terms[i].exp>p2->terms[j].exp)
sum->terms[k++]=p1->terms[i++];
else if(p1->terms[i].exp < p2->terms[j].exp)
sum->terms[k++]=p2->terms[j++];
else
{
sum->terms[k].exp=p1->terms[i].exp;
sum->terms[k++].coeff=p1->terms[i+
+].coeff+p2->terms[j++].coeff;
}
}
for(;i<p1->n;i++)sum->terms[k++]=p1->terms[i];
for(;j<p2->n;j++)sum->terms[k++]=p2->terms[j];
sum->n=k;
return sum;
}
int main()
{
struct Poly p1,p2,*p3;
create(&p1);
create(&p2);
p3=add(&p1,&p2);
printf(" \ n ");
display(p1);
printf(" \ n ");
display(p2);
printf(" \ n ");
display(*p3);
return 0;
}

