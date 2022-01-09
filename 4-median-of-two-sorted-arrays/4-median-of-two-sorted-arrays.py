class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1,nums2 = nums2, nums1
        #Shorter array is nums1
        n1,n2 = len(nums1),len(nums2)
        
        leftHalf = (n1+n2+1)//2
        
        #Now the minimum contribution nums1 can make to the merged array is 0 and the max contribution is n1(nums1's length)
        minContribution = 0
        maxContribution = n1
        
        #We are essentially finding the last element of the left half of the merged final array, because it is sufficient for finding the median. We do this using binary search.
        while minContribution <= maxContribution:
            
            #We are searching in the space [minContribution,maxContribution] for the number of elements nums1 will contribute to the left half of the merged array. Since we know the size of the left half of the merged array, we can calculate the number of elements nums2 will contribute. Thus, we can find the median.
            c1 = minContribution + (maxContribution-minContribution)//2 #Num of elements nums1 contributes
            c2 = leftHalf - c1#Num of elements nums2 contributes
            x,x2,y,y2 = None,None,None,None
            
            if c1>0 : x = nums1[c1-1]
            if c2>0 : y = nums2[c2-1]
                
            if c1<n1: x2 = nums1[c1]
            if c2<n2: y2 = nums2[c2]
            
            #This is the important part. If x > y2, it means that x will come after y2 in the final merged array. Hence, we need to decrease maxContribution by 1. 
            if x is not None and y2 is not None and x>y2: maxContribution= c1-1
                
            #Similarly, if y>x2, we need to increase num of elements nums2 contributes; hence, increase the number of elemenets nums1 contributes.
            elif y and x2 and y>x2: minContribution = c1+1
            
            #This is the case which happens when we've found our answer
            else:
                
                #Here we find out the last element of the left half of the merged array. If x>y, it means that x will be the, median(since it will occur after y in the merged array). SImilar reasoning is applicable for the other case.
                leftHalfEnd = None
                if not x: leftHalfEnd = y
                elif not y or x>y: leftHalfEnd = x
                else: leftHalfEnd = y
                    
                #Now if the total elements(n1+n2) is odd, we can simply return the leftHalfEnd
                if (n1+n2)%2:
                    return leftHalfEnd
                
                #However, if it is even, we need to find the first element in the right half of the merged array and calculate their mean and return it.
                else:
                    rightHalfFirst = None
                    if not x2: rightHalfFirst = y2
                    elif not y2 or x2<y2: rightHalfFirst = x2
                    else: rightHalfFirst = y2
                    
                    return (rightHalfFirst + leftHalfEnd)/2
        return -1