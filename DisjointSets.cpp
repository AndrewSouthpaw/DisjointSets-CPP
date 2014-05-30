//
//  DisjointSets.cpp
//
//  Created by Andrew Smith on 5/30/14.
//
//

#include "DisjointSets.h"


/* Constructor initializes default values */
template <typename KeyType>
DisjointSets<KeyType>::DisjointSets() {
	numSets = 0;
	map = unordered_map<KeyType, Node>();
}


/* Destructor */
template <typename KeyType>
DisjointSets<KeyType>::~DisjointSets() {
}


/* Function: contains
 * Usage: if (!dset.contains(node))
 * ================================
 * Returns whether the set contains the node.
 */
template <typename KeyType>
bool DisjointSets<KeyType>::contains(KeyType& node) {
	return map.find(node) != map.end();
}

/* Function: makeSet
 * Usage: dset.makeSet(node);
 * ==========================
 * Adds the node as a singleton set.
 */
template <typename KeyType>
void DisjointSets<KeyType>::makeSet(KeyType& node) {
	/* Do nothing if already contains this node */
	if (!contains(node)) {
		/* Make struct to store info about this node */
		Node n;
		n.parent = node;
		n.rank = 0;
		
		/* Store in map */
		map[node] = n;
		
		/* Increment number of sets */
		numSets++;
	}
	
}

/* Function: size
 * Usage: int numSets = dset.size()
 * ================================
 * Returns size of disjoint-sets. */
template <typename KeyType>
int DisjointSets<KeyType>::size() {
	return numSets;
}


/* Function: find
 * ===================================
 * Provides two overloaded functions. If one node is provided, it returns
 * its root node. If two nodes are provided, it checks whether the two nodes
 * are connected.
 *
 * Usage: KeyType root = dsets.find(node);
 * ===================================
 * Returns the root node of a provided node. Compresses path along the way,
 * flattening the map by setting each node visited along the path to the root
 * to link directly to the root.
 */
template <typename KeyType>
KeyType DisjointSets<KeyType>::find(KeyType& node) {
	if (map[node].parent != node) map[node].parent = find(map[node].parent);
	return map[node].parent;
}

/* Usage: bool connected = dsets.find(node1, node2);
 * =================================================
 * Returns whether two nodes are connected. */
template <typename KeyType>
bool DisjointSets<KeyType>::find(KeyType& node1, KeyType& node2) {
	return find(node1) == find(node2);
}

/* Function: link
 * Usage: dsets.link(node1, node2);
 * ================================
 * Joins together the two sets to which two nodes belong. Uses weighted
 * union approach (smaller tree added to bigger tree). */
template <typename KeyType>
void DisjointSets<KeyType>::link(KeyType& node1, KeyType& node2) {
	KeyType root1 = find(node1);
	KeyType root2 = find(node2);
	if (root1 != root2) {
		/* Link the smaller tree to the bigger tree (weighted) */
		if (map[root1].rank < map[root2].rank)
			map[root1].parent = root2;
		else if (map[root2].rank < map[root1].rank)
			map[root2].parent = root1;
		/* Else, trees of equal size; increment rank */
		else {
			map[root2].parent = root1;
			map[root1].rank++;
		}
        
		/* Decrement number of sets */
		numSets--;
	}
    
}
























