
#include<bits/stdc++.h>
#include<cmath>
 
#define mem(a,b) memset(a,b,sizeof a)
#define INF 0x3f3f3f3f
 
using namespace std;
 
typedef long long ll;
 
ll gcd(ll a,ll b){ a=abs(a); b=abs(b); return a==0?b:gcd(b%a,a); }

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

//解决的是 ax + by = c的问题 利用扩展欧几里得可以求出一组合法的解（是等于gcd（a,b）的解）
// x = x0 + b / gcd * k k为任意整数
// y = y0 - a / gcd * k k为任意整数
//注意！！！当扩大倍数乘目标结果时，b0也就是b/gcd或者a0不需要跟着翻倍
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

const ll kMod = 1e9 + 7;
//=============================================================
ll C(ll x, ll k) { 
  //求得从n个数中取出k个数的组合
  //此处k=1 / 2，用了特判写法。
  //k = 1 时，C(x, 1) = x;
  //k = 2 时，C(x, 2) = x * (x - 1) / 2;
  return (k == 1ll ? x : x * (x - 1ll) / 2ll) % kMod;
}