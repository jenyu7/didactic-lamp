#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int * x, int length)
{
  int i;
  for (i=0; i<length; i++)
    {
      printf("\telement: %d: %d\n", i, x[i]);
    }
}

int main(){
  
  //seed random generator
  srand( time(NULL) );
  
  //Initialization (1)
  int arr1[10]; //first array
  int i; //counter var
  
  //populate first array with random numbers
  for(i = 0; i < 9; i ++)
    {
      arr1[i] = rand();
    }

  arr1[9] = 0;

  //print out elements of first array
  print_array(arr1, 10);


  //Initialization (2)
  int arr2[10]; //second array
  int * ptr; //pointer
  //Use the counter already initialized before

  //populate the second array...using a POINTER
  for (i = 9; i >= 0; i--)
    {
      ptr = &arr1[9-i];
      arr2[i] = *ptr;
    }

  //print out newlines to separate previous prints
  printf("\n\n\n");

  print_array(arr2, 10);
  
}




