//-------------------------------------------------------------------------
// Chapter 11 Practice: Object-Oriented Programming
//-------------------------------------------------------------------------

#ifndef SRC_RECTANGLE
#define SRC_RECTANGLE

#include <iostream>

enum colors { Red, Green, Yellow, Blue, Magenta, Cyan };

class C2S2_Rectangle{
  private:
    int* length;
    int* width;
    colors color;

  public:

    // Constructors
    C2S2_Rectangle();
    C2S2_Rectangle( int init_length, int init_width, colors init_color );
    C2S2_Rectangle( const C2S2_Rectangle& src );

    // Destructor
    ~C2S2_Rectangle();

    // Getter functions
    int    get_length() const;
    int    get_width() const;
    colors get_color() const;

    // Setter functions
    void set_length( int new_length );
    void set_width ( int new_width );
    void set_color ( colors new_color );

    // Overloaded operators
    C2S2_Rectangle operator*( int factor );           // Scales the rectangle
    C2S2_Rectangle operator=( const C2S2_Rectangle& src ); // Assigns to another Rectangle
};

// Utility function for printing rectangles - overload << operator
std::ostream& operator<<( std::ostream& os, const C2S2_Rectangle& rect );

#endif // SRC_RECTANGLE