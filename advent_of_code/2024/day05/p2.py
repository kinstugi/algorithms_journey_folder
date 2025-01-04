from collections import defaultdict

edges = defaultdict(list)
indegrees = defaultdict(int)

def top_sort(nd:int, order:list[int], present: set):
    order.append(nd)
    for nei in edges[nd]:
        if nei in present:
            indegrees[nei] -= 1
            if indegrees[nei] == 0:
                top_sort(nei, order, present)


def main():
    first, second = "", ""
    with open("input.in") as fh:
        first, second = fh.read().split("\n\n")

    for line in first.strip().split('\n'):
        a,b = list(map(int, line.split('|')))
        edges[a].append(b)
        indegrees[b] += 1
        indegrees[a]
    
    res = 0
    for line in second.strip().split("\n"):
        arr = list(map(int, line.split(',')))
        earlier = set()
        ok = True
        present = set(arr)

        for num in arr:
            for sub in edges[num]:
                if sub in present:
                    indegrees[sub] += 1
                if sub in earlier:
                    ok = False
            earlier.add(num)

        print(indegrees)
        if ok:
            res += arr[len(arr) // 2]
        else:
            order = []
            start = []
            for e in arr:
                print(indegrees[e])

    print(res)    


if __name__ == "__main__":
    main()