#pragma once

namespace mycge
{
    namespace gui
    {
        template<typename T>
        class Position2D
        {
        public:
            Position2D()
                :X( 0 ),
                 Y( 0 )
            {

            }

            Position2D( T x, T y )
                :X( x ),
                 Y( y )
            {

            }

            explicit Position2D( T n )
                :X( n ),
                 Y( n )
            {

            }

            Position2D( const Position2D<T>& rhs )
                :X( rhs.X ),
                 Y( rhs.Y )
            {

            }

            Position2D<T> operator-() const
            {
                return Position2D<T>( -X, -Y );
            }

            Position2D<T>& operator=( const Position2D<T>& rhs )
            {
                if ( &rhs == this )
                {
                    return *this;
                }

                X = rhs.X;
                Y = rhs.Y;

                return *this;
            }

            Position2D<T> operator+( const Position2D<T>& rhs )
            {
                return Position2D<T>( X + rhs.X, Y + rhs.Y );
            }

            Position2D<T>& operator+=( const Position2D<T>& rhs )
            {
                X += rhs.X;
                Y += rhs.Y;

                return *this;
            }

            Position2D<T> operator+( T n )
            {
                return Position2D<T>( X + n, Y + n );
            }

            Position2D<T>& operator+=( T n )
            {
                X += n;
                Y += n;

                return *this;
            }

        public:
            T GetX() const
            {
                return X;
            }

            T GetY() const
            {
                return Y;
            }

        private:
            T X;

            T Y;
        };

        typedef Position2D<int> Position2DInt;

        typedef Position2D<float> Position2DFloat;
    }
}