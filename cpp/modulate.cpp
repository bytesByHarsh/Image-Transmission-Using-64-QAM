#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <fstream>
#include"tmwtypes.h"
#include"stdlib.h"

void mod(vector<int> x){
	ofstream fp1;
	fp1.open("QAMDATA.txt");
	int n = x.size();
	cout<<"X size:"<<n<<endl;
	creal_T mod[n/6];
	int k=0;
	for(int i=0;i<n;i=i+6){
		if(x[i]==0 && x[i+1]==0 && x[i+2]==0){
			
			mod[k].re = -7;
		}
		else if(x[i]==0 && x[i+1]==0 && x[i+2]==1){
			mod[k].re = -5;
			
		}
		else if(x[i]==0 && x[i+1]==1 && x[i+2]==1){
			mod[k].re = -3;
			
		}
		else if(x[i]==0 && x[i+1]==1 && x[i+2]==0){
			mod[k].re = -1;
			
		}
		else if(x[i]==1 && x[i+1]==1 && x[i+2]==0){
			mod[k].re = 1;
			
		}
		else if(x[i]==1 && x[i+1]==0 && x[i+2]==0){
			mod[k].re = 3;
			
		}
		else if(x[i]==1 && x[i+1]==0 && x[i+2]==1){
			mod[k].re = 5;
			
		}
		else if(x[i]==1 && x[i+1]==1 && x[i+2]==1){
			mod[k].re = 7;
			
		}
		
		//*************For Imaginary************************
		
		
		if(x[i+3]==0 && x[i+4]==0 && x[i+5]==0){
			
			mod[k].im = -7;
		}
		else if(x[i+3]==0 && x[i+4]==0 && x[i+5]==1){
			mod[k].im = -5;
			
		}
		else if(x[i+3]==0 && x[i+4]==1 && x[i+5]==1){
			mod[k].im = -3;
			
		}
		else if(x[i+3]==0 && x[i+4]==1 && x[i+5]==0){
			mod[k].im = -1;
			
		}
		else if(x[i+3]==1 && x[i+4]==1 && x[i+5]==0){
			mod[k].im = 1;
			
		}
		else if(x[i+3]==1 && x[i+4]==0 && x[i+5]==0){
			mod[k].im = 3;
			
		}
		else if(x[i+3]==1 && x[i+4]==0 && x[i+5]==1){
			mod[k].im = 5;
			
		}
		else if(x[i+3]==1 && x[i+4]==1 && x[i+5]==1){
			mod[k].im = 7;
			
		}
		fp1<<mod[k].re<<" "<<mod[k].im<<endl;	
		k++;
		
	}
	cout<<"Num:"<<k<<endl;
	fp1.close();
}


int main(){
	
	FILE *fp1;
	fp1 = fopen("new.bmp","rb");
	int n=0;
	int h[1024];
	do{
		char c = fgetc(fp1);
		h[n]=(c+128);
		
		n++;
    }while(!feof(fp1));
    
    cout<<endl<<"Count:"<<n<<endl;
    
    vector<int> x;
	for(int i=0;i<n;i++){
		int a=h[i];
		int reva=x.size();
		int t=0;
		while(a||t<8){
			x.push_back(a%2);
			a=a/2;
			t++;	
		}
		reverse(x.begin()+reva,x.end());			
	}
	cout<<"Size of Binary:"<<x.size()<<endl;
	mod(x);
	fclose(fp1);
	return 0;
}
