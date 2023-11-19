#ifndef MYARRAY__
#define MYARRAY__
#include<bits/stdc++.h>
#include<random>
#include<chrono>
using namespace std;
template<typename Key_,typename Zhi_,typename pri_type = int>
class treap_map{
	Zhi_ NOT_have_return;
	int RAND_SEED;
	pri_type rand(pri_type smoll,pri_type big){
		static mt19937_64 engine(RAND_SEED);
		//static random_device RAND;
		pri_type a=big-smoll+1,sum;
		sum=engine()%a+smoll;
		
		return sum;
	}
	
	long long get_rand_seed(){
		long long duration = (std::chrono::high_resolution_clock::now()).time_since_epoch().count();
		mt19937 Rand(duration);
		return Rand();
	} 

	template<typename Key__,typename Zhi__>
	struct node{
		Zhi__ zhi_;
		Key__ key_  ;
		int soms=0,pri;
		node *l=NULL,*r=NULL;//l×ó,rÓÒ 
	};
	

	int sizes=0;
	node<Key_,Zhi_>* head=NULL;
	node<Key_,Zhi_>* new_node(Key_ k,Zhi_ z){
		node<Key_,Zhi_>* j=new node<Key_,Zhi_>;
		j->zhi_=z;
		j->key_=k;
		(j->pri=rand(1,100000000));
		return j;
	}
	void Split(node<Key_,Zhi_>*& u,Key_ x,node<Key_,Zhi_>*& L,node<Key_,Zhi_>*& R){
		if(u==NULL){L=R=NULL;return;}
		if(u->key_<=x){
			L=u;
			Split(u->r,x,u->r,R);
		}else{
			R=u;
			Split(u->l,x,L,u->l);
		}
	}
	node<Key_,Zhi_>* Merge(node<Key_,Zhi_>* L,node<Key_,Zhi_>* R){
		if(L==NULL){
			return R;
		}else if(R==NULL){
			return L;
		}
		if(L->pri>R->pri){
			L->r=Merge(L->r,R);
			return L;
		}else{
			R->l=Merge(L,R->l);
			return R;
		}
	}
	node<Key_,Zhi_>* found(Key_ k,node<Key_,Zhi_>* a){
		while(1){
			if(a==NULL){
				return NULL;
			}
			if(k==a->key_)return a;
			
			if(k<a->key_)a=a->l;
			else a=a->r;
		}
	}
	void clears(node<Key_,Zhi_>* j){
			if(j==NULL)return;
			if(j->r==NULL&&j->l==NULL){
			
				delete j;
				return;
			}else{
				
				clears(j->l);clears(j->r);
				j->r=NULL;
				j->l=NULL;
			
				delete j;
			}
	}
	int depth1(int l,node<Key_,Zhi_>* j){
		if(j==NULL){
			return l;
		}
		return max(depth1(l+1,j->r),depth1(l+1,j->l));
	}
	node<Key_,Zhi_>* pr_insert(Key_ k,Zhi_ z){
			node<Key_,Zhi_>* newd=new_node(k,z),*L,*R;
			Split(head,k,L,R);
			head=Merge(Merge(L,newd),R);
			return newd;
	}
	public:
		treap_map<Key_,Zhi_,pri_type>(){
			RAND_SEED=get_rand_seed();
		}
		~treap_map<Key_,Zhi_,pri_type>(){
			clear();
		}
		void clear(){
			clears(head);
			head=NULL;
		}
		void insert(Key_ k,Zhi_ z){
			if(found(k,head)==NULL){
				node<Key_,Zhi_>* newd=new_node(k,z),*L,*R;
				Split(head,k,L,R);
				head=Merge(Merge(L,newd),R);
			}
		}
		void erase(Key_ k){
				node<Key_,Zhi_> *L,*R,*ll,*rr;
				Split(head,k,L,R);
				Split(L,k-1,ll,rr);
				if(rr){
					rr->r=rr->l=NULL;
					delete rr;
				}
				
				head=Merge(ll,R);
				
			
		}
		Zhi_& operator[](Key_ k){
			node<Key_,Zhi_>* re=found(k,head);
			if(re!=NULL){
				return re->zhi_;
			}else{
				insert(k,NOT_have_return);
				return pr_insert(k,NOT_have_return)->zhi_;
			}
		}
		int depth(){
			return depth1(0,head);
		}
		
		
};
#endif
