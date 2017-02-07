/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = abs(C-A)*abs(D-B);
        int s2 = abs(G-E)*abs(H-F);
        int s3 = cross(A,C,E,G)*cross(B,D,F,H);
        return s1+s2-s3;
    }

    int cross(int A,int B, int C,int D){
        int l1,l2,r1,r2;
        if(B>A){l2 = B;l1 = A;}
        else{l1 = B;l2 = A;}
        if(C>D){r2 = C;r1 = D;}
        else{r1 = C;r2 = D;}
        if(r1>=l2||l1>=r2){return 0;}
        if(r1<=l1 && l2<=r2){return l2-l1;}
        if(l1<=r1 && r2<=l2){return r2-r1;}
        if(r1<=l1 && r2<=l2){return r2-l1;}
        if(l1<=r1 && l2<=r2){return l2-r1;}
        return 0;
    }
    
};