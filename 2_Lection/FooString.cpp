#include <iostream>
#include <cstring>

// Вариант 4 – перевыделить память и добавить строку str в конец

class FooString
{
private:
	char* buf;
public:
	FooString(const char* tbuf);
	~FooString();
	void show();
	void add(FooString str);
	bool TestAdd();
	void runTest(const std::string & testName);
};

FooString::FooString(const char* tbuf)
{
	int size = strlen(tbuf)+1;
	buf = new char[size];
	strcpy_s(buf, size, tbuf);
}

FooString::~FooString()
{
	//delete[] buf;
}

void FooString::show()
{
	std::cout << buf;
}

void FooString::add(FooString str)
{
	int size = strlen(buf) + strlen(str.buf)+1;
	strcat_s(buf, size, str.buf);
}

bool FooString::TestAdd()  //Тестирует фунцию add(FooString str) на перевыделение памяти
{
	FooString str1("gg");
	FooString str2(" wp");
	std::cout << "The size of two strings: " << strlen(str1.buf) << " and " << strlen(str2.buf) << std::endl; //должно вывести 2 и 3
	str1.add(" wp");
	std::cout << "The size of the combined strings: " << strlen(str1.buf) << std::endl; //должно вывести 5
	if (strlen(str1.buf) == 5)
		return true;
	else
		return false;
}

void FooString::runTest(const std::string& testName)
{
	if (FooString::TestAdd() == true)
		std::cout << "Test " << testName << " - OK" << std::endl;
	else
		std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main()
{
	FooString testFunction("Test");
	testFunction.runTest("TestAdd");
	return 0;
}
