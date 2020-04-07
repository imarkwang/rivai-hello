#include <stdio.h>
#include <fcntl.h>
#include <assert.h>

int main (void) {
  asm volatile(
    "auipc t0,0\n\r"
    "addi  a1,t0,0x0200\n\r"
    "csrr a0,mhartid\n\r"
    "lw t0,24(t0)\n\r"
    "ld t0,24(t0)\n\r"
    "jr t0\n\r"
    );

  return 0;
}

