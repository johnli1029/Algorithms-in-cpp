/* ����ճ���ļ�ʱ�������ڹ����ڴ������Ϊ�ļ�·�� 
 * 2017��10��7�� 
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
