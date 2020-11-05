/** https://en.wikipedia.org/wiki/Primality_test **/
int is_prime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

   int init_num = 5;

    while ((init_num * init_num) <=  num) {
        if ( num % init_num == 0  || num % (init_num + 2 ) == 0) {
            return 0;
        }

        init_num+=6;
    }

    return 1;
}