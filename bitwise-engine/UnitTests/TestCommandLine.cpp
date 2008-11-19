#include <BitwiseEngine/CommandLine.h>
#include <UnitTest++/UnitTest++.h>
#include <iostream>
using namespace BitwiseEngine;

SUITE(CommandLineTestSuite)
{
	TEST(IsOptionExists)
	{
		char** argv = new char*[2];
		argv[0] = "executable.exe";
		argv[1] = "-f";

		CommandLine cmd(2, argv);
		CHECK(cmd.IsOption("-f"));
	}

	TEST(IsOptionNotExists)
	{
		char** argv = new char*[2];
		argv[0] = "executable.exe";
		argv[1] = "-f";

		CommandLine cmd(2, argv);
		CHECK(!cmd.IsOption("--in"));
	}

	TEST(GetOptionBoolExistsTrue)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "TRUE";

		CommandLine cmd(3, argv);
		bool val;

		CHECK(cmd.GetOption("-f", val));
		CHECK(val);
	}

	TEST(GetOptionBoolIllegalValue)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "orange";

		CommandLine cmd(3, argv);
		bool val;

		CHECK(!cmd.GetOption("-f", val));
	}

	TEST(GetOptionBoolExistsFalse)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "false";

		CommandLine cmd(3, argv);
		bool val;

		CHECK(cmd.GetOption("-f", val));
		CHECK(!val);
	}

	TEST(GetOptionBoolNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "true";

		CommandLine cmd(3, argv);
		bool val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetOptionIntExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "-20";

		CommandLine cmd(3, argv);
		int val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_EQUAL(-20, val);
	}

	TEST(GetOptionIntNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "-20";

		CommandLine cmd(3, argv);
		int val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetOptionUnsignedIntExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "20";

		CommandLine cmd(3, argv);
		unsigned int val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_EQUAL(20, val);
	}

	TEST(GetOptionUnsignedIntNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "20";

		CommandLine cmd(3, argv);
		unsigned int val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetOptionShortExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "-20";

		CommandLine cmd(3, argv);
		short val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_EQUAL(-20, val);
	}

	TEST(GetOptionShortNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "-20";

		CommandLine cmd(3, argv);
		short val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetOptionUnsignedShortExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "20";

		CommandLine cmd(3, argv);
		unsigned short val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_EQUAL(20, val);
	}

	TEST(GetOptionUnsignedShortNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "20";

		CommandLine cmd(3, argv);
		unsigned short val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetOptionUnsignedCharExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "2";

		CommandLine cmd(3, argv);
		unsigned char val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_EQUAL('2', val);
	}

	TEST(GetOptionUnsignedCharNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";

		CommandLine cmd(2, argv);
		unsigned char val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetOptionCharExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "2";

		CommandLine cmd(3, argv);
		char val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_EQUAL('2', val);
	}

	TEST(GetOptionCharNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";

		CommandLine cmd(2, argv);
		char val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetOptionFloatExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "2.0";

		CommandLine cmd(3, argv);
		float val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_CLOSE(2.0f, val, 0.0001);
	}

	TEST(GetOptionFloatNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";

		CommandLine cmd(2, argv);
		float val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetOptionDoubleExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "2.0";

		CommandLine cmd(3, argv);
		double val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_CLOSE(2.0, val, 0.0001);
	}

	TEST(GetOptionDoubleNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";

		CommandLine cmd(2, argv);
		double val;

		CHECK(!cmd.GetOption("--in", val));
	}
	

	TEST(GetOptionStringExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "Hello";

		CommandLine cmd(3, argv);
		std::string val;

		CHECK(cmd.GetOption("-f", val));
		CHECK_EQUAL("Hello", val);
	}

	TEST(GetOptionStringNotExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";

		CommandLine cmd(2, argv);
		std::string val;

		CHECK(!cmd.GetOption("--in", val));
	}

	TEST(GetExecutableExists)
	{
		char** argv = new char*[3];
		argv[0] = "executable.exe";
		argv[1] = "-f";
		argv[2] = "Hello";

		CommandLine cmd(3, argv);
		std::string val;

		CHECK(cmd.GetExecutable(val));
		CHECK_EQUAL("executable.exe", val);
	}
}