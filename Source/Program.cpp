// ---------------------------------------------------------------------------
// Program.cpp
// The main program.
//
// Original author: <Liam>
// Date created: 07/10/2014
// ---------------------------------------------------------------------------
#include "Program.h"
#include "Binary.h"
#include <iostream>

using namespace std;

//Initializing program flags
bool Program::signedMode = false;
bool Program::decimalMode = false;

Program::Program()
{
}

Program::~Program()
{
}

void Program::Run()
{
	// Menu input variables
	char menuInput = 0;

	do
	{
		// Main program menu
		cout << endl << endl;
		cout << "|--------------------------------------" << endl;
		cout << "| Bitwise Operator Program             " << endl;
		cout << "| Author: Liam Parker                  " << endl;
		cout << "|                                      " << endl;
		cout << "| Sign Mode: " << (signedMode ? "Signed" : "Unsigned") << endl;
		cout << "| Base Mode: " << (decimalMode ? "10 (Decimal)" : "2 (Binary)") << endl;
		cout << "|                                      " << endl;
		cout << "| A - Switch Sign Mode                 " << endl;
		cout << "| B - Switch Base Mode                 " << endl;
		cout << "|                                      " << endl;
		cout << "| C - Binary/Decimal Conversion        " << endl;
		cout << "| D - Bitwise Operations               " << endl;
		cout << "| E - Addition/Subtraction             " << endl;
		cout << "|                                      " << endl;
		cout << "| X - Exit Program                     " << endl;
		cout << "|                                      " << endl;
		cout << "|--------------------------------------" << endl << endl;

		cout << " Please select an option: ";
		
		cin >> menuInput;

		cout << endl;

		switch(menuInput)
		{
		case 'A':
		case 'a':
			{
				if(signedMode)
					signedMode = false;
				else
					signedMode = true;

				break;
			}
		case 'B':
		case 'b':
			{
				if(decimalMode)
					decimalMode = false;
				else
					decimalMode = true;

				break;
			}
		case 'C':
		case 'c':
			{
				string input;

				(decimalMode ? cout << " Decimal to Binary Mode" : cout << " Binary to Decimal Mode") << endl << endl;

				if(decimalMode)
				{
					cout << " Please input a decimal integer: ";
					cin >> input;
					cout << endl;
					cout << input << " = " << Binary::ToBinary(input);
				}
				else
				{
					do
					{
						cout << " Please input a binary value no larger than " << (Binary::BITS * Binary::BYTES) << " bits: ";
						cin >> input;
						cout << endl;
					}
					while(input.length() > (Binary::BITS * Binary::BYTES));

					cout << input << " = " << Binary::ToDecimal(input);
				}

				break;
			}
		case 'D':
		case 'd':
			{
				//Bitwise Operations Menu
				BitwiseMenu();

				break;
			}
		case 'E':
		case 'e':
			{
				// Basic Mathematics Menu
				BasicMath();

				break;
			}
		case 'X':
		case 'x':
			{
				// Exit case
				break;
			}
		}
	}
	while(menuInput != 'X' && menuInput != 'x');
}

void Program::BitwiseMenu()
{
	char menuInput;
	string binInA, binInB;
	int decA, decB;

	do
	{
		cout << endl << endl;
		cout << "|--------------------------------------" << endl;
		cout << "| Bitwise Operation Submenu            " << endl;
		cout << "|                                      " << endl;
		cout << "| A - AND                              " << endl;
		cout << "| B - OR                               " << endl;
		cout << "| C - NOT                              " << endl;
		cout << "| D - XOR                              " << endl;
		cout << "| E - Left Shift                       " << endl;
		cout << "| F - Right Shift                      " << endl;
		cout << "|                                      " << endl;
		cout << "| X - Main Menu                        " << endl;
		cout << "|                                      " << endl;
		cout << "|--------------------------------------" << endl << endl;

		cout << " Please select an option: ";
		
		cin >> menuInput;

		cout << endl;

		switch(menuInput)
		{
		case 'A':
		case 'a':
			{
				// AND
				if(decimalMode)
				{
					cout << " Please enter the first decimal integer: ";
					cin >> decA;
					cout << endl;
					cout << " Please enter the second decimal integer: ";
					cin >> decB;
					cout << endl;

					cout << " " << decA << " AND " << decB << " = " << (decA & decB);
				}
				else
				{
					cout << " Please enter the first " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInA;
					Binary binA(binInA);
					cout << endl;
					cout << " Please enter the second " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInB;
					Binary binB(binInB);
					cout << endl;

					cout << " " << binA.ToString() << " AND " << binB.ToString() << " = " << (binA & binB);
				}

				break;
			}
		case 'B':
		case 'b':
			{
				// OR
				if(decimalMode)
				{
					cout << " Please enter the first decimal integer: ";
					cin >> decA;
					cout << endl;
					cout << " Please enter the second decimal integer: ";
					cin >> decB;
					cout << endl;

					cout << " " << decA << " OR " << decB << " = " << (decA | decB);
				}
				else
				{
					cout << " Please enter the first " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInA;
					Binary binA(binInA);
					cout << endl;
					cout << " Please enter the second " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInB;
					Binary binB(binInB);
					cout << endl;

					cout << " " << binA.ToString() << " OR " << binB.ToString() << " = " << (binA | binB);
				}

				break;
			}
		case 'C':
		case 'c':
			{
				// NOT
				if(decimalMode)
				{
					cout << " Please enter a decimal integer: ";
					cin >> decA;
					cout << endl;

					cout << " NOT " << decA << " = " << (~decA);
				}
				else
				{
					cout << " Please enter an " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInA;
					Binary binA(binInA);
					cout << endl;

					cout << " NOT " << binA.ToString() << " = " << (~binA);
				}

				break;
			}
		case 'D':
		case 'd':
			{
				// XOR
				if(decimalMode)
				{
					cout << " Please enter the first decimal integer: ";
					cin >> decA;
					cout << endl;
					cout << " Please enter the second decimal integer: ";
					cin >> decB;
					cout << endl;

					cout << " " << decA << " XOR " << decB << " = " << (decA ^ decB);
				}
				else
				{
					cout << " Please enter the first " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInA;
					Binary binA(binInA);
					cout << endl;
					cout << " Please enter the second " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInB;
					Binary binB(binInB);
					cout << endl;

					cout << " " << binA.ToString() << " XOR " << binB.ToString() << " = " << (binA ^ binB);
				}

				break;
			}
		case 'E':
		case 'e':
			{
				// LEFT SHIFT
				int shiftAmount;

				if(decimalMode)
				{
					cout << " Please enter a decimal integer: ";
					cin >> decA;
					cout << endl;

					cout << " Please enter an amount to shift left by: ";
					cin >> shiftAmount;
					cout << endl;

					cout << " " << decA << " left shifted " << shiftAmount << " bit/s = " << (decA << shiftAmount);
				}
				else
				{
					cout << " Please enter an " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInA;
					Binary binA(binInA);
					cout << endl;

					cout << " Please enter an amount to shift left by: ";
					cin >> shiftAmount;
					cout << endl;

					cout << " " << binA.ToString() << " left shifted " << shiftAmount << " bit/s = " << (binA << shiftAmount);
				}

				break;
			}
		case 'F':
		case 'f':
			{
				// RIGHT SHIFT
				int shiftAmount;

				if(decimalMode)
				{
					cout << " Please enter a decimal integer: ";
					cin >> decA;
					cout << endl;

					cout << " Please enter an amount to shift right by: ";
					cin >> shiftAmount;
					cout << endl;

					cout << " " << decA << " right shifted " << shiftAmount << " bit/s = " << (decA >> shiftAmount);
				}
				else
				{
					cout << " Please enter an " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInA;
					Binary binA(binInA);
					cout << endl;

					cout << " Please enter an amount to shift right by: ";
					cin >> shiftAmount;
					cout << endl;

					cout << " " << binA.ToString() << " right shifted " << shiftAmount << " bit/s = " << (binA >> shiftAmount);
				}

				break;
			}
		case 'X':
		case 'x':
			{
				//EXIT CASE
				break;
			}
		default:
			{
				cout << "Please enter a valid option!" << endl;
				break;
			}
		}
	}
	while(menuInput != 'X' && menuInput != 'x');
}

void Program::BasicMath()
{
	char menuInput;
	string binInA, binInB;
	int decA, decB;

	do
	{
		cout << endl << endl;
		cout << "|--------------------------------------" << endl;
		cout << "| Basic Mathematics Submenu            " << endl;
		cout << "|                                      " << endl;
		cout << "| A - Addition                         " << endl;
		cout << "| B - Subtraction                      " << endl;
		cout << "|                                      " << endl;
		cout << "| X - Main Menu                        " << endl;
		cout << "|                                      " << endl;
		cout << "|--------------------------------------" << endl << endl;

		cout << " Please select an option: ";
		
		cin >> menuInput;

		cout << endl;

		switch(menuInput)
		{
		case 'A':
		case 'a':
			{
				// Addition
				if(decimalMode)
				{
					cout << " Please enter the first decimal integer: ";
					cin >> decA;
					cout << endl;
					cout << " Please enter the second decimal integer: ";
					cin >> decB;
					cout << endl;

					cout << " " << decA << " + " << decB << " = " << (decA + decB);
				}
				else
				{
					cout << " Please enter the first " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInA;
					Binary binA(binInA);
					cout << endl;
					cout << " Please enter the second " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInB;
					Binary binB(binInB);
					cout << endl;

					cout << " " << binA.ToString() << " + " << binB.ToString() << " = " << binA + binB << endl;
				}

				break;
			}
		case 'B':
		case 'b':
			{
				// Addition
				if(decimalMode)
				{
					cout << " Please enter the first decimal integer: ";
					cin >> decA;
					cout << endl;
					cout << " Please enter the second decimal integer: ";
					cin >> decB;
					cout << endl;

					cout << " " << decA << " + " << decB << " = " << (decA + decB);
				}
				else
				{
					cout << " Please enter the first " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInA;
					Binary binA(binInA);
					cout << endl;
					cout << " Please enter the second " << (Binary::BITS * Binary::BYTES) << " bit binary value: ";
					cin >> binInB;
					Binary binB(binInB);
					cout << endl;

					cout << " " << binA.ToString() << " + " << binB.ToString() << " = " << binA - binB << endl;
				}

				break;
			}
		case 'X':
		case 'x':
			{
				break;
			}
		default:
			{
				cout << "Please enter a valid option!" << endl;
				break;
			}
		}
	}
	while(menuInput != 'X' && menuInput != 'x');
}

//////////////////////////////
//
// PROGRAM ENTRY POINT
//
//////////////////////////////
int main()
{
	Program *app = new Program();
	app->Run();
	delete app;
	return 0;
}