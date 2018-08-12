class Solution:

    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        result = []
        i = 0

        self.helpp(R, C, r0, c0, 0, 0, 1, 0, result, 0)
        return result

    def helpp(self, R, C, r, c, orient, step,  max_step, time, result, count):
        steps = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        if count == R*C:
            return
        if 0<= r < R and 0<= c < C:
            count += 1
            result.append([r, c])
        rr, cc = steps[orient]
        r += rr
        c += cc
        step += 1
        if step == max_step:
            if orient == 0:
                orient = 1
            elif orient == 1:
                orient = 2
            elif orient == 2:
                orient = 3
            else:
                orient = 0
            step = 0
            time += 1
            if time == 2:
                max_step += 1
                time = 0
        self.helpp(R, C, r, c, orient, step, max_step, time, result, count)
