

def numInList(array : list):
    #base case == array is 0
    
    if len(array) == 0: 
        return 0
    
    array.pop()
    return  1 + numInList(array)


array = [1,2,3,4,7,9,10]
print(numInList(array))