/*!
 * \file yamlobjectscreationstrategy.cpp
 * \author Michele Marostica
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
#include "yamlobjectscreationstrategy.h"

namespace sgt {

void SIFTDetectorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                  std::vector<KeyPointDetector::ConstPtr> &vector) const
{
    std::vector<std::string>
            NumFeatures,
            NumOctaveLayers,
            EdgeThreshold,
            ContrastThreshold,
            Sigma;

    fs["FeatureOptions"]["NumFeatures"] >> NumFeatures;
    fs["FeatureOptions"]["NumOctaveLayers"] >> NumOctaveLayers;
    fs["FeatureOptions"]["ContrastThreshold"] >> ContrastThreshold;
    fs["FeatureOptions"]["EdgeThreshold"] >> EdgeThreshold;
    fs["FeatureOptions"]["Sigma"] >> Sigma;

    for (size_t a = 0; a < NumFeatures.size(); a++)
    {
        for(size_t b = 0; b < ContrastThreshold.size(); b++)
        {
            for(size_t c = 0; c < NumOctaveLayers.size(); c++)
            {
                for(size_t d = 0; d < EdgeThreshold.size(); d++)
                {
                    for(size_t e = 0; e < Sigma.size(); e++)
                    {
                        std::string name = "SIFT";
                        parameters params;

                        params.insert(std::pair<param_name, param_value>("NumFeatures", NumFeatures[a]));
                        params.insert(std::pair<param_name, param_value>("ContrastThreshold", ContrastThreshold[b]));
                        params.insert(std::pair<param_name, param_value>("NumOctaveLayers", NumOctaveLayers[c]));
                        params.insert(std::pair<param_name, param_value>("EdgeThreshold", EdgeThreshold[d]));
                        params.insert(std::pair<param_name, param_value>("Sigma", Sigma[e]));

                        YAMLParameterizedObject obj(name, params);

                        vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
                    }
                }
            }
        }
    }
}

void SIFTDescriptorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                    std::vector<DescriptorExtractor::ConstPtr> &vector) const
{
    SIFTDetectorCreationStrategy s;
    s.createFromYAML(fs, vector);
}

void SURFDetectorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                  std::vector<KeyPointDetector::ConstPtr> &vector) const
{
    std::vector<std::string>
            HessianThreshold,
            NumOctaves,
            NumOctaveLayers,
            Upright,
            Extended;

    fs["FeatureOptions"]["HessianThreshold"] >> HessianThreshold;
    fs["FeatureOptions"]["NumOctaves"] >> NumOctaves;
    fs["FeatureOptions"]["NumOctaveLayers"] >> NumOctaveLayers;
    fs["FeatureOptions"]["Extended"] >> Extended;
    fs["FeatureOptions"]["Upright"] >> Upright;

    for (size_t a = 0; a < HessianThreshold.size(); a++)
    {
        for(size_t b = 0; b < NumOctaves.size(); b++)
        {
            for(size_t c = 0; c < NumOctaveLayers.size(); c++)
            {
                for(size_t d = 0; d < Extended.size(); d++)
                {
                    for(size_t e = 0; e < Upright.size(); e++)
                    {

                        std::string name = "SURF";
                        parameters params;

                        params.insert(std::pair<param_name, param_value>("HessianThreshold", HessianThreshold[a]));
                        params.insert(std::pair<param_name, param_value>("NumOctaves", NumOctaves[b]));
                        params.insert(std::pair<param_name, param_value>("NumOctaveLayers", NumOctaveLayers[c]));
                        params.insert(std::pair<param_name, param_value>("Extended", Extended[d]));
                        params.insert(std::pair<param_name, param_value>("Upright", Upright[e]));

                        YAMLParameterizedObject obj(name, params);

                        vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
                    }
                }
            }
        }
    }
}

void SURFDescriptorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                    std::vector<DescriptorExtractor::ConstPtr> &vector) const
{
    SURFDetectorCreationStrategy s;
    s.createFromYAML(fs, vector);
}

void FASTDetectorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                  std::vector<KeyPointDetector::ConstPtr> &vector) const
{
    std::vector<std::string>
            Threshold,
            NonMaxSuppression;

    fs["FeatureOptions"]["Threshold"] >> Threshold;
    fs["FeatureOptions"]["NonMaxSuppression"] >> NonMaxSuppression;

    for (size_t a = 0; a < Threshold.size(); a++)
    {
        for(size_t b = 0; b < NonMaxSuppression.size(); b++)
        {
            std::string name = "FAST";
            parameters params;

            params.insert(std::pair<param_name, param_value>("Threshold", Threshold[a]));
            params.insert(std::pair<param_name, param_value>("NonMaxSuppression", NonMaxSuppression[b]));

            YAMLParameterizedObject obj(name, params);

            vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
        }
    }
}

void STARDetectorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                  std::vector<KeyPointDetector::ConstPtr> &vector) const
{
    std::vector<std::string>
            MaxSize,
            Response,
            LineThreshold,
            LineBinarized,
            Suppression;

    fs["FeatureOptions"]["MaxSize"] >> MaxSize;
    fs["FeatureOptions"]["Response"] >> Response;
    fs["FeatureOptions"]["LineThreshold"] >> LineThreshold;
    fs["FeatureOptions"]["LineBinarized"] >> LineBinarized;
    fs["FeatureOptions"]["Suppression"] >> Suppression;

    for (size_t a = 0; a < MaxSize.size(); a++)
    {
        for(size_t b = 0; b < Response.size(); b++)
        {
            for(size_t c = 0; c < LineThreshold.size(); c++)
            {
                for(size_t d = 0; d < LineBinarized.size(); d++)
                {
                    for(size_t e = 0; e < Suppression.size(); e++)
                    {
                        std::string name = "STAR";
                        parameters params;

                        params.insert(std::pair<param_name, param_value>("MaxSize", MaxSize[a]));
                        params.insert(std::pair<param_name, param_value>("Response", Response[b]));
                        params.insert(std::pair<param_name, param_value>("LineThreshold", LineThreshold[c]));
                        params.insert(std::pair<param_name, param_value>("LineBinarized", LineBinarized[d]));
                        params.insert(std::pair<param_name, param_value>("Suppression", Suppression[e]));

                        YAMLParameterizedObject obj(name, params);

                        vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
                    }
                }
            }
        }
    }
}

void ORBDetectorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                 std::vector<KeyPointDetector::ConstPtr> &vector) const
{
    std::vector<std::string>
            nfeatures,
            scaleFactor,
            nlevels,
            edgeThreshold,
            WTA_K,
            scoreType,
            patchSize;

    fs["FeatureOptions"]["nfeatures"] >> nfeatures;
    fs["FeatureOptions"]["scaleFactor"] >> scaleFactor;
    fs["FeatureOptions"]["nlevels"] >> nlevels;
    fs["FeatureOptions"]["edgeThreshold"] >> edgeThreshold;
    fs["FeatureOptions"]["WTA_K"] >> WTA_K;
    fs["FeatureOptions"]["scoreType"] >> scoreType;
    fs["FeatureOptions"]["patchSize"] >> patchSize;

    for (size_t a = 0; a < nfeatures.size(); a++)
    {
        for(size_t b = 0; b < scaleFactor.size(); b++)
        {
            for(size_t c = 0; c < nlevels.size(); c++)
            {
                for(size_t d = 0; d < edgeThreshold.size(); d++)
                {
                    for(size_t e = 0; e < WTA_K.size(); e++)
                    {
                        for(size_t f = 0; f < scoreType.size(); f++)
                        {
                            for(size_t g = 0; g < patchSize.size(); g++)
                            {
                                std::string name = "ORB";
                                parameters params;

                                params.insert(std::pair<param_name, param_value>("nfeatures", nfeatures[a]));
                                params.insert(std::pair<param_name, param_value>("scaleFactor", scaleFactor[b]));
                                params.insert(std::pair<param_name, param_value>("nlevels", nlevels[c]));
                                params.insert(std::pair<param_name, param_value>("edgeThreshold", edgeThreshold[d]));
                                params.insert(std::pair<param_name, param_value>("WTA_K", WTA_K[e]));
                                params.insert(std::pair<param_name, param_value>("scoreType", scoreType[f]));
                                params.insert(std::pair<param_name, param_value>("patchSize", patchSize[g]));

                                YAMLParameterizedObject obj(name, params);

                                vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
                            }
                        }
                    }
                }
            }
        }
    }
}

void ORBDescriptorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                   std::vector<DescriptorExtractor::ConstPtr> &vector) const
{
    ORBDetectorCreationStrategy s;
    s.createFromYAML(fs, vector);
}

void BRISKDetectorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                   std::vector<KeyPointDetector::ConstPtr> &vector) const
{
    std::vector<std::string>
            thresh,
            octaves,
            patternScale;

    fs["FeatureOptions"]["thresh"] >> thresh;
    fs["FeatureOptions"]["octaves"] >> octaves;
    fs["FeatureOptions"]["patternScale"] >> patternScale;

    for (size_t a = 0; a < thresh.size(); a++)
    {
        for(size_t b = 0; b < octaves.size(); b++)
        {
            for(size_t c = 0; c < patternScale.size(); c++)
            {
                std::string name = "BRISK";
                parameters params;

                params.insert(std::pair<param_name, param_value>("thresh", thresh[a]));
                params.insert(std::pair<param_name, param_value>("octaves", octaves[b]));
                params.insert(std::pair<param_name, param_value>("patternScale", patternScale[c]));

                YAMLParameterizedObject obj(name, params);

                vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
            }
        }
    }
}

void BRISKDescriptorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                     std::vector<DescriptorExtractor::ConstPtr> &vector) const
{
    BRISKDetectorCreationStrategy s;
    s.createFromYAML(fs, vector);
}

void MSERDetectorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                  std::vector<KeyPointDetector::ConstPtr> &vector) const
{
    //int _delta, int _min_area, int _max_area,
    //float _max_variation, float _min_diversity,
    //int _max_evolution, double _area_threshold,
    //double _min_margin, int _edge_blur_size

    std::vector<std::string>
            delta,
            minArea,
            maxArea,
            maxVariation,
            minVariation,
            maxEvolution,
            areaThreshold,
            minMargin,
            edgeBlurSize;

    fs["FeatureOptions"]["delta"] >> delta;
    fs["FeatureOptions"]["minArea"] >> minArea;
    fs["FeatureOptions"]["maxVariation"] >> maxVariation;
    fs["FeatureOptions"]["minVariation"] >> minVariation;
    fs["FeatureOptions"]["maxEvolution"] >> maxEvolution;
    fs["FeatureOptions"]["areaThreshold"] >> areaThreshold;
    fs["FeatureOptions"]["minMargin"] >> minMargin;
    fs["FeatureOptions"]["maxArea"] >> maxArea;
    fs["FeatureOptions"]["edgeBlurSize"] >> edgeBlurSize;

    for (size_t a = 0; a < delta.size(); a++)
    {
        for(size_t b = 0; b < minArea.size(); b++)
        {
            for(size_t c = 0; c < maxVariation.size(); c++)
            {
                for(size_t d = 0; d < minVariation.size(); d++)
                {
                    for(size_t e = 0; e < maxEvolution.size(); e++)
                    {
                        for(size_t f = 0; f < areaThreshold.size(); f++)
                        {
                            for(size_t g = 0; g < minMargin.size(); g++)
                            {
                                for(size_t h = 0; h < maxArea.size(); h++)
                                {
                                    for(size_t i = 0; i < edgeBlurSize.size(); i++)
                                    {
                                        std::string name = "MSER";
                                        parameters params;

                                        params.insert(std::pair<param_name, param_value>("delta", delta[a]));
                                        params.insert(std::pair<param_name, param_value>("minArea", minArea[b]));
                                        params.insert(std::pair<param_name, param_value>("maxVariation", maxVariation[c]));
                                        params.insert(std::pair<param_name, param_value>("minVariation", minVariation[d]));
                                        params.insert(std::pair<param_name, param_value>("maxEvolution", maxEvolution[e]));
                                        params.insert(std::pair<param_name, param_value>("areaThreshold", areaThreshold[f]));
                                        params.insert(std::pair<param_name, param_value>("minMargin", minMargin[g]));
                                        params.insert(std::pair<param_name, param_value>("maxArea", maxArea[h]));
                                        params.insert(std::pair<param_name, param_value>("edgeBlurSize", edgeBlurSize[i]));

                                        YAMLParameterizedObject obj(name, params);

                                        vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void GFTTDetectorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                  std::vector<KeyPointDetector::ConstPtr> &vector) const
{
    // int maxCorners=1000, double qualityLevel=0.01,
    // double minDistance=1., int blockSize=3,
    // bool useHarrisDetector=false, double k=0.04


    std::vector<std::string>
            maxCorners,
            qualityLevel,
            minDistance,
            blockSize,
            useHarrisDetector,
            k;

    fs["FeatureOptions"]["maxCorners"] >> maxCorners;
    fs["FeatureOptions"]["qualityLevel"] >> qualityLevel;
    fs["FeatureOptions"]["minDistance"] >> minDistance;
    fs["FeatureOptions"]["blockSize"] >> blockSize;
    fs["FeatureOptions"]["useHarrisDetector"] >> useHarrisDetector;
    fs["FeatureOptions"]["k"] >> k;

    for (size_t a = 0; a < maxCorners.size(); a++)
    {
        for(size_t b = 0; b < qualityLevel.size(); b++)
        {
            for(size_t c = 0; c < minDistance.size(); c++)
            {
                for(size_t d = 0; d < blockSize.size(); d++)
                {
                    for(size_t e = 0; e < useHarrisDetector.size(); e++)
                    {
                        for(size_t f = 0; f < k.size(); f++)
                        {
                            std::string name = "GFTT";
                            parameters params;

                            params.insert(std::pair<param_name, param_value>("maxCorners", maxCorners[a]));
                            params.insert(std::pair<param_name, param_value>("qualityLevel", qualityLevel[b]));
                            params.insert(std::pair<param_name, param_value>("minDistance", minDistance[c]));
                            params.insert(std::pair<param_name, param_value>("blockSize", blockSize[d]));
                            params.insert(std::pair<param_name, param_value>("useHarrisDetector", useHarrisDetector[e]));
                            params.insert(std::pair<param_name, param_value>("k", k[f]));
                            YAMLParameterizedObject obj(name, params);

                            vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
                        }
                    }
                }
            }
        }
    }
}

void FREAKDescriptorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                     std::vector<DescriptorExtractor::ConstPtr> &vector) const
{
    //bool orientationNormalized=true, bool scaleNormalized=true, float patternScale=22.0f, int nOctaves=4
    std::vector<std::string>
            orientationNormalized,
            scaleNormalized,
            patternScale,
            nOctaves;

    fs["FeatureOptions"]["orientationNormalized"] >> orientationNormalized;
    fs["FeatureOptions"]["scaleNormalized"] >> scaleNormalized;
    fs["FeatureOptions"]["patternScale"] >> patternScale;
    fs["FeatureOptions"]["nOctaves"] >> nOctaves;

    for (size_t a = 0; a < orientationNormalized.size(); a++)
    {
        for(size_t b = 0; b < scaleNormalized.size(); b++)
        {
            for(size_t c = 0; c < patternScale.size(); c++)
            {
                for(size_t d = 0; d < nOctaves.size(); d++)
                {
                    std::string name = "FREAK";
                    parameters params;

                    params.insert(std::pair<param_name, param_value>("orientationNormalized", orientationNormalized[a]));
                    params.insert(std::pair<param_name, param_value>("scaleNormalized", scaleNormalized[b]));
                    params.insert(std::pair<param_name, param_value>("patternScale", patternScale[c]));
                    params.insert(std::pair<param_name, param_value>("nOctaves", nOctaves[d]));

                    YAMLParameterizedObject obj(name, params);

                    vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
                }
            }
        }
    }
}

void BRIEFDescriptorCreationStrategy::createFromYAML(const cv::FileStorage &fs,
                                                     std::vector<DescriptorExtractor::ConstPtr> &vector) const
{
    // bytes is a length of descriptor in bytes. It can be equal 16, 32 or 64 bytes.

    std::vector<std::string>
            bytes;

    fs["FeatureOptions"]["bytes"] >> bytes;

    for (size_t a = 0; a < bytes.size(); a++)
    {
        std::string name = "BRIEF";
        parameters params;

        params.insert(std::pair<param_name, param_value>("bytes", bytes[a]));

        YAMLParameterizedObject obj(name, params);

        vector.push_back(std::make_shared<const YAMLParameterizedObject>(obj));
    }
}

}
