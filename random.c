// C implementation of the ``minimal standard'' generator proposed by Park and Miller
#define a 48271
#define m 2147483647
#define q (m / a)
#define r (m % a)

static long int seed = 1;

long double PMrand()
{
    long int hi = seed / q;
    long int lo = seed % q;
    long int test = a * lo - r * hi;
    if(test > 0)
        seed = test;
    else	seed = test + m;
    return (double)seed / m;
}
