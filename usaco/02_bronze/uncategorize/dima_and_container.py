import heapq
from collections import Counter

N = int(input())

nums = []
pq = []


for _ in range(N):
    tmp = int(input())

    if tmp != 0:
        nums.append(tmp)
        heapq.heappush(pq, tmp)
        while len(pq) > 3:
            heapq.heappop(pq)
    else:
        cnt = len(pq)
        mp = Counter(pq)
        for num in nums:
            
            if num in mp and mp[num] > 0:
                if cnt == 3:
                    print("pushFront")
                elif cnt == 2:
                    print("pushQueue")
                else:
                    print("pushStack")
                cnt -= 1
                mp[num] -= 1
            else:
                print("pushBack")
        
        if not nums:
            print(0)
        elif len(nums) >= 3:
            print("3 popStack popQueue popFront")
        elif len(nums) >= 2:
            print("2 popStack popQueue")
        else:
            print("1 popStack")
        
        nums = []
        pq = []

for num in nums:
    print("pushBack")