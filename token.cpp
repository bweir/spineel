#include "token.h"

#include <stdio.h>
#include <QDebug>

TokenMatch::TokenMatch()
{
    _token = TNull;
    _file = "";
    _line = 1;
    _col = 1;
    _text = "";
    _linetext = "";
}

TokenMatch::TokenMatch(TokenID token, 
             QString file,
             int line,
             int col,
             QString text,
             QString linetext)
{
    _token = token;
    _file = file;
    _line = line;
    _col = col;
    _text = text;
    _linetext = linetext;
}


int TokenMatch::line()
{
    return _line;
}

int TokenMatch::col()
{
    return _col;
}

TokenID TokenMatch::token()
{
    return _token;
}

QString TokenMatch::file()
{
    return _file;
}

QString TokenMatch::text()
{
    return _text;
}

QString TokenMatch::lineText()
{
    return _linetext;
}

void TokenMatch::print()
{
    fprintf(stderr, "(%s(%i,%i) '%s')\n",
            qPrintable(file()),
            line(),
            col(),
            qPrintable(text()));
}



QList<TokenData> initializeTokenData()
{
    QList<TokenData> data;

#include "tokenlist.h"

    return data;
}

QRegularExpression initializeTokenRegex(QList<TokenData> data)
{
    QStringList patternlist;

    foreach (TokenData d, data)
    {
        qDebug() << d.name() << d.pattern();
        patternlist.append(d.pattern());
    }

    QString pattern = patternlist.join("|");
    pattern = "(" + pattern + ")";

    QRegularExpression re(pattern, QRegularExpression::DotMatchesEverythingOption
                                 | QRegularExpression::CaseInsensitiveOption);

    return re;
}


