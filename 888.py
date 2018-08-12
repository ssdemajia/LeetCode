import itertools
class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        As = A.split(' ')
        Bs = B.split(' ')
        result = []
        # print(As)
        m = dict()
        for i in itertools.chain(As, Bs):
            if i in m:
                m[i] += 1
            else:
                m[i] = 1
        for k, v in m.items():
            if v == 1:
                result.append(k)
        return result
def main():
    A = "this apple is sweet"
    B = "this apple is sour"
    so = Solution()
    print(so.uncommonFromSentences(A, B))

if __name__ == '__main__':
    main()