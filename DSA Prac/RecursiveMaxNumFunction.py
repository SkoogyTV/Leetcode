

def RecursiveMaxFunction(array : list):
    
    #baseCase: arraySize == 1
    #if the array is size 1 the only element in the array has to be both the min and the max
    if len(array) == 1:
        return array[0]
    
    #get the current first and compare to see if this is the max compared to the rest of the list
    first = array[0]
    max_of_rest = RecursiveMaxFunction(array[1:])
    
    return first if first > max_of_rest else max_of_rest

array = [500,-1,9000,2,10,65]

print(f'The Max of this vector is: {RecursiveMaxFunction(array)}')

