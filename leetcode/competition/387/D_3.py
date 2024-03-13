import bisect
from sortedcontainers import SortedList


class Solution:
    def resultArray(self, nums):
        n = len(nums)
        arr1 = [nums[0]]
        mp1 = SortedList([nums[0]])
        arr2 = [nums[1]]
        mp2 = SortedList([nums[1]])
        for i in range(2, n):
            index1 = mp1.bisect_right(nums[i])
            index2 = mp2.bisect_right(nums[i])
            cnt1 = len(mp1) - index1
            cnt2 = len(mp2) - index2

            if cnt1 > cnt2:
                arr1.append(nums[i])
                mp1.add(nums[i])
            elif cnt1 < cnt2:
                arr2.append(nums[i])
                mp2.add(nums[i])
            else:
                if len(mp1) <= len(mp2):
                    arr1.append(nums[i])
                    mp1.add(nums[i])
                else:
                    arr2.append(nums[i])
                    mp2.add(nums[i])
        return arr1 + arr2
