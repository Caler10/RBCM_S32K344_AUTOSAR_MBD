/* Copyright 2022 The MathWorks, Inc. */
#ifndef _OCRUTILS_
#define _OCRUTILS_

#ifndef OCRUTILSLEGACY_API
#    define OCRUTILSLEGACY_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif


#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C OCRUTILSLEGACY_API
int32_T tesseractRecognizeTextUint8Legacy(void **, const uint8_T * I, char ** utf8Text,
                                    const int32_T width, const int32_T height,
                                    const char * textLayout, const char * charSet,
                                    const char * tessdata, const char * lang,
                                    const boolean_T resetParams);

EXTERN_C OCRUTILSLEGACY_API
int32_T tesseractRecognizeTextLogicalLegacy(void **, const boolean_T * I, char ** utf8Text,
                                      const int32_T width, const int32_T height,
                                      const char * textLayout, const char * charSet,
                                      const char * tessdata, const char * lang,
                                      const boolean_T resetParams);

EXTERN_C OCRUTILSLEGACY_API
void cleanupTesseractLegacy(void *);

EXTERN_C OCRUTILSLEGACY_API
void copyTextAndCleanupLegacy(char * src, uint8_T * dest, const size_t length);

EXTERN_C OCRUTILSLEGACY_API
int32_T getTextFromMetadataLegacy(void * ocrMetadata, char ** utf8Text);

EXTERN_C OCRUTILSLEGACY_API
void cleanupMetadataLegacy(void *);

EXTERN_C OCRUTILSLEGACY_API
void collectMetadataLegacy(void * tessAPI, void ** ocrMetadata,
                     int32_T * numChars, int32_T * numWords, int32_T * numTextLines,
                     int32_T * numParagraphs, int32_T * numBlocks);

EXTERN_C OCRUTILSLEGACY_API
void copyMetadataLegacy(void * ocrMetadata,
                  double * charBBox,
                  int32_T * charWordIndex,
                  float * charConfidence,
                  double * wordBBox,
                  int32_T * wordTextLineIndex,
                  float * wordConfidence,
                  int32_T * wordCharacterIndex,
                  double * textlineBBox,
                  int32_T * textlineParagraphIndex,
                  float * textlineConfidence,
                  int32_T * textlineCharacterIndex,
                  double * paragraphBBox,
                  int32_T * paragraphBlockIndex,
                  float * paragraphConfidence,
                  int32_T * paragraphCharacterIndex,
                  double * blockBBox,
                  int32_T * blockPageIndex,
                  float * blockConfidence,
                  int32_T * blockCharacterIndex);
#endif  


