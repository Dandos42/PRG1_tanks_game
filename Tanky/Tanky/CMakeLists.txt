# CMakeList.txt: Projekt CMake pro Tanky, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#
cmake_minimum_required (VERSION 3.8)

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (Tanky "Tanky.cpp" "Tanky.h" "strelba.h" "strelba.cpp"    )

# TODO: V případě potřeby přidejte testy a cíle instalace.
