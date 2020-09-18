/**
 *	@author: Nijad Huseynov
 * 	@file: Unionfind
 * 	@date: 22/08/20 23:13 	 
 */
 
#pragma once 
 
class Unionfind{
	public:
		Unionfind(int _size){
			m_size.reserve(_size);
			m_parents.reserve(_size);
			
			for(int i = 0; i < _size; i++){
				m_size[i] = 1;
				m_parents[i] = i;
			}
		};
	/**
	 *   Returns the parent of a given node
	 *   @param v - node.
	 *   @return parent of the node.
	 */	
	int get_parent(int v){
		if(v == m_parents[v])
			return v;
			return m_parents[v] = get_parent(m_parents[v]);
	}	
	/**
	 *   Returns true if the given nodes are already connected, otherwise unites them and returns false.
	 *   @param u - node.
	 *   @param v - node.
	 *   @return true if the given nodes are connected.
	 */
	bool unite(int u,int v){
		int par_u = get_parent(u);
		int par_v = get_parent(v);
		if(par_u == par_v){
			return true;
		}
		if(m_size[par_u] < m_size[par_v]){
			swap(par_u,par_v);
		}
		m_size[par_u] += m_size[par_v];
		m_parents[par_v] = par_u;
		return false;
	}
	private:
		vector<int> m_size;
		vector<int> m_parents;
		
};

