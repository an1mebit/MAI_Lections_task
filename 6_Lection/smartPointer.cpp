#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace money
{
	class Morgenshtern
	{
		const char* word;
		const char* pFile;

	public:
		Morgenshtern(): pFile(0), word(0) {
		}
		Morgenshtern(const char* pFile, const char* word): pFile(pFile), word(word) {
		}
		~Morgenshtern() {
		}

		void TrackList()
		{
			cout << "$TRACKLIST$" << endl;


			ifstream file_out(pFile);

			if (!file_out)
			{
				cout << "Error reading file" << endl;
				exit(-1);
			}

			while (file_out)
			{
				string strInput;
				getline(file_out, strInput);
				cout << strInput << endl;
			}
		}
		void addTrack()
		{
			ofstream file(pFile, ios::app);

			if (!file)
			{
				cout << "Error reading file" << endl;
				exit(-1);
			}

			file << word << endl;
		}
	};
}

namespace money
{
	class rich
	{
		Morgenshtern* pMorgen;

	public:
		rich(Morgenshtern* pVal) : pMorgen(pVal){
		}
		~rich()
		{
			delete pMorgen;
		}

		Morgenshtern& operator*()
		{
			return *pMorgen;
		}

		Morgenshtern* operator->()
		{
			return pMorgen;
		}
	};
}

using namespace money;
void main()
{
	rich p(new Morgenshtern("track.txt", "merin"));
	p->addTrack();
	p->TrackList();
}
