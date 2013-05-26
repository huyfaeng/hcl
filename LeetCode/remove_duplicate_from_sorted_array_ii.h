
class Solution_R_D_F_S_A_II {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(0 == n)
		{
			return 0;
		}
		int dup_cnt = 2;
		int start = 0;
		int end = start+1;

		for(;end<n;++end)
		{
			if(A[end-1] != A[end])
			{
				start +=1;
				A[start] = A[end];
				dup_cnt = 2;
			}
			else if(A[end-1] == A[end]&& --dup_cnt>0)
			{
				start +=1;
				A[start] = A[end];
			}
		}

		return start+1;
    }
};