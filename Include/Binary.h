// ---------------------------------------------------------------------------
// Binary.h
// An object to represent a binary value.
//
// Original author: <Liam>
// Date created: 07/10/2014
// ---------------------------------------------------------------------------
#ifndef _BINARY_H_
#define _BINARY_H_
#include "Program.h"
#include <string>

using namespace std;

class Binary
{
public:
	Binary();
	Binary(string binaryInput);

	void Set(string binaryInput);
	string ToString();

	string operator+(Binary &other);
	string operator-(Binary &other);
	string operator&(const Binary &other);
	string operator|(const Binary &other);
	string operator^(const Binary &other);
	string operator<<(int amount);
	string operator>>(int amount);
	string operator~();

	static string ToDecimal(string binaryInput);
	static string ToBinary(string decimalInput);

	~Binary();

	static const int BITS = 8;
	static const int BYTES = 1;

private:
	static string Pad(string binaryInput);
	static string Space(string binaryInput);

	int binary[BITS * BYTES];
	unsigned int count;
};

#endif // _BINARY_H_