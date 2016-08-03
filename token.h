#pragma once

#include "tokens.h"

#include <QString>
#include <QObject>
#include <QRegularExpression>
#include <QStringList>

class TokenMatch
{
    TokenID _token;

    QString _file;
    int     _line;
    int     _col;

    QString _text;
    QString _linetext;

public:
    TokenMatch();
    TokenMatch(TokenID token, 
               QString file,
               int line,
               int col,
               QString text,
               QString linetext);

    TokenID token();

    QString file();
    int line();
    int col();

    QString text();
    QString lineText();

    void print();
};

class TokenData {

    TokenID     _token;
    QString     _name;
    QString     _pattern;
    QVariant    _printable;

public:
    TokenData();
    TokenData(TokenID token,
            QString name,
            QString pattern,
            QString printable)
    {
        _token = token;
        _name = name;
        _pattern = pattern;
        _printable = QVariant(printable);
    }

    TokenID     token()     { return _token; }
    QString     name()      { return _name; }
    QString     pattern()   { return _pattern; }
    QString     printable() { return _printable.toString(); }
};

QList<TokenData> initializeTokenData();
QRegularExpression initializeTokenRegex(QList<TokenData> data);

static QList<TokenData> tokenData = initializeTokenData();
static QRegularExpression tokenRegex = initializeTokenRegex(tokenData);
