
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(0 == n)
		{
			return 0;
		}

		int start = 0;
		int end = start+1;

		for(;end<n;++end)
		{
			if(A[start] != A[end])
			{
				start +=1;
				A[start] = A[end];
			}
		}

		return start+1;
    }
};