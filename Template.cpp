/**
	@author: Nijad Huseynov
 	@file: template
 	@date: 14/12/19 17:05 	
	@description: template for competetive programming   
*/

#include <bits/stdc++.h>

#define FAST 1 
#define UP_LIMIT 100010
#define MOD 1000000007
#define PI acos(-1)

#define f first
#define s second 
#define pb push_back
#define sz(x) (int)x.size()
#define be(x) x.begin(),x.end()
#define eb(x) x.rbegin(),x.rend()
 
#define debug(a...) cout << #a << " = "; dbg::Out(a);

using namespace std;

namespace dbg
{
	template<typename PType1,typename PType2>
	ostream & operator<<(ostream & out, const pair<PType1,PType2> & p){
		out << "(" << p.first << "," << p.second << ")";
	}
	template<typename VType>
	ostream & operator<<(ostream & out, const vector<VType> & v){
		out << "[";
		for(auto it = v.begin(); it != v.end(); it++){
			if(it != v.begin())
				out << " ";
			out << *it ;	
		}
		out << "]";	
		return out;
	}
	template<typename SType>
	ostream & operator<<(ostream & out, const set<SType> & s){
		out << "[";
		for(auto it = s.begin(); it != s.end(); it++){
			if(it != s.begin())
				out << ", ";
			out << *it;	
		}
		out << "]";
	}
	template<typename MType1, typename MType2>
	ostream & operator<<(ostream & out, const map<MType1,MType2> & m){
		out << "[";
		for(auto it = m.begin(); it != m.end(); it++){
			if(it != m.begin())
				out << ",";
			out << "{" << it->first << ":" << it->second << "}";
		}
		out << "]";
	}
	void Out(){cout << endl;}
	template<typename T, typename... U>
	void Out(T start,U... rest){
		cout << start << " ";
		Out(rest...);
	}	
}

int main(){
	#ifdef FAST
		ios_base::sync_with_stdio(false);
		cin.tie(NULL),cout.tie(NULL);
	#endif	
	int a = 1, b = 2, c = 3;
	debug(a,b,c);
	vector<int> A{1,2,3,4};
	debug(A,A,A);
	debug(A,A,A);
	return 0;
}

