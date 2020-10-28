/* bubble sort without ifs */

#include <stdio.h>

void bubble_sort(int nums[], int cnt) {
  while (--cnt > 0) {
    int sorted = 1;

    for (int i = 0; i < cnt; ++i) {
      int cond = nums[i] > nums[i + 1];
      int tmp = nums[i + 1];
      nums[i + cond] = nums[i];
      nums[i + 1 - cond] = tmp;
      sorted = sorted && !cond;
    }

    cnt *= !sorted;
  }
}

int main(void) {
  int nums[] = {1, 5, 2, 7, 1, 0, 9};
  int cnt = sizeof(nums) / sizeof(int);

  bubble_sort(nums, cnt);

  /* print sorted nums */
  int i = 0;
  for (; i < cnt - 1; ++i)
    printf("%d ", nums[i]);
  printf("%d\n", nums[i]);
  return 0;
}