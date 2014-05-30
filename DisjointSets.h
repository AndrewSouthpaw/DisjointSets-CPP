//
//  DisjointSets.h
//  Trailblazer
//
//  Created by Andrew Smith on 5/30/14.
//
//

#ifndef _DisjointSets_h
#define _DisjointSets_h

#include <iostream>
#include "hashmap.h"
#include <unordered_map>

template <typename KeyType>
class DisjointSets {
public:
	/* Constructor */
	DisjointSets();
	
	/* Destructor */
	~DisjointSets();
	
	/* Returns whether the node is in the disjoint-sets */
	bool contains(KeyType& node);
	
	/* Adds a singleton to the disjoint-sets */
	void makeSet(KeyType& node);
	
	/* Returns size of disjoint-sets */
	int size();
	
	/* Finds the root node */
	KeyType find(KeyType& node);
	
	/* Returns whether two nodes are connected */
	bool find(KeyType& node1, KeyType& node2);
	
	/* Joins together the two sets to which two nodes belong */
	void link(KeyType& node1, KeyType& node2);
	
private:
	struct Node {
		KeyType parent;
		int rank;
	};
	int numSets;	/* Number of sets in disjoint-sets */
	unordered_map<KeyType, Node> map;		/* Map of KeyType to Node  */
};

#include "DisjointSets.cpp"

#endif /* defined(_DisjointSets_h) */





