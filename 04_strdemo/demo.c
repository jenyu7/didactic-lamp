/****************************
 * Jen Yu
 * Period 10 Systems
 * HW #04: Demostringing Code
 * 2017-09-28
 ***************************/

#include <stdio.h>
#include <string.h>

int main()
{
  /***************************
   * strchr(...): 
   * What it does: Looks for the first occurence of a character in a string. 
   * Declaration: char *strchr( char *str, int c)
   * Returns a pointer to the first occurence to c in str, null pointer otherwise
   * NOTE: `int` is able to store all values of chars, but wastes memory if you don't need the extra space. 
   * str is the string being searched, c is the character being searched for. 
   * Operates on null ended strings
   **************************/
  //try out strchr()
  char * s = "llllfllll";
  char letter = 'f';
  char * new_ptr = strchr(s, letter);
  
  printf("The first occurence of %c  in %s is: %s\n", letter, s, new_ptr);

  //what if the character is not in the string?
  s = "llllllll";
  new_ptr = strchr(s, letter);
  printf("The first occurence of %c  in %s is: %s\n", letter, s, new_ptr);
  //If c is not in str, then the function returns (null)


  /**************************
   * strstr(...): 
   * What it does: Finds the first occurence of a substring within a string
   * Declaration: char *strstr( char * str1, char * str2)
   * Returns a pointer to the first occurrence  of str2 within str1, null pointer otherwise
   * str1 is the string being searched, str2 is the substring being searched for. 
   *************************/

  //try out strstr()
  char * whole = "Got shackles on my wings on tight";
  char * part = "wings";
  new_ptr = strstr(whole, part);

  printf("The first occurrence of %s in %s is: %s\n", part, whole, new_ptr);

  //what if non-existent?
  part = "not here!";
  new_ptr = strstr(whole, part);

  printf("The first occurrence of %s in %s is: %s\n", part, whole, new_ptr);
  
}
