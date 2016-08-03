#include "lexer.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);

    QString filename = argv[1];
    QFile file(filename);
    if (!file.open(QFile::ReadOnly))
    {
        qDebug() << "Error: File not found:" << filename;
        return 1;
    }

    QString text = file.readAll();
    file.close();

    if (text.isEmpty())
    {
        qDebug() << "Error: File empty:" << filename;
        return 1;
    }

    Lexer lexer(text, QFileInfo(filename).fileName());

    printf("{%s}\n", qPrintable(tokenRegex.pattern()));

    TokenMatch m;
    while ((m = lexer.get()).token() != TEnd)
    {
        m.print();
    }

    return 0;
}
