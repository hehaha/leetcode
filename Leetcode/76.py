# -*- coding: utf-8 -*-


class Solution(object):
    def minWindow(self, s, t):
        set_t = set(t)
        index_map = {c: set() for c in set_t}
        for c in set_t:
            find = s.find(c)
            while find != -1:
                index_map[c].add(find)
                find = s.find(c, find + 1)
        left, right = None, None
        for c, index, in
