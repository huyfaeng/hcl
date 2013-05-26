#include <vector>
using namespace std;

class Solution_Rotate_Image {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int n = matrix.size();
		if(1 >= n)
		{
			return;
		}
		int half_n = n/2;

		//in place translate
		for(int i = 0; i < half_n;++i)
		{
			int tmp_n = n-2*i-1;
			for(int j=0; j<tmp_n; ++j)
			{
				int x1 = i;
				int y1 = i+j; 

				int x2 = i+j;
				int y2 = i+tmp_n;

				int x3 = i+tmp_n;
				int y3 = tmp_n+i-j;

				int x4 = tmp_n+i-j;
				int y4 = i;

				int tmp_value = matrix[x1][y1];

				matrix[x1][y1] = matrix[x4][y4];
				matrix[x4][y4] = matrix[x3][y3];
				matrix[x3][y3] = matrix[x2][y2];
				matrix[x2][y2] = tmp_value;

			}
		}
    }
};