#pragma once

namespace mycge
{
    namespace gui
    {
        template<typename T>
        class Position2D;

        template<typename T>
        class Dimension2D
        {
        public:
            //! Default constructor for empty dimension
            Dimension2D() : Width(0), Height(0) 
            {
            }
            //! Constructor with width and height
            Dimension2D( const T& width, const T& height )
                : Width( width ), 
                  Height( height ) 
            {
            }

            Dimension2D( const Position2D<T>& other ); // Defined in Position2D.h

            //! Use this constructor only where you are sure that the conversion is valid.
            template <typename U>
            explicit Dimension2D( const Dimension2D<U>& other ) :
            Width((T)other.Width), Height((T)other.Height) { }

            template <typename U>
            Dimension2D<T>& operator=(const Dimension2D<U>& other)
            { 
                Width = (T)other.Width;
                Height = (T)other.Height;
                return *this;
            }


            //! Equality operator
            bool operator==( const Dimension2D<T>& other ) const
            {
                return Width == other.Width && Height == other.Height;
            }

            //! Inequality operator
            bool operator!=( const Dimension2D<T>& other ) const
            {
                return ! (*this == other);
            }

            bool operator==( const Position2D<T>& other ) const;  // Defined in Position2D.h

            bool operator!=( const Position2D<T>& other ) const
            {
                return !(*this == other);
            }

            //! Set to new values
            Dimension2D<T>& Set( const T& width, const T& height )
            {
                Width = width;
                Height = height;
                return *this;
            }

            //! Divide width and height by scalar
            Dimension2D<T>& operator/=( const T& scale )
            {
                Width /= scale;
                Height /= scale;
                return *this;
            }

            //! Divide width and height by scalar
            Dimension2D<T> operator/( const T& scale ) const
            {
                return Dimension2D<T>( Width/scale, Height/scale );
            }

            //! Multiply width and height by scalar
            Dimension2D<T>& operator*=( const T& scale )
            {
                Width *= scale;
                Height *= scale;
                return *this;
            }

            //! Multiply width and height by scalar
            Dimension2D<T> operator*( const T& scale ) const
            {
                return Dimension2D<T>( Width*scale, Height*scale );
            }

            //! Add another dimension to this one.
            Dimension2D<T>& operator+=( const Dimension2D<T>& other )
            {
                Width += other.Width;
                Height += other.Height;
                return *this;
            }

            //! Subtract a dimension from this one
            Dimension2D<T>& operator-=( const Dimension2D<T>& other )
            {
                Width -= other.Width;
                Height -= other.Height;
                return *this;
            }


            //! Add two dimensions
            Dimension2D<T> operator+( const Dimension2D<T>& other ) const
            {
                return Dimension2D<T>( Width+other.Width, Height + other.Height );
            }

            //! Get area
            T GetArea() const
            {
                return Width * Height;
            }

            //! Get the optimal size according to some properties
            /** This is a function often used for texture dimension
            calculations. The function returns the next larger or
            smaller dimension which is a power-of-two dimension
            (2^n,2^m) and/or square (Width=Height).
            \param requirePowerOfTwo Forces the result to use only
            powers of two as values.
            \param requireSquare Makes width==height in the result
            \param larger Choose whether the result is larger or
            smaller than the current dimension. If one dimension
            need not be changed it is kept with any value of larger.
            \param maxValue Maximum texturesize. if value > 0 size is
            clamped to maxValue
            \return The optimal dimension under the given
            constraints. */
            Dimension2D<T> GetOptimalSize(
                bool bRequirePowerOfTwo = true,
                bool bRequireSquare = false,
                bool bLarger = true,
                unsigned int maxValue = 0 ) const
            {
                unsigned int i=1;
                unsigned int j=1;
                if ( bRequirePowerOfTwo )
                {
                    while ( i < (unsigned int)Width )
                    {
                        i <<= 1;
                    }

                    if ( !bLarger && i != 1 && i != (unsigned int)Width )
                    {
                        i >>= 1;
                    }

                    while ( j < (unsigned int)Height )
                    {
                        j <<= 1;
                    }

                    if ( !bLarger && j != 1 && j != (unsigned int)Height )
                    {
                        j >>= 1;
                    }

                }
                else
                {
                    i = (unsigned int)Width;
                    j = (unsigned int)Height;
                }

                if ( false != bRequireSquare )
                {
                    if (( bLarger && ( i > j )) || ( !bLarger && ( i < j )))
                    {
                        j = i;
                    }
                    else
                    {
                        i = j;
                    }
                }

                if ( maxValue > 0 && i > maxValue)
                {  
                    i = maxValue;
                }

                if ( maxValue > 0 && j > maxValue)
                {
                    j = maxValue;
                }

                return Dimension2D<T>( (T)i, (T)j );
            }

            //! Get the interpolated dimension
            /** \param other Other dimension to interpolate with.
            \param d Value between 0.0f and 1.0f.
            \return Interpolated dimension. */
            Dimension2D<T> GetInterpolated( const Dimension2D<T>& other, float d ) const
            {
                float inv = (1.0f - d);
                return Dimension2D<T>( (T)( other.Width * inv + Width * d ), (T)( other.Height * inv + Height * d ));
            }


            //! Width of the dimension.
            T Width;
            //! Height of the dimension.
            T Height;
        };

        //! Typedef for an float dimension.
        typedef Dimension2D<float> Dimension2Df;
        //! Typedef for an unsigned integer dimension.
        typedef Dimension2D<unsigned int> Dimension2Du;

        //! Typedef for an integer dimension.
        /** There are few cases where negative dimensions make sense. Please consider using
        Dimension2Du instead. */
        typedef Dimension2D<int> Dimension2Di;
    }
}