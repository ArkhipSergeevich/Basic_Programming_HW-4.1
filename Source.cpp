#include <iostream>
#include <string>
#include <fstream>

class addresses
{
public:
	std::string get_city()
	{
		return city;
	}
	std::string get_street()
	{
		return street;
	}
	int get_num_home()
	{
		return num_home;
	}
	int get_num_flat()
	{
		return num_flat;
	}
	addresses()
	{ }
private:
	std::string city, street;
	int num_home, num_flat, size;
};
int open_file()
{
	int size;
	std::ifstream in_file;
	std::ofstream out_file;
	in_file.open("in.txt");
	if (in_file.is_open())
	{
		in_file >> size;
		out_file.open("out.txt"); // I use the "usual" opening to delete all the data from the file
		//out_file.close();
		//out_file.open("out.txt", std::ios_base::app);  // I open the file again this way to be able write down addresses one at a time
		if (out_file.is_open())
		{
			out_file << "Number of addresses: " << size << std::endl;
		}
		else
		{
			std::cout << "file (out_file) is not open\n";
		}
	}
	else
	{
		std::cout << "file (in_file) is not open\n";
	}
	return size;
}
//void get_address()
//{
//	std::string address;
//	std::ifstream in_file;
//	int size;
//	in_file.open("in.txt");
//	in_file >> size;
//	std::cout << std::endl;
//	for (int i = 0; i < 4; i++)
//	{
//		in_file >> address;
//		std::cout << address << std::endl;
//	}
//
//}
//void addresses::open_file()
//{
//	in_file.open("in.txt");
//	if (in_file.is_open())
//	{
//		in_file >> size;
//		out_file.open("out.txt", std::ios_base::app);
//		if (out_file.is_open()) {}
//		else
//		{
//			std::cout << "file (out_file) is not open\n";
//		}
//	}
//	else
//	{
//		std::cout << "file (in_file) is not open\n";
//	}
//}
int main()
{
	setlocale(LC_ALL, "Russian");
	std::ifstream in_file;
	std::ofstream out_file;
	in_file.open("in.txt");
	int size, size1=3;
	size=open_file();
	std::cout << size;
	addresses* addresses_array = new addresses[size];
	for (int i = 0; i < size; i++)
	{
		std::string address;
		std::ifstream in_file;
		int size;
		in_file.open("in.txt");
		in_file >> size;
		std::cout << std::endl;
		for (int i = 0; i < 4; i++)
		{
			in_file >> address;
			std::cout << address << std::endl;
			addresses_array.city[i] = address;
		}
		
	}
	delete[] addresses_array;
}