//实现函数 double Power(double base,int exponent),求base的
//exponent次方，不得使用库函数，同时不需要考虑大数问题。
#include <iostream>
#include <math.h>
//#include <stdlib.h>

using namespace std;

#define ESPION 1e-8

bool g_InvalidInput = false;

bool equal(double x,double y)
{
    if((x-y)<ESPION && (y-x)<ESPION) return true;
    else return false;
}


double Power(double base,int exponent)
{
  if(equal(base,0) && exponent<=0) 
  {
    cout<<"Input paramter error!";
//    exit(1);
  g_InvalidInput = true;
   return 0.0;
  }
  if(equal(base,0.0<ESPION) && exponent>0) return 0.0;

  if(exponent>0)
  {
    int n = exponent;
    double result = 1.0;
    while(n)
    {
      result *= base;
      n--;
    }
    return result;
  }

  if(exponent==0) return 1.0;

  if(exponent<0)
  {
    int n = -exponent;
    double result = 1.0;
    while(n)
    {
      result *= base;
      n--;
    }

    if(equal(result,0))
    {
        cout<<"The result is infinity!"<<endl;
      //  exit(1);
      g_InvalidInput = true;
      return 0.0;
    }
    else
      return(1.0/result);
  }

}


int main()
{

double  base = 1.102;
double  exponent = -10000;
 cout<<"base: "<<base <<" exponent: "<<exponent<<"Result: "<< Power(base,exponent)<<endl;

  base = 0.102;
  exponent = -10000;
 cout<<"base: "<<base <<" exponent: "<<exponent<<"Result: "<< Power(base,exponent)<<endl;

  base = 0;
  exponent = 0;
 cout<<"base: "<<base <<" exponent: "<<exponent<<"Result: "<< Power(base,exponent)<<endl;

  base = 0;
  exponent = -10000;
 cout<<"base: "<<base <<" exponent: "<<exponent<<"Result: "<< Power(base,exponent)<<endl;

  base = 0;
  exponent = 10000;
 cout<<"base: "<<base <<" exponent: "<<exponent<<"Result: "<< Power(base,exponent)<<endl;

  base = -10;
  exponent = -100;
 cout<<"base: "<<base <<" exponent: "<<exponent<<"Result: "<< Power(base,exponent)<<endl;

  base = 10;
  exponent = -100;
 cout<<"base: "<<base <<" exponent: "<<exponent<<"Result: "<< Power(base,exponent)<<endl;

  base = 100;
  exponent = 3;
 cout<<"base: "<<base <<" exponent: "<<exponent<<"Result: "<< Power(base,exponent)<<endl;






}

double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
  if(exponent==0) return 1;
  if(exponent==1) return base;
   
  double result = PowerWithUnsignedExponent(base,exponent>>1);
   result *= result;
   if(exponent&1) result *= base;

    return result;
}








