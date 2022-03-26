/******************************************************************************
 In this program M,N,P and Q are arrays for houses, shops, bridges and wharves 
 respectively. The bridge and wharf arrays keep the addresses of the before and 
 after nearest bridge and wharf to the house of their index. 
  The minimum paths which are the results are kept in the MinDistance matrix.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int M[100], N[100], P[100], Q[100];
int m, n, p, q;
int D1, D2, D3, D4, S1, S2, S;
int MinDistance[100][100];
int i, j, last;
int bridge[2][100], wharf[2][100];
int
main ()
{
  
  // READING INPUTS
  
  printf(" \n Enter the number of houses: ");
  scanf ("%d", &m);
  printf(" \n Enter" " %d non decreasing logo number for houses:  ", m);
  for (i = 1; i <= m; i++)
    scanf ("%d", &M[i]);
  printf(" \n Enter the number of shops: ");
  scanf ("%d", &n);
  printf(" \n Enter" " %d non decreasing logo number for shops:  ", n);
  for (i = 1; i <= n; i++)
    scanf ("%d", &N[i]);
  printf(" \n Enter the number of bridges: ");
    scanf ("%d", &p);
  printf(" \n Enter" " %d non decreasing logo number for bridges:  ", p);
  for (i = 1; i <= p; i++)
    scanf ("%d", &P[i]);
  printf(" \n Enter the number of wharves: ");
  scanf ("%d", &q);
  printf(" \n Enter" " %d non decreasing logo number for wharves:  ", q);
  for (i = 1; i <= q; i++)
    scanf ("%d", &Q[i]);

  // DETERMINING THE NEAREST BRIDGES AND WHARFS TO HOUSES

  for (i = 0; i < 2; i++)
    for (j = 0; j < 100; j++)
      {
	bridge[i][j] = 1000;
	wharf[i][j] = 1000;
      }
  i = 1;
  j = 1;
  last = 1000;
  while (i <= m && j <= p)
    {
    bridge[0][i] = last;
       if (M[i] < P[j])
	{
	  bridge[1][i] = P[j];
	  i++;
	}
      else
	{
	  bridge[0][i] = P[j];
	  last = P[j];
	  j++;
	}
    }
    if (i < m)
	for (int k = i +1; k <= m; k++)
	bridge[0][k] = last;
  i = 1;
  j = 1;
  last = 1000;
  while (i <= m && j <= q)
    {
        wharf[0][i] = last;
      if (M[i] < Q[j])
	{
	  wharf[1][i] = Q[j];
	  i++;
	}
      else
	{
	  wharf[0][i] = Q[j];
	  last = Q[j];
	  j++;
	}
	if (i < m)
	for (int k = i +1; k <= m; k++)
	wharf[0][k] = last;
    }
    
    printf("\n");
    
//  CALCULATION THE MINIMUM TIME FROM ANY HOME TO ANY SHOP           

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      {
	D1 = abs (M[i] - bridge[0][i]) + abs (N[j] - bridge[0][i]) + 4;
	D2 = abs (M[i] - bridge[1][i]) + abs (N[j] - bridge[1][i]) + 4;
	D3 = 2 * (abs (M[i] - wharf[0][i]) + abs (N[j] - wharf[0][i])) + 4;
    D4 = 2 * (abs (M[i] - wharf[1][i]) + abs (N[j] - wharf[1][i])) + 4;

	if (D1 < D2) S1 = D1;
	  else S1 = D2;
	if (D3 < D4) S2 = D3;
	  else S2 = D4; 
	if (S1 < S2) MinDistance[i][j] = S1;
	  else  MinDistance[i][j] = S2;

      }

  for (i = 1; i <= m; i++){
      printf( "\n");
     for (j = 1; j <= n; j++)
    printf (" %4d ", MinDistance[i][j]);
  }  
  return 0;
}


