#pragma once

namespace mycge
{
	namespace gui
	{
        class IOSOperator
        {
        public:
            virtual ~IOSOperator(){}

            //! Copies text to the clipboard
            virtual void CopyToClipboard( const char* szText ) const = 0;

            //! Get text from the clipboard
            /** \return Returns 0 if no string is in there. */
            virtual const char* GetTextFromClipboard() const = 0;

            //! Get the processor speed in megahertz
            /** \param MHz The integer variable to store the speed in.
            \return True if successful, false if not */
            virtual bool GetProcessorSpeedMHz( unsigned int* nMHz ) const = 0;

            //! Get the total and available system RAM
            /** \param Total: will contain the total system memory
            \param Avail: will contain the available memory
            \return True if successful, false if not */
            virtual bool GetSystemMemory( unsigned int* nTotal, unsigned int* nAvail ) const = 0;
        };
	}
}