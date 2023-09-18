#include "rle.h"
#include <iostream>
#include <string>

std::string RLE::Compresser(const std::string& data)
{
	std::string output;
	int count = 1;

	for (int i = 1; i <= data.length(); ++i)
	{
		if (i == data.length() || data[i] != data[i - 1])
		{
			while (count > 0)
			{
				char avant = data[i - 1];
				int max = std::min(count, 255);
				output += (char)max;
				output += avant;
				count -= max;
			}
			count = 1;
		}
		else {
			count++;
		}
	}

	return output;
}

std::string RLE::Decompresser(const std::string& data)
{
	std::string resultat;

	for (int i = 0; i < data.length(); i += 2)
	{
		int count = unsigned char(data[i]);
		char c = data[i + 1];

		for (int j = 0; j < count; j++)
		{
			resultat += c;
		}
	}

	return resultat;
}
