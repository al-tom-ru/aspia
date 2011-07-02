/*
 * PROJECT:         Aspia
 * FILE:            aspia/report/csv.c
 * LICENSE:         LGPL (GNU Lesser General Public License)
 * PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
 */

#include "../main.h"


static FILE *hReport = NULL;


BOOL
CsvAppendStringToFile(LPWSTR lpszString)
{
    DWORD dwLen = SafeStrLen(lpszString);

    if (!hReport) return FALSE;

    fwrite(lpszString, sizeof(WCHAR), dwLen, hReport);

    return TRUE;
}

BOOL
CsvCreateReport(LPWSTR lpszFile)
{
    if (_wfopen_s(&hReport, lpszFile, L"wt+,ccs=UTF-8") != 0)
        return FALSE;

    if (!hReport) return FALSE;

    return TRUE;
}

VOID
CsvCloseReport(VOID)
{
    fclose(hReport);
    hReport = NULL;
}

VOID
CsvWriteValueString(LPWSTR lpszString)
{
    WCHAR szText[MAX_STR_LEN];

    StringCbPrintf(szText, sizeof(szText), L"%s;", lpszString);
    CsvAppendStringToFile(szText);
}

VOID
CsvWriteItemString(LPWSTR lpszString)
{
    WCHAR szText[MAX_STR_LEN];

    StringCbPrintf(szText, sizeof(szText), L"\n%s;", lpszString);
    CsvAppendStringToFile(szText);
}

VOID
CsvWriteColumnString(LPWSTR lpszString)
{
    WCHAR szText[MAX_STR_LEN];

    StringCbPrintf(szText, sizeof(szText), L"%s;", lpszString);
    CsvAppendStringToFile(szText);
}

VOID
CsvTableTitle(LPWSTR lpszTitle)
{
    WCHAR szText[MAX_STR_LEN];

    StringCbPrintf(szText, sizeof(szText), L"\n%s\n", lpszTitle);
    CsvAppendStringToFile(szText);
}

VOID
CsvEndTable(VOID)
{
    CsvAppendStringToFile(L"\n");
}