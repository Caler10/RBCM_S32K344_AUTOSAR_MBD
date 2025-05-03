/* Copyright 2020-2021 The MathWorks, Inc. */

/**
 * @file: slImageTypes.h
 *
 * @brief SimStruct types for Simulink Image operations
 *
 */

#ifndef __SIMSTRUC__IMAGETYPES
#define __SIMSTRUC__IMAGETYPES

#include "images/datatypes/ImageDefs.hpp"

/* Data type properties for image types */
typedef struct {
    size_t numChannels;
    size_t numRows;
    size_t numCols;
    images::datatypes::ColorFormat colorFormat;
    images::datatypes::Layout dataLayout;
    images::datatypes::UnderlyingType baseType;
} ImageDataTypeProperties;

#endif
