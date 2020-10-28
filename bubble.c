/* simple bubble sort */

#include <stdio.h>

void bubble_sort(int nums[], int cnt) {
  while (--cnt) {
    int sorted = 1;

    for (int i = 0; i < cnt; ++i)
      if (nums[i] > nums[i + 1]) {
        sorted = nums[i];
        nums[i] = nums[i + 1];
        nums[i + 1] = sorted;
        sorted = 0;
      }

    if (sorted)
      return;
  }
}

/*
 * 6. as cnt is only a copy of nums count, we can safely change it
 * 7. this variable is used to stop early if array is already sorted
 * 9. put the biggest item from unsorted part
 * to the leftmost position in sorted part
 * 10. algorithm is stable, we do not swap equal values
 * 11. sorted flag may be used for swapping values during bubbling
 * to avoid using additional variables
 * 14. array is not yet sorted
 */

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

/*
 * 33. we need to sort them in ascending order
 * 34. sizeof(nums) returns number of bytes in nums array.
 * sizeof(int) return number of bytes used to store one integer value
 * dividing sizeof(nums) by sizeof(int) we get
 * number of integers stored in nums array
 */