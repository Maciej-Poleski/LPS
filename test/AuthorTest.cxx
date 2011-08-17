#define BOOST_TEST_MODULE AuthorTest
#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "Author.hxx"

#include <QtCore/QDataStream>
#include <QtCore/QBuffer>
#include <QtCore/QTemporaryFile>

std::ostream & operator<<(std::ostream & out,const QString & string)
{
    return out<<qPrintable(string);
}

BOOST_AUTO_TEST_CASE( constructor )
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

BOOST_AUTO_TEST_CASE(getters_and_setters)
{
    Author a1("pubkey","name","e-mail");
    BOOST_CHECK_EQUAL(a1.getEmail(),"e-mail");
    BOOST_CHECK_EQUAL(a1.getName(),"name");
    BOOST_CHECK_EQUAL(a1.getPublicKeyFile(),"pubkey");
    a1.setEmail("email1");
    BOOST_CHECK_EQUAL(a1.getEmail(),"email1");
    a1.setName("name1");
    BOOST_CHECK_EQUAL(a1.getName(),"name1");
    a1.setPublicKeyFile("pubkey1");
    BOOST_CHECK_EQUAL(a1.getPublicKeyFile(),"pubkey1");

    a1.setEmail("email2").setName("name2").setPublicKeyFile("pubkey2");
    BOOST_CHECK_EQUAL(a1.getEmail(),"email2");
    BOOST_CHECK_EQUAL(a1.getName(),"name2");
    BOOST_CHECK_EQUAL(a1.getPublicKeyFile(),"pubkey2");

    a1.setEmail("").setPublicKeyFile("");
    BOOST_CHECK_EQUAL(a1.getEmail(),"");
    BOOST_CHECK_EQUAL(a1.getEmail(),QString());
    BOOST_CHECK_EQUAL(a1.getPublicKeyFile(),"");
    BOOST_CHECK_EQUAL(a1.getPublicKeyFile(),QString());
    BOOST_CHECK_EQUAL(a1.hasEmail(),false);
    BOOST_CHECK_EQUAL(a1.isNull(),true);

    BOOST_CHECK_EQUAL(a1.hasName(),true);
    a1.setName(QString());
    BOOST_CHECK_EQUAL(a1.getName(),"");
    BOOST_CHECK_EQUAL(a1.getName(),QString());
    BOOST_CHECK_EQUAL(a1.hasName(),false);
}

BOOST_AUTO_TEST_CASE(serialization)
{
    Author::initialize(2);
    Author a1("pubkey1","name1","email1");
    Author a2("pubkey2","name2","email2");

	QTemporaryFile file;
	BOOST_REQUIRE(file.open());
	QDataStream stream(&file);
    stream<<a1<<a2;

	file.flush();

    Author a3,a4;
    stream>>a3>>a4;
    stream<<a3;
    stream>>a2;

    BOOST_CHECK_EQUAL(a3.getEmail(),"email1");
    BOOST_CHECK_EQUAL(a3.getID(),2);
    BOOST_CHECK_EQUAL(a3.getName(),"name1");
    BOOST_CHECK_EQUAL(a3.getPublicKeyFile(),"pubkey1");

    BOOST_CHECK_EQUAL(a4.getEmail(),"email2");
    BOOST_CHECK_EQUAL(a4.getID(),3);
    BOOST_CHECK_EQUAL(a4.getName(),"name2");
    BOOST_CHECK_EQUAL(a4.getPublicKeyFile(),"pubkey2");

    BOOST_CHECK_EQUAL(a2.getEmail(),"email1");
    BOOST_CHECK_EQUAL(a2.getID(),2);
    BOOST_CHECK_EQUAL(a2.getName(),"name1");
    BOOST_CHECK_EQUAL(a2.getPublicKeyFile(),"pubkey1");
    
}
