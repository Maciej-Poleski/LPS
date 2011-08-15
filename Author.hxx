/* (C) Maciej Poleski 2011 */

#ifndef AUTHOR_HXX
#define AUTHOR_HXX

#include <QtCore/QString>

/**
 * @brief Przechowuje informacje o Autorze dopuszczonym do pracy z systemem.
 **/
class Author
{
    QString publicKeyFile;
    QString name;
    QString email;
};

#endif // AUTHOR_HXX
