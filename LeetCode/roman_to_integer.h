
#include<string>
#include<map>
using namespace std;

class Solution_Roman_To_Integer {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(s.empty())
		{
			return 0;
		}

		//I£¨1£©¡¢V£¨5£©¡¢X£¨10£©¡¢L£¨50£©¡¢C£¨100£©¡¢D£¨500£©ºÍM£¨1000£©

		map<char,int> map_roman;
		map_roman.insert(make_pair('I',1));
		map_roman.insert(make_pair('V',5));
		map_roman.insert(make_pair('X',10));
		map_roman.insert(make_pair('L',50));
		map_roman.insert(make_pair('C',100));
		map_roman.insert(make_pair('D',500));
		map_roman.insert(make_pair('M',1000));

		int roman_value = map_roman[*(s.end()-1)];
		for(int i = s.length()-2;i>=0;--i)
		{
			if(map_roman[s.at(i)] >= map_roman[s.at(i+1)])
			{
				roman_value += map_roman[s.at(i)];
			}
			else
			{
				roman_value -= map_roman[s.at(i)];
			}
		}
		return roman_value;
    }
};