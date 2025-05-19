#selection sort for ascedning array
#Time complexity O(N^2) Space Complexity O(N)

def find_smallest_index(array : list):
    smallest = array[0]
    smallest_index = 0
    for i in range(1,len(array)):
       if array[i] < smallest:
            smallest_index = i
            smallest = array[i]
    return smallest_index

def selction_sort(array : list):
    result_arr = []
    copied_arr = list(array)
    for i in range (len(copied_arr)):
        smallest_index = find_smallest_index(copied_arr)
        result_arr.append(copied_arr.pop(smallest_index))

    print(result_arr)
    
    
test = [47,10,15,-1,-2,67,199]

selction_sort(test)