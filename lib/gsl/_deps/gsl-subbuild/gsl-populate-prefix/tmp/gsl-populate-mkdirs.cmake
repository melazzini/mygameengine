# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/_deps/gsl-src"
  "/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/_deps/gsl-build"
  "/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/_deps/gsl-subbuild/gsl-populate-prefix"
  "/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/_deps/gsl-subbuild/gsl-populate-prefix/tmp"
  "/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp"
  "/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/_deps/gsl-subbuild/gsl-populate-prefix/src"
  "/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp/${subDir}")
endforeach()
