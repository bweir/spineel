#include "lexer.h"

#include <stdio.h>

#include <QRegularExpression>
#include <QDebug>

Lexer::Lexer(QString text, QString name)
{
    reset();
    _in = text;
    _name = name;
}

Lexer::Lexer(const Lexer & other)
{
    _name       = other._name;
    _index      = other._index;
    _lineindex  = other._lineindex;
    _linenum    = other._linenum;
    _colnum     = other._colnum;

    _in         = other._in;
    _last       = other._last;
    _name       = other._name;
}

Lexer Lexer::operator=(const Lexer & other)
{
    _name       = other._name;
    _index      = other._index;
    _lineindex  = other._lineindex;
    _linenum    = other._linenum;
    _colnum     = other._colnum;

    _in         = other._in;
    _last       = other._last;
    _name       = other._name;

    return *this;
}

Lexer::~Lexer()
{

}

void Lexer::reset()
{
    _index = 0;
    _lineindex = 0;
    _linenum = 1;
    _colnum = 1;

    _in = "";
    _last = TokenMatch();
}

TokenMatch Lexer::get()
{
    foreach(TokenData d, tokenData)
    {
        QRegularExpression re(d.pattern(), QRegularExpression::DotMatchesEverythingOption
                                         | QRegularExpression::CaseInsensitiveOption);

        QRegularExpressionMatch m = re.match(_in, _index);

        if (m.hasMatch() && m.capturedStart() == _index)
        {
            qDebug() << d.pattern() << m.captured();
            _last = TokenMatch(d.token(), name(), line(), col(), m.captured(), lastLine());
            _index += m.captured().size();

            if (d.token() == TNewLine)
            {
                _linenum++;
                _lineindex = _index;
            }
            _colnum = _index - _lineindex;

            return _last;
        }
    }
    return TokenMatch();
}

QString Lexer::last()
{
    return _last.text();
}

QString Lexer::name()
{
    return _name;
}

int Lexer::col()
{
    return _colnum;
}

int Lexer::line()
{
    return _linenum;
}

int Lexer::pos()
{
    return _index;
}

QString Lexer::lastLine()
{
    return _in.mid(_lineindex, _in.indexOf("\n",_lineindex) - _lineindex);
}

TokenMatch Lexer::lastTokenMatch()
{
    return _last;
}
