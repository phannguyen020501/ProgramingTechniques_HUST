#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
typedef struct bigNum{
	char sign;
	char num[101];
}bigNum;
void swap1(bigNum &a,int size)
{
	a.sign=a.num[0];
	int r=size-1;
	int l=0;
	while(l<r)
	{
		swap(a.num[l],a.num[r]);
		l++;r--;
	}
	a.num[size-1]='\0';
}
void swap2(bigNum &a,int size)
{
	int r=size-1;
	int l=0;
	while(l<r)
	{
		swap(a.num[l],a.num[r]);
		l++;r--;
	}
}
bigNum operator + (bigNum a, bigNum b)
{
	int test=0;
	bigNum c;
	int x=strlen(a.num);
	int y=strlen(b.num);
	int n=(x>y)?x:y;
	a.sign=a.num[0];
	b.sign=b.num[0];

	if(a.sign!=b.sign){
	if(x<y)
	{
		char temp[101];
		strcpy(temp,a.num);
		strcpy(a.num,b.num);
		strcpy(b.num,temp);
		test=1;
	}
	else{
		char temp[101];
		strcpy(temp,a.num);
		temp[0]=b.num[0];
		if(x==y&&(strcmp(b.num,temp)>0))
		{
		char temp2[101];
		strcpy(temp2,a.num);
		strcpy(a.num,b.num);
		strcpy(b.num,temp2);
		test=1;
		}
	}
	}
	if(test==1){
		swap1(a,y);swap1(b,x);
	}else{
		swap1(a,x);swap1(b,y);
	}
	x=strlen(a.num)+1;
	y=strlen(b.num)+1;
	if(x!=y){
	if(x<y)
	{
		for(int i=x-1;i<y-1;i++)
		{
			a.num[i]='0';
		}
	}else{
		for(int i=y-1;i<x-1;i++)
		{
			b.num[i]='0';
		}
	}}
	a.num[n-1]='0';
	b.num[n-1]='0';
	int i=0;
	int k=0;
//	printf("\n%s",a.num);
//	printf("\n%s",b.num);
	if(a.sign==b.sign)
	{
	while(i<n)
	{
		int soa=((int)a.num[i])-48;
		int sob=((int)b.num[i])-48;
		int sok=soa+sob+k;
		c.num[i]=(char)(48+sok%10);
		k=sok/10;
		i++;
	}

		if(c.num[n-1]=='0')
		{
		swap2(c,n);
		c.num[0]=a.sign;
		c.num[n]='\0';
		}
		else{
		if(c.num[n-1]=='1')
		{
			c.num[n]=a.sign;
			c.num[n+1]='\0';
			swap2(c,n+1);
		}}
	}else{
		while(i<n)
		{
			int soa=((int)a.num[i])-48;
			int sob=((int)b.num[i])-48;
			int sok=soa-sob-k;
			if(sok>=0)
			{
				c.num[i]=char(48+sok);k=0;
			}else{
				c.num[i]=char(58+sok);
				k=1;
			}
			i++;
		}
//		printf("\n%s",c.num);
		if(test==1)
			{
				if(a.sign=='1'){
				
				c.num[n]='1';}
				else{
					if(a.sign=='0'){
						c.num[n]='0';
					}
				}
			}
			else{
				if(a.sign=='1')
				c.num[n]='1';
				else {
				if(a.sign=='0')
				{
					c.num[n]='0';
				}}
			}
			c.num[n+1]='\0';
			swap2(c,n+1);
		}
	while(c.num[1]=='0'){
		for(int i=1;i<strlen(c.num);i++)
		{
			c.num[i]=c.num[i+1];
		}
		c.num[strlen(c.num)]='\0';
	}
	return c;
	}

void mabu1(bigNum a,int size)
{
	for(int i=1;i<size;i++)
	{
		a.num[i]=(char)(105-(int)a.num[i]);
	}
	a.num[0]='1';
}
bigNum operator - (bigNum a, bigNum b)
{
	a.sign=a.num[0];
	b.sign=b.num[0];
	if(b.sign=='1')
	{
		b.sign='0';
		b.num[0]='0';
		return a+b;
	}else{
		b.sign='1';
		b.num[0]='1';
		return a+b;
	}

}
void dichbit(bigNum &a,int n){
	int x=strlen(a.num);
	int i=0;
	while(i<n)
	{
		a.num[x+i]='0';
		i++;
	}
	a.num[x+n]='\0';
}
bigNum nhan(bigNum a, int n)
{
	int i=0;int k=0;
	a.sign=a.num[0];
	int x=strlen(a.num);
	swap1(a,x);
	bigNum c;
	while(i<x-1)
	{
		int soa=((int)a.num[i]-48)*n;
		int k1=soa+k;
		int k2=k1%10;
		c.num[i]=char(48+k2);
		k=k1/10;
		i++;
	}
	c.num[x-1]=char(48+k);
	c.num[x]=a.sign;
	swap2(c,x+1);
	c.num[x+1]='\0';
	return c;
}
bigNum operator * (bigNum a, bigNum b)
{
	bigNum c;
	c.num[0]='1';c.num[1]='0';c.num[2]='\0';
	a.sign=a.num[0];
	b.sign=b.num[0];
	char x=a.sign;
	char y=b.sign;
	a.num[0]='1';b.num[0]='1';
	a.sign='1';b.sign='1';
	int m=strlen(b.num);
	int i=0;
	while(i<m-1)
	{
		int n=(int)b.num[m-1-i]-48;
		bigNum d = nhan(a,n);
		dichbit(d,i);
		c=c+d;
		i++;
	}
	if(x==y)
	{
		c.num[0]='1';
	}
	else{
		c.num[0]='0';
	}
	return c;
}
int main()
{	
	printf("Phan Ngoc Nguyen- 20194134\n");
	bigNum x,y,d,e,c;
	gets(x.num);
	fflush(stdin);
	gets(y.num);
	c=x*y;
	d=nhan(x,3);
	e=nhan(y,4);
	c=x*y-d+e;
	printf("%s",c.num);
	return 0;
}
