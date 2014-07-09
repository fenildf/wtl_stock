
#include "gtest/gtest.h"
#include "db.h"
#include "global.h"
class dbTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		//db::set_default("test.db");
		//EXPECT_STREQ("test.db",db::default_.c_str());

		//db::set_default(L"test.db");
		//EXPECT_STREQ("test.db", db::default_.c_str());
		//可在此删除unlink()
		_unlink("test.db");
	}

	virtual void TearDown()
	{
		
	}

	//db* db_;
};

////db类的静态函数set_default
TEST_F(dbTest, set_default_test)
{
	auto rc = db::set_default("test.db");
	EXPECT_STREQ("test.db", db::default_.c_str());
}

//db类的静态函数set_default使用wstring
TEST_F(dbTest, set_default_wstring_test)
{
	auto rc = db::set_default(L"wtest.db");
	EXPECT_STREQ("wtest.db", db::default_.c_str());
}

//db类的静态函数set_default
TEST_F(dbTest, create_default_database_test)
{
	EXPECT_EQ(true, db::set_default("test.db",global::create_default_database));
}
