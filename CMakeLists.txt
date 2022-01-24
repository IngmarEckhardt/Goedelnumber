cmake_minimum_required(VERSION 3.20)
project(Goedelnumber)

set(CMAKE_CXX_STANDARD 17)

add_executable(Goedelnumber Goedelnumber.cpp PrimeRepository.cpp Primes.cpp Primes.h SieveOfEratosthenes.cpp GoedelGenerator.cpp GoedelGenerator.h HelpPage.cpp BigUnsignInt.cpp BigUnsignInt.h PrimeRepository.h SieveOfEratosthenes.h)
