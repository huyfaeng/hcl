

class Solution_Palindrome_Num {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		unsigned int value = x;
		if(value < 10)
		{
			return true;
		}

		unsigned int multi = 1;
		while(value/multi >9)
		{
			multi *= 10;
		}
	//	multi /=10;

		int left_value = 0;
		int right_value = 0;

		do
		{
			right_value = value%10;
			left_value = value/multi;

			if(right_value != left_value)
			{
				return false;
			}

			value %= multi;
			value /= 10;
			multi /= 100;
		}while(value > 9);

		return true;
    }
};