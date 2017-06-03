#include <valve/hl1bspasset.h>
#include <valve/filesystem.h>
#include <iostream>

int main(int argc, char* argv[])
{
    valve::hl1::BspAsset asset(valve::FileSystem::LocateDataFile, valve::FileSystem::LoadFileData);

    if (argc > 1 && asset.Load(argv[argc-1]))
    {
        int planeCount = asset._planeData.count;
        std::cout << "Map loaded" << std::endl;
    }
    else
    {
        std::cout << "Unable to load map" << std::endl;
    }

    return 0;
}
