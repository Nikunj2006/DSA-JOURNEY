class Solution:
    def isRectangleOverlap(self, rec1, rec2):
        return not (rec2[0] >= rec1[2] or rec1[0] >= rec2[2] or rec2[1] >= rec1[3] or rec1[1] >= rec2[3])   