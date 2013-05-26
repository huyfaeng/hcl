
class Solution_Reverse_Integer {
public:
	int reverse(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int rst = 0; 
		//bool negtive = x<0;

		while(x)
		{
			int tmp = x%10;
			x /= 10;
			rst *=10;
			rst += tmp;
		}
        
		return rst;
		//return negtive?-rst:rst;
        
	}
};