#include "impl.h"

char* IntToBinaryRepresentation(char *buf, int num) {
  for (int i = sizeof(int) * 8, j = 0; i > 0; i--, j++) {
    buf[i - 1] = ((num >> j) & 0x01) ? '1' : '0';
  }

  buf[sizeof(int) * 8] = '\0';
  return buf;
}
