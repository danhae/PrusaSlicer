#ifndef PNGREAD_HPP
#define PNGREAD_HPP

#include <vector>
#include <string>

namespace Slic3r { namespace png {

struct ReadBuf { const void *buf = nullptr; const size_t sz = 0; };

template<class PxT> struct Image {
    std::vector<PxT> buf;
    size_t rows, cols;
    PxT get(size_t row, size_t col) const { return buf[row * cols + col]; }
};

struct RGB { uint8_t r, g, b; };

using ImageRGB = Image<RGB>;
using ImageGreyscale = Image<uint8_t>;

bool is_png(const ReadBuf &pngbuf);

// Only decodes true 8 bit grayscale png images. Returns false for other formats
// TODO: implement transformation of rgb images into grayscale...
bool decode_png(const ReadBuf &pngbuf, ImageGreyscale &img);

// TODO
// bool decode_png(Buffer &&pngbuf, ImageRGB &img);

}}
#endif // PNGREAD_HPP
