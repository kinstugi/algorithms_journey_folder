from collections import defaultdict

n, m = list(map(int, input().split()))
cats = list(map(int, input().split()))
cats = [0] + cats

graph = defaultdict(list)

for i in range(1, n):
  a, b  = list(map(int, input().split()))
  graph[a].append(b)
  graph[b].append(a)


def helper_iter(root, nn):
  stk = [(root, nn)]
  seen = set([root])
  ans = 0

  while stk:
    node, cc = stk.pop()
    isLeaf = True

    for nei in graph[node]:
      if nei in seen: continue
      
      isLeaf = False
      seen.add(nei)
      nxt = cc + 1 if cats[nei] == 1 else 0

      if nxt > m: continue
      stk.append((nei, nxt))
    
    if not isLeaf: continue
    if cc <= m:
      ans += 1
  return ans


print(helper_iter(1, cats[1]))