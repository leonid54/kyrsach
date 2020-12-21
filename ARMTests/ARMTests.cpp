#include "CppUnitTest.h"
#include "../АРМ кассира кинотеатра/Classic_Hall.h"
#include "../АРМ кассира кинотеатра/Premium_Hall.h"
#include "../АРМ кассира кинотеатра/Morning_Seans.h"
#include "../АРМ кассира кинотеатра/Evening_Seans.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ARMTests
{
	TEST_CLASS(ARMTests)
	{
	public:
		
		TEST_METHOD(Classic_Hall_Test_Price)
		{
			Chall p;
			Assert::IsTrue(p.get_morning_price() == "200 рублей");
			Assert::IsTrue(p.get_evening_price() == "350 рублей");
		}
		TEST_METHOD(Classic_Hall_Test_Check_Place)
		{
			Chall p;
			Assert::IsTrue(p.set_and_check_place_morning(5, 10));
			Assert::IsTrue(p.set_and_check_place_evening(5, 10));
		}
		TEST_METHOD(Premium_Hall_Test_Price)
		{
			Phall p;
			Assert::IsTrue(p.get_morning_price() == "350 рублей");
			Assert::IsTrue(p.get_evening_price() == "500 рублей");

		}
		TEST_METHOD(Premium_Hall_Test_Check_Place)
		{
			Phall p;
			Assert::IsTrue(p.set_and_check_place_morning(5, 10));
			Assert::IsTrue(p.set_and_check_place_evening(5, 10));
		}
		TEST_METHOD(Morning_Seans_Test_Movie)
		{
			Morning_Seans p;
			Assert::IsTrue(p.set_get_movie(0) != "");
			Assert::IsTrue(p.set_get_movie(1) != "");
			Assert::IsTrue(p.set_get_movie(2) != "");
			Assert::IsTrue(p.set_get_movie(3) != "");
			Assert::IsTrue(p.set_get_movie(4) != "");
		}
		TEST_METHOD(Morning_Seans_Test_Time)
		{
			Morning_Seans p;
			Assert::IsTrue(p.set_get_time(0) != "");
			Assert::IsTrue(p.set_get_time(1) != "");
			Assert::IsTrue(p.set_get_time(2) != "");
			Assert::IsTrue(p.set_get_time(3) != "");
			Assert::IsTrue(p.set_get_time(4) != "");
		}
		TEST_METHOD(Morning_Seans_Test_Info)
		{
			Morning_Seans p;
			Assert::IsTrue(p.set_get_info(0) != "");
			Assert::IsTrue(p.set_get_info(1) != "");
			Assert::IsTrue(p.set_get_info(2) != "");
			Assert::IsTrue(p.set_get_info(3) != "");
			Assert::IsTrue(p.set_get_info(4) != "");
		}
		TEST_METHOD(Evening_Seans_Test_Movie)
		{
			Evening_Seans p;
			Assert::IsTrue(p.set_get_movie(0) != "");
			Assert::IsTrue(p.set_get_movie(1) != "");
			Assert::IsTrue(p.set_get_movie(2) != "");
			Assert::IsTrue(p.set_get_movie(3) != "");
			Assert::IsTrue(p.set_get_movie(4) != "");
		}
		TEST_METHOD(Evening_Seans_Test_Time)
		{
			Evening_Seans p;
			Assert::IsTrue(p.set_get_time(0) != "");
			Assert::IsTrue(p.set_get_time(1) != "");
			Assert::IsTrue(p.set_get_time(2) != "");
			Assert::IsTrue(p.set_get_time(3) != "");
			Assert::IsTrue(p.set_get_time(4) != "");
		}
		TEST_METHOD(Evening_Seans_Test_Info)
		{
			Evening_Seans p;
			Assert::IsTrue(p.set_get_info(0) != "");
			Assert::IsTrue(p.set_get_info(1) != "");
			Assert::IsTrue(p.set_get_info(2) != "");
			Assert::IsTrue(p.set_get_info(3) != "");
			Assert::IsTrue(p.set_get_info(4) != "");
		}
		/*TEST_METHOD()
		{

		}
		TEST_METHOD()
		{

		}
		TEST_METHOD()
		{

		}
		TEST_METHOD()
		{

		}
		TEST_METHOD()
		{

		}
		TEST_METHOD()
		{

		}
		TEST_METHOD()
		{

		}
		*/


	};
}
