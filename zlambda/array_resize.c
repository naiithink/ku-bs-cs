#include <stdio.h>

#define LEN 5
#define LEN_TO 18

int main(void) {
  char *s1 = NULL;
  int ns[LEN] = {0, 1, 2, 3, 4};
  char *s2 = NULL;

  ns[LEN_TO];

  for (int i = 0; i < LEN_TO; i++)
    printf("% 3d: %d\n", i, ns[i]);

  return 0;
}
