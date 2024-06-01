#include <config.h>
#include <stdio.h>
#include <sys/types.h>
#include "system.h"

// #ifndef DEFAULT_ECHO_TO_XPG
// enum { DEFAULT_ECHO_TO_XPG = false };
// #endif
// 기본값으로 false 를 주고 시작
bool DEFAULT_ECHO_TO_XPG = false;

/* Convert C from hexadecimal character to integer.  */

// argc : 명령줄 인수의 개수 argv : 명령줄 인수의 배열, argv[0]은 프로그램 이름
int main(int argc, char **argv)
{
    bool display_return = true;

    // bool allow_options =
    //(! DEFAULT_ECHO_TO_XPG);
    bool allow_options = true;
    bool do_v9 = DEFAULT_ECHO_TO_XPG;

    // initialize_main (&argc, &argv);
    // set_program_name (argv[0]);
    // setlocale (LC_ALL, "");
    // bindtextdomain (PACKAGE, LOCALEDIR);
    // textdomain (PACKAGE);

    // atexit (close_stdout);

    --argc;
    ++argv;

    if (allow_options)
        while (argc > 0 && *argv[0] == '-')
        {
            char const *temp = argv[0] + 1;
            size_t i;

            for (i = 0; temp[i]; i++)
                switch (temp[i])
                {
                case 'e':
                case 'E':
                    break;
                    // default:
                    //   goto just_echo;
                }

            if (i == 0)
                goto just_echo;

            while (*temp)
                switch (*temp++)
                {
                case 'e':
                    do_v9 = true;
                    break;

                case 'E':
                    do_v9 = false;
                    break;
                }

            argc--;
            argv++;
        }

just_echo:

    if (do_v9)
    {
        while (argc > 0)
        {
            char const *s = argv[0];
            unsigned char c;

            while ((c = *s++))
            {
                if (c == '\\' && *s)
                {
                    switch (c = *s++) //
                    {
                    case 'b':
                        c = '\b';
                        break;
                    case 'c':
                        exit(EXIT_SUCCESS);
                    case 'e':
                        c = '\x1B';
                        break;
                    case 'n':
                        c = '\n';
                        break;
                    case 't':
                        c = '\t';
                        break;
                    case 'v':
                        c = '\v';
                        break;
                    case '\\':
                        break;

                    not_an_escape:
                    default:
                        putchar('\\');
                        break;
                    }
                }
                putchar(c);
            }
            argc--;
            argv++;

            if (argc > 0)
                putchar(' ');
        }
    }
    else
    {
        while (argc > 0)
        {
            fputs(argv[0], stdout);
            argc--;
            argv++;
            if (argc > 0)
                putchar(' ');
        }
    }

    if (display_return)
        putchar('\n');
    exit(EXIT_SUCCESS);
}