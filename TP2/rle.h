#ifndef RLE_H__
#define RLE_H__
#include <string>

class RLE
{
public:
	// Accepte des donnees non-compressees en parametre et retourne les donnees compressees
	std::string Compresser(const std::string& data);

	// Accepte des donnees compressees en parametre et retourne les donnees decompressees
	std::string Decompresser(const std::string& data);

private:
};

#endif 

