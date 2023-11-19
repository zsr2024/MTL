#ifndef TREE_ARRAY
#define TREE_ARRAY 
#include<bits/stdc++.h>
using namespace std;
class is_not_debug{
	
};
template<typename T,typename vessel=vector<T> >
class tree_array{
	vessel tree1,tree2;
	int max_pos=0;
	#define lowbit(x) (x&-x)
	
	void add1(int i,T x)
	{
		while(i<=tree1.size()){
			tree1[i]+=x;
			i+=lowbit(i);
		}
	}
	void add2(int i,T x)
	{
		while(i<=tree2.size()){
			tree2[i]+=x;
			i+=lowbit(i);
		}
	}
	
	T prefix1(int end_pos){
			int ans=0;
			while(end_pos){ans+=tree1[end_pos];end_pos-=lowbit(end_pos);}
			return ans;
		}
		T prefix2(int end_pos){
			int ans=0;
			while(end_pos){ans+=tree2[end_pos];end_pos-=lowbit(end_pos);}
			return ans;
		}
	public:
		T prefix(int end_pos){
			
			return sum(0,end_pos);
		}
		tree_array(int len):max_pos(len){
			tree1.resize(len+5);
			tree2.resize(len+5);
		}
		tree_array(){
			tree1.resize(5);
			tree2.resize(5);
		}
		const T operator[](int pos){
			return sum(pos,pos+1);
		}
		void update(int pos,T val){
			T t=val-sum(pos,pos+1);
			update(pos,pos+1,t);
		}
		void push_back(T x){
			tree1.push_back(x-x);
			tree2.push_back(x-x);
			update(max_pos++,x);
		} 
		void update(int begin_pos,int end_pos,T abb_val){
			begin_pos++;
			add1(begin_pos,abb_val);
			add1(end_pos+1,-abb_val);
			add2(begin_pos,abb_val*(begin_pos-1));
			add2(end_pos+1,-abb_val*end_pos);
		}
		T sum(int begin_pos,int end_pos){
			begin_pos++; 
			return end_pos*prefix1(end_pos)-prefix2(end_pos)-(begin_pos-1)*prefix1(begin_pos-1)+prefix2(begin_pos-1);
		}
}; 
#endif 
//end_pos×ÜÊÇ³¬Î²ÔªËØ 

