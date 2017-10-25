// ---------------------------------------------------------------------------
// Program.h
// The main program.
//
// Original author: <Liam>
// Date created: 07/10/2014
// ---------------------------------------------------------------------------
#ifndef _PROGRAM_H_
#define _PROGRAM_H_

class Program
{
public:
	Program();
	~Program();

	void Run();

	static bool signedMode;
	static bool decimalMode;

private:
	void BitwiseMenu();
	void BasicMath();
};

#endif // _PROGRAM_H_