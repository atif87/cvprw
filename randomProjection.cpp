#include<iostream>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
using namespace std;
int main()
{
	float f;
	int i=0;
	srand(time(NULL));
	for(i=0;i<100;i++)
	{
		float j =  ((int)(rand())%100)*1.0/50-1 ;
		cout<<j<<endl;
	}
}
