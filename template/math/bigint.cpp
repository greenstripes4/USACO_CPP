
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll m=1e8;//大数数组每个元素为8位

struct Bigint{
	ll s[50];
    int l;//l为长度
	void print(){
		printf("%lld",s[l]);
		for(int i=l-1;i>=0;i--)printf("%08lld",s[i]);
	}
	void read(ll x){//将整数x存入高精度数组
		l=-1;memset(s,0,sizeof(s));
		do{
			s[++l]=x%m;
			x/=m;
		}while(x);
	}
}ans;

Bigint operator + (Bigint a,Bigint b){//大数加
	ll d=0;
	a.l=max(a.l,b.l);
	for(int i=0;i<=a.l;i++){
		a.s[i]+=d+b.s[i];
		d=a.s[i]/m;a.s[i]%=m;
	}
	if(d)a.s[++a.l]=d;
	return a;
}

Bigint operator - (Bigint a,Bigint b){//大数减
	ll d=0;
	for(int i=0;i<=a.l;i++){
		a.s[i]-=d;
		if(a.s[i]<b.s[i])a.s[i]+=m,d=1;
		else d=0;
		a.s[i]-=b.s[i];
	}
	while(a.l&&!a.s[a.l])a.l--;
	return a;
}

Bigint operator * (int b,Bigint a){//int与大数乘(顺序不能换)
	ll d=0;
	for(int i=0;i<=a.l;i++){
		d+=a.s[i]*b;a.s[i]=d%m;
		d/=m;
	}
	while(d){
		a.s[++a.l]=d%m;
		d/=m;
	}
	return a;
}

Bigint operator / (Bigint a,int b){//大数与int除(顺序不能变)
	ll d=0;
	for(int i=a.l;i>=0;i--){
		d*=m;d+=a.s[i];
		a.s[i]=d/b;d%=b;
	}
	while(a.l&&!a.s[a.l])a.l--;
	return a;
}

Bigint operator * (Bigint a,Bigint b){//大数与大数乘
	Bigint c;memset(c.s,0,sizeof(c.s));
	for(int i=0;i<=a.l;i++){
		for(int j=0;j<=b.l;j++){
			c.s[i+j]+=a.s[i]*b.s[j];
			if(c.s[i+j]>m){
				c.s[i+j+1]+=c.s[i+j]/m;
				c.s[i+j]%=m;
			}
		}
	}
	c.l=a.l+b.l+10;
	while(!c.s[c.l]&&c.l)c.l--;
	while(c.s[c.l]>m){
		c.s[c.l+1]+=c.s[c.l]/m;
		c.s[c.l++]%=m;
	}
	return c;
}
