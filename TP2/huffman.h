#ifndef HUFFMAN_H__
#define HUFFMAN_H__
#include <string>
#include <queue>
#include <map>

class Huffman
{
public:
	// Accepte des donnees non-compressees en parametre et retourne les donnees compressees
	std::string Compresser(const std::string& data);

	// Accepte des donnees compressees en parametre et retourne les donnees decompressees
	std::string Decompresser(const std::string& data);

private:
	struct Noeud
	{
		char c;
		int freq;
		Noeud* gauche;
		Noeud* droite;

		Noeud(char c, int freq, Noeud* gauche, Noeud* droite) : c(c), freq(freq), gauche(gauche), droite(droite) {}
	};

	struct  Comparateur
	{
		bool operator()(const Noeud* gauche, const Noeud* droite) const
		{
			return gauche->freq > droite->freq;
		}
	};

	typedef std::map<char, std::string> Dictionnaire;

	void GenererDictionnaire(Noeud* n, std::string code, Dictionnaire& dictionnaire);

	int m_bitCount = 0;
	Noeud* m_racine;
};

#endif 
