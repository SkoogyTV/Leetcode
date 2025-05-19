#this is my python rendition of quickSort

"""
    Choosing a piviot then quicksort(Less) <- (piviot) < quicksort(Greator)
    
    
"""

def quickSort(array : list):
    #BaseCase len < 2: Empty list and list of 1 is sorted
    
    if len(array) < 2:
        return array
    
    # else we have to sort the array!!!!!
    
    mid_index = len(array) // 2
    piv = array[mid_index]
    less = [i for i in array if i < piv] #if i < piv then append to less than list
    greator = [i for i in array if i > piv] #if i >= piv then append to greator than list
    equal = [i for i in array if i == piv]
    
    return quickSort(less) + equal + quickSort(greator)


array = [19,17,1,67,59,1000,-17]

print(quickSort(array))