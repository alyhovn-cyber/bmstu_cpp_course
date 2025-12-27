#include "str2int.h"
#include <assert.h>
#include <stdio.h>

int str2int(const char* str) {
    if (str == NULL) {
        assert(0 && "NULL pointer");
    }
    
    if (str[0] == '\0') {
        assert(0 && "Empty string");
    }
    
    int i = 0;
    int sign = 1;
	
    if (str[i] == '-') {
        if (str[i + 1] == '\0') {
            assert(0 && "Only minus sign");
        }
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        if (str[i + 1] == '\0') {
            assert(0 && "Only plus sign");
        }
        i++;
    }
    
    while (str[i] == '0') {
        i++;
        if (str[i] == '\0') {
            return 0;
        }
    }
    
    long long result = 0;
    const long long int_max = 2147483647LL;
    const long long int_min = -2147483648LL;
    
    while (str[i] != '\0') {
        char c = str[i];
        
        if (c < '0' || c > '9') {
            assert(0 && "Invalid character");
        }
        
        int digit = c - '0';
        
        if (sign == 1) {
            if (result > (int_max - digit) / 10) {
                assert(0 && "Overflow");
            }
            result = result * 10 + digit;
        } else {
            if (result < (int_min + digit) / 10) {
                assert(0 && "Underflow");
            }
            result = result * 10 - digit;
        }
        
        i++;
    }
    
    if (result < int_min || result > int_max) {
        assert(0 && "Value out of range");
    }
    
    return (int)result;
}