#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "UserManage.hpp"
#include "mysql\MysqlWrapper.h"


class CUserManageTest : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE( CUserManageTest );
    CPPUNIT_TEST( AuthenticateTest );
    CPPUNIT_TEST_SUITE_END();
	CUserManage um;
public:
    void setUp()
    {
       
    }
    void tearDown()
    {
        
    }
public:
	void AuthenticateTest()
	{
		MWConnection conn;
		CPPUNIT_ASSERT(conn.Connect("xxy1991.dlinkddns.com", "vnoc", "ldldld", "vnoc", 3306)!= MW_SQL_ERR);
		string strUser = "user00";
		char strPassword[20] = "0000000000000000000"; 
		userinfo stInfo = {};
		CPPUNIT_ASSERT(um.Authenticate(strUser, (char*)strPassword, &stInfo));
        
    }

};
CPPUNIT_TEST_SUITE_REGISTRATION ( CUserManageTest );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CUserManageTest, "CUserManageTest");