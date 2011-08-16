/* (C) Maciej Poleski 2011 */

#include "Author.hxx"

#include <QtCore/QDataStream>

quint16 Author::lastID=~ ( static_cast<quint16> ( 0u ) );

Author::Author() : id ( lastID++ )
{

}

Author::Author ( QString publicKeyFile, QString name, QString email ) :
    publicKeyFile ( publicKeyFile ), name ( name ), email ( email ), id ( lastID++ )
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

quint16 Author::getID() const
{
    return id;
}

bool Author::hasEmail() const
{
    return !email.isEmpty();
}

bool Author::hasName() const
{
    return !name.isEmpty();
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

QDataStream& operator<< ( QDataStream& stream, const Author& data )
{
    return stream<<data.id<<data.publicKeyFile<<data.name<<data.email;
}

QDataStream& operator>> ( QDataStream& stream, Author& data )
{
    return stream>>data.id>>data.publicKeyFile>>data.name>>data.email;
}

void Author::initialize ( quint16 lastID )
{
    Author::lastID=lastID;
}
