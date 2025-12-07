#include <bits/stdc++.h>
int main()
{
    freopen("Ahihi.out","w",stdout);
    std::locale::global(std::locale("")); // activate user-preferred locale, in my case en_US.utf8
    std::wifstream wf("Ahihi.inp"); // test.txt contains utf-8 text
    for(wchar_t c; wf.get(c); )
        std::wcout << c;
}
