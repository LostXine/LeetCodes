6. ZigZag Conversion  QuestionEditorial Solution  My Submissions
Total Accepted: 105301
Total Submissions: 419034
Difficulty: Easy
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


class Solution {
public:
    string convert(string s, int numRows) 
    {
        int len = s.length();
        if(len < numRows || numRows <2 ){return s;}
        
        string result = "";
        
        for(int i = 0;i<numRows;i++)
        {
            int index = i;
            bool mid = (i>0 && i < numRows-1);
            bool flag = true;
            while(index<len)
            {
                result.push_back(s[index]);
                if(mid)
                {
                    if(flag)
                    {
                        index+=(2*(numRows-i-1));
                    }
                    else
                    {
                        index +=(2*i);
                    }
                    flag = !flag;
                }
                else
                {
                    index+=(numRows*2-2);
                }
            }
        }
        return result;
        
    }
};