
class Solution_Remove_Element {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		for(int i=0;i<n;++i)
		{
			if(A[i] == elem)
			{
				while(n>i && elem == A[--n]);
				A[i] = A[n];
			}
		}
		return n;
    }
};