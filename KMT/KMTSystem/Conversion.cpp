#include "Header.h"

int value(char c)
{
	// 0 - 9
	// 48 - 57
	if ('0' <= c && c <= '9')
		return int(c - '0');

	// 97 - 122 (Lower case)
	if ('a' <= c && c <= 'z')
		c -= 32;

	return int(c - 'A') + 10;
}

string ConvertToHex(int value)
{
	bool isNegative = (value < 0);

	// convert abs(value) first
	if (isNegative)
		value *= -1;

	string output;

	while (value > 0)
	{
		char digit = value % 16;
		// 0-9
		if (digit < 10)
			digit += '0';
		// A-Z
		else
			digit = digit + 'A' - 10;
		// Append digit to string (in reverse order)
		output += digit;
		value /= 16;
	}
	if (isNegative)
		output += '-';
	reverse(output.begin(), output.end());

	if (output.length() == 1)
		output = "0" + output;

	return output;
}

string HexToBin(char c)
{
	switch (c)
	{
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	}
	return "ERROR";
}

