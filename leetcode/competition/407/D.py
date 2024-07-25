def minOperations(nums, target):
    n = len(nums)
    diff = [target[i] - nums[i] for i in range(n)]
    total_operations = 0
    max_increase = 0  # 记录需要最多增加的次数

    for d in diff:
        total_operations += abs(d)
        max_increase = max(max_increase, abs(d))

    return max(total_operations, max_increase)


# Example usage:
nums = [1, 3, 2]
target = [2, 1, 4]
print(minOperations(nums, target))  # Output: 3
