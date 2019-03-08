//the program is created by zzc(915106840742) on 12.31 ,2017.
//the report has the detail introduction ,Thank.
//////////////////////////////////////////////////////////////////
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
const int maxn=100;
const double x0=-1;
double e[maxn][maxn],M[maxn],d[maxn];
double L[maxn],U[maxn];
double h,f[maxn],df0,dfn; 
int N;
double F(double x)
{
	if(x>=-1&&x<=1)
	return  (double)1/(1+25*x*x);
	else return -1;
}
void init()
{
	h=(double)2/N;
	memset(L,0,sizeof(L));
	memset(U,0,sizeof(U));
	memset(e,0,sizeof(e));
	memset(M,0,sizeof(M));
	memset(d,0,sizeof(d));
	memset(f,0,sizeof(f));
	for(int i=0;i<=N;i++){
		f[i]=F(x0+i*h);
		cout<<setw(10)<<x0+i*h<<setw(10)<<f[i]<<endl;
	}
} 
void Thomas()
{
	U[0]=e[0][0];
	for(int i=1;i<=N;i++)
	{
		L[i]=e[i][i-1]/U[i-1];
		U[i]=e[i][i]-L[i]*e[i-1][i]; 
	} 
	M[0]=d[0];
	for(int i=1;i<=N;i++)
	{
		M[i]=d[i]-L[i]*M[i-1];
	}
	M[N]=M[N]/U[N];
	for(int i=N-1;i>=0;i--)
	{
		M[i]=(M[i]-e[i][i+1]*M[i+1])/U[i]; 
	} 
}
void get_equation(int n,double df0,double dfn)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=i-1;j<i+2;j++)
		{
			if(j<0||j>n)continue;
			if((i==0&&j==1)||(i==n&&j==n-1))e[i][j]=1;
			else if(j==i-1)e[i][j]=(double)1/2;
			else if(j==i)e[i][j]=2;
			else e[i][j]=(double)1/2;
		}
	}
	d[0]=6*((f[1]-f[0])/h-df0)/h;
	d[n]=6*(dfn-(f[n]-f[n-1])/h)/h;
	for(int i=1;i<n;i++)
		d[i]=6*(f[i-1]+f[i+1]-2*f[i])/2/h/h;
} 
int main()
{
	cout<<"input n: ";
	cin>>N;
	init();
	
	//cout<<"input d0: ";
	//cin>>d0;
	//cout<<"input dn: ";
	//cin>>dn;
	df0=(double)1/(26*26)*(-50)*(-1);
	dfn=(double)1/(26*26)*(-50)*1; 
	cout<<df0<<"   "<<dfn<<endl;
	get_equation(N,df0,dfn);
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
		      cout<<setw(7)<<e[i][j];
	    cout<<endl; 
	}
	cout<<endl;
	for(int i=0;i<=N;i++)
	{
		cout<<setw(10)<<d[i]; 
	}
	cout<<endl;
	Thomas();
	for(int i=0;i<=N;i++)
	{
		cout<<setw(10)<<M[i];
	}
	cout<<endl;
	
	for(int i=0;i<N;i++)
	{
		cout<<left<<setw(10)<<M[i]/6/h<<setw(10)<<M[i+1]/6/h<<setw(10)<<(f[i]-M[i]*h*h/6)/h<<setw(10)<<(f[i+1]-M[i+1]*h*h/6)/h<<endl;
	}
	return 0;
}
