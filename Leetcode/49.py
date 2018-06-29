# -*- coding: utf-8 -*-
class Solution(object):
    def groupAnagrams(self, strs):
        result_map = {}
        for s in strs:
            trans_s = "".join(sorted(s))
            if trans_s in result_map:
                result_map[trans_s].append(s)
            else:
                result_map[trans_s] = [s]
        return [r for r in result_map.values()]

s = Solution()
print s.groupAnagrams(["", ""])
