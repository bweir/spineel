#pragma once

#include <QString>

#include "token.h"

class Lexer
{
    int     _linenum;
    int     _colnum;
    int     _lineindex;
    int     _tokenindex;
    int     _index;

    QString _in;
    QString _name;

    TokenMatch _last;

public:
    Lexer(QString text = QString(), QString name = QString());
    Lexer(const Lexer & other);
    Lexer operator=(const Lexer & other);
    ~Lexer();
    void reset();
    TokenMatch get();

    QString name();
    int pos();
    int line();
    int col();
    TokenMatch lastTokenMatch();
    QString last();
    QString lastLine();
};
