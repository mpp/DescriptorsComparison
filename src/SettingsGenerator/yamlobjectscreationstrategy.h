/*!
 * \file yamlobjectscreationstrategy.h
 * \author Michele Marostica
 * \brief This class define the set of strategies that are available for the build of
 *        YAML parameterized objects. Here a factory pattern does not make sense because
 *        all the objects are of the same type.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Michele Marostica - michele[dot]marostica[at]dei[dot]unipd[dot]it
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef YAMLOBJECTSCREATIONSTRATEGY_H
#define YAMLOBJECTSCREATIONSTRATEGY_H

#include <vector>
#include <functional>

#include <opencv2/opencv.hpp>

#include "yamlparameterizedobject.h"

namespace sgt {

typedef YAMLParameterizedObject KeyPointDetector;
typedef YAMLParameterizedObject DescriptorExtractor;

void defaultCreateFromYAMLFunction(const cv::FileStorage &fs,
                                   std::vector<YAMLParameterizedObject::ConstPtr> &vector);

class YAMLObjectsCreator
{

public:

    typedef std::function< void (const cv::FileStorage&,
                                 std::vector<YAMLParameterizedObject::ConstPtr>&) > CreateFromYAMLFunction ;

    explicit YAMLObjectsCreator(CreateFromYAMLFunction cfy_f = defaultCreateFromYAMLFunction)
        : create_function_(cfy_f) {}

    /*!
     * \brief createYAMLParameterizedObjects add the created objects to the vector
     * \param [in] fs
     * \param [out] vector
     */
    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<YAMLParameterizedObject::ConstPtr> &vector) const;

private:

    CreateFromYAMLFunction create_function_;

};

/*****************************************************************************
 * SIFT detector and extractor                                               *
 *****************************************************************************/

void SIFTDetectorsFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector);

void SIFTExtractorsFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector);

/*****************************************************************************
 * SURF detector and extractor                                               *
 *****************************************************************************/

void SURFDetectorsFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector);

void SURFExtractorsFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector);

/*****************************************************************************
 * ORB detector and extractor                                                *
 *****************************************************************************/
void ORBDetectorsFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector);

void ORBExtractorsFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector);

/*****************************************************************************
 * BRISK detector and extractor                                              *
 *****************************************************************************/
void BRISKDetectorsFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector);

void BRISKExtractorsFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector);

/*****************************************************************************
 * FAST detector                                                             *
 *****************************************************************************/
void FASTDetectorsFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector);

/*****************************************************************************
 * MSER detector                                                             *
 *****************************************************************************/
void MSERDetectorsFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector);

/*****************************************************************************
 * STAR detector                                                             *
 *****************************************************************************/
void STARDetectorsFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector);

/*****************************************************************************
 * GFTT detector                                                             *
 *****************************************************************************/
void GFTTDetectorsFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector);

/*****************************************************************************
 * FREAK extractor                                                           *
 *****************************************************************************/
void FREAKExtractorsFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector);

/*****************************************************************************
 * BRIEF extractor                                                           *
 *****************************************************************************/
void BRIEFExtractorsFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector);

} // namespace sgt

#endif // YAMLOBJECTSCREATIONSTRATEGY_H
