#ifndef TTFRNDR_H
#define TTFRNDR_H
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
extern FT_Library ftLib;

struct Glyph {
    int width, height;
    float u0, v0, u1, v1;
    int advance;
};

class TTFFont {
public:
    FT_Face face;
    std::map<char, Glyph> glyphs; // Кэш глифов
    bool Load(const char* path, int fontSize) {
        FT_Error err = FT_New_Face(ftLib, path, 0, &face);
        if (err) return false;
        FT_Set_Pixel_Sizes(face, 0, fontSize);
        return true;
    }
    void CacheGlyphs();
    void DrawTTFNumber(int x, int y, int iNumber, TTFFont& font);
    void DrawTTFString(int x, int y, const char* text, TTFFont& font);
};
#endif
