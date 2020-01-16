#include<bits/stdc++.h>

using namespace std;

#define MAX_POWER 30
long int pow_2[MAX_POWER + 1];
double pow_p[MAX_POWER + 1];
int lp[10000];

double prob(long int n, int m_start, int m_end, double p, int stage) {
    if(m_start == m_end)
        return pow_p[stage];
    else if(m_start > m_end)
        return 0;
    long int n_division = n - pow_2[stage - 1];
    int i;
    for(i = m_start; i <= m_end; i++) {
        if(lp[i] > n_division)
            break;
    }
    double prob1 = prob(n_division, m_start, i - 1, p, stage - 1);
    double prob2 = prob(n, i, m_end, p, stage - 1);
    return ( prob1*prob2 + prob1*(1 - prob2)*p + (1 - prob1)*prob2*p );
}

int main()
{
    int test_cases, m, p_int;
    long int n;
    double p;
    scanf("%d", &test_cases);

    pow_2[0] = 1;
    for(int i = 1; i <= MAX_POWER; i++)
        pow_2[i] = (pow_2[i-1] << 1);

    while(test_cases--) {
        scanf("%ld %d %d", &n, &m, &p_int);
        p = (double)p_int / 100;
        pow_p[0] = 1;
        for(int i = 1; i <= MAX_POWER; i++)
            pow_p[i] = pow_p[i-1] * p;

        for(int i = 0; i < m; i++)
            scanf("%d", &lp[i]);
        sort(lp, lp + m);
        
        int power = 1;
        while(n > pow_2[power])
            power++;
        int n_power = power;
        printf("%.10lf\n", prob(n, 0, m - 1, p, n_power) * 100);
    }

    printf("\n");
    return 0;
}