#include <stdio.h>

#define real unsigned long long int
int xor_c64(register int* arr, register real size) {
    register real res = 0;
    if (size & 1) res ^= *(arr+(--size));
    register const real* end = (real*)(arr+size);
    for (register real* p = (real*)arr; p < end; p++) res ^= *(p);
    return res ^ (res>>32); 
}

int xorArray_c(register int *arr, const unsigned long long int size) {
    register int res = 0;
    const int *end = arr+size; 
    for (; arr < end; arr++) res ^= *arr;
    return res;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 8};
    printf("%d", xor_c64(arr, 7));
    return 0;
}