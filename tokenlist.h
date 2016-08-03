
#define TOKEN(a, c, d, e)   data << TokenData(a, \
                            QObject::tr(c), \
                            d, \
                            QObject::tr(e));

TOKEN(TBinary,          "decimal number",       "[0-1]([0-1_]+[0-1]|[0-1]*)",                               "")
TOKEN(TQuaternary,      "quaternary number",    "[0-3]([0-3_]+[0-3]|[0-3]*)",                               "")
TOKEN(TDecimal,         "decimal number",       "[0-9]([0-9_]+[0-9]|[0-9]*)",                               "")
TOKEN(THexadecimal,     "hexadecimal number",   "[0-9a-f]([0-9a-f_]+[0-9a-f]|[0-9a-f]*)",                   "")
TOKEN(TFloat,           "float number",         "[0-9]([0-9_]+[0-9]|[0-9]*)\\.[0-9]([0-9_]+[0-9]|[0-9]*)",  "")

TOKEN(TIdentifier,      "identifier",           "[a-z][a-z0-9]*",                   "")




TOKEN(TNewLine,         "new line",             "\n",     "\n" )
TOKEN(TEnd,             "end of file",          "\\Z",     "<<EOF>>" )

TOKEN(TDot,             "dot",                  ".",    "" )
TOKEN(TNull,            "null token",           "",     "(null)" )
    
