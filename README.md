# OBJ-Reader

Biblioteka do odczytywania danych z plików .obj

Zależności:

1. Tworzone i kompilowane przy użyciu MS Visual Studio Community 2015 https://www.visualstudio.com/pl-pl/products/visual-studio-community-vs.aspx
2. Wykorzystuje struktury z biblioteki glm-0.9.7.4 http://glm.g-truc.net/0.9.7/index.html
3. Zalecane używanie jednakowych kompilatorów dla DLL i wykorzystujących ją projektów (dla zgodności ABI)

Założenia:

1. Obiekty rozrózniane wg używanej tekstury ('usemtl')
2. Elementy Face jednorodne - wszystkie wierzchołki w formie v, v//n, v/t, albo v/t/n
3. Nie więcej niż 1 obiekt ('o') w pliku.

Więcej informacji na temat plików .obj:
- https://en.wikipedia.org/wiki/Wavefront_.obj_file
- http://paulbourke.net/dataformats/obj/
