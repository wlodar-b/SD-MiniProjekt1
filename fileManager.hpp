#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <utility>
#include <vector>

class FileManager {
public:
    static bool saveMeasurements(
        const std::string& structureName,
        int structureSize,
        int measurementCount,
        const std::vector<std::pair<std::string, long long>>& results,
        const std::string& fileName = "pomiary.txt"
    );
};

#endif
