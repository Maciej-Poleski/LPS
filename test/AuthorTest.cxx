#define BOOST_TEST_MODULE AuthorTest
#include <boost/test/unit_test.hpp>

#include "Author.hxx"

BOOST_AUTO_TEST_CASE(constructor)
{
    Author a1;
    BOOST_CHECK(a1.isNull());
    BOOST_CHECK(a1.hasEmail()==false);
    BOOST_CHECK(a1.hasName()==false);
    BOOST_CHECK(a1.getEmail().isEmpty());
    BOOST_CHECK(a1.getName().isEmpty());
    BOOST_CHECK(a1.getPublicKeyFile().isEmpty());

    Author a2("pubkey1");
    BOOST_CHECK(a2.isNull()==false);
    BOOST_CHECK(a2.hasEmail()==false);
    BOOST_CHECK(a2.hasName()==false);
    BOOST_CHECK(a2.getEmail().isEmpty());
    BOOST_CHECK(a2.getName().isEmpty());
    BOOST_CHECK(a2.getPublicKeyFile().isEmpty()==false);
    BOOST_CHECK_EQUAL(a2.getPublicKeyFile(),"pubkey1");

    Author a3("pubkey2","name1");
    BOOST_CHECK(a3.isNull()==false);
    BOOST_CHECK(a3.hasEmail()==false);
    BOOST_CHECK(a3.hasName()==true);
    BOOST_CHECK(a3.getEmail().isEmpty());
    BOOST_CHECK(a3.getName().isEmpty()==false);
    BOOST_CHECK(a3.getPublicKeyFile().isEmpty()==false);
    BOOST_CHECK_EQUAL(a3.getPublicKeyFile(),"pubkey2");
    BOOST_CHECK_EQUAL(a3.getName(),"name1");

    Author a4("pubkey3","name2","email1");
    BOOST_CHECK(a4.isNull()==false);
    BOOST_CHECK(a4.hasEmail()==true);
    BOOST_CHECK(a4.hasName()==true);
    BOOST_CHECK(a4.getEmail().isEmpty()==false);
    BOOST_CHECK(a4.getName().isEmpty()==false);
    BOOST_CHECK(a4.getPublicKeyFile().isEmpty()==false);
    BOOST_CHECK_EQUAL(a4.getPublicKeyFile(),"pubkey3");
    BOOST_CHECK_EQUAL(a4.getName(),"name2");
    BOOST_CHECK_EQUAL(a4.getEmail(),"email1");
}