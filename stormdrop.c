// Copyright William Stafford Parsons

#include <stdint.h>

struct stormdrop_state {
  uint64_t a;
  uint64_t b;
};

uint32_t stormdrop(struct stormdrop_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 1111111111111111;
  return s->a;
}
