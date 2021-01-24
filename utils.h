//
// Created by tim on 16.04.2020
//
#ifndef UTILS_H
#define UTILS_H
#include "types.h"



uint32 digit_count(int num)
{
    uint32 count = 0;
    if(num == 0)
        return 1;
    while(num > 0){
        count++;
        num = num/10;
    }
    return count;
}


void itoa2(int num, char *number)
{
    int dgcount = digit_count(num);
    int index = dgcount - 1;
    char x;
    if(num == 0 && dgcount == 1){
        number[0] = '0';
        number[1] = '\0';
    }else{
        while(num != 0){
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount] = '\0';
    }
}


uint32 strlen(const char* str)
{
    uint32 length = 0;
    while(str[length])
        length++;
    return length;
}


char * itoa( int value, char * str, int base )
{
    char * rc;
    char * ptr;
    char * low;
    // Check for supported base.
    if ( base < 2 || base > 36 )
    {
        *str = '\0';
        return str;
    }
    rc = ptr = str;
    // Set '-' for negative decimals.
    if ( value < 0 && base == 10 )
    {
        *ptr++ = '-';
    }
    // Remember where the numbers start.
    low = ptr;
    // The actual conversion.
    do
    {
        // Modulo is negative for negative value. This trick makes abs() unnecessary.
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    } while ( value );
    // Terminating the string.
    *ptr-- = '\0';
    // Invert the numbers.
    while ( low < ptr )
    {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
    return rc;
}
#endif