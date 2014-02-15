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

#include <opencv2/opencv.hpp>

#include "yamlparameterizedobject.h"

namespace sgt {

class YAMLObjectsCreationStrategy
{

public:

    /*!
     * \brief createYAMLParameterizedObjects add the created objects to the vector
     * \param [in] fs
     * \param [out] vector
     */
    virtual void createFromYAML(const cv::FileStorage &fs,
                                std::vector<YAMLParameterizedObject::ConstPtr> &vector ) const = 0;

};

typedef YAMLParameterizedObject KeyPointDetector;
typedef YAMLParameterizedObject DescriptorExtractor;

/*****************************************************************************
 * SIFT detector and extractor                                               *
 *****************************************************************************/

class SIFTDetectorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    SIFTDetectorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector) const;
};

class SIFTDescriptorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    SIFTDescriptorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector) const;
};


/*****************************************************************************
 * SURF detector and extractor                                               *
 *****************************************************************************/

class SURFDetectorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    SURFDetectorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector) const;
};

class SURFDescriptorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    SURFDescriptorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector) const;
};


/*****************************************************************************
 * ORB detector and extractor                                                *
 *****************************************************************************/

class ORBDetectorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    ORBDetectorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector) const;
};

class ORBDescriptorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    ORBDescriptorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector) const;
};


/*****************************************************************************
 * BRISK detector and extractor                                              *
 *****************************************************************************/

class BRISKDetectorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    BRISKDetectorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector) const;
};

class BRISKDescriptorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    BRISKDescriptorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector) const;
};


/*****************************************************************************
 * FAST detector                                                             *
 *****************************************************************************/

class FASTDetectorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    FASTDetectorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector) const;
};


/*****************************************************************************
 * MSER detector                                                             *
 *****************************************************************************/

class MSERDetectorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    MSERDetectorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector) const;
};


/*****************************************************************************
 * STAR detector                                                             *
 *****************************************************************************/

class STARDetectorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    STARDetectorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector) const;
};


/*****************************************************************************
 * GFTT detector                                                             *
 *****************************************************************************/

class GFTTDetectorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    GFTTDetectorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<KeyPointDetector::ConstPtr> &vector) const;
};


/*****************************************************************************
 * FREAK extractor                                                           *
 *****************************************************************************/

class FREAKDescriptorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    FREAKDescriptorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector) const;
};


/*****************************************************************************
 * BRIEF extractor                                                           *
 *****************************************************************************/

class BRIEFDescriptorCreationStrategy : public YAMLObjectsCreationStrategy
{
public:
    BRIEFDescriptorCreationStrategy() {}

    void createFromYAML(const cv::FileStorage &fs,
                        std::vector<DescriptorExtractor::ConstPtr> &vector) const;
};

} // namespace sgt

#endif // YAMLOBJECTSCREATIONSTRATEGY_H
