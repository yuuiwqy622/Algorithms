#include <cstdio>
#include <thread>

const int CNT = 1000000;

void fill(int *nums, int s, int e) {
  for (; s < e; ++s)
    nums[s] = s;
}

int main() {
  int *nums = new int[CNT];
  std::thread t1(fill, nums, 0, 500000);
  std::thread t2(fill, nums, 500000, 1000000);
  t1.join();
  for (int i = 0; i < 500000; ++i) {
    printf("%d\n", nums[i]);
  }
  t2.join();

  for (int i = 500000; i < 1000000; ++i) {
    printf("%d\n", nums[i]);
  }

  delete[] nums;
  return 0;
}