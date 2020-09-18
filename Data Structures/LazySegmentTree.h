/**
 *	@author: Nijad Huseynov
 * 	@file: LazySegmentTree.h
 *	@date: 24/01/20 14:06	
 *	@description: Lazy Segment Tree       
 *
 */



#pragma once

typedef long long int ll;

/**
 * Implementation of a lazy Segment Tree - Range Sum
 */
template <typename T>
class LazySegmentTree{
	public:
		LazySegmentTree(int _size): node((_size<<2) + 4,0),lazy((_size<<2) + 4,0){}; 
		LazySegmentTree(const vector<ll> & a){
			int _size = (int)a.size();
			node = lazy = vector<T>((_size << 2) + 4,0);
			build(a,1,1,_size);
		}
		/**
		 *   Adds val to the range [l,r] .
		 *   @param l - left side of the range.
 		 *   @param r - right side of the range.
		 */
		void Update(int l, int r, T val){ 
			update(1,1,((int)node.size()-4)/4,l,r,val);
		}
		/**
		 *   Returns sum of the values in the range [l,r].
		 *   @param l - left side of the range.
 		 *   @param r - right side of the range.
 		 *   @return sum of the values in the range [l,r] 
		 */
		T Get(int l, int r){ 
			return get(1,1,((int)node.size()-4)/4,l,r);
		}	
	private:
		vector<T> node;
		vector<T> lazy;
		void push(int pos,int l, int r){
			int mid = (l+r) >> 1;
			node[pos << 1] += lazy[pos] * (mid - l + 1);
			lazy[pos << 1] += lazy[pos];
			node[pos << 1 | 1] += lazy[pos] * (r - mid);
			lazy[pos << 1 | 1] += lazy[pos];
			lazy[pos] = 0; 
		}
		void update(int pos, int l, int r, int a, int b, T val){
			if(l > r) return;
			push(pos,l,r);
			if(l > b || r < a) return;
			if(a <= l && r <= b){
				node[pos] += val * (r-l+1);
				lazy[pos] += val;
				return;
			}
			int mid = (l+r) >> 1;
			update(pos << 1, l, mid,a,b,val);
			update(pos << 1 | 1,mid+1,r,a,b,val);
			node[pos] = node[pos << 1] + node[pos << 1 | 1];	
		}
		T get(int pos, int l, int r, int a, int b){
			if(l > r) return 0;
			push(pos,l,r);
			if(l > b || r < a) return 0;
			if(a <= l&&r <= b) return node[pos];
			int mid = (l+r) >> 1;
			return get(pos << 1, l, mid, a, b) + get(pos << 1 | 1, mid+1,r , a, b);
		}	
		void build(const vector<T> & a, int pos, int l, int r){
			if(l > r) return;
			if(l==r){
				node[pos] = a[l];
				return;	
			}
			int mid = (l + r) >> 1;
			build(a,pos << 1,l,mid);
			build(a,pos << 1 | 1,mid+1,r);
			node[pos] = node[pos << 1] + node[pos << 1 | 1];
		}
};
