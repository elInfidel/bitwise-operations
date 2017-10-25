// ---------------------------------------------------------------------------
// Binary.cpp
// An object to represent a binary value.
//
// Original author: <Liam>
// Date created: 07/10/2014
// ---------------------------------------------------------------------------
#include "Binary.h"
#include <algorithm>
#include <math.h>

Binary::Binary()
{
	for(int i = 0; i < (BITS * BYTES); ++i)
	{
		binary[i] = 0;
	}

	count = (BITS * BYTES);
}

Binary::~Binary()
{
}

Binary::Binary(string binaryInput)
{
	count = binaryInput.length();

	binaryInput = Pad(binaryInput);

	for(int i = 0; i < (BITS * BYTES); ++i)
	{
		//Removing 48 to convert from ascii values to 0 | 1
		binary[i] = (binaryInput[i] - 48);
	}
}

//////////////////////////////
//
// A function which will set the individual bits of the binary value
// with the values in binaryInput.
//
//////////////////////////////
void Binary::Set(string binaryInput)
{
	count = binaryInput.length();

	binaryInput = Pad(binaryInput);

	for(int i = 0; i < (BITS * BYTES); ++i)
	{
		//Removing 48 to convert from ascii values to 0 | 1
		binary[i] = (binaryInput[i] - 48);
	}

}

//////////////////////////////
//
// Converts a binary object into a string for return
// to the console.
//
//////////////////////////////
string Binary::ToString()
{
	string binaryNumber;

	for(int i = 0; i < (BITS * BYTES); ++i)
	{
		binaryNumber.append(to_string(binary[i]));
	}
	return Space(binaryNumber);
}


//////////////////////////////
//
// An operator overload where the sum of two binary inputs
// is found.
//
//////////////////////////////
string Binary::operator+(Binary &other)
{
	int carry = 0;
	string sum;

	if(Program::signedMode)
	{
		//Obtaining 2's complement of value
		for(int i = 0; i < (BITS * BYTES); ++i)
		{
			if(other.binary[i] == 1)
				other.binary[i] = 0;
			else
				other.binary[i] = 1;
		}

		//Adding 1
		for(int i = (BITS * BYTES - 1); i > 0; --i)
		{
			if(other.binary[i] == 0)
			{
				other.binary[i] = 1;
				break;
			}
		}

		//Adding two's comp right hand to left hand value
		for(int i = (BITS * BYTES - 1); i > 0; --i)
		{
			sum.append(to_string((binary[i] ^ other.binary[i]) ^ carry));
			carry = ((binary[i] & other.binary[i]) | (binary[i] & carry)) | (other.binary[i] & carry);
		}
		reverse(sum.begin(), sum.end());

		return Space(Pad(sum));
	}
	else
	{
		for(int i = (BITS * BYTES - 1); i > 0; --i)
		{
			sum.append(to_string((binary[i] ^ other.binary[i]) ^ carry));
			carry = ((binary[i] & other.binary[i]) | (binary[i] & carry)) | (other.binary[i] & carry);
		}
	}
	reverse(sum.begin(), sum.end());

	return Space(Pad(sum));
}

//////////////////////////////
//
// An operator overload where the result of two binary inputs
// is found.
//
//////////////////////////////
string Binary::operator-(Binary &other)
{
	int carry = 0;
	int borrow = 0;
	string difference;
	string sum;

	if(Program::signedMode)
	{
		//Obtaining 2's complement of value
		for(int i = 0; i < (BITS * BYTES); ++i)
		{
			if(other.binary[i] == 1)
				other.binary[i] = 0;
			else
				other.binary[i] = 1;
		}

		//Adding 1
		for(int i = (BITS * BYTES - 1); i > 0; --i)
		{
			if(other.binary[i] == 0)
			{
				other.binary[i] = 1;
				break;
			}
		}

		//Adding two's comp right hand to left hand value
		for(int i = (BITS * BYTES - 1); i > 0; --i)
		{
			sum.append(to_string((binary[i] ^ other.binary[i]) ^ carry));
			carry = ((binary[i] & other.binary[i]) | (binary[i] & carry)) | (other.binary[i] & carry);
		}
		sum.erase(count, 1);
		reverse(sum.begin(), sum.end());

		return Space(Pad(sum));
	}
	else
	{
		for(int i = (BITS * BYTES - 1); i > 0; --i)
		{
			if(binary[i] == 0 && other.binary[i] == 1)
			{
				borrow++;
				difference.append("1");
			}
			else
			{
				if(borrow == 1)
				{
					borrow--;
					difference.append(to_string(borrow ^ other.binary[i]));
				}
				else
				{
					difference.append(to_string(binary[i] ^ other.binary[i]));
				}
			}
		}
	}
	reverse(difference.begin(), difference.end());

	return Space(Pad(difference));
}

//////////////////////////////
//
// An operator overload where the AND
// operation is done on each bit in the binary input.
//
//////////////////////////////
string Binary::operator&(const Binary &other)
{
	string result;

	for(int i = 0; i < (BITS * BYTES); ++i)
	{
		result.append(to_string(binary[i] & other.binary[i]));
	}

	return Space(Pad(result));
}

//////////////////////////////
//
// An operator overload where the OR
// operation is done on each bit in the binary input.
//
//////////////////////////////
string Binary::operator|(const Binary &other)
{
	string result;

	for(int i = 0; i < (BITS * BYTES); ++i)
	{
		result.append(to_string(binary[i] | other.binary[i]));
	}

	return Space(Pad(result));
}

//////////////////////////////
//
// An operator overload where the XOR
// operation is done on each bit in the binary input.
//
//////////////////////////////
string Binary::operator^(const Binary &other)
{
	string result;

	for(int i =0; i < (BITS * BYTES); ++i)
	{
		result.append(to_string(binary[i] ^ other.binary[i]));
	}

	return Space(Pad(result));
}

//////////////////////////////
//
// An operator overload where all bits in the binary input are inverted,
// an equivalent of the NOT operation.
//
//////////////////////////////
string Binary::operator~()
{
	string result;

	for(int i = 0; i < (BITS * BYTES); ++i)
	{
		if(binary[i] == 1)
			result.append("0");
		else
			result.append("1");
	}

	return Space(Pad(result));
}

//////////////////////////////
//
// An operator overload for right bit shifting,
// the Binary value will be shifted to the right
// 'amount' times.
//
//////////////////////////////
string Binary::operator<<(int amount)
{
	string result;

	for(int i = 0; i < amount; ++i)
	{
		result.append("0");
	}

	for(int i = (BITS * BYTES - 1); i >= amount; --i)
	{
		result.append(to_string(binary[i]));
	}
	reverse(result.begin(), result.end());

	return Space(Pad(result));
}

//////////////////////////////
//
// An operator overload for left bit shifting,
// the Binary value will be shifted to the left
// 'amount' times.
//
//////////////////////////////
string Binary::operator>>(int amount)
{
	string result;

	for(int i = 0; i < amount; ++i)
	{
		result.insert(0, "0");
	}

	for(int i = 0; i < (BITS * BYTES) - amount; ++i)
	{
		result.insert(result.length(), to_string(binary[i]));
	}

	return Space(Pad(result));
}

//////////////////////////////
//
// Converts a binary input into its decimal representation using
// the positional notation method for positive/unsigned values and two's complement
// for negative values.
//
//////////////////////////////
string Binary::ToDecimal(string binaryInput)
{
	int decimal = 0;
	int posNotation = 1;

	if(Program::signedMode)
	{
		//Checking if the sign bit is set meaning the value is negative
		if(binaryInput[0] == '1')
		{
			//Obtaining 2's complement of value
			for(int i = 0; i < binaryInput.length(); ++i)
			{
				if(binaryInput[i] == '1')
					binaryInput[i] = '0';
				else
					binaryInput[i] = '1';
			}

			//Adding 1
			for(int i = binaryInput.length(); i > 0; --i)
			{
				if(binaryInput[i] == '0')
				{
					binaryInput[i] = '1';
					break;
				}
			}

			reverse(binaryInput.begin(), binaryInput.end());

			//Positional notation method
			for(size_t i = 0; i < binaryInput.length() - 1; ++i)
			{
				if(binaryInput[i] == 49)
				{
					decimal += posNotation;
				}
				posNotation *= 2;
			}

			//Adding negative sign and returning.
			string result = "-" + to_string(decimal);
			return result;

		}
		else // SIGN BIT == 0
		{
			reverse(binaryInput.begin(), binaryInput.end());

			//Positional notation method
			for(size_t i = 0; i < binaryInput.length(); ++i)
			{
				if(binaryInput[i] == 49)
				{
					decimal += posNotation;
				}
				posNotation *= 2;
			}
		}
	}
	else // UNSIGNED MODE
	{
		reverse(binaryInput.begin(), binaryInput.end());

		//Positional notation method
		for(size_t i = 0; i < binaryInput.length(); ++i)
		{
			if(binaryInput[i] == 49)
			{
				decimal += posNotation;
			}
			posNotation *= 2;
		}
	}

	return to_string(decimal);
}


//////////////////////////////
//
// Converts a decimal input string into an intger and uses the
// divide by two method to convert it to a binary value.
// If the value is negative, it's made absolute and the above process is taken on it,
// after that is complete the function will return the two's complement.
//
//////////////////////////////
string Binary::ToBinary(string decimalInput)
{
	int num = stoi(decimalInput);
	int remainder = 0;
	string binary;

	if(Program::signedMode)
	{
		if(num >= 0)
		{
			while(num > 0)
			{
				//Divide by 2 method
				remainder = num % 2;
				num /= 2;
				binary.append(to_string(remainder));
			}
			std::reverse(binary.begin(), binary.end());
		}
		else
		{
			//Taking absolute value of input
			num = abs(num);

			//Converting value to binary using divide by two method
			while(num > 0)
			{
				//Divide by 2 method
				remainder = num % 2;
				num /= 2;
				binary.append(to_string(remainder));
			}
			std::reverse(binary.begin(), binary.end());
			binary = Pad(binary);

			//Obtaining 2's complement of value
			for(int i = 0; i < binary.length(); ++i)
			{
				if(binary[i] == '1')
					binary[i] = '0';
				else
					binary[i] = '1';
			}

			//Adding 1
			for(int i = (BITS * BYTES - 1); i > 0; --i)
			{
				if(binary[i] == '0')
				{
					binary[i] = '1';
					break;
				}
			}
		}
	}
	else // UNSIGNED MODE
	{
		while(num > 0)
		{
			//Divide by 2 method
			remainder = num % 2;
			num /= 2;
			binary.append(to_string(remainder));
		}
		std::reverse(binary.begin(), binary.end());
	}

	return Space(Pad(binary));
}

//////////////////////////////
//
// Pad adds '0' bits to the binary string until its length
// is equal to (BITS * BYTES). These constants can be found in the Binary.h file.
//
//////////////////////////////
string Binary::Pad(string binaryInput)
{
	//Padding out binary value with 0
	while(binaryInput.length() < (BITS * BYTES))
	{
		binaryInput.insert(binaryInput.begin(), '0');
	}

	return binaryInput;
}


//////////////////////////////
//
// Space adds spacing to a binary string at each 4 bits for improved readability,
// it should only be used on strings that are ready to be parsed back to the console for display.
//
//////////////////////////////
string Binary::Space(string binaryInput)
{
	int place = 0;

	//Placing a space at each 4 bit chunk for easier reading
	for(size_t i = 0; i < binaryInput.length(); ++i)
	{
		if(place == 4)
	    {
			binaryInput.insert(i, " ");
			place = 0;
		}
		else
		{
			place++;
		}
	}

	return binaryInput;
}
