 #Longest Substring Without Repeating Characters
 
 #This is an O(n) Time Complexity Solution for this Problem.
 #This is also an O(n) Space Complexity Problem.
 #This uses a hash set as well as a sliding window to track the longest subset problem.
 #Dumb Apprach would involve getting every substring which would be a O(n!) time complexity probelem very slow
 
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        Left = 0
        sett = set()
        max_leng = 0
        
        for Right in range(len(s)):
            #case 1: duplicate char
            while s[Right] in sett:
                sett.remove(s[Left])
                Left+=1
            
            #case 2: No Duplicate Char
            max_leng = max(max_leng, Right-Left+1)
            sett.add(s[Right])
        return max_leng