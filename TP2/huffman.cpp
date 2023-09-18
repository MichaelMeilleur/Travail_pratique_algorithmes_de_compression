#include "huffman.h"
#include "bitpacker.h"
#include <iostream>
#include <queue>
#include <map>
#include <fstream>
#include <bitset>
#include <unordered_map>

std::string Huffman::Compresser(const std::string& data)
{
	std::string s = data;

	// Calculer les frequences
	int freq[256] = { 0 };
	for (int i = 0; i < s.length(); i++)
		freq[(unsigned char)s[i]]++;

	// Creer les noeuds et les trier en ordre croissant de frequence
	std::priority_queue<Noeud*, std::vector<Noeud*>, Comparateur> m_q;
	for (int i = 0; i < 256; i++)
	{
		if (freq[i] != 0)
			m_q.push(new Noeud((char)i, freq[i], nullptr, nullptr));
	}

	// Construire l'arbre de huffman
	while (m_q.size() != 1)
	{
		Noeud* gauche = m_q.top();
		m_q.pop();
		Noeud* droite = m_q.top();
		m_q.pop();

		m_q.push(new Noeud(0, gauche->freq + droite->freq, gauche, droite));
	}

	m_racine = m_q.top();

	Dictionnaire dictionnaire;
	GenererDictionnaire(m_racine, "", dictionnaire);

	// Compresser
	BitPacker bp;
	std::string output = "";
	for (char c : s)
	{
		bp << dictionnaire[c];
	}

	// Mettre le contenue du BitPacker bp en string et retourner cette string
	std::vector<uint8_t> datacmp = bp.Get();

	for (uint8_t byte : datacmp)
	{
		output += std::bitset<8>(byte).to_string();
	}

	return output;
}

std::string Huffman::Decompresser(const std::string& data)
{
	std::string s = data;
	std::string output = "";
	Noeud* n = m_racine;

	for (int i = 0; i < s.size(); i++)
	{
		if (n)
		{
			if (s[i] == '0')
				n = n->gauche;
			else
				n = n->droite;
		}

		if (n)
		{
			if (n->gauche == nullptr && n->droite == nullptr)
			{
				output += n->c;
				n = m_racine;
			}
		}
	}

	return output;
}

void Huffman::GenererDictionnaire(Noeud* n, std::string code, Dictionnaire& dictionnaire)
{
	if (!n)
		return;

	// Descendre recursivement dans l'arbre de huffman
	GenererDictionnaire(n->gauche, code + "0", dictionnaire);
	GenererDictionnaire(n->droite, code + "1", dictionnaire);

	// Si c'est un noeud feuille, ajouter dans le dictionnaire
	if (!n->gauche && !n->droite)
	{
		if (code == "")
			code = "0";

		dictionnaire[n->c] = code;
	}
}
