/* (C) Maciej Poleski 2011 */

#include "Author.hxx"

Author::Author()
{

}

Author::Author ( QString publicKeyFile, QString name, QString email ) :
    publicKeyFile ( publicKeyFile ), name ( name ), email ( email )
{

}

QString Author::getEmail() const
{
    return email;
}

QString Author::getName() const
{
    return name;
}

QString Author::getPublicKeyFile() const
{
    return publicKeyFile;
}

bool Author::hasEmail() const
{
    return email.isEmpty();
}

bool Author::hasName() const
{
    return name.isEmpty();
}

bool Author::isNull() const
{
    return publicKeyFile.isEmpty();
}

Author& Author::setEmail ( QString email )
{
    this->email=email;
    return *this;
}

Author& Author::setName ( QString name )
{
    this->name=name;
    return *this;
}

Author& Author::setPublicKeyFile ( QString file )
{
    this->publicKeyFile=file;
    return *this;
}
