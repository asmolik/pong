# pong

## Python
Testowane na wersji 3.4.3 (Windows) oraz 2.7 (Linux - Ubuntu)
## Tornado
Program wymaga biblioteki tornado:
http://www.tornadoweb.org/en/stable/index.html
## Boost
Na systemie Windows konieczne jest użycie wersji co najwyżej 1.55, ponieważ w nowszych wydaniach występują błędy podczas kompilacji biblioteki boost.python.
Na systemie Ubuntu aplikacja pomyślnie się kompiluje z wykorzystaniem wersji 1.59.
Aplikacja wykorzystuje system budowania boost build (b2, bjam). Aby kompilacja przebiegła pomyślnie należy w pliku Jamroot podać katalog zawierający bibliotekę boost. Dodatkowo podczas kompilacji na systemie Linux wymagane jest podanie parametru kompilacji -std==c++14. Zatem aby przeprowadzić na tym systemie kompilację należy wywołać komendę "b2 toolset=gcc cxxflags=-std=c++14".

## Kompilacja:
1. W katalogu zawierającym źródła programu wywołanie programu "b2".
2. Polecenie kompilacji
  * Windows: b2
  * Linux: b2 toolset=gcc cxxflags=-std=c++14
3. cd Pong/bin
4. python server.py
5. localhost:8888