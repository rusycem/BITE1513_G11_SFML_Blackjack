#ifndef SFML_GLYPH_HPP
#define SFML_GLYPH_HPP

// Headers
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Rect.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Structure describing a glyph
///
////////////////////////////////////////////////////////////
class SFML_GRAPHICS_API Glyph
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    Glyph() : advance(0) {}

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    float     advance;     //!< Offset to move horizontally to the next character
    int       lsbDelta;    //!< Left offset after forced autohint. Internally used by getKerning()
    int       rsbDelta;    //!< Right offset after forced autohint. Internally used by getKerning()
    FloatRect bounds;      //!< Bounding rectangle of the glyph, in coordinates relative to the baseline
    IntRect   textureRect; //!< Texture coordinates of the glyph inside the font's texture
};

} // namespace sf


#endif // SFML_GLYPH_HPP


////////////////////////////////////////////////////////////
/// \class sf::Glyph
/// \ingroup graphics
///
/// A glyph is the visual representation of a character.
///
/// The sf::Glyph structure provides the information needed
/// to handle the glyph:
/// \li its coordinates in the font's texture
/// \li its bounding rectangle
/// \li the offset to apply to get the starting position of the next glyph
///
/// \see sf::Font
///
////////////////////////////////////////////////////////////
