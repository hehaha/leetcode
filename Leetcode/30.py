# -*- coding: utf-8 -*-


class Solution(object):
    def findSubstring(self, s, words):
        if not words or not s:
            return []
        index_map = {}
        word_len = len(words[0])
        words_amount = len(words)
        for word in set(words):
            find = s.find(word)
            while find != -1:
                index_map[find] = word
                find = s.find(word, find + 1)
        result = []
        end = len(s) - words_amount * word_len
        for index, word in sorted(index_map.items()):
            if index > end:
                break
            word_set = list(words)
            next_index = index
            while(word_set and word):
                try:
                    word_set.remove(word)
                except ValueError:
                    break
                else:
                    next_index += word_len
                    word = index_map.get(next_index)
            else:
                if not word_set:
                    result.append(index)
        return result


s = Solution()
print s.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", ["fooo","barr","wing","ding","wing"])
