#include<bits/stdc++.h>
#include"treap_map.h"
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	clock_t j=clock();
	treap_map<long long,long long,long long> m;
	for(int i=0;i<10000000;i++)m.insert(i,i);
	cout<<"depth"<<m.depth()<<"t1insert:"<<clock()-j<<endl;
	j=clock();
	map<long long,long long> mm;
	for(int i=0;i<10000000;i++)mm[i]=i;
	cout<<"t2insert:"<<clock()-j;
	cout<<"\n\n";
	 j=clock();
	for(int i=0;i<10000000;i++)m[i];
	cout<<"t1get:"<<clock()-j<<endl;
	j=clock();
	for(int i=0;i<10000000;i++)mm[i];
	cout<<"t2get:"<<clock()-j;
	cout<<"\n\n";
	j=clock();
	for(int i=0;i<10000000;i++)m.erase(i);
	cout<<"t1erase:"<<clock()-j<<endl;
	j=clock();
	for(int i=0;i<10000000;i++)mm.erase(i);
	cout<<"t2erase:"<<clock()-j;
}
