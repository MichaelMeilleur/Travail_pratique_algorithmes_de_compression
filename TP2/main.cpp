#include <iostream>
#include <queue>
#include <map>
#include <iomanip>
#include "bitpacker.h"
#include "huffman.h"
#include "rle.h"
#include <string>
#include <fstream>

std::string LoadFile(const std::string& filename)
{
	std::ifstream f(filename.c_str(), std::ios::binary);
	if (!f.is_open())
		return "";
	f.seekg(0, std::ios::end);
	unsigned int len = f.tellg();
	f.seekg(0, std::ios::beg);
	char* tmp = new char[len];
	f.read(tmp, len);
	f.close();
	std::string buffer(tmp, len);
	delete[] tmp;
	return buffer;
}

/// <summary>
/// Méthode pour afficher les résultats 
/// </summary>
/// <param name="filename">Nom du fichier</param>
/// <param name="dataOrg">Data original</param>
/// <param name="dataComp">Data decompresser</param>
void AfficherResultatRle(const std::string& filename, std::string dataOrg, std::string dataDecomp, int i)
{
	std::cout << "Taille originale: " << LoadFile(filename).length() << std::endl;
	if (i == 0)
		std::cout << "Taille finale: " << dataOrg.length() << std::endl;
	if (i == 1)
		std::cout << "Taille finale: " << dataOrg.size() / 8 << std::endl;
	std::cout << "Taille Decompressee: " << dataDecomp.length() << std::endl;
	std::cout << "" << std::endl;
}

int main()
{	
	// TESTS RLE
	std::cout << "           TESTS RLE" << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << "" << std::endl;

	RLE rle;
	std::string dataRle;
	std::string dataDecomp;

	// Test fichier 1
	std::cout << "==== Test : 01.txt ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("01.txt"));
	dataDecomp = rle.Decompresser(rle.Compresser(LoadFile("01.txt")));
	AfficherResultatRle("01.txt", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 2
	std::cout << "==== Test : 02.html ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("02.html"));
	dataDecomp = rle.Decompresser(rle.Compresser(LoadFile("02.html")));
	AfficherResultatRle("02.html", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 3
	std::cout << "==== Test : 03.bmp ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("03.bmp"));
	dataDecomp = rle.Decompresser(rle.Compresser(LoadFile("03.bmp")));
	AfficherResultatRle("03.bmp", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 4
	std::cout << "==== Test : 04.jpg ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("04.jpg"));
	dataDecomp = rle.Decompresser(rle.Compresser(LoadFile("04.jpg")));
	AfficherResultatRle("04.jpg", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 5
	std::cout << "==== Test : 05.exe ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("05.exe"));
	dataDecomp = rle.Decompresser(rle.Compresser(LoadFile("05.exe")));
	AfficherResultatRle("05.exe", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 6
	std::cout << "==== Test : 06.zip ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("06.zip"));
	dataDecomp = rle.Decompresser(dataRle);
	AfficherResultatRle("06.zip", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 7
	std::cout << "==== Test : 07.bin ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("07.bin"));
	dataDecomp = rle.Decompresser(dataRle);
	AfficherResultatRle("07.bin", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 8
	std::cout << "==== Test : 08.bin ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("08.bin"));
	dataDecomp = rle.Decompresser(dataRle);
	AfficherResultatRle("08.bin", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 9
	std::cout << "==== Test : 09.bin ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("09.bin"));
	dataDecomp = rle.Decompresser(dataRle);
	AfficherResultatRle("09.bin", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 10
	std::cout << "==== Test : 10.bin ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("10.bin"));
	dataDecomp = rle.Decompresser(dataRle);
	AfficherResultatRle("10.bin", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 11
	std::cout << "==== Test : 11.bin ====" << std::endl;
	dataRle = rle.Compresser(LoadFile("11.bin"));
	dataDecomp = rle.Decompresser(dataRle);
	AfficherResultatRle("11.bin", dataRle, dataDecomp, 0);
	if (dataRle == rle.Decompresser(rle.Compresser(dataRle)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// TESTS HUFFMAN
	std::cout << "         TESTS HUFFMAN" << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << "" << std::endl;

	Huffman huffman;
	std::string data;
	std::string data2;

	//// Test fichier 1
	std::cout << "==== Test : 01.txt ====" << std::endl;
	data = huffman.Compresser(LoadFile("01.txt"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("01.txt")));
	AfficherResultatRle("01.txt", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 2
	std::cout << "==== Test : 02.html ====" << std::endl;
	data = huffman.Compresser(LoadFile("02.html"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("02.html")));
	AfficherResultatRle("02.html", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 3
	std::cout << "==== Test : 03.bmp ====" << std::endl;
	data = huffman.Compresser(LoadFile("03.bmp"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("03.bmp")));
	AfficherResultatRle("03.bmp", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 4
	std::cout << "==== Test : 04.jpg ====" << std::endl;
	data = huffman.Compresser(LoadFile("04.jpg"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("04.jpg")));
	AfficherResultatRle("04.jpg", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 5
	std::cout << "==== Test : 05.exe ====" << std::endl;
	data = huffman.Compresser(LoadFile("05.exe"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("05.exe")));
	AfficherResultatRle("05.exe", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 6
	std::cout << "==== Test : 06.zip ====" << std::endl;
	data = huffman.Compresser(LoadFile("06.zip"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("06.zip")));
	AfficherResultatRle("06.zip", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 7
	std::cout << "==== Test : 07.bin ====" << std::endl;
	data = huffman.Compresser(LoadFile("07.bin"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("03.bmp")));
	AfficherResultatRle("07.bin", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 8
	std::cout << "==== Test : 08.bin ====" << std::endl;
	data = huffman.Compresser(LoadFile("08.bin"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("08.bin")));
	AfficherResultatRle("08.bin", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 9
	std::cout << "==== Test : 09.bin ====" << std::endl;
	data = huffman.Compresser(LoadFile("09.bin"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("09.bin")));
	AfficherResultatRle("09.bin", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 10
	std::cout << "==== Test : 10.bin ====" << std::endl;
	data = huffman.Compresser(LoadFile("10.bin"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("10.bin")));
	AfficherResultatRle("10.bin", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	// Test fichier 11
	std::cout << "==== Test : 11.bin ====" << std::endl;
	data = huffman.Compresser(LoadFile("11.bin"));
	data2 = huffman.Decompresser(huffman.Compresser(LoadFile("11.bin")));
	AfficherResultatRle("11.bin", data, data2, 1);
	if (data == huffman.Decompresser(huffman.Compresser(data)))
		std::cout << "Succes" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	std::cout << "==== Fin des tests ====" << std::endl;
}