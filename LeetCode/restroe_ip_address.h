#include <vector>
#include <string>

using namespace std;

class Solution_Restore_IP_Addr {
public:
	string& itoa(int val,string& str)
	{
		str.clear();
		if(0 == val)
		{
			str.push_back('0');
			return str;
		}
		int v = val;
		while(v)
		{
			int i = v%10;
			v /= 10;
			char c = i+'0';
			str.insert(0,&c,1);
		}
		return str;
	}
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		int len = s.length();
		vector<string> vec_rst;

		if(len <4 || len >12)
		{
			return vector<string>();
		}
		int p1 = 1; 

		for(int i=0;i<3;++i,++p1)
		{ 
			int ip1 = atoi(s.substr(0,p1).c_str());
			if(ip1 >255)
			{
				continue;
			}

			int p2 = p1+1;
			for(int j=0;j<3 &&p2<len;++j,++p2)
			{
				int ip2 = atoi(s.substr(p1,p2-p1).c_str());
				if( ip2 >255)
				{
					continue;
				}

				int p3 = p2+1;
				for(int k=0;k<3 && p3<len;++k,++p3)
				{
					int ip3 = atoi(s.substr(p2,p3-p2).c_str());
					if(ip3 >255)
					{
						continue;
					}

					int ip4 = atoi(s.substr(p3).c_str());
					if(ip4 >255)
					{
						continue;
					}
					//add to vector<string>
					string ctmp;
					string s_valid;
					s_valid.append((itoa(ip1,ctmp)));
					s_valid.push_back('.');
					s_valid.append((itoa(ip2,ctmp)));
					s_valid.push_back('.');
					s_valid.append((itoa(ip3,ctmp)));
					s_valid.push_back('.');
					s_valid.append((itoa(ip4,ctmp)));

					// length must be the same
					if(find(vec_rst.begin(),vec_rst.end(),s_valid) != vec_rst.end()
						|| s_valid.length() != len+3)
						continue;
					vec_rst.push_back(s_valid);

				} 
			} 
		}
		return vec_rst;
    }
};
