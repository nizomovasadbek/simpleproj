#ifndef _KSTDINT_H
#define _KSTDINT_H

typedef char i8;
typedef unsigned char u8;
typedef short i16;
typedef unsigned short u16;
typedef int i32;
typedef unsigned int u32;
#ifdef __x86_64__
    typedef long i64;
    typedef unsigned long u64;
#else
    typedef long long i64;
    typedef unsigned long long u64;
#endif

typedef u64 size_t;
typedef u8 bool;

#define true    1
#define false   0
#define NULL    (void*)0

#define BYTE    sizeof(i8)
#define WORD    sizeof(i16)
#define DWORD   sizeof(i32)
#define QWORD   sizeof(i64)

#endif