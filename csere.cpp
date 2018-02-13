#include <iostream>

void osszeadasos_csere(int &x, int &y);
void szorzasos_csere(int &x, int &y);
void xor_csere(int &x, int &y);

int main()
{
    int a = 101;
    int b = 1984;
    std::cout << "a = " << a << "\nb = " << b << "\n\n";

    osszeadasos_csere(a,b);
    std::cout << "Osszeadasos csere:\n";
    std::cout << "a = " << a << "\nb = " << b << "\n\n";

    szorzasos_csere(a,b);
    std::cout << "Szorzasos csere:\n";
    std::cout << "a = " << a << "\nb = " << b << "\n\n";

    xor_csere(a,b);
    std::cout << "Xor-os csere:\n";
    std::cout << "a = " << a << "\nb = " << b << "\n\n";

    return 0;
}

void osszeadasos_csere(int &x, int &y){
    x = x + y;
    y = x - y;
    x = x - y;
}

void szorzasos_csere(int &x, int &y){
    x = x * y;
    y = x / y;
    x = x / y;
}

void xor_csere(int &x, int &y){
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}
