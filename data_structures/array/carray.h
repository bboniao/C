/*
 * CArray.h
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Modified by: Leonardo Vencovsky
 * Last modified: 19/03/2018
 *
 * Header for Array in C
 *
 * Compiled in Visual Studio 2017
 *
 */

/* #pragma once一般由编译器提供保证：同一个文件不会被包含多次。这里所说的”同一个文件”是指物理上的一个文件，而不是指内容相同的两个文件。无法对一个头文件中的一段代码作
 * #pragma once声明，而只能针对文件。此方式不会出现宏名碰撞引发的奇怪问题，大型项目的编译速度也因此提供了一些。缺点是如果某个头文件有多份拷贝，此方法不能保证它们不被重复包含。在C/C++中，
 * #pragma once是一个非标准但是被广泛支持的方式。
 */
/* #pragma once方式产生于#ifndef之后。#ifndef方式受C/C++语言标准的支持，不受编译器的任何限制；而
 * #pragma once方式有些编译器不支持(较老编译器不支持，如GCC 3.4版本之前不支持#pragmaonce)，兼容性不够好。#ifndef可以针对一个文件中的部分代码，而
 * #pragma once只能针对整个文件。
 */
#pragma once

/*
 * 1、C++代码调用 C 语言代码；
 * 2、在 C++的头文件中使用；
 * 3、在多个人协同开发时，可能有的人比较擅长 C 语言，而有的人擅长
 * C++，这样的情况下也会有用到； 4、重点提示：如果是 C++ 调用由 C
 * 语言编写的第三方库，必须使用 extern “C” 告诉编译以 C
 * 方式编译，否则会出现编译报错的问题；
 */
#ifdef __cplusplus
extern "C"
{
#endif

#define ARRAY_ERASED -1
#define SUCCESS 0
#define INVALID_POSITION 1
#define POSITION_INIT 2
#define POSITION_NOT_INIT 3
#define POSITION_EMPTY 4
#define ARRAY_FULL 5

    typedef struct CArray
    {
        int *array;
        int size;
    } CArray;

    // +-------------------------------------+
    // |           Returns array             |
    // +-------------------------------------+
    CArray *getCArray(int size);
    CArray *getCopyCArray(CArray *array);

    // +-------------------------------------+
    // |           Input / Output            |
    // +-------------------------------------+
    int insertValueCArray(CArray *array, int position, int value);
    int removeValueCArray(CArray *array, int position);
    int pushValueCArray(CArray *array, int value);
    int updateValueCArray(CArray *array, int position, int value);

    // +-------------------------------------+
    // |               Erase                 |
    // +-------------------------------------+
    int eraseCArray(CArray *array);

    // +-------------------------------------+
    // |             Switching               |
    // +-------------------------------------+
    int switchValuesCArray(CArray *array, int position1, int position2);
    int reverseCArray(CArray *array);

    // +-------------------------------------+
    // |              Sorting                |
    // +-------------------------------------+
    int bubbleSortCArray(CArray *array);
    int selectionSortCArray(CArray *array);
    int insertionSortCArray(CArray *array);
    int blenderCArray(CArray *array);

    // +-------------------------------------+
    // |             Searching               |
    // +-------------------------------------+
    int valueOcurranceCArray(CArray *array, int value);
    CArray *valuePositionsCArray(CArray *array, int value);
    int findMaxCArray(CArray *array);
    int findMinCArray(CArray *array);

    // +-------------------------------------+
    // |              Display                |
    // +-------------------------------------+
    int displayCArray(CArray *array);

#ifdef __cplusplus
}
#endif
