#include <stdbool.h>
/** https://en.wikipedia.org/wiki/Primality_test **/
bool is_prime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

   int init_num = 5;

    while ((init_num * init_num) <=  num) {
        if ( num % init_num == 0  || num % (init_num + 2 ) == 0) {
            return false;
        }

        init_num+=6;
    }

    return true;
}