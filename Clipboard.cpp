/* 复制粘贴文件时，储存在公用内存的数据为文件路径 
 * 2017年10月7日 
 * From Zhihu 
 */
 
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
int main()
{
	if (OpenClipboard(nullptr))
	{
		HDROP hdrop = HDROP(GetClipboardData(CF_HDROP));
		if (hdrop)
		{
			UINT count = DragQueryFileA(hdrop,-1,nullptr,0);
			for (UINT i = 0; i < count; ++i)
			{
				vector<char> path(DragQueryFileA(hdrop, i, nullptr, 0)+1);
				DragQueryFileA(hdrop, i, path.data(), path.size());
				cout << path.data() << endl;
			}
		}
		CloseClipboard();
	}
	return 0;
}
