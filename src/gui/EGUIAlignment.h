#pragma once

namespace mycge
{
    namespace gui
    {
        enum EGUI_ALIGNMENT
        {
            //! Aligned to parent's top or left side (default)
            EGUIA_UPPERLEFT=0,
            //! Aligned to parent's bottom or right side
            EGUIA_LOWERRIGHT,
            //! Aligned to the center of parent
            EGUIA_CENTER,
            //! Stretched to fit parent
            EGUIA_SCALE
        };

        //! Names for alignments
        const char* const GUIAlignmentNames[] =
        {
            "upperLeft",
            "lowerRight",
            "center",
            "scale",
            0
        };

    }
}