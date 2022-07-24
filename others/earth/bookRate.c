/*
a = 1
b = 2

temp = a == 1                 temp: 1
a = b == 2                    a: 2
b = temp == 1                 b: 1

===========================================================================

b[0]
b[1]
b[2]
b[3]

strncpy(temp.reviewerName, b[0].reviewerName, 50);
temp.bookRate                 = b[0].bookRate
temp.id                       = b[0].id

strncpy(b[2].reviewerName, b[0].reviewerName, 50);
b[0].bookRate                 = b[1].bookRate;
b[0].id                       = b[1].id

strncpy(b[1].reviewerName, temp.id, 50);
b[1].bookRate                 = temp.bookRate
b[1].id                       = temp.id

struct book temp;
temp.reviewerName
temp.bookRate
temp.id
+-------+
|       |
|       |
+-------+

*/

#include <stdio.h>

#define RATE_MIN 1.0
#define RATE_MAX 5.0

struct book {
  char reviewerName[50];
  double bookRate;
  int id;
};

int main() {
  int reviewCount;
  int loop1;
  double rate;
  double totalRate;
  double avgRate;
  double highestRate;

  printf("Enter the reviews count: ");
  scanf("%d", &reviewCount);

  if (reviewCount < 0) {
    printf("ERROR");
    return 0;
  } else if (reviewCount == 0) {
    printf("No reviews found");
    return 0;
  }

  struct book b[reviewCount];
  struct book temp;

  for (loop1 = 0; loop1 < reviewCount; loop1++) {
    printf("Rate your book (1.0 - 5.0) and name of the book. \n");
    scanf("%lf %s", &rate, b[loop1].reviewerName);

    if (rate < RATE_MIN || rate > RATE_MAX) {
      loop1--;
      continue;
    }

    b[loop1].id = 1 + loop1;

    b[loop1].bookRate = rate;
    totalRate += rate;

    if (highestRate < b[loop1].bookRate) {
      highestRate = b[loop1].bookRate;
    }

    avgRate = totalRate / (double)reviewCount;
  }

  printf("Average Score: %.2lf \n", avgRate);
  printf("%.2lf \n", highestRate);

  for (loop1 = 0; loop1 < reviewCount; loop1++) {
    printf("%.2lf %s (id: %d)\n", b[loop1].bookRate, b[loop1].reviewerName,
           b[loop1].id);
  }
}
