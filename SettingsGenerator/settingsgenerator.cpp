/**
 * \file settingsgenerator.cpp
 * \Author: Michele Marostica
 *  
 * Copyright (c) 2012, Michele Marostica (michelemaro@gmail.com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * 1 - Redistributions of source code must retain the above copyright notice, 
 *     this list of conditions and the following disclaimer.
 * 2 - Redistributions in binary form must reproduce the above copyright 
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "settingsgenerator.h"

#include <boost/lexical_cast.hpp>

// void closeFS(cv::FileStorage &fs, std::string &fsString)
// {
//     
// }

SettingsGenerator::SettingsGenerator(cv::FileStorage settingParameters, std::string outputPath)
{
    
    cv::FileStorage 
        actualFS;
    
    std::vector<std::string> DetectorType;
    settingParameters["FeatureOptions"]["DetectorType"] >> DetectorType;
    
    std::vector<std::string> DetectorMode;
    settingParameters["FeatureOptions"]["DetectorMode"] >> DetectorMode;
    
    std::vector<float> Epsilon;
    settingParameters["NNDR"]["epsilon"] >> Epsilon;
    
    std::vector<std::string> ExtractorType;
    settingParameters["FeatureOptions"]["ExtractorType"] >> ExtractorType;
    
    int 
        fileCounter = 0;
    
    for (size_t e_t = 0; e_t < ExtractorType.size(); e_t++)
    {   
        for (size_t e_p = 0; e_p < Epsilon.size(); e_p++)
        {   
            for (std::vector<std::string>::iterator it_DetectorType = DetectorType.begin(); it_DetectorType != DetectorType.end(); it_DetectorType++)
            {
                std::string 
                    detectorType = (*it_DetectorType);
                
                for (std::vector<std::string>::iterator it_DetectorMode = DetectorMode.begin(); it_DetectorMode != DetectorMode.end(); it_DetectorMode++)
                {
                    std::string 
                        detectorMode = (*it_DetectorMode);
                    
                    if (detectorMode == "ADAPTIVE")
                    {
                        // Adaptive Detectors only work with STAR, SURF and FAST
                        if (detectorType == "FAST" || detectorType == "SURF" || detectorType == "STAR")
                        {
                            std::vector<int> 
                                MinFeatures,
                                MaxFeatures,
                                MaxIters;
                            
                            settingParameters["FeatureOptions"]["Adaptive"]["MinFeatures"] >> MinFeatures;
                            settingParameters["FeatureOptions"]["Adaptive"]["MaxFeatures"] >> MaxFeatures;
                            settingParameters["FeatureOptions"]["Adaptive"]["MaxIters"] >> MaxIters;
                            
                            for (size_t a = 0; a < MinFeatures.size(); a++)
                            {
                                for(size_t b = 0; b < MaxFeatures.size(); b++)
                                {
                                    for(size_t c = 0; c < MaxIters.size(); c++)
                                    {
                                        std::string filename = "file_"+boost::lexical_cast<std::string>(fileCounter++)+".yml";
                                        actualFS = cv::FileStorage(outputPath+filename, cv::FileStorage::WRITE);
                                        
                                        actualFS << "NNDR" << "{";
                                            actualFS << "epsilon" << Epsilon[e_p];
                                        actualFS << "}";
                                        
                                        actualFS << "FeatureOptions" << "{";
                                            actualFS << "DetectorType" << detectorType;
                                            actualFS << "DetectorMode" << detectorMode;
                                            actualFS << "Adaptive" << "{";
                                                actualFS << "MinFeatures" << MinFeatures[a];
                                                actualFS << "MaxFeatures" << MaxFeatures[b];
                                                actualFS << "MaxIters" << MaxIters[c];
                                            actualFS << "}";
                                            actualFS << "ExtractorType" << ExtractorType[e_t];
                                        actualFS << "}";
                                        
                                        actualFS.release();
                                    }
                                }
                            }
                        }
                    }
                    else // "STATIC"
                    {
                        if (detectorType == "FAST")
                        {
                            std::vector<int> 
                                Threshold, NonMaxSuppression;
                            
                            settingParameters["FeatureOptions"]["FastDetector"]["Threshold"] >> Threshold;
                            settingParameters["FeatureOptions"]["FastDetector"]["NonMaxSuppression"] >> NonMaxSuppression;
                            
                            for (size_t a = 0; a < Threshold.size(); a++)
                            {
                                for(size_t b = 0; b < NonMaxSuppression.size(); b++)
                                {
                                    std::string filename = "file_"+boost::lexical_cast<std::string>(fileCounter++)+".yml";
                                    actualFS = cv::FileStorage(outputPath+filename, cv::FileStorage::WRITE);
                                    
                                    actualFS << "NNDR" << "{";
                                        actualFS << "epsilon" << Epsilon[e_p];
                                    actualFS << "}";
                                        
                                    actualFS << "FeatureOptions" << "{";
                                        actualFS << "DetectorType" << detectorType;
                                        actualFS << "DetectorMode" << detectorMode;
                                        actualFS << "FastDetector" << "{";
                                            actualFS << "Threshold" << Threshold[a];
                                            actualFS << "NonMaxSuppression" << NonMaxSuppression[b];
                                        actualFS << "}";
                                    actualFS << "ExtractorType" << ExtractorType[e_t];
                                    actualFS << "}";
                                            
                                    actualFS.release();
                                }
                            }
                        }
                        else if (detectorType == "SURF")
                        {
                            std::vector<int> 
                                HessianThreshold, NumOctaves, NumOctaveLayers, Upright, Extended;
                            
                            settingParameters["FeatureOptions"]["SurfDetector"]["HessianThreshold"] >> HessianThreshold;
                            settingParameters["FeatureOptions"]["SurfDetector"]["NumOctaves"] >> NumOctaves;
                            settingParameters["FeatureOptions"]["SurfDetector"]["NumOctaveLayers"] >> NumOctaveLayers;
                            settingParameters["FeatureOptions"]["SurfDetector"]["Extended"] >> Extended;
                            settingParameters["FeatureOptions"]["SurfDetector"]["Upright"] >> Upright;
                            
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
                                                std::string filename = "file_"+boost::lexical_cast<std::string>(fileCounter++)+".yml";
                                                actualFS = cv::FileStorage(outputPath+filename, cv::FileStorage::WRITE);
                                                
                                                actualFS << "NNDR" << "{";
                                                    actualFS << "epsilon" << Epsilon[e_p];
                                                actualFS << "}";
                                                
                                                actualFS << "FeatureOptions" << "{";
                                                    actualFS << "DetectorType" << detectorType;
                                                    actualFS << "DetectorMode" << detectorMode;
                                                    actualFS << "SurfDetector" << "{";
                                                        actualFS << "HessianThreshold" << HessianThreshold[a];
                                                        actualFS << "NumOctaves" << NumOctaves[b];
                                                        actualFS << "NumOctaveLayers" << NumOctaveLayers[c];
                                                        actualFS << "Extended" << Extended[d];
                                                        actualFS << "Upright" << Upright[e];
                                                    actualFS << "}";
                                                actualFS << "ExtractorType" << ExtractorType[e_t];
                                                actualFS << "}";
                                                
                                                actualFS.release();
                                            }
                                        }
                                    }
                                }
                            }
                        }   
                        else if (detectorType == "SIFT")
                        {
                            std::vector<int> 
                                NumFeatures, NumOctaveLayers, EdgeThreshold;
                            std::vector<double> 
                                ContrastThreshold, Sigma;
                            
                            settingParameters["FeatureOptions"]["SiftDetector"]["NumFeatures"] >> NumFeatures;
                            settingParameters["FeatureOptions"]["SiftDetector"]["NumOctaveLayers"] >> NumOctaveLayers;
                            settingParameters["FeatureOptions"]["SiftDetector"]["ContrastThreshold"] >> ContrastThreshold;
                            settingParameters["FeatureOptions"]["SiftDetector"]["EdgeThreshold"] >> EdgeThreshold;
                            settingParameters["FeatureOptions"]["SiftDetector"]["Sigma"] >> Sigma;
                            
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
                                                std::string filename = "file_"+boost::lexical_cast<std::string>(fileCounter++)+".yml";
                                                actualFS = cv::FileStorage(outputPath+filename, cv::FileStorage::WRITE);
                                                
                                                actualFS << "NNDR" << "{";
                                                    actualFS << "epsilon" << Epsilon[e_p];
                                                actualFS << "}";
                                                
                                                actualFS << "FeatureOptions" << "{";
                                                    actualFS << "DetectorType" << detectorType;
                                                    actualFS << "DetectorMode" << detectorMode;
                                                    actualFS << "SiftDetector" << "{";
                                                        actualFS << "NumFeatures" << NumFeatures[a];
                                                        actualFS << "ContrastThreshold" << ContrastThreshold[b];
                                                        actualFS << "NumOctaveLayers" << NumOctaveLayers[c];
                                                        actualFS << "EdgeThreshold" << EdgeThreshold[d];
                                                        actualFS << "Sigma" << Sigma[e];
                                                    actualFS << "}";
                                                actualFS << "ExtractorType" << ExtractorType[e_t];
                                                actualFS << "}";
                                                
                                                actualFS.release();
                                            }
                                        }
                                    }
                                }
                            }
                        }   
                        else if (detectorType == "STAR")
                        {
                            std::vector<int>
                                MaxSize, Response, LineThreshold, LineBinarized, Suppression;
                            settingParameters["FeatureOptions"]["StarDetector"]["MaxSize"] >> MaxSize;
                            settingParameters["FeatureOptions"]["StarDetector"]["Response"] >> Response;
                            settingParameters["FeatureOptions"]["StarDetector"]["LineThreshold"] >> LineThreshold;
                            settingParameters["FeatureOptions"]["StarDetector"]["LineBinarized"] >> LineBinarized;
                            settingParameters["FeatureOptions"]["StarDetector"]["Suppression"] >> Suppression;
                            
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
                                                std::string filename = "file_"+boost::lexical_cast<std::string>(fileCounter++)+".yml";
                                                actualFS = cv::FileStorage(outputPath+filename, cv::FileStorage::WRITE);
                                                
                                                actualFS << "NNDR" << "{";
                                                    actualFS << "epsilon" << Epsilon[e_p];
                                                actualFS << "}";
                                                
                                                actualFS << "FeatureOptions" << "{";
                                                    actualFS << "DetectorType" << detectorType;
                                                    actualFS << "DetectorMode" << detectorMode;
                                                    actualFS << "StarDetector" << "{";
                                                        actualFS << "MaxSize" << MaxSize[a];
                                                        actualFS << "Response" << Response[b];
                                                        actualFS << "LineThreshold" << LineThreshold[c];
                                                        actualFS << "LineBinarized" << LineBinarized[d];
                                                        actualFS << "Suppression" << Suppression[e];
                                                    actualFS << "}";
                                                actualFS << "ExtractorType" << ExtractorType[e_t];
                                                actualFS << "}";
                                                
                                                actualFS.release();
                                            }
                                        }
                                    }
                                }
                            }
                        }   
                        else if (detectorType == "MSER")
                        {
                        }   
                    }
                }
            }
        }
    }
}

