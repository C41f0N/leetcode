list1 = [1, 2, 3, 5, 5, 66, 88, 99, 100]

def getStartingFrom(list1: list, left: int, right: int, num: int) -> int:
    
    if (right < left):
        if list1[right] > num:
            return right
        else:
            return left
    else:
        mid = int(left + (right - left) / 2)

        if list1[mid] == num:
            return mid
        elif list1[mid] > num:
            return getStartingFrom(list1, left, mid - 1, num)
        else:
            return getStartingFrom(list1, mid + 1, right, num)

def getEndingFrom(list1: list, left: int, right: int, num: int) -> int:
    if (right < left):
        if list1[left] < num:
            return left
        else:
            return right
    else:
        mid = int(left + (right - left) / 2)

        if list1[mid] == num:
            return mid
        elif list1[mid] > num:
            return getEndingFrom(list1, left, mid - 1, num)
        else:
            return getEndingFrom(list1, mid + 1, right, num)
        
print(getEndingFrom(list1, 0, len(list1) - 1, 37))