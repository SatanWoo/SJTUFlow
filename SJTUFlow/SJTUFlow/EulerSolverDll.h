#ifndef EULERSOLVERDLL_H
#define EULERSOLVERDLL_H

#ifdef EULERSOLVERDLL_EXPORTS
#define EULERSOLVERDLL_API __declspec(dllexport)
#else
#define EULERSOLVERDLL_API __declspec(dllimport)
#endif

#endif