/* Laxman Adhikari
   CS 241L 

   This is the main program of project7 where we have called header file by 
   inlcuding header.h in the top. After that I wrote main function inside 
   which I have declared different variables and used them accordingly. The 
   description are given in between the codes so that it would be easy to keep
   track of what is happening in each part of code. I have called three function 
   from path.c inside the main function which seaarches path, removes the path, 
   and frees the memory.
*/ 

#include "header.h"

int main(int argc, char *argv[])
{
   char rowstr[200];   /* variable to keep line data from input file */
   cell **area;
   int idx, i, len;
   int pidx;

   /* Allocate array of MAXROW cell pointer */
   area = (cell **) malloc (MAXROW * sizeof(cell *));
   idx = 0;

   /* Load data from input file, to the array */
   while(fgets(rowstr, 200, stdin)) {
      rowstr[strcspn(rowstr, "\n\r")] = 0;
      len = strlen(rowstr);
      if (len < 2) break;

      /* Allocate memory for each row */
      colnumber = len;
      area[idx] = (cell *)malloc(len * sizeof(cell));

      /* Fill the cell of array, with data from file*/
      for (i = 0; i < len; i++) {
         area[idx][i].charval = rowstr[i];
         area[idx][i].status = 0;
      }
      idx++;
   }

   /* Set rownumber (total row), colnumber (total column), *
    * and target location                                  */
   rownumber = idx;
   target_row = rownumber-1;
   target_col = colnumber-1;

   /* Call search_path function, to search the path from origin to the *
    * target location, the path result will be kept in path argument   */
   pidx = search_path(area, rownumber, colnumber, path);

   /* Print the result */
   print_path(rownumber, colnumber, path, pidx);

   /* Release the previous allocated memory */
   free_memory(area, rownumber);

   return 0;
}
