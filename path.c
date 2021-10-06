/* Laxman Adhikari
   CS 241L 

   This is the path.c file of project7 where we have called header file by 
   inlcuding header.h in the top. All the necessary functions are coded in this
   file and are called inside the main function in main.c. I have added few 
   comments in between the code to show what is happening in that part of code.
*/ 

#include "header.h"


int move_next(cell **area, int *pidx)
{
   int r, c;

   r = path[*pidx].row;
   c = path[*pidx].col;

   if (area[r][c].status == 0) {
   /* Check right side */
      if (c == colnumber-1) area[r][c].status = 1;
      else if (area[r][c+1].charval == '0') area[r][c].status = 1;
      else if (area[r][c+1].status == 2) area[r][c].status = 1;
      else {
         (*pidx)++;
         path[*pidx].row = r;
         path[*pidx].col = c+1;
         area[r][c].status = 1;
         return 0;
      }
   }

   if (area[r][c].status == 1) {
   /* Check down side */
      if (r == rownumber-1) area[r][c].status = 2;
      else if (area[r+1][c].charval == '0') area[r][c].status = 2;
      else if (area[r+1][c].status == 2) area[r][c].status = 2;
      else {
         (*pidx)++;
         path[*pidx].row = r+1;
         path[*pidx].col = c;
         area[r][c].status = 2;
         return 1;
      }
   }

   /* No right or down possibility, then go back */
   if (area[r][c].status == 2) {
      (*pidx)--;
      return 2;
   }
   return 0;
}

int search_path(cell **area, int rows, int cols, path_t *path)
{
   int pidx = 0;

   path[pidx].row = 0;
   path[pidx].col = 0;

   while(1) {
      move_next(area, &pidx);

      if (path[pidx].row == target_row && path[pidx].col == target_col) {
         success = 1;  /* Success */
         break;
      }
      if (path[pidx].row == 0 && path[pidx].col == 0 && 
                                area[0][0].status == 2) {
         success = 0;  /* Fail - no path */
         break;
      }
   }
   return pidx;
}

int print_path(int rows, int cols, path_t *path, int pidx)
{

   int i, j;
   int r, c;
   char **pt;

   if (success) printf("PATH FOUND!\n");
   else {
      printf("no path found.\n");
      return 0;
   }

   pt = (char **) malloc (rownumber * sizeof(*pt));
   for (i = 0; i < rownumber; i++) {
      pt[i] = (char *) malloc (colnumber);
      for (j = 0; j < colnumber; j++)
         pt[i][j] = '0';
   }

   for (i = 0; i <= pidx; i++) {
      r = path[i].row;
      c = path[i].col;
      pt[r][c] = '1';
   }

   for (i = 0; i < rownumber; i++) {
      for (j = 0; j < colnumber; j++) {
         printf("%c", pt[i][j]);
      }
      printf("\n");
   }
   return 0;
}

/* Function to release the allocated memory */
void free_memory(cell **area, int rows)
{
   int i;

   for (i = 0; i < rows; i++) free(area[i]);
   free (area);
}
