#pragma once

#include "GUIDimension.h"

namespace mycge
{
	namespace gui
	{
        class IVideoDriver
        {
        public:
            //! Get the size of the screen or render window.
            /** \return Size of screen or render window. */
            virtual const Dimension2D<unsigned int>& GetScreenSize() const = 0;
        };
	}
}