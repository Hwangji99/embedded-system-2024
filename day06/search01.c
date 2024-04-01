// date : 2024-03-20

/* 순차탐색 */

#include <stdio.h>

int lSearch();

void main()
{
   int ary[] = {3, 5, 2, 4, 9, 8, 1};
   int size = sizeof(ary) / sizeof(int);
   int ridx;
   ridx = lSearch(ary, size, 9);
   if(ridx == -1) printf("찾는 원소가 없습니다\n");
   else {
      printf("찾은 인덱스 : %d\n", ridx);
   }


}

int lSearch(int *ary, int n, int value)
{
   //int size = sizeof(ary) / sizeof(int);

   int i;

   for(i = 0; i < n; i++)
   {
      if(ary[i] == value)
      {
         return i;
      }
   }
}
