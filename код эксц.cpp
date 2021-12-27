#include <iostream>
#include <math.h>
using namespace std;
 
int main() {
	double A,B,C,D,E,F,det,d;
	cin>>A>>B>>C>>D>>E>>F;
	det=(A*C*F)+(B*E*D/4)-(D*D*C/4)-(E*E*A/4)-(B*B*F/4);
	d = B*B - 4*A*C;
	if(A!=0 || B!=0 || C!=0){
		if (det == 0){
			if(d>0)cout<<"Это пара пересекающихся прямых";
			else if(d==0){
				if(D*D+E*E > 4*(A+C)*F)cout<<"Это две параллельные прямые";
				else if(D*D+E*E == 4*(A+C)*F)cout<<"Это прямая линия";
				else cout<<"Это пустое множество";
			}
			else cout<<"Это точка";
		}else{
			int k=1;
			if(det>0)k*=-1;
			double e=sqrt((2*sqrt(pow((A-C),2)+B*B)) / (k*(A+C)+sqrt(pow((A-C),2)+B*B)));
			if(d>0)cout<<"Это гипербола. Её числовой эксцентриситет равен "<<e;
			else if(d<0){
				if((A+C)*det<0){
					if(A==C && B==0)cout<<"Это круг. Его числовой эксцентриситет равен 0";
					else cout<<"Это эллипс. Его числовой эксцентриситет равен "<<e;
				}else cout<<"Это мнимый эллипс ";
			}else cout<<"Это парабола. Её числовой эксцентриситет равен 1";
		}
	}else{
		if(E==0 && D==0)cout<<"Это пустое множество";
		else cout<<"Это прямая линия";
	}
	return 0;
}