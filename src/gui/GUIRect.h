#pragma once

#include "GUIPosition.h"
namespace mycge
{
    namespace gui
    {
        template<typename T>
        class Rect
        {
        public:
            //! Default constructor creating empty Rectangle at (0,0)
            Rect()
                : m_UpperLeftCorner( 0, 0), m_LowerRightCorner( 0, 0) {}

            //! Constructor with two corners
            Rect( T x, T y, T x2, T y2 )
                : m_UpperLeftCorner( x, y), m_LowerRightCorner( x2, y2) {}

            //! Constructor with two corners
            Rect( const Position2D<T>& upperLeft, const Position2D<T>& lowerRight )
                : m_UpperLeftCorner( upperLeft ), m_LowerRightCorner( lowerRight ) {}

        public:
            //! move right by given numbers
		Rect<T> operator+( const Position2D<T>& pos ) const
		{
			Rect<T> ret(*this);
			return ret += pos;
		}

		//! move right by given numbers
		Rect<T>& operator+=( const Position2D<T>& pos )
		{
			m_UpperLeftCorner += pos;
			m_LowerRightCorner += pos;
			return *this;
		}

		//! move left by given numbers
		Rect<T> operator-(const Position2D<T>& pos) const
		{
			Rect<T> ret(*this);
			return ret-=pos;
		}

		//! move left by given numbers
		Rect<T>& operator-=(const Position2D<T>& pos)
		{
			m_UpperLeftCorner -= pos;
			m_LowerRightCorner -= pos;
			return *this;
		}

		//! equality operator
		bool operator==(const Rect<T>& other) const
		{
			return ( m_UpperLeftCorner == other.m_UpperLeftCorner &&
				m_LowerRightCorner == other.m_LowerRightCorner);
		}

		//! inequality operator
		bool operator!=(const Rect<T>& other) const
		{
			return ( m_UpperLeftCorner != other.m_UpperLeftCorner ||
				m_LowerRightCorner != other.m_LowerRightCorner);
		}

		//! compares size of Rectangles
		bool operator<(const Rect<T>& other) const
		{
			return GetArea() < other.GetArea();
		}

		//! Returns size of Rectangle
		T GetArea() const
		{
			return GetWidth() * GetHeight();
		}

		//! Returns if a 2d point is within this Rectangle.
		/** \param pos Position to test if it lies within this Rectangle.
		\return True if the position is within the Rectangle, false if not. */
		bool IsPointInside(const Position2D<T>& pos) const
		{
			return (m_UpperLeftCorner.X <= pos.X &&
				m_UpperLeftCorner.Y <= pos.Y &&
				m_LowerRightCorner.X >= pos.X &&
				m_LowerRightCorner.Y >= pos.Y);
		}

        //! Check if the Rectangle collides with another Rectangle.
		/** \param other Rectangle to test collision with
		\return True if the rectangles collide. */
		bool IsRectCollided( const Rect<T>& other ) const
		{
			return ( m_LowerRightCorner.Y > other.m_UpperLeftCorner.Y &&
				m_UpperLeftCorner.Y < other.m_LowerRightCorner.Y &&
				m_LowerRightCorner.X > other.m_UpperLeftCorner.X &&
				m_UpperLeftCorner.X < other.m_LowerRightCorner.X );
		}

		//! Clips this Rectangle with another one.
		/** \param other Rectangle to clip with */
		void ClipAgainst( const Rect<T>& other )
		{
			if ( other.m_LowerRightCorner.X < m_LowerRightCorner.X )
            {
				m_LowerRightCorner.X = other.m_LowerRightCorner.X;
            }

			if ( other.m_LowerRightCorner.Y < m_LowerRightCorner.Y )
            {
                m_LowerRightCorner.Y = other.m_LowerRightCorner.Y;
            }

			if ( other.m_UpperLeftCorner.X > m_UpperLeftCorner.X )
            {
                m_UpperLeftCorner.X = other.m_UpperLeftCorner.X;
            }

			if ( other.m_UpperLeftCorner.Y > m_UpperLeftCorner.Y )
            {
                m_UpperLeftCorner.Y = other.m_UpperLeftCorner.Y;
            }

			// corRect possible invalid Rect resulting from clipping
			if ( m_UpperLeftCorner.Y > m_LowerRightCorner.Y )
            {
				m_UpperLeftCorner.Y = m_LowerRightCorner.Y;
            }

			if ( m_UpperLeftCorner.X > m_LowerRightCorner.X )
            {
                m_UpperLeftCorner.X = m_LowerRightCorner.X;
            }

		}

		//! Moves this Rectangle to fit inside another one.
		/** \return True on success, false if not possible */
		bool ConstrainTo( const Rect<T>& other )
		{
			if (other.GetWidth() < GetWidth() || other.GetHeight() < GetHeight())
				return false;

			T diff = other.m_LowerRightCorner.X - m_LowerRightCorner.X;
			if ( diff < 0 )
			{
				m_LowerRightCorner.X += diff;
				m_UpperLeftCorner.X  += diff;
			}

			diff = other.m_LowerRightCorner.Y - m_LowerRightCorner.Y;
			if ( diff < 0 )
			{
				m_LowerRightCorner.Y += diff;
				m_UpperLeftCorner.Y  += diff;
			}

			diff = m_UpperLeftCorner.X - other.m_UpperLeftCorner.X;
			if ( diff < 0 )
			{
				m_UpperLeftCorner.X  -= diff;
				m_LowerRightCorner.X -= diff;
			}

			diff = m_UpperLeftCorner.Y - other.m_UpperLeftCorner.Y;
			if ( diff < 0 )
			{
				m_UpperLeftCorner.Y  -= diff;
				m_LowerRightCorner.Y -= diff;
			}

			return true;
		}

		//! Get width of Rectangle.
		T GetWidth() const
		{
			return m_LowerRightCorner.X - m_UpperLeftCorner.X;
		}

		//! Get height of Rectangle.
		T GetHeight() const
		{
			return m_LowerRightCorner.Y - m_UpperLeftCorner.Y;
		}

		//! If the lower right corner of the Rect is smaller then the upper left, the points are swapped.
		void Repair()
		{
			if ( m_LowerRightCorner.X < m_UpperLeftCorner.X )
			{
				T t = m_LowerRightCorner.X;
				m_LowerRightCorner.X = m_UpperLeftCorner.X;
				m_UpperLeftCorner.X = t;
			}

			if ( m_LowerRightCorner.Y < m_UpperLeftCorner.Y )
			{
				T t = m_LowerRightCorner.Y;
				m_LowerRightCorner.Y = m_UpperLeftCorner.Y;
				m_UpperLeftCorner.Y = t;
			}
		}

		//! Returns if the Rect is valid to draw.
		/** It would be invalid if the m_UpperLeftCorner is lower or more
		right than the m_LowerRightCorner. */
		bool IsValid() const
		{
			return (( m_LowerRightCorner.X >= m_UpperLeftCorner.X ) &&
				( m_LowerRightCorner.Y >= m_UpperLeftCorner.Y ));
		}

		//! Get the center of the Rectangle
		Position2D<T> GetCenter() const
		{
			return Position2D<T>(
					( m_UpperLeftCorner.X + m_LowerRightCorner.X ) / 2,
					( m_UpperLeftCorner.Y + m_LowerRightCorner.Y ) / 2);
		}

        T Left() const
        {
            return m_UpperLeftCorner.GetX();
        }

        T Right() const
        {
            return m_LowerRightCorner.GetX();
        }

        T Top() const
        {
            return m_UpperLeftCorner.GetY();
        }

        T Bottom() const
        {
            return m_LowerRightCorner.GetY();
        }

        private:
            //! Upper left corner
            Position2D<T> m_UpperLeftCorner;
            //! Lower right corner
            Position2D<T> m_LowerRightCorner;
        };

        //! Rectangle with float values
        typedef Rect<float> RectFloat;
        //! Rectangle with int values
        typedef Rect<int> RectInt;
    }
}