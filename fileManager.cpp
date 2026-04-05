#include "fileManager.hpp"

#include <fstream>

bool FileManager::saveMeasurements(
    const std::string& structureName,
    int structureSize,
    int measurementCount,
    const std::vector<std::pair<std::string, long long>>& results,
    const std::string& fileName
) {
    std::ofstream file(fileName, std::ios::app);
    if (!file.is_open()) {
        return false;
    }

    file << "========================================\n";
    file << "Struktura: " << structureName << '\n';
    file << "Rozmiar: " << structureSize << '\n';
    file << "Liczba pomiarow: " << measurementCount << '\n';

    for (const auto& result : results) {
        file << result.first << ": " << result.second << " ns\n";
    }

    file << '\n';
    return true;
}
