/**
 *	@author: Nijad Huseynov
 * 	@file: SegTree-AddingGeoProgression.h
 *	@date: 31/01/20 23:14	
 *	@description: Adding geometric progression to the interval with common ratio 'Q'     
 *
 */



#pragma once


typedef long long int ll;

const ll MOD = 1e9 + 9;
const ll Q1 = 691504013;
const ll Q2 = 308495997;
const ll Q3 = 276601605;

/**
 *   Returns the n-th power of given integer modulo MOD.
 *   @param a - integer.
 *   @param n - integer.
 *   @return (a ^ n) mod MOD
 */
ll power(ll a, ll n){
	if(n==0) return 1ll;
	if(n==1) return a%MOD;
	ll q = power(a,n>>1);
	q = q * q % MOD;
	if(n&1) q = q * (a%MOD) % MOD;
	return q; 
}

/**
 *   Returns inverse of given integer modulo MOD.
 *   @param a - integer.
 *   @return (a ^ -1) mod MOD
 */

ll inv(ll a){
	return power(a,MOD-2);
}


/**
 * Implementation of a lazy SegmentTree with geometric addition
 *
 * To instantiate a class with common ration Q use the following syntax:
 * 	SegmentTree tree(n,Q1)
 * To add (Q + Q^2 + Q^3 + ... + Q ^ (r-l+1)) to the range [l,r] use the following syntax:  
 * 	tree.Update(l,r)	
 * To find the sum in the range [l,r] use the following syntax:
 *      tree.Query(l,r)
 * @note  All the operations are done modulo MOD
 */
class SegmentTree{
	public:	
		ll Q, INV;
		struct Node{
			long long sum;
			long long lazy;
			Node():sum(0),lazy(0){};
			Node(ll a, ll c):sum(a),lazy(c){};
		};
		SegmentTree(int _size, ll _Q): tree((_size << 3),{0,0}),Q(_Q),pref(_size+12){
			pref[1] = Q;
			for(int i = 2; i <= _size; i++){
				pref[i] = pref[i-1] * Q % MOD;
			}
			INV = inv(Q - 1+ MOD);
		};
		/**
 		 *   Adds geometric progression to the range [l,r] with common ratio
 		 *   @param l - left side of the range.
 		 *   @param r - right side of the range.
		 */
		void Update(int l, int r){
			update(1,1,((int)tree.size() ) / 8,l,r,Q);
		}
		
		/**
		 *   Returns sum of the values in the range [l,r]  modulo MOD.
		 *   @param l - left side of the range.
 		 *   @param r - right side of the range.
 		 *   @return sum of the values in the range [l,r] 
		 */
		ll Query(int l,int r){
			return query(1,1,((int)tree.size() ) / 8,l,r) * Q3 % MOD; 
		}
	private:
		vector<Node> tree;
		vector<ll> pref;
	ll geoSum(ll b1, ll n){
		ll tmp = (pref[n] - 1) * INV % MOD;
		tmp = tmp * b1 % MOD;
		return tmp;
	}	
	void push(int pos, int l, int r){
		if(!tree[pos].lazy) return;
		int mid = (l+r) >> 1;
		int lSize = mid - l + 1;
		int rSize = r - mid;
		
		tree[pos << 1].sum = (tree[pos << 1].sum + geoSum(tree[pos].lazy,lSize));
		if(tree[pos << 1].sum >= MOD) tree[pos << 1].sum-=MOD; 
		tree[pos << 1].lazy= (tree[pos << 1].lazy + tree[pos].lazy);
		if(tree[pos << 1].lazy>= MOD)tree[pos << 1].lazy-=MOD;	 
		ll b1 =  pref[lSize];
		b1 = b1 * tree[pos].lazy % MOD;

		tree[pos << 1 | 1].sum = (tree[pos << 1 | 1].sum + geoSum(b1,rSize)); 
		if(tree[pos << 1 | 1].sum >= MOD) tree[pos << 1 | 1].sum-=MOD; 

		tree[pos << 1 | 1].lazy= (tree[pos << 1 | 1].lazy + b1); 
		if(tree[pos << 1 | 1].lazy>= MOD)tree[pos << 1 | 1].lazy-=MOD;	
		tree[pos].lazy = 0;
				
		
	}	
	void update(int pos, int l, int r, int a, int b, ll d){
		if(r < a || l > b) return;
		if(a <= l && r <= b){
			tree[pos].sum = (tree[pos].sum + geoSum(d,r-l+1));
			if(tree[pos].sum >= MOD) tree[pos].sum-=MOD;
			tree[pos].lazy = (tree[pos].lazy + d);
			if(tree[pos].lazy >= MOD) tree[pos].lazy-=MOD;		  
			return;
		}
		
		push(pos,l, r);
		int mid = (l+r) >> 1;
		update(pos << 1, l, mid, a, b, d);
		ll rd = pref[max(mid - a + 2,1)];
		update(pos << 1 | 1,mid+1,r,a,b,rd);
		tree[pos].sum = (tree[pos << 1].sum + tree[pos << 1 | 1].sum);
		if(tree[pos].sum >= MOD) tree[pos].sum-=MOD;	
	}	
	ll query(int pos, int l, int r, int a, int b){
		if(r < a || l > b) return 0;		
		push(pos,l,r);
		if(a <= l && r <= b) return tree[pos].sum;
		int mid = (l+r) >> 1;
		ll res = (query(pos << 1,l,mid,a,b) + query(pos << 1 | 1,mid+1,r,a,b));
		if(res >= MOD) res-=MOD;
		return res;
	}	
};



