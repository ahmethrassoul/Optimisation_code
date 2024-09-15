#ifndef _RDTSC_H
#define _RDTSC_H

#include <stdint.h>

__attribute__((always_inline))
static inline void serialize()
{
    asm volatile("cpuid\n\t" ::: "%rax", "%rbx", "%rcx", "%rdx");
}

__attribute__((always_inline))
static inline uint64_t rdtsc()
{
    register uint64_t res;
    asm volatile (
        "rdtsc\n\t"
        "shl $0x20, %%rdx\n\t" /* shift higher order bits */
        "orq %%rax, %%rdx\n\t" /* combine lower and higher order */
        : "=d" (res) :: "%rax"
    );
    return res;
}

__attribute__((always_inline))
static inline uint64_t rdtscp()
{
    register uint64_t res;
    asm volatile (
        "rdtscp\n\t"
        "shl $0x20, %%rdx\n\t" /* shift higher order bits */
        "orq %%rax, %%rdx\n\t" /* combine lower and higher order */
        : "=d" (res) :: "%rax"
    );
    return res;
}

__attribute__((always_inline))
static inline uint64_t ts_start()
{
    uint64_t ret;
    serialize();
    ret = rdtsc();
    serialize();
    return ret;
}

__attribute__((always_inline))
static inline uint64_t ts_stop()
{
    serialize();
    const uint64_t tmp = rdtscp();
    serialize();
    return tmp;
}

#endif
