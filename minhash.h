#include <stdint.h>

extern "C" {

typedef struct {
  uint32_t hash;
  uint32_t pos;
} Min;

Min minhash (char*, int, int);

}
