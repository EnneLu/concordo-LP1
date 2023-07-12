cmake_minimum_required(VERSION 3.22.1)

project(concordo VERSION 3.22.1 LANGUAGES CXX )

include_directories( include )

add_executable( program
               src/canal.cpp
               src/canalTexto.cpp
               src/canalVoz.cpp
               src/main.cpp
               src/mensagem.cpp
               src/servidor.cpp
               src/sistema.cpp
               src/usuario.cpp)