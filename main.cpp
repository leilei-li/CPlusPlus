#include <fstream>

using namespace std;

int main()
{
	ifstream ifs("adv_library", ifstream::binary);
	ofstream ofs("adv_library_0", ofstream::binary);
	char key, l1, l2;
	ifs.get(key);
	while (key && ifs.get(l1) && ifs.get(l2))
	{
		l1 ^= key;
		l2 ^= key;
		if (!l1 && !l2)
			break;
		int size = (unsigned char)l1 * 0x100 + (unsigned char)l2;
		char data[0x1000] = { '\0' };
		ifs.read(data, size);
		for (int i = 0; i < size; ++i)
			data[i] ^= key;
		string ss = data;
		ofs << ss.c_str() << endl;
	}
	ifs.close();
	ofs.close();
    return 0;
}
