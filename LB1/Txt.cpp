#include "Txt.h"
namespace l1
{
	Txt::Txt()
	{
		pstr = nullptr;
		count_write = 0;
	}

	Txt::Txt(const char *pathfile) :Txt()
	{
		std::ifstream file_read;
		file_read.open(pathfile);

		if (file_read.is_open())
		{
			while (file_read.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'))
				count_write++;

			file_read.clear();
			file_read.seekg(0, std::ios::beg);
			pstr = new std::string[count_write];

			int i = 0;

			while (!file_read.eof())
			{
				getline(file_read, pstr[i]);
				++i;
			}
			file_read.close();
		}
		else
		{
			std::cout << "Unable to open file" << std::endl;
			file_read.close();
		}
	}

	Txt::Txt(const Txt &obj)
	{
		this->count_write = obj.count_write;
		this->pstr = new std::string[obj.count_write];
		for (size_t i = 0; i < obj.count_write; i++)
		{
			this->pstr[i] = obj.pstr[i];
		}
	}
	Txt::Txt(Txt &&obj)
	{
		this->count_write = obj.count_write;
		if (this->pstr != nullptr)
			delete[] this->pstr;

		this->pstr = obj.pstr;
		obj.count_write = 0;
		obj.pstr = nullptr;
	}

	size_t Txt::size() const
	{
		return count_write;
	}

	Txt & Txt::operator=(const Txt &obj)
	{
		this->count_write = obj.count_write;
		if (pstr != nullptr)
			delete[] this->pstr;

		this->pstr = new std::string[obj.count_write];

		for (size_t i = 0; i < obj.count_write; i++)
		{
			this->pstr[i] = obj.pstr[i];
		}
		return *this;
	}

	Txt & Txt::operator=(Txt &&obj)
	{

		this->count_write = obj.count_write;
		if (this->pstr != nullptr)
			delete[] this->pstr;

		this->pstr = obj.pstr;

		obj.count_write = 0;
		obj.pstr = nullptr;

		return *this;
	}
	Txt::~Txt()
	{
		if (pstr != nullptr)
			delete[] pstr;
	}
}


