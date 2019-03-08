//the program is created by zzc(915106840742) on 1.1,2018.
//the report has the detail introduction ,Thank.
//////////////////////////////////////////////////////////////////
#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<ctime>
using namespace std;
const int maxn=100;
const double a=0,b=1;
double xk[maxn][maxn],Ak[maxn][maxn];
void init()
{
	xk[0][0]=0;
	Ak[0][0]=2;
	xk[1][0]=0.5773502692,xk[1][1]=-0.5773502692;
	Ak[1][0]=Ak[1][1]=1;
	xk[2][0]=0.7745966692,xk[2][1]=-0.7745966692,xk[2][2]=0;
	Ak[2][0]=Ak[2][1]=0.5555555556,Ak[2][2]=0.8888888889;
	xk[3][0]=0.8611363116,xk[3][1]=-0.8611363116,xk[3][2]=0.3399810436,xk[3][3]=-0.3399810436;
	Ak[3][0]=Ak[3][1]=0.3478548451,Ak[3][2]=Ak[3][3]=0.6521451549;
	xk[4][0]=0.9061798459,xk[4][1]=-0.9061798459,xk[4][2]=0.5384693101,xk[4][3]=-0.5384693101,xk[4][4]=0;
	Ak[4][0]=Ak[4][1]=0.2369268851,Ak[4][2]=Ak[4][3]=0.4786286705,Ak[4][4]=0.5688888889;
	xk[5][0]=0.9324695142,xk[5][1]=-0.9324695142,xk[5][2]=0.6612093865,xk[5][3]=-0.6612093865,xk[5][4]=0.2386191861,xk[5][5]=-0.2386191861;
	Ak[5][0]=Ak[5][1]=0.1713244924,Ak[5][2]=Ak[5][3]=0.3607615730,Ak[5][4]=Ak[5][5]=0.4679139346;
	xk[6][0]=0.9491079123,xk[6][1]=-0.9491079123,xk[6][2]=0.7415311856,xk[6][3]=-0.7415311856,xk[6][4]=0.4058451514,xk[6][5]=-0.4058451514,
	xk[6][6]=0;
	Ak[6][0]=Ak[6][1]=0.1294849662,Ak[6][2]=Ak[6][3]=0.2797053915,Ak[6][4]=Ak[6][5]=0.3818300505,Ak[6][6]=0.4179591837;
}
double F(double x)
{
	if(x==0)return 1;
	return (double)sin(x)/x;
}
double Gauss_Legendre(int d,int n)
{
	double t=(b-a)/d,ret=0,at,bt,x0;
	for(int i=0;i<d;i++)
	{
		at=t*i,bt=t*(i+1);
		//cout<<"at : "<<at<<"  ,bt: "<<bt<<endl;
		for(int j=0;j<=n;j++)
		{
			x0=(double)0.5*(at+bt)+0.5*(bt-at)*xk[n][j];
			ret+=((bt-at)*0.5*Ak[n][j]*F(x0));
		//	cout<<"Ret: "<<ret<<endl;
		}
	}
	return ret;
}
int main()
{
	init();
	int d,n;
	cout<<"input the number of interval : ";
	cin>>d;
	//cout<<"input the degreee: ";
	//cin>>n;
	//for(int i=0;i<7;i++){
		for(int j=1;j<=5;j++){
			 long long a=clock();
	         double ans=Gauss_Legendre(d,j);
	         long long b=clock();
	         cout<<"d : "<<d<<"   n: "<<j<<endl;
	         cout<<"ans: "<<setprecision(8)<<ans<<endl;
	         cout<<"time: "<<b-a<<endl;
	     }
    //}
	return 0; 
}
