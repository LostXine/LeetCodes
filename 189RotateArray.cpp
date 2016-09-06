189. Rotate Array  QuestionEditorial Solution  My Submissions
Total Accepted: 88288
Total Submissions: 393150
Difficulty: Easy
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

//Way1:
class Solution {
public:
    void rotate(vector<int>& nums, int k)
	{
		
		int st = nums.size();
		if (st<2){ return; }
		int time = st - k%st;
		int i;
		nums.resize(st + time);
		for (i = 0; i<time; i++)
		{
			nums[st+i] = nums[i];
		}
		//STL vector每次超过限制时都会换一块内存
		nums.erase(nums.begin(), nums.begin()+i);
	}
};

//Way2:
//直接循环替换即可
 void rotate(vector<int>& nums, int k) 
    {
        //Way 2
        int st = nums.size();
        if(st < 2){return;}
        int shift = k%st;
        int count = 0;
        for(int i = 0;count<st;i++)//这里的计数器是count和size
        {
            int now = i;
            int cache = nums[i];
            do
            {
                now = (now+shift)%st;
                int tmp = nums[now];
                nums[now] = cache;
                cache = tmp;
                count ++;
            }
            while(now != i);
        }
    }