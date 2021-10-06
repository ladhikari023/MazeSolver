/* Laxman Adhikari
   CS 241L 

   This is the header file of project7 where we have declared important 
   variables and functions that we are using in this project.
*/ 

#ifndef _MAZEH_
#define _MAZEH_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXROW    200


typedef struct {
   char charval;
   int status;
} cell;

typedef struct {
   int row;
   int col;
} path_t;

path_t path[500];              /* Path to keep the searching path*/
int rownumber, colnumber;      /* Size of existing maze */
int target_row, target_col;    /* Target location */
int success;                   /* Success flag, 1 = Success, 0 = Fail */

int print_path(int r, int c, path_t *p, int pd);
int search_path(cell **a, int r, int c, path_t *p);
void free_memory(cell **a, int r);
#endif

