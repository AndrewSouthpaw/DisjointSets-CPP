DisjointSets-CPP
================

This is my first public contribution to GitHub! Comments on my implementation are very welcome. I still have much to learn in programming.

This file provides a basic disjoint-sets data structure (http://en.wikipedia.org/wiki/Disjoint-set_data_structure) in C++. It includes weighted union and path compression features, thus has a running-time on M union-find operations on N objects in O(N + Mlog*(N)) time.

If you want to use this data structure for a type that does not have a standard hash function defined, you can add this code:

```
namespace std {
	namespace tr1 {
		template <>
		struct hash<Loc>{
			public :
			size_t operator()(const Loc &loc ) const
			{
				return hashCode(loc);
			}
		};
	};
};
```

(Based on this reference: http://marknelson.us/2011/09/03/hash-functions-for-c-unordered-containers/)

