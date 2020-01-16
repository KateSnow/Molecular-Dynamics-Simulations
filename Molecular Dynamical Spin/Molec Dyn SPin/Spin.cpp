#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "nr.h"
using namespace std;

DP fEpot(Vec_IO_DP &SPIN, int &n, float &A);

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
Vec_DP spin(N);	//define spin vector
x[1] = 0;
y[1] = 0;
spin[1]=1;
int S;
double Sf;
int count=0;

for (int i=0; i<n; i++){		
	for(int j=0; j<n; j++){		
			if(i+j!=0){	
		count=count+1;
		x[count+1]=x[1]+i*a;
		y[count+1]=y[1]+j*a;
//spin is what is varied in this case. Initially defined spin alternatively by position;
S=(count+1)/2;
Sf=(count+1)/2.0;
if((S-Sf)!=0){
spin[count+1]=1;}
else{
spin[count+1]=-1;}
			}
		}
		}

float Epot;
for(int j=0; j<N; j++){
Epot = fEpot(spin, n, a);
spin[j]=-spin[j];
//energy change;
float E=fEpot(spin, n, a)-Epot;
//if E<0 accept inversion, otherwise apply condition similar to prev
float T;
T=0.1;		//Take room temp 298
float g=rand()/((double)RAND_MAX+1);
float k = 1.38e-23;
float q = exp(-E/(k*T));
if(g>q){
spin[j]=-spin[j];	//reject the change
	}
else {
	Epot=fEpot(spin, n, a);
	}
cout<<Epot<<endl;
}

system ("PAUSE");
return 0;
}



DP fEpot(Vec_IO_DP &SPIN, int &n, float &A){

float sumE=0;
float N=n*n;
//lenght of lattice then is;
float L=n*A;
for(int i=1; i<N+1; i++){
//apply periodic boundary conditions
	if(i+1>N){
	SPIN[i+1]=SPIN[1];}
	if((i-1)<1){
	SPIN[i-1]=SPIN[N];}
	if((i-n-1)<0){
	SPIN[i-n]=SPIN[N-n+i];}
	if((i+n)>N){
	SPIN[i+n]=SPIN[i+n-N];}
//now determine the potential sum;
sumE=sumE+SPIN[i]*SPIN[i+1]+SPIN[i]*SPIN[i-1]+SPIN[i]*SPIN[i+n]+SPIN[i]*SPIN[i-n];
}
return (-sumE/2);
}
