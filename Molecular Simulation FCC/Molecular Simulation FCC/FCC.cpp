#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "nr.h"
using namespace std;

DP fEpot(Vec_I_DP &X, Vec_I_DP &Y, Vec_I_DP &Z, const int &N);

int main(){
double N;		//number atoms
cout<<"How many atoms? Must be of form 4m*m*m"<<endl;
cin>>N;
int f = pow(N/4, 1.0/3.0);
double p = pow(N/4, 1.0/3.0);
if((p-f)!=0){		//Determines if N of form 4m3.
	cout<<"Incorrect N"<<endl;
	system ("PAUSE");
	return 0;
	}
float n;			//packing factor
cout<<"What is the packing factor?"<<endl;
cin>>n;
if(n>0.74){
	n=0.74;}		//so n is never larger then 0.74

float d; 	// density
float A;	//Atmoic weight
A = 63.5;	//set it to Iron for now
const double NA = 6.023e+23;	//Avagadro’s number;
cout<<"What is the density of the cell g/cm3?"<<endl;
cin>>d;
//with d, the volume can be calculated for one unit cell;
double Vunit = A/((d*NA)*100*100*100);		//*100 because is in cm3
//then total volume is Vunit time number unit cells
//number of unit cells is N/4
double V;
V = Vunit*N/4;

float a = pow(Vunit, 1.0/3.0)*2;		//as a/2 gives side of unit cell
float m = pow(N/4, 1.0/3.0);			//from N=4m3
int count=0;
Vec_DP x(N);
Vec_DP y(N);
Vec_DP z(N);
x[1] = 0;
x[2] = 0.5*a;
x[3] = 0.5*a;
x[4] = 0;
y[1] = 0;
y[2] = 0.5*a;
y[3] = 0;
y[4] = 0.5*a;
z[1] = 0;
z[2] = 0;
z[3] = 0.5*a;
z[4] = 0.5*a;
cout<<a<<endl;
for (int n=1; n<5; n++){		//runs though the 4 unit cell points
for (int i=0; i<m; i++){		//runs through the a added to x coordinate
	for(int j=0; j<m; j++){		//runs through the a added to y coordinate
		for(int k=0; k<m; k++){		//a added to z coordinate
			if(i+j+k!=0){	//required so at least on a is added
		count=count+1;
		x[count+4]=x[n]+i*a;
		y[count+4]=y[n]+j*a;
		z[count+4]=z[n]+k*a;
			}
			}
		}
	}
}

float Epot;

for(int j=0; j<N; j++){
Epot = fEpot(x, y, z, N);
float d;
d=0.2*a;
float xr;
float yr;
float zr;
xr= d*((rand()/((double)RAND_MAX+1))-0.5);
yr = d*((rand()/((double)RAND_MAX+1))-0.5);
zr = d*((rand()/((double)RAND_MAX+1))-0.5);

float L = pow(V, 1.0/3.0);
int xc = xr/L;
int yc = yr/L;
int zc = zr/L;
xr= xr-L*xc;
yr= yr-L*yc;
zr= zr-L*zc;

x[j] = x[j] + xr;
y[j] = y[j] + yr;
z[j] = z[j] + zr;
float T;
T=298;		//Take room temp
float g=rand()/((double)RAND_MAX+1);
float k = 1.38e-23;
float q = exp(-(fEpot(x,y,z,N)-Epot)/(k*T));
if(g>q){
	x[j]=x[j]-xr;
	y[j]=y[j]-yr;
	z[j]=z[j]-zr;
	}
else {
	Epot=fEpot(x, y, z, N);
	}
cout<<Epot<<endl;
}

system ("PAUSE");
return 0;
}

DP fEpot(Vec_I_DP &X, Vec_I_DP &Y, Vec_I_DP &Z, const int &N){

double phi;
cout<<"What is phi?"<<endl;
cin>>phi;
//phi=3e-10;
float epsilon;
cout<<"What is eplsion?"<<endl;
cin>>epsilon;
//epsilon=1e-21;
double r;	//is distance between particles
float Epot = 0;		//is the total potential energy

for(int i=1; i<N; i++){
	for(int j=i+1; j<N+1; j++){
		r = sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])+(Z[i]-Z[j])*(Z[i]-Z[j]));
		Epot = Epot +4*epsilon*(pow(phi/r,12.0)+pow(phi/r, 6.0));
	}
}
return Epot;
}