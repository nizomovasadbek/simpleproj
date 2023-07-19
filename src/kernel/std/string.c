#include "string.h"

i8 tolower(i8 c) {
    return (c >= 'A' && c <= 'Z')?c+32:c;
}

i8 toupper(i8 c) {
    return (c >= 'a' && c <= 'z')?c-32:c;
}