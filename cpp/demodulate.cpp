#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <fstream>
#include"tmwtypes.h"
#include"stdlib.h"


vector<int> demodulate(){
	ifstream fp2;
	fp2.open("QAMDATA_WITH_NOISE.txt");
	vector<int> dem;
	int temp;
	while(fp2 >> temp) {
		dem.push_back(round(temp));
		//cout << round(temp) << " ";
		fp2 >> temp;
		dem.push_back(round(temp));
		//cout << round(temp) << endl;
	}
	cout<<"Dem size:"<<dem.size()<<endl;
	
	fp2.close();
	vector<int> a;
	cout<<"Init a size:"<<a.size()<<endl;
	int n = dem.size();
	int kk=0;
	for(int i=0;i<n;i=i+2){
		kk++;
		//cout<<"Init a size:"<<a.size()<<endl;
		switch (dem[i]){
			case -7:
            	
				a.push_back(0);
            	a.push_back(0);
            	a.push_back(0);
            	break;
	        case -5:
	            a.push_back(0);
            	a.push_back(0);
            	a.push_back(1);
            	break;
	        case -3:
	            a.push_back(0);
            	a.push_back(1);
            	a.push_back(1);
            	break;
	        case -1:
	            a.push_back(0);
            	a.push_back(1);
            	a.push_back(0);
            	break;
	        case 1:
	            a.push_back(1);
            	a.push_back(1);
            	a.push_back(0);
            	break;
	        case 3:
	            a.push_back(1);
            	a.push_back(0);
            	a.push_back(0);
            	break;
	        case 5:
	            a.push_back(1);
            	a.push_back(0);
            	a.push_back(1);
            	break;
	        case 7:
	            a.push_back(1);
            	a.push_back(1);
            	a.push_back(1);
            	break;
            default:
            	cout<<"Somewthing is wrong!!"<<endl;
			
		}
		
		
		switch (dem[i+1]){
			case -7:
            	a.push_back(0);
            	a.push_back(0);
            	a.push_back(0);
            	break;
	        case -5:
	            a.push_back(0);
            	a.push_back(0);
            	a.push_back(1);
            	break;
	        case -3:
	            a.push_back(0);
            	a.push_back(1);
            	a.push_back(1);
            	break;
	        case -1:
	            a.push_back(0);
            	a.push_back(1);
            	a.push_back(0);
            	break;
	        case 1:
	            a.push_back(1);
            	a.push_back(1);
            	a.push_back(0);
            	break;
	        case 3:
	            a.push_back(1);
            	a.push_back(0);
            	a.push_back(0);
            	break;
	        case 5:
	            a.push_back(1);
            	a.push_back(0);
            	a.push_back(1);
            	break;
	        case 7:
	            a.push_back(1);
            	a.push_back(1);
            	a.push_back(1);
            	break;
            default:
            	cout<<"Somewthing is wrong!! in 2nd loop"<<endl;
			
		}
	}
	cout<<"Size Of a:"<<a.size()<<" "<<kk<<endl;
	return a;
}


int main(){
	vector<int> xd;
	xd = demodulate();
	int n = xd.size();
	cout<<"XD Size:"<<n<<endl;
	vector<int>v;
	for(int i=0;i<(n);i+=8){	
		int u=0;
		u+=xd[i]*pow(2,7);
		u+=xd[i+1]*pow(2,6);
		u+=xd[i+2]*pow(2,5);
		u+=xd[i+3]*pow(2,4);
		u+=xd[i+4]*pow(2,3);
		u+=xd[i+5]*pow(2,2);
		u+=xd[i+6]*pow(2,1);
		u+=xd[i+7]*pow(2,0);
		v.push_back(u);	
	}
	char q[n/8];
	for(int i=0;i<n/8;i++){
		q[i]=(char)(v[i]-128);	
	}
	cout<<"Done3"<<endl;
	FILE *fp5;
	fp5=fopen("finalcameraman.bmp","wb");
	for(int i=0;i<n/8;i++){
		fputc(q[i],fp5);
	}
	fclose(fp5);
	return 0;
}
