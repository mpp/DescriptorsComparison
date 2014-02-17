#include <iostream>
#include <locale>
#include <fstream>
#include <iomanip>

//#include "SettingsGenerator/settingsgenerator.h"

#include "SettingsGenerator/yamlobjectscreationstrategy.h"

/** Displays the usage message
 */
int help(void)
{
    std::cout << "Usage: descriptorscomparison -s <settings.yml> -p <output_path>" << std::endl;
    return 0;
}

int main(int argc, char **argv) {
    
    /////////////////////////////    
    /// Check arguments
    
    if (argc != 5)
    {
        help();
        exit(-1);
    }
    
    if (std::string(argv[1]) != "-s" || std::string(argv[3]) != "-p")
    {
        help();
        exit(-1);
    }
    
    std::cout << std::fixed << std::setprecision(6);
    setlocale(LC_NUMERIC, "C");
    
    
    /////////////////////////////    
    /// Open input files
    
    std::string 
        settFileName = argv[2],
        outputPath = argv[4];
    
    cv::FileStorage 
        fs;
    
    fs.open(settFileName, cv::FileStorage::READ);
    
    if (!fs.isOpened()) 
    {
        std::cerr << "Could not open settings file: " << settFileName << std::endl;
        exit(-1);
    }
    
    //SettingsGenerator sg(fs, outputPath);
    std::vector<sgt::YAMLParameterizedObject::ConstPtr> vector;

    sgt::YAMLObjectsCreator yoc;
    yoc.createFromYAML(fs,vector);

    std::cout << vector.size() << std::endl;

    return 0;
}

