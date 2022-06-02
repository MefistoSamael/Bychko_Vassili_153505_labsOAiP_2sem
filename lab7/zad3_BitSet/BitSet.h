#ifndef BITSET_H
#define BITSET_H

#include <string.h>
#include <cstdint>
#include <string>

template<size_t s>
class BitSet
{
    class bit_rfr
    {
        uint8_t* byte;

        uint8_t ind;

    public:

        bit_rfr(uint8_t* byte, uint8_t ind) :
            byte(byte),
            ind(ind) {}

        bit_rfr(bit_rfr& other) :
            byte(other.byte),
            ind(other.ind) {}

        bit_rfr& operator=(bool b) noexcept
        {
            if (bool(*byte & (1 << ind)) != b)
                flip();

            return *this;
        }

        bit_rfr& operator=(bit_rfr& other) noexcept
        {
            if (bool(*byte & (1 << ind)) != bool(other))  // not equal bits
                flip();

            return *this;
        }

        bit_rfr& flip()
        {
            *byte ^= 1 << ind;

            return *this;
        }

        bool operator~() const
        {
            return ~(*byte) & (1 << ind);
        }

        operator bool()
        {
            return bool(*byte & (1 << ind));
        }

        ~bit_rfr() {}
    };

    const size_t bit_size;

    const size_t arr_size;
    uint8_t* arr;

public:

    BitSet(uint64_t num = 0)
        :
        bit_size(s),
        arr_size(s + 7 >> 3),
        arr((uint8_t*)calloc(arr_size, 1)) {

        if (!num) return;
        size_t length = (8 < arr_size) ? 8 : arr_size;
        memcpy(arr, &num, length);
    }

    BitSet(const BitSet<s>& other)
        :
        bit_size(other.bit_size),
        arr_size(other.arr_size),
        arr((uint8_t*)calloc(arr_size, 1)) {

        memcpy(this->arr, other.arr, arr_size);
    }

    bool all()
    {
        uint8_t* full_1 = (uint8_t*)calloc(arr_size, 1);

        memset(full_1, 255, arr_size - 1);

        for (uint8_t i = 0; i < bit_size % 8; i++)
            full_1[arr_size - 1] ^= (1 << i);

        bool ans = memcmp(full_1, arr, arr_size);
        free(full_1);

        return !ans;
    }

    bool any()
    {
        uint8_t* full_0 = (uint8_t*)calloc(arr_size, 1);

        bool ans = memcmp(full_0, arr, arr_size);
        free(full_0);

        return ans;
    }

    bool none()
    {
        return !any();
    }


    size_t size()
    {
        return bit_size;
    }

    size_t byteSize()
    {
        return arr_size;
    }

    size_t byte2size()
    {
        return arr_size/2;
    }

    uint16_t* arrByte2() const
    {
        return (uint16_t*)arr;
    }

    uint8_t* bit_list() const
    {
        return arr;
    }


    BitSet& flip()
    {
        for (size_t i = 0; i < arr_size - 1; i++)
            arr[i] = ~arr[i];

        for (uint8_t i = 0; i < bit_size % 8; i++)
            arr[arr_size - 1] ^= (1 << i);

        return *this;
    }

    BitSet& flip(size_t ind)
    {
        arr[ind >> 3] ^= 1 << ind % 8;

        return *this;
    }

    BitSet operator~()
    {
        BitSet<s> tmp(*this);

        return tmp.flip();
    }


    BitSet& reset()
    {
        free(arr);
        arr = (uint8_t*)calloc(arr_size, 1);

        return *this;
    }

    BitSet& reset(size_t ind)
    {
        arr[ind >> 3] &= ~(1 << ind % 8);

        return *this;
    }


    BitSet& set()
    {
        free(arr);
        arr = (uint8_t*)calloc(arr_size, 1);

        memset(arr, 255, arr_size - 1);

        for (uint8_t i = 0; i < bit_size % 8; i++)
            arr[arr_size - 1] ^= (1 << i);

        return *this;
    }

    BitSet& set(size_t ind)
    {
        arr[ind >> 3] |= (1 << ind % 8);

        return *this;
    }


    std::string to_string()
    {
        std::string ans;

        for (size_t i = 0; i < bit_size; i++)
            ans += 48 + test(i);

        return ans;
    }

    uint64_t to_ullong()
    {
        uint64_t ans = 0;
        size_t length = (8 < arr_size) ? 8 : arr_size;

        memcpy(&ans, arr, length);

        return ans;
    }

    uint32_t to_ulong()
    {
        uint32_t ans = 0;
        size_t length = (4 < arr_size) ? 4 : arr_size;

        memcpy(&ans, arr, length);

        return ans;
    }


    bit_rfr operator[](size_t ind)
    {
        bit_rfr rfr(arr + (ind >> 3), ind % 8);
        return  rfr;
    }

    bool operator[](size_t ind) const
    {
        return test(ind);
    }

    bool test(size_t ind) const
    {
        return arr[ind >> 3] & (1 << ind % 8);
    }

    size_t count()
        {
            size_t ans = 0;
            for(int i = 0; i< bit_size; i++)
                if (test(i)) ans++;

            return ans;
        }

    ~BitSet()
    {
        free(arr);
    }

    BitSet<s> operator=(uint64_t digit)
    {
        if (!digit)
        {
            this->reset();
        }
        else
        {
            free(arr);
            arr = (uint8_t*)calloc(arr_size, 1);
            size_t length = (8 < arr_size) ? 8 : arr_size;
            memcpy(arr, &digit, length);
        }
        return *this;
    }
};

template<size_t s>
BitSet<s> operator&(const BitSet<s>& first, const BitSet<s>& second)
{
    BitSet<s> tmp;

    for (size_t i = 0; i < tmp.byteSize(); i++)
        tmp.bit_list()[i] = first.bit_list()[i] & second.bit_list()[i];

    for (uint8_t i = 7; i >= tmp.size() % 8; i--)
        tmp.bit_list()[tmp.byteSize() - 1] &= ~(1 << i);

//    for(size_t i = 0; i < tmp.byte2size(); i++)
//    {
//        tmp.arrByte2()[i] = first.arrByte2()[i] & second.arrByte2()[i];
//    }

//    for(size_t i = 0; i < tmp.size() % 16; i++)
//    {
//        tmp.arrByte2()[tmp.byte2size()] ^= (first.arrByte2()[tmp.byte2size()] & 1<<i) & (second.arrByte2()[tmp.byte2size()] & 1<<i);

//    }

    return tmp;
}

template<size_t s>
BitSet<s> operator|(const BitSet<s>& first, const BitSet<s>& second)
{
    BitSet<s> tmp;

    for (size_t i = 0; i < tmp.byteSize(); i++)
        tmp.bit_list()[i] = first.bit_list()[i] | second.bit_list()[i];

    for (uint8_t i = 7; i >= tmp.size() % 8; i--)
        tmp.bit_list()[tmp.byteSize() - 1] &= ~(1 << i);

//    for(size_t i = 0; i < tmp.byte2size(); i++)
//    {
//        tmp.arrByte2()[i] = first.arrByte2()[i] | second.arrByte2()[i];
//    }

//    for(size_t i = 0; i < tmp.size() % 16; i++)
//    {
//        tmp.arrByte2()[tmp.byte2size()] ^= (first.arrByte2()[tmp.byte2size()] & (1<<i)) | (second.arrByte2()[tmp.byte2size()] & (1<<i));
//    }

    return tmp;
}

template<size_t s>
BitSet<s> operator^(const BitSet<s>& first, const BitSet<s>& second)
{
    BitSet<s> tmp;

    for (size_t i = 0; i < tmp.byteSize(); i++)
        tmp.bit_list()[i] = first.bit_list()[i] ^ second.bit_list()[i];

    for (uint8_t i = 7; i >= tmp.size() % 8; i--)
        tmp.bit_list()[tmp.byteSize() - 1] &= ~(1 << i);

//    for(size_t i = 0; i < tmp.byte2size(); i++)
//    {
//        tmp.arrByte2()[i] = first.arrByte2()[i] ^ second.arrByte2()[i];
//    }

//    for(size_t i = 0; i < tmp.size() % 16; i++)
//    {
//        tmp.arrByte2()[tmp.byte2size()] |= (first.arrByte2()[tmp.byte2size()] & 1<<i) ^ (second.arrByte2()[tmp.byte2size()] & 1<<i);
//    }

    return tmp;
}

#endif // BITSET_H
