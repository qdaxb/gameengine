#pragma once

#include <string>
#include <cctype>

namespace mycge
{
    namespace gui
    {
        //! Used in places where we identify objects by a filename, but don't actually work with the real filename
        /** Irrlicht is internally not case-sensitive when it comes to names.
        Also this class is a first step towards support for correctly serializing renamed objects.
        */
        class SNamedPath
        {
        public:
            //! Constructor
            SNamedPath() {}

            //! Constructor
            SNamedPath( const string& strPath ) : m_strPath( strPath ), m_strInternalName( PathToName( strPath ) )
            {
            }

            //! Is smaller comparator
            bool operator <( const SNamedPath& other ) const
            {
                return m_strInternalName < other.m_strInternalName;
            }

            //! Set the path.
            void SetPath( const string& strPath )
            {
                m_strPath = strPath;
                m_strInternalName = PathToName( strPath );
            }

            //! Get the path.
            const string& GetPath() const
            {
                return m_strPath;
            };

            //! Get the name which is used to identify the file.
            //! This string is similar to the names and filenames used before Irrlicht 1.7
            const string& GetInternalName() const
            {
                return m_strInternalName;
            }

        protected:
            // convert the given path string to a name string.
            string PathToName( const string& strPath ) const
            {
                string strName( strPath );
                strName.replace( '\\', '/' );
                transform( strName.begin(), strName.end(), strName.begin(), tolower ); 
                return strName;
            }

        private:
            string m_strPath;

            string m_strInternalName;
        };
    }
}