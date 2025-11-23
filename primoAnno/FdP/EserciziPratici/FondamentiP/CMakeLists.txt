# Versione minima di CMake richiesta
cmake_minimum_required(VERSION 3.20)

# Nome del workspace
project(Workspace_Fondamenti CXX)

# Imposta uno standard C++
set(CMAKE_CXX_STANDARD 17)

# Carica i progetti che si trovano nelle sottocartelle
add_subdirectory(esame)
add_subdirectory(Esercitazioni)
add_subdirectory(biblioteca)
add_subdirectory(raccoglitore)
add_subdirectory(listaCaratteri)
add_subdirectory(mensa)
add_subdirectory(cloudStorage)
add_subdirectory(playlist)