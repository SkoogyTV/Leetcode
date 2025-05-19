from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        holder = defaultdict(list)
        
        for str in strs:
            counter = [0] * 26
            for c in str:
                counter[ord(c) - ord('a')]+=1
            
            holder[tuple(counter)].append(str)
            
        result = []    
        for key, value in holder.items():
            result.append(value)
            
        return result