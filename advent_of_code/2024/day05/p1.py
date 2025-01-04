import sys
from collections import defaultdict

sys.setrecursionlimit(4000)

ranks = defaultdict(int)
seen = set()

def calWeight(nd, graph):
    if nd in seen: return ranks[nd]
    rk = len(graph[nd])

    for nei in graph[nd]:
        rk += calWeight(nei, graph)
    seen.add(nd)
    ranks[nd] = rk
    return rk

def main():
    first, second = "", ""
    with open("input.in") as fh:
        first, second = fh.read().split("\n\n")
    
    edges = defaultdict(list)
    for line in first.strip().split('\n'):
        a,b = list(map(int, line.split('|')))
        edges[a].append(b)
    
    for k in edges.keys():
        if k not in seen:
            calWeight(k, edges)
    
    print(ranks)
    res = 0
    for line in second.strip().split("\n"):
        arr = list(map(int, line.split(',')))
        

    print(res)   

if __name__ == "__main__":
    main()     