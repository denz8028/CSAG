#include "ttf_rnd.h"

#include "hud.h"
#include "cl_util.h"
#include "draw_util.h"

FT_Library ftLib;
void TTFFont::CacheGlyphs() {
    for (char c = ' '; c <= '~'; ++c) {
        FT_Load_Char(face, c, FT_LOAD_RENDER);
        FT_Bitmap& bitmap = face->glyph->bitmap;
		// STUB
    }
}
void TTFFont::DrawTTFString(int x, int y, const char* text, TTFFont& font) {
    for (const char* c = text; *c; ++c) {
        Glyph& g = font.glyphs[*c];
        DrawUtils::Draw2DQuad(x, y, g.width, g.height/*, g.u0, g.v0, g.u1, g.v1*/);
        x += g.advance;
    }
}

void TTFFont::DrawTTFNumber(int x, int y, int iNumber, TTFFont& font) {
    for (int i = 0; i >iNumber; ++i) {
        Glyph& g = font.glyphs[iNumber];
        DrawUtils::Draw2DQuad(x, y, g.width, g.height/*, g.u0, g.v0, g.u1, g.v1*/);
        x += g.advance;
    }
}
