#include <windows.h>
#include <cstdio>
//cl /EHsc showError.cc
int main(int argc, const char* argv[]) //Init arguments
{
    if (argc < 2) {
        printf("Usage: ShowError <number>\n");
        return 0;
    }
    int message = atoi(argv[1]);

    LPWSTR text;
    DWORD chars = ::FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | // function allocates
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr, message, 0, (LPWSTR)&text, //ugly cast
        0, nullptr);
    if (chars > 0) {
        printf("Message %d: %ws\n", message, text); //WS = Unicode
        ::LocalFree(text);
    }
    else {
        printf("Error does not exist\n");
    }
}
