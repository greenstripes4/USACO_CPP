const int N = 1e7 + 5;
int st[N];

//埃拉托斯特尼筛法，简称埃氏筛。
void E_sieve(int  n){
	for(int i = 2; i <= n / i; i++)
	{
		if(st[i] == 0)
		{
			for(int j = i * i; j <= n; j += i)
			    st[j] = 1; // j是i的一个倍数，j是合数，筛掉。
		}
	}
}

//欧拉筛的核心思想就是确保每个合数只被最小质因数筛掉。或者说是被合数的最大因子筛掉。
int primes[N];
int cnt=0;
void ola(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i] == 0) primes[cnt ++ ] = i;//将质数存到primes中
        for (int j = 0; primes[j] <= n / i; j ++ )//要确保质数的第i倍是小于等于n的。
        {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
