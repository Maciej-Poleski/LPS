/* (C) Maciej Poleski 2011 */

#ifndef AUTHOR_HXX
#define AUTHOR_HXX

#include <QtCore/QString>

/**
 * @brief Przechowuje informacje o Autorze dopuszczonym do pracy z systemem.
 **/
class Author
{
public:
    /**
     * @brief Konstruktor domyślny. Pozostawia obiekt niezainicjalizowanym.
     * isNull() zwróci True.
     *
     **/
    Author();

    /**
     * @brief Konstruktor inicjalizuje dany obiekt conajmniej informacją
     * o kluczu publicznym danego autora. Wywołanie do isNull() zwróci False.
     *
     * @param publicKeyFile Pełna nazwa pliku klucza publicznego.
     * @param name Nazwa autora. Defaults to QString().
     * @param email E-mail autora. Defaults to QString().
     **/
    Author ( QString publicKeyFile, QString name=QString(), QString email=QString() );

    /**
     * @brief Czy ten obiekt coś sobą przedstawia.
     *
     * @return bool True jeżeli tak.
     **/

    bool isNull() const;

    /**
     * @brief Czy jest zdefiniowana nazwa autora.
     *
     * @return bool True jeżeli tak
     **/
    bool hasName() const;

    /**
     * @brief Czy autor ma zdefiniowanego e-maila.
     *
     * @return bool True Jeżeli tak.
     **/
    bool hasEmail() const;

    /**
     * @brief Zwraca pełną nazwę pliku z kluczem publicznym danego autora.
     *
     * @return QString Pełna nazwa pliku klucza publicznego danego autora.
     **/
    QString getPublicKeyFile() const;

    /**
     * @brief Zwraca nazwę autora.
     *
     * @return QString Nazwa autora.
     **/
    QString getName() const;

    /**
     * @brief Zwraca adres e-mail autora.
     *
     * @return QString Adres e-mail autora.
     **/
    QString getEmail() const;

    /**
     * @brief Zwraca unikalny identyfikator autora.
     *
     * @return quint16 Identyfikator.
     **/
    quint16 getID() const;

    /**
     * @brief Ustawia klucz publiczny danemu autorowi.
     *
     * @param file Pełna nazwa plucza publicznego.
     * @return Author& Dany obiekt.
     **/
    Author & setPublicKeyFile ( QString file );

    /**
     * @brief Ustawia nazwę danemu autorowi.
     *
     * @param name Nazwa autora.
     * @return Author& Dany obiekt.
     **/
    Author & setName ( QString name );

    /**
     * @brief Ustawia adres E-mail danemu autorowi.
     *
     * @param email Adres e-mail.
     * @return Author& Dany obiekt.
     **/
    Author & setEmail ( QString email );

    /**
     * @brief Umożliwia serializację wszystkich danych o autorze do strumienia.
     *
     * @param stream Strumień wyjściowy.
     * @param data Dane które mają zostać zapisane
     * @return QDataStream& Strumień wyjściowy.
     **/
    friend QDataStream & operator<<(QDataStream & stream, const Author & data);

    /**
     * @brief Umożliwia odczyt wszystkich informacji o autorze ze strumienia.
     *
     * @param stream Strumień wejściowy
     * @param data Obiekt do którego będą odczytane dane.
     * @return QDataStream& Strumień wejściowy.
     **/
    friend QDataStream & operator>>(QDataStream & stream, Author & data);

    /**
     * @brief Inicjalizuje fabryke obiektów pierwszym dostępnym ID.
     *
     * @param lastID Pierwszy dostępny ID.
     **/
    static void initialize(quint16 lastID);

private:
    QString publicKeyFile;
    QString name;
    QString email;
    quint16 id; ///< FIXME: Zaimplementować funkcjonalność
    static quint16 lastID;
};

#endif // AUTHOR_HXX
