#ifndef HEIGHTMAP
#define HEIGHTMAP

typedef struct {

    // xy dimensions (size = width * height)
    unsigned int width, height;
    unsigned long size;

    unsigned int depth;

    // z dimensions (range = max - min = relief)
    unsigned char min, max, range;

    // raster with size pixels ranging in value from min to max
    unsigned char *data;

} Heightmap;

Heightmap* ReadHeightmap(const char *path);
void ScanHeightmap(Heightmap *hm);
int HeightmapToSTL(Heightmap *hm);
void FreeHeightmap(Heightmap **hm);

#endif // HEIGHTMAP

