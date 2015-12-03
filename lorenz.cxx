#include<iostream>
using namespace std;
void lorenz_model(double*p ,const int a,const int b,const double c,double x,double y,double z);
int main(){
const int N=100000;
const double a=10;
const double b=28;
const double c=8.0/3.0;
double x=1,y=1,z=1,T=100,p[3], k1[3], k2[3], k3[3], k4[3];
const double dt=T/N;

for(int i=0; i<=N; i++){
  
lorenz_model(k1,a,b,c,x,y,z);
lorenz_model(k2,a,b,c, x+(dt/2)*k1[0], y+(dt/2)*k1[1], z+(dt/2)*k1[2]);
lorenz_model(k3,a,b,c, x+(dt/2)*k2[0], y+(dt/2)*k2[1], z+(dt/2)*k2[2]);
lorenz_model(k4,a,b,c, x+dt*k3[0],     y+dt*k3[1],     z+dt*k3[2]);

x+=(dt/6)*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
y+=(dt/6)*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
z+=(dt/6)*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);

cout<<i*dt<<'\t'<<x<<'\t'<<y<<'\t'<<z<<endl;
}
  return 0;
}
void lorenz_model(double*p ,const int a,const int b,const double c,double x,double y,double z){
p[0]=a*(y-x);     //x'=p[0]
p[1]=x*(b-z)-y;  //y'=p[0]
p[2]=x*y-c*z;   //z'=p[0]
}