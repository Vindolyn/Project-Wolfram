#ifndef WOLFRAM_ENGINE_H
#define WOLFRAM_ENGINE_H

#ifdef BUILD_WOLFRAM
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif

class Wolfram {
public:

};

#endif // WOLFRAM_ENGINE_H
