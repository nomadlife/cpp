double nth_even_fib(long n)
{
    assert(n >= 0);
    double mu = (2 + sqrt(5));
    return round(pow(mu, n) / sqrt(5));
}

double sum_even_fibs(double limit)
{
    double sum = 0;
    for (int i = 1; nth_even_fib(i) < limit; ++i)
    {
        sum += nth_even_fib(i);
    }
    return sum;
}

int main()
{
    printf("%.0lf\n", sum_even_fibs(4e6));
    return 0;
}