/* ( C ) Maciej Poleski 2011 */

#ifndef PROTOTYPE_HXX
#define PROTOTYPE_HXX

#include <QtCore/QString>
#include <QtCore/QDateTime>
#include "Author.hxx"

/**
 * @brief Przechowuje pojedynczy przykład wykorzystywany w prototypowniu.
 **/
class Prototype
{
    Author author;
    QString example;
    QString comment;
    QDateTime date;     ///< Data i czas stworzenia pomysłu (po stronie twórcy)
    quint32 id;
};

#endif // PROTOTYPE_HXX
