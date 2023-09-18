#ifndef BITPACKER_H
#define BITPACKER_H

#include <string>
#include <vector>
#include <cstdint>

class BitPacker
{
public:
    BitPacker() : m_currentByte(0), m_currentBitCount(0) {}

    BitPacker& operator<<(const std::string& binary)
    {
        for (size_t i = 0; i < binary.length(); ++i)
        {
            m_currentByte <<= 1;
            m_currentByte |= (binary[i] == '1' ? 1 : 0);
            ++m_currentBitCount;

            if (m_currentBitCount == 8)
            {
                m_data.push_back(m_currentByte);
                m_currentByte = 0;
                m_currentBitCount = 0;
            }
        }
        return *this;
    }

    int Size() const
    {
        return m_data.size() * 8 + m_currentBitCount;
    }

    std::vector<uint8_t> Get() const
    {
        if (m_currentBitCount == 0)
            return m_data;

        std::vector<uint8_t> result(m_data);
        result.push_back(m_currentByte << (8 - m_currentBitCount));
        return result;
    }

private:
    std::vector<uint8_t> m_data;
    uint8_t m_currentByte;
    int m_currentBitCount;
};

#endif /* BITPACKER_H */

