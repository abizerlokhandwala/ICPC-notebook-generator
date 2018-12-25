from collections import defaultdict
from heapq import *

def dijkstra(edges, f, t):
   g = defaultdict(list)
   for l,r,c in edges:
       g[l].append((c,r))

   q, seen = [(0,f,())], set()
   while q:
       (cost,v1,path) = heappop(q)
       if v1 not in seen:
           seen.add(v1)
           path = (v1, path)
           if v1 == t: return (cost, path)
           for c, v2 in g.get(v1, ()):
               if v2 not in seen:
                   heappush(q, (cost+c, v2, path))
   return float("inf")

#Code example
edges = [("A", "B", 7), ("A", "D", 5), ("B", "C", 8),
         ("B", "D", 9), ("B", "E", 7), ("C", "E", 5)]
print "A -> E:"
print dijkstra(edges, "A", "E")   #(14, ('E', ('B', ('A', ()))))
