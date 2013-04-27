#pragma once

namespace mycge
{
	namespace gui
	{
        //! Possible log levels.
        enum ELOG_LEVEL
        {
            //! High log level, warnings, errors and important information texts are printed out.
            ELL_INFORMATION = 0,

            //! Default log level, warnings and errors are printed out
            ELL_WARNING,

            //! Low log level, only errors are printed into the log
            ELL_ERROR,

            //! Nothing is printed out to the log
            ELL_NONE
        };
	}
}