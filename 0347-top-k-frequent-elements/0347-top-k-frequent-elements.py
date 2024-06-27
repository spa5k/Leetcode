class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter ={}
        
        for i in nums:
            if i in counter:
                counter[i]+=1
            else:
                counter[i]=1
                
        heap=[]
        
        for i in counter.keys():
            if len(heap)==k:
                heapq.heappushpop(heap, (counter[i],i))
            else:
                heapq.heappush(heap, (counter[i],i))

        ans=[]

        while k>0:
            k-=1
            ans.append(heapq.heappop(heap)[1])
        return ans