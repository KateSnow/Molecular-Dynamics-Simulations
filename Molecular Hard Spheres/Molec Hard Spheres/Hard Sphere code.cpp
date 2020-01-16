#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "nr.h"
using namespace std;


int main(){
double N;		//number atoms
cout<<"How many atoms? Must be of form n*n"<<endl;	//now of form n*n
cin>>N;
int n = sqrt(N);
double f = sqrt(N);
if((n-f)!=0){		//Determines if N of form 4m3.
	cout<<"Incorrect N"<<endl;
	system ("PAUSE");
	return 0;
	}
//2-D square lattice
float a;
float A;
cout<<"What is distance between particles in nm?"<<endl;
cin>>A;
a = A/1000000000;
Vec_DP x(N);
Vec_DP y(N);
x[1] = 0;
y[1] = 0;

int count=0;
for (int i=0; i<n; i++){		
	for(int j=0; j<n; j++){		
			if(i+j!=0){	
		count=count+1;
		x[count+1]=x[1]+i*a;
		y[count+1]=y[1]+j*a;
			}
		}
		}
float k = 1.38e-23;
float T;
T=298;		//Take room temp 298
float v;
float m;
m=1.89e-12;	//mass for iron radius 0.214nm, can be varied for other substance if required
v=sqrt(3*N*k*T/(m));
Vec_DP vx(N);
Vec_DP vy(N);
Vec_DP r(N/2);
float Factor;

for(int i=0; i<N/2; i++){
r[2*i+2]= rand()/((double)RAND_MAX+1)*v;	//allows random magnitude
//to allow random direction use Factor
if(rand()/((double)RAND_MAX+1)<0.5){
	Factor=1;}
else{Factor=-1;}
vx[2*i+2]=Factor*r[2*i+2];
vy[2*i+2]=Factor*sqrt(-vx[2*i+2]*vx[2*i+2]+v*v);
}
//then to allow total momentum to be zero;
for(int i=0; i<N/2; i++){
vx[2*i+1]=-vx[N-2*i];	//use N-2i to make the velocity distribution more random
vy[2*i+1]=-sqrt(-vx[2*i+1]*vx[2*i+1]+v*v);
}

for(int i=1; i<N+1; i++){
	//cout<<vx[i]<<"	"<<vy[i]<<endl;
	ofstream SaveFile("Velocity.txt", ios::app);
	SaveFile <<vx[i]<<"	"<<vy[i]<<endl;
	SaveFile.close();
}
float sumx=0;
float sumy=0;
for(int i=1; i<N+1; i++){
sumx=sumx+vx[i];
sumy=sumy+vy[i];
}
//cout<<sumx<<"	"<<sumy<<endl;

float b, R;
float d = 0.241e-09;
float V;
float time[256][256];
float t[256];
float partner[256];
float xb, yb, vxb, vyb;
float t0;
float particle0;
float partner0;

float timex0[256], timey0[256], timexna[256], timeyna[256];

for(int Collision=0; Collision<100; Collision++){	//is number of collisions to be calculated;

for(int i=1; i<N+1; i++){
t[i]=100.0;
t0=100.0;}

for (int i=1; i<N+1; i++){
for(int j=1; j<N+1; j++){
R = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
xb=x[j]-x[i];
yb=y[j]-y[i];
vxb=vx[j]-vx[i];
vyb=vy[j]-vy[i];
//b then found by dot product;
b = xb*vxb+yb*vyb;
V = sqrt((vx[i]-vx[j])*(vx[i]-vx[j])+(vy[i]-vy[j])*(vy[i]-vy[j]));
time[i][j] = (-b-sqrt(b*b-V*V*(R*R-d*d)))/(V*V);
if(time[i][j]>0){
if(time[i][j]<t[i]){
t[i]=time[i][j];
partner[i]=j;
}
}
}	//closes j loop
timex0[i] = (abs(x[i])-d/2)/(-vx[i]);
if(timex0[i]>0){
if(timex0[i]<t[i]){
t[i]=timex0[i];
partner[i]= N+1;
}
}
timey0[i] = (abs(y[i])-d/2)/(-vy[i]);
if(timey0[i]>0){
if(timey0[i]<t[i]){
t[i]=timey0[i];
partner[i]= N+2;
}
}
timexna[i] = (n*a-x[i]+d/2)/vx[i];
if(timexna[i]>0){
if(timexna[i]<t[i]){
t[i]=timexna[i];
partner[i]=N+3;
}
}
timeyna[i] = (n*a-y[i]+d/2)/vy[i];
if(timeyna[i]>0){
if(timeyna[i]<t[i]){
t[i]=timeyna[i];
partner[i]=N+4;
}
}
if(t[i]<t0){
t0=t[i];
particle0=i;
partner0=partner[i];
}
}	//closes i loop


ofstream SaveFile("Particle9.txt", ios::app);
SaveFile<<t0<<"	"<<particle0<<"	"<<x[particle0]<<"	"<<vx[particle0]<<"	"<<partner0<<"	"<<x[partner0]<<"	"<<vx[partner0]<<endl;
//SaveFile<<t0<<"	"<<x[9]<<"	"<<vx[9]<<endl;
SaveFile.close();

for(int i=1; i<N+1; i++){
x[i] = x[i]+vx[i]*t0;
y[i] = y[i]+vy[i]*t0;
if(x[i]<0){
x[i]=abs(x[i]-n*a*int(x[i]/(n*a)));}
if(x[i]>n*a){
x[i] = n*a-(x[i]-n*a*int(x[i]/(n*a)));}
if(y[i]<0){
y[i]=abs(y[i]-n*a*int(y[i]/(n*a)));}
if(y[i]>n*a){
y[i] = n*a-(y[i]-n*a*int(y[i]/(n*a)));}
//cout<<x[i]<<"	"<<y[i]<<endl;
}

//cout<<vy[particle0]+vy[partner0]<<endl;
//cout<<b<<endl;
b = (x[partner0]-x[particle0])*(vx[partner0]-vx[particle0])+(y[partner0]-y[particle0])*(vy[partner0]-vy[particle0]);
vx[particle0]=vx[particle0]+(x[partner0]-x[particle0])*b/(d*d);
vy[particle0]=vy[particle0]+(y[partner0]-y[particle0])*b/(d*d);
vx[partner0]=vx[partner0]-(x[partner0]-x[particle0])*b/(d*d);
vy[partner0]=vy[partner0]-(y[partner0]-y[particle0])*b/(d*d);

//cout<<vy[particle0]+vy[partner0]<<endl;
//cout<<t0<<endl;


}//closes Collision loop

system ("PAUSE");
return 0;
}


