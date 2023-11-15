def median(nums: list[int]) -> float:
    size = len(nums)
    if size == 0:
        return 0
    else:
        nums.sort()
        if size % 2 == 0:
            return (nums[size // 2 - 1] + nums[size // 2]) / 2
        else:
            return nums[size // 2]
