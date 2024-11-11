#include <stdio.h>
#include <stdlib.h>

int xor_c(register const int *arr, register const unsigned long long int size) {
    register int res = 0;
    register const int *end = arr+size; 
    for (; arr < end; arr++) res^= *arr;
    return res;
}

#define real unsigned long long int
int xor_c64(register const int* arr, register real size) {
    register real res = 0;
    if (size & 1) res^= *(arr+(--size));
    register const real* end = (real*)(arr+size);
    for (register const real* p = (real*)arr; p < end; p++) res^= *(p);
    return res^ (res>>32); 
}

int xor_c100(register const int* arr, register real size) {
    register int res = 0;
    register const int* end = arr+size;
    size %= 100;
    end -= size;
for (register const int*p=arr;p<end;p+=100){
res^=
*(p+1)^
*(p+2)^
*(p+3)^
*(p+4)^
*(p+5)^
*(p+6)^
*(p+7)^
*(p+8)^
*(p+9)^
*(p+10)^
*(p+11)^
*(p+12)^
*(p+13)^
*(p+14)^
*(p+15)^
*(p+16)^
*(p+17)^
*(p+18)^
*(p+19)^
*(p+20)^
*(p+21)^
*(p+22)^
*(p+23)^
*(p+24)^
*(p+25)^
*(p+26)^
*(p+27)^
*(p+28)^
*(p+29)^
*(p+30)^
*(p+31)^
*(p+32)^
*(p+33)^
*(p+34)^
*(p+35)^
*(p+36)^
*(p+37)^
*(p+38)^
*(p+39)^
*(p+40)^
*(p+41)^
*(p+42)^
*(p+43)^
*(p+44)^
*(p+45)^
*(p+46)^
*(p+47)^
*(p+48)^
*(p+49)^
*(p+50)^
*(p+51)^
*(p+52)^
*(p+53)^
*(p+54)^
*(p+55)^
*(p+56)^
*(p+57)^
*(p+58)^
*(p+59)^
*(p+60)^
*(p+61)^
*(p+62)^
*(p+63)^
*(p+64)^
*(p+65)^
*(p+66)^
*(p+67)^
*(p+68)^
*(p+69)^
*(p+70)^
*(p+71)^
*(p+72)^
*(p+73)^
*(p+74)^
*(p+75)^
*(p+76)^
*(p+77)^
*(p+78)^
*(p+79)^
*(p+80)^
*(p+81)^
*(p+82)^
*(p+83)^
*(p+84)^
*(p+85)^
*(p+86)^
*(p+87)^
*(p+88)^
*(p+89)^
*(p+90)^
*(p+91)^
*(p+92)^
*(p+93)^
*(p+94)^
*(p+95)^
*(p+96)^
*(p+97)^
*(p+98)^
*(p+99)^
*(p);}
    if (size > 0) res^= xor_c64(end, size);
    return res;
}

int main() {
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand();
    }
    printf("%d, %d", xor_c64(arr, sizeof(arr)/sizeof(arr[0])), xor_c100(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}