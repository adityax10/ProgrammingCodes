    #include <stdio.h>
    unsigned long long Solve(unsigned long long n);
    unsigned long long global = (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10) + 7;
    int main ()
    {
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
    unsigned long long n ;
    scanf("%llu", &n);
    //printf ("%llu\n", n);
    unsigned long long r = Solve(n);
    printf ("%llu\n", r);
    }
    }
    unsigned long long TwoPowerN(unsigned long long n)
    {
    if (n == 0)
    {
    return 1;
    }
    if (n == 1)
    {
    return 2;
    }
    if (n % 2 == 1)
    {
    unsigned long long x = TwoPowerN(n/2) % global;
    return (2 * x * x ) % global;
    }
    else
    {
    unsigned long long x = TwoPowerN(n/2) % global;
    return (x * x) % global;
    }
    }
    unsigned long long ** CalculateMatrix(unsigned long long n);
    unsigned long long CalculateCorrectWay(unsigned long long n)
    {
    if (n == 3)
    {
    return 7;
    }
    else if (n == 2)
    {
    return 4;
    }
    else if (n == 1)
    {
    return 2;
    }
    unsigned long long **matrix = CalculateMatrix(n - 3);
    return (matrix[0][0] * 7 + matrix[0][1] * 4 + matrix[0][2] * 2) % global;
    }
    unsigned long long ** CalculateMatrix(unsigned long long n)
    {
    if (n == 1)
    {
    unsigned long long **m = new unsigned long long * [3];
    m[0] = new unsigned long long [3];
    m[0][0] = 1;
    m[0][1] = 1;
    m[0][2] = 1;
    m[1] = new unsigned long long [3];
    m[1][0] = 1;
    m[1][1] = m [1][2] = 0;
    m[2] = new unsigned long long [3];
    m[2][0] = m[2][2] = 0;
    m[2][1] = 1;
    return m;
    }
    unsigned long long **mm = CalculateMatrix(n/2);
    unsigned long long a1 = (mm[0][0] * mm[0][0] + mm[0][1] * mm[1][0] +
    mm[0][2] * mm[2][0] ) % global;
    unsigned long long a2 = (mm[0][0] * mm[0][1] + mm[0][1] * mm[1][1] +
    mm[0][2] * mm[2][1] ) % global;
    unsigned long long a3 = (mm[0][0] * mm[0][2] + mm[0][1] * mm[1][2] +
    mm[0][2] * mm[2][2] ) % global;
    unsigned long long a4 = (mm[1][0] * mm[0][0] + mm[1][1] * mm[1][0] +
    mm[1][2] * mm[2][0] ) % global;
    unsigned long long a5 = (mm[1][0] * mm[0][1] + mm[1][1] * mm[1][1] +
    mm[1][2] * mm[2][1] ) % global;
    unsigned long long a6 = (mm[1][0] * mm[0][2] + mm[1][1] * mm[1][2] +
    mm[1][2] * mm[2][2] ) % global;
    unsigned long long a7 = (mm[2][0] * mm[0][0] + mm[2][1] * mm[1][0] +
    mm[2][2] * mm[2][0] ) % global;
    unsigned long long a8 = (mm[2][0] * mm[0][1] + mm[2][1] * mm[1][1] +
    mm[2][2] * mm[2][1] ) % global;
    unsigned long long a9 = (mm[2][0] * mm[0][2] + mm[2][1] * mm[1][2] +
    mm[2][2] * mm[2][2] ) % global;
    mm[0][0] = a1;
    mm[0][1] = a2;
    mm[0][2] = a3;
    mm[1][0] = a4;
    mm[1][1] = a5;
    mm[1][2] = a6;
    mm[2][0] = a7;
    mm[2][1] = a8;
    mm[2][2] = a9;
    if (n % 2 == 1)
    {
    mm[0][0] = (a1 + a2) % global;
    mm[0][1] = (a1 + a3) % global;
    mm[0][2] = a1;
    mm[1][0] = (a4 + a5) % global;
    mm[1][1] = (a4 + a6) % global;
    mm[1][2] = a4;
    mm[2][0] = (a7 + a8) % global;
    mm[2][1] = (a7 + a9) % global;
    mm[2][2] = a7;
    }
    return mm;
    }
    unsigned long long Solve (unsigned long long n)
    {
    unsigned long long twoPowerN = TwoPowerN(n);
    unsigned long long correctWay = CalculateCorrectWay(n);
    //printf ("2^n = %llu cway = %llu\n", twoPowerN, correctWay);
    if (twoPowerN > correctWay)
    {
    return (twoPowerN - correctWay) % global;
    }
    else
    {
    return (((long long) (twoPowerN - correctWay)) + (long long) global) % global;
    }
    }

