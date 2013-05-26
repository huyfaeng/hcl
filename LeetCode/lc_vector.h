
#include<vector>
#include<cstdarg>
using namespace std;

vector<vector<int> > init_vector(int n, ...)
{
	va_list vl;
	va_start(vl,n);

	vector<vector<int> > vec_2d;

	int width = (int)sqrt(n);

	if(width*width != n)
	{
		return vector< vector<int> >();
	}

	for(int i=0;i<width;++i)
	{
		vector<int> vec_tmp;
		vec_tmp.clear();

		for(int j=0;j<width;++j)
		{
			vec_tmp.push_back(va_arg(vl,int));
		}

		vec_2d.push_back(vec_tmp);
	}
	
	va_end(vl);

	return vec_2d;
}